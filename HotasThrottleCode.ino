#include "USB.h"
#include "USBHIDGamepad.h"

// Das Objekt, das für Windows den Joystick simuliert
USBHIDGamepad Gamepad;

// --- Pin-Konfiguration ---
const int potPin = 5;

/////////////////////////////////////////////////////////////////////////////////////////////////////
// APPLY YOUR INDIVIDUAL SETTINGS HERE!                                                              //
/////////////////////////////////////////////////////////////////////////////////////////////////////
const int buttonPins[] = {2, 38, 45, 47, 48};
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);

int rawMinValue = 110;  
int rawMaxValue = 3900; 

/////////////////////////////////////////////////////////////////////////////////////////////////////

// --- Debounce-Speicher ---
const unsigned long debounceDelay = 20; // ms
int lastButtonReading[16];
int lastButtonStates[16];
unsigned long lastDebounceTime[16];

// --- Throttle-Filter-Einstellungen ---
const float smoothingAlpha = 0.20f;     
const int oversampleCount = 16;         
const unsigned long axisUpdateInterval = 5; 
const int axisHysteresis = 2;           

float smoothedValue = 0;
int lastSentAxisValue = -128;
unsigned long lastAxisUpdate = 0;

int readPotAveraged() {
  long sum = 0;
  for (int i = 0; i < oversampleCount; i++) {
    sum += analogRead(potPin);
  }
  return sum / oversampleCount;
}

void setup() {
  Serial.begin(115200); 

  // Konsistente ADC-Konfiguration
  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);

  // Buttons initialisieren (Gemischte Verkabelung)
  for (int i = 0; i < numButtons; i++) {
    if (i == 0) {
      pinMode(buttonPins[i], INPUT_PULLDOWN); // Button 1 schaltet 3.3V durch
    } else {
      pinMode(buttonPins[i], INPUT_PULLUP);   // Alle anderen schalten GND durch
    }
    
    // Initiale Status-Werte an die Pull-Widerstände anpassen
    lastButtonReading[i] = (i == 0) ? LOW : HIGH;
    lastButtonStates[i] = (i == 0) ? LOW : HIGH;
    lastDebounceTime[i] = 0;
  }

  smoothedValue = readPotAveraged();

  // --- Die USB-Erkennung für Windows ---
  USB.productName("Surottoru");
  USB.manufacturerName("Custom HOTAS Throttle");

  Gamepad.begin();
  USB.begin();
}

void loop() {
  unsigned long now = millis();

  // 1. BUTTONS
  for (int i = 0; i < numButtons; i++) {
    int reading = digitalRead(buttonPins[i]);

    if (reading != lastButtonReading[i]) {
      lastDebounceTime[i] = now;
    }

    if ((now - lastDebounceTime[i]) > debounceDelay) {
      if (reading != lastButtonStates[i]) {
        lastButtonStates[i] = reading;
        
        // Prüfen, ob der Taster als "gedrückt" gilt
        bool isPressed = false;
        if (i == 0 && reading == LOW) {     // GEÄNDERT: Reagiert jetzt auf LOW
          isPressed = true; 
        } else if (i > 0 && reading == LOW) {
          isPressed = true; 
        }

        if (isPressed) {
          Gamepad.pressButton(i + 1); 
        } else {
          Gamepad.releaseButton(i + 1);
        }
      }
    }
    lastButtonReading[i] = reading;
  }

  // 2. THROTTLE
  if (now - lastAxisUpdate >= axisUpdateInterval) {
    lastAxisUpdate = now;

    int rawValue = readPotAveraged();

    // Glättung
    smoothedValue = (smoothingAlpha * rawValue) + ((1.0f - smoothingAlpha) * smoothedValue);
    int currentValue = (int)(smoothedValue + 0.5f);

    // Erzeuge eine kleine "Deadzone" an den physikalischen Enden, damit 100% und 0% sicher gehalten werden
    currentValue = constrain(currentValue, rawMinValue + 10, rawMaxValue - 20);

    // Mapping auf Windows-Werte
    int axisValue = map(currentValue, rawMinValue + 10, rawMaxValue - 20, -127, 127);
    axisValue = constrain(axisValue, -127, 127);

    // Hysterese-Check. Nur senden, wenn die Änderung größer/gleich 2 ist
    if (abs(axisValue - lastSentAxisValue) >= axisHysteresis) {
      Gamepad.leftStick(0, axisValue);
      lastSentAxisValue = axisValue;
    }
  }
}