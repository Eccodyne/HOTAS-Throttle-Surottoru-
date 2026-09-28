## 📌 Welcome to the "HOTAS Throttle Surottoru" Project!

![HOTAS Throttle Surottoru](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/IMG_4241.JPG)

### 💡What is this repository for?
Ready to build your own physical throttle? This repository holds the code and instructions for my HOTAS Throttle Surottoru project.

The throttle movement works smoothly and the five buttons can be configured individually in your games.

It’s a straightforward project that combines a few simple electronics, a 3D-printed case, and basic Arduino code. You don't need to be an expert to make this—just grab the parts, follow the steps below, and you'll have a fully tested, perfectly working controller in no time!
Link to 3D printing files on Makerworld: [Click](https://makerworld.com/de/models/2927499-garmin-g1000-controller-ms-flight-simulator-2024#profileId-3276793)

---
### 🛒 What components do I need to make this project?
- 3D printed parts
- ESP32 S3 Dev Kit (I used one from "diymore" ([link](https://www.amazon.de/dp/B0DWWVRNQX) to Amazon). Make sure to buy a board which has screw holes)
- 2x carbon rods (6mm diameter, 150mm length)
- 1x 470 Ohm resistor
- 1x 1k Ohm resistor
- 1x linear slide potentiometer (75mm)
- 1x KY-004 tactile button module 
- 4x tactile buttons (4pins), 12mm x 12mm size with a square shaped head on top (see image below)
- M3 threaded inserts
- Sufficient number of jumper wires (female/female, female/male)
- Set of M3 countersunk screws (various lengths) 
- Set of M3 cylinder head screws (various lengths)
- 2x M2.5 screws
- Heat-shrink tubings
- USB-C cable to connect the throttle device to your computer
- Soldering iron
- Super glue
- Hot glue
- 4x self-adhesive rubber feet to be attached to the bottom of the housing

***
### 💾 What software do I need to make this project?  
- Arduino IDE (free of cost)

***
### 🔎 Instructions

### 1️⃣ Building the HOTAS throttle:

- Download *.3mf files for this project from Makerworld: [Link](https://makerworld.com/de/models/2927499-garmin-g1000-controller-ms-flight-simulator-2024#profileId-3276793).
- 3D print the required components.
- Use super glue to attach the logo (Japanese text) to the front of the base.
- Using a soldering iron, install the M3 heat-set threaded inserts into the printed parts as shown in the images below.
- Solder two jumper wires (GND and signal) to each of the four tactile buttons. Use two adjacent pins on the same side of the button (see image below). Once done, you need to carefully bend the pins to the back, otherwise the cover will not fit on the base.
- Insert the linear potentiometer into the printed holder, ensuring the four pins of the potentiometer face the front of the housing.
- Take a jumper wire (for GND) and cut it in half. Add a 470 Ohm resistor and connect the two cables by either soldering or tighly twisting the cables.
- Take a jumper wire (for 3.3V) and repeat the above procedure, though with a 1k Ohm resistor.
- Both resistors are required for the ESP32 S3 to read the full range of the linear potentiometer. The throttle will not work correctly if you skip this step.
- Attach the GND jumper wire with the attached 470 OLhm resistor to the lower pin at the far end of the potentiometer (facing the back of the housing, see image). 
- Attach the 3.3V wire with the 1k Ohm resistor to the lowest of the four pins at the opposite end of the potentiometer.
- Attach a signal wire to the pin directly above the 3.3V pin.
- Mount the potentiometer holder to the housing using two M3 screws.
- Install the ESP32-S3 board upside down in the housing by pressing it down onto the standoffs. The two USB-C ports should fit perfectly between the two rear standoffs.
- Secure the ESP32-S3 board in place using the printed fixation plate and screw.

- Insert the carbon rods into the rod holder and attach it to the linear potentiometer's metal pin (note the cutout on the side of the rod holder).
- Secure the carbon rods by screwing on the four caps.
- Place the four tactile buttons into the back of the base cover and secure them using the printed brackets (see image below).
- Turn the base cover over and install the four printed buttons.
- Because the ESP32-S3 has only two GND pins, you must combine all GND wires of the buttons into a single wire that connects to one of the two GND pins on the ESP32 S3. You can do this by soldering or tightly twisting the wires together, then securing them with heat shrink tubing.
- This process needs to be repeated for the GND wires connected to the linear potentiometer and the KY-004 button module, but at a later stage.
- Complete the wiring, extending any wires as needed if they are too short. Organize everything using the printed cable guides, which can be attached to the cover and base with adhesive tape (refer to the images below for examples). I also used heat shrink tubing for better cable management.
- Connect all signal wires from the four tactile buttons to available data pins on the ESP32-S3, and connect the combined GND wire to one of the GND pins.
- Connect the 3.3V wire from the linear potentiometer to a free 3.3V pin on the ESP32-S3.
- Route the GND, 3.3V, and signal wires for the KY-004 tactile button module through the shaft of the right handle (see image below).
- Extend the three wires coming down from the shaft using male/female jumper wires.
- Mount the shaft with the routed wires to the right side of the rod holder using two M3 screws from below (see images below).
- Secure the wires coming from the shaft using the plate, as shown in the images below.
- Combine the GND wires from the linear potentiometer and the KY-004 tactile button module into a single GND wire (by either soldering or twisting them together), and connect it to the second GND pin on the ESP32-S3.
- Connect the signal wire from the linear potentiometer to a data pin on the ESP32-S3, making sure to note down the pin number
- Connect the 3.3V wire from the linear potentiometer to the second 3.3V pin on the ESP32-S3.
- Make sure that the rod holder runs smoothly backand forth with the metal pin of the linear potentiometer attached to it. There should not be any resistance.
- Place the cover over the base and fixate it with four M3 screws. 
- Guide the GND, 3.3V and signal wires through the right handle of the throttle and fixate the handle using two M3 cylinder head screws (see images below).
- Attach the KY-004 tactile button module to the right handle of the throttle using two M2.5 screws and attach the GND, 3.3V and signal wires to the module.
- Attach the printed button to the cap of the right handle, place the cap on the handle and secure it with two M3 cylinder head screws.
- Attach the left shaft to the left handle using two M3 cylinder head screws and fixate the shaft (with the attached left handle) to the rod holder with two M3 screws.
- Secure the lid to the bottom of the housing using two M3 screws.
  
### 2️⃣ Running the Arudino code:
- Install and run the Arduino IDE.
- Create a new sketch and paste the code from the "HotasThrottleCalibration.ino" file provided on this GitHub page.
- Connect the ESP32-S3 to your computer with a USB-C cable using the TTL port (the left port on the back of the base).
- In the Arduino IDE, select the correct board (Tools -> Board); it should be "ESP32-S3-USB-OTG".
- Select the correct COM port for the ESP32-S3 (Tools -> Port).
- On line 7 of the code, replace the potPin variable's pin number with the one you are actually using for the linear potentiometer. The line looks like this: const int potPin = 5; // Change Pin number to your individual value.
- Save the sketch and upload it to your ESP32-S3 board.
- Once uploaded, open the Serial Monitor in the Arduino IDE. Press every button on the cover and the right handle of the throttle, and note down the corresponding pin numbers.
- Pull the throttle all the way back and note the value shown as "Position". This will be your rawMinValue in the final Arduino code.
- Push the throttle all the way forward and note this value as well. This will be your rawMaxValue.
- Close the sketch, create a new one, and paste the code from the "HotasThrottleCode.ino" file.
- On line 13 (buttonPins[]), replace the default pin numbers with your specific values. IMPORTANT: The pin for the KY-004 tactile button module must be placed at the first position in the array!
- On lines 16 and 17, replace the default values with your own rawMinValue and rawMaxValue.
- Save the sketch and upload it to your ESP32-S3.
- Move the USB-C cable from the TTL port to the OTG port on your ESP32-S3.
- Your computer should now recognize the ESP32-S3 as an input device.
- Run the Windows tool joy.cpl, select your ESP32-S3 device, and click "Properties" to test if the buttons and throttle are working correctly.
- If the buttons or throttle do not work, double-check your wiring and ensure all pin numbers were entered correctly in the Arduino code.
- If the throttle acts "jumpy", ensure that the rod holder moves smoothly and without resistance. Also, check that no cables are in the way causing interference or obstructing its movement.

### 📷 Images:

M3 threaded inserts (base):
![Inserts](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/M3_threaded_inserts_base.jpg)
![Inserts2](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/M3_threaded_inserts_base_2.jpg)

M3 threaded inserts (left handle):
![Inserts3](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/M3_threaded_inserts_left_handle.jpg)

M3 threaded inserts (right handle):
![Inserts4](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/M3_threaded_inserts_right_handle_front.jpg)
![Inserts5](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/M3_threaded_inserts_right_handle_back.jpg)

M3 threaded inserts (shafts):
![Inserts6](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/M3_threaded_inserts_shafts.jpg)

ESP32-S3 (with screw holes):
![ESP32S3](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/ESSP32S3.JPG)

Tactile button (you need four of these):
![TactileButton](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/TactileButton.JPG)


Cable fixator:
![Inserts6](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/Fixate_cables.jpg)

Resistors for GND and 3.3V wires of linear potentiometer:
![Resistors](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/Resistors.jpg)

Combined wires:

![Combined1](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/Combined_GND_wires_I.jpg)
![Combined2](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/Combined_GND_wires_II.jpg)

Base:
![Base](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/Base.JPG)

Front view:
![FrontView](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/IMG_4248.JPG)

Buttons:
![Buttons](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/Base_Cover.JPG)

Rod Holder:
![RodHolder](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/Rod_Holder.JPG)

Right shaft with wires:
![RightShaft](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/Right_Shaft.JPG)

Right handle with KY-004 mdoule:
![RightHandle](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/Right_Handle.JPG)
