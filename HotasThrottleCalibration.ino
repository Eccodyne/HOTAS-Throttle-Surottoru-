// --- Digital Pins Setup ---
const int safePins[] = {1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 21, 38, 39, 40, 41, 42, 45, 46, 47, 48};
const int numPins = sizeof(safePins) / sizeof(safePins[0]);
int lastState[numPins];

// --- Analog Pin Setup ---
const int potPin = 5; // Change Pin number to your individual value
int lastAnalogValue = -1000;
float smoothedValue = 0; // Stores the smoothed floating-point math

void setup() {
  Serial.begin(115200);

  delay(1000);
  Serial.println("Monitoring digital pins (HIGH -> LOW) and Pin 5 for smooth analog changes...");
  Serial.println("--------------------------------------------------------------------------------");

  for (int i = 0; i < numPins; i++) {
    // Enable the ESP32 internal pull-up resistor
    pinMode(safePins[i], INPUT_PULLUP); 
    // The unpressed state is now HIGH
    lastState[i] = HIGH; 
  }
  
  // Take an initial reading to give the smoother a starting point
  smoothedValue = analogRead(potPin);
}

void loop() {
  // ---------------------------------------------------------
  // 1. DIGITAL PIN CHECK
  // ---------------------------------------------------------
  for (int i = 0; i < numPins; i++) {
    int pin = safePins[i];
    int currentState = digitalRead(pin);
    
    // Check for a falling edge: button just went from HIGH (unpressed) to LOW (pressed)
    if (currentState == LOW && lastState[i] == HIGH) {
      Serial.print(">>> DIGITAL SIGNAL on Pin: ");
      Serial.println(pin);
    }
    lastState[i] = currentState;
  }

// ---------------------------------------------------------
  // 2. ANALOG PIN CHECK (With Smoothing Filter & Float Math)
  // ---------------------------------------------------------
  int rawValue = analogRead(potPin);
  
  smoothedValue = (0.20 * rawValue) + (0.80 * smoothedValue);
  int currentValue = (int)smoothedValue;
  
  
  ///////////////////////////////////////////////////////////////////////////////////////////////////// 
  // APPLY YOUR INDIVIDUAL SETTINGS HERE!                                                            //
  /////////////////////////////////////////////////////////////////////////////////////////////////////
  float rawMinValue = 250.0; // Replace with your indiviual value as display in console output
  float rawMaxValue = 3900.0; // Replace with your indiviual value as display in console output
  /////////////////////////////////////////////////////////////////////////////////////////////////////


  if (abs(currentValue - lastAnalogValue) > 1) {
    
    // Calculate the percentage as a floating-point number (float) and invert it directly (100 - X)
    float percentage = 100.0 - (((float)currentValue - rawMinValue) / (rawMaxValue - rawMinValue) * 100.0);
    
    // Enforce limits (prevents values below 0.0 or above 100.0)
    if (percentage < 0.0) percentage = 0.0;
    if (percentage > 100.0) percentage = 100.0;
    
    Serial.print("~~~ ANALOG CHANGE on Poti Pin | Raw: ");
    Serial.print(currentValue);
    Serial.print(" | Position: ");
    
    // The ", 1" at the end specifies that 1 decimal place is printed (e.g., 0.8)
    Serial.print(percentage, 1); 
    Serial.println("%");
    
    lastAnalogValue = currentValue; 
  }

  delay(20); 
}
