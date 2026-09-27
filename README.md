## 📌 Welcome to the "HOTAS Throttle Surottoru" Project!

![HOTAS Throttle Surottoru](https://github.com/Eccodyne/HOTAS-Throttle-Surottoru-/blob/main/images/IMG_4241.JPG)

# HOTAS Throttle "Surottoru"
This ESP32-S3-based throttle is recognized by Windows as a game controller, making it ideal for flight simulators and any other games where you want to control thrust with a pysical device.

### 💡What is this repository for?
Ready to build your own physical throttle? This repository holds the code and instructions for my HOTAS Throttle Surottoru project.

It’s a straightforward project that combines a few simple electronics, a 3D-printed case, and basic Arduino code. You don't need to be an expert to make this—just grab the parts, follow the steps below, and you'll have a fully tested, perfectly working controller in no time!
Link to 3D printing files on Makerworld: [Click](https://makerworld.com/de/models/2927499-garmin-g1000-controller-ms-flight-simulator-2024#profileId-3276793)

---
### 🛒 What components do I need to make this project?
- 3D printed parts
- ESP32 S3 Dev Kit (I used one from "diymore" ([link](https://www.amazon.de/dp/B0DWWVRNQX) to Amazon). Make sure to buy a board which has screw holes)
- 2x carbon rods (6mm diameter, 150mm length)
- 1x linear slide potentiometer (75mm)
- 1x KY-004 tactile button module 
- 4x tactile buttons (4pins), 12mm x 12mm size with a square shaped head on top (see image below)
- M3 threaded inserts
- Sufficient number of jumper wires
- Set of M3 countersunk screws (various lengths) 
- Set of M3 cylinder head bolts (various lengths)
- USB-C cable to connect the throttle device to your computer
- Soldering iron
- 4x self-adhesive rubber feet to be attached to the bottom of the housing

***
### 💾 What software do I need to make this project?  
- Arduino IDE (free of cost)

***
### 🔎 How do I get started?
- Download *.3mf files for this project from Makerworld: [Link](https://makerworld.com/de/models/2927499-garmin-g1000-controller-ms-flight-simulator-2024#profileId-3276793)
- Print the files with your 3D printer
- Use a soldering iron to apply M3 threaded inserts to the various printed parts as per the images shown below 
- Do the same for the right handle of the throttle (two inserts), the left handle (two inserts) and the two shafts to which the handles are connected to (see image below)
- Use a soldering iron to solder two jumper wires (GND and SIGNAL) to each of the four tactile buttons (use two pins that are right next to each other on the same side of the button, see image below)
- Insert the linear potentiometer into the printed potentiometer holder. The fours pins of the potentiometer need to face to the front of the housing
- Attach a jumper wire (GND) to the lower pin at the back of the potentiometer (see image). You can use hot glue to keep the jumper wire in place or use a soldering iron
- Attach a jumper wire (3.3V) to the lowest of the four pins at the other end the potentiometer
- Attach a jumper wire (SIGNAL) to the pin above the 3.3V PIN
- Attach the poti holder to the housing using two M3 screws
- 
- Install the ESP32 S3 board to the housing (upside down) by pushing it down onto the spacers. The two USB-C ports of the ESP32 S3 will fit inbetween the two spacers at the back of the housing.
- Lock the ESP32 S3 board by using the printed screw and the fixation plate
-  
- Install the Arduino 2560 MEGA board to the housing using the M2.5 screws. Do not use force.
- Attach the tactile buttons to the button covers (see image below)
- Install the joystick to the top cover using M3 screws
- Install the rotary encoders to the top cover using M2.5 screws
- Attach jumper wires to the tactiles buttons, 1x GND, 1X digital signal for each button, what pin you choose for GND or VOLTAGE does not not matter (see images and instructions below).
- Connect one pin of the tactile buttons to a GND port on the breadboard and the other pin to a digital port of the Arduino 2560 MEGA. As noted above, for the tactile buttons, it does not matter which of the two pins you choose for GND or the digital signal.
- Connect the joystick and the rotary encoders with jumper wires in accordance with the instructions coming with for parts. You can also look up pin layouts via a Google search
- Fix the GND/VOLTAGE breadboard on top of one of the button covers (see image below). You can use self-adhevise tape, my breadbord already had self-adhesive tape applied to it
- Connect all GND/VOLT pins of the joystick and the rotary encoders to GND/Voltage pins of the breadbord, and all other digital pins of the joystick to the Arduino 2560 MEGA
- Connect the VRX pin of the joystick to pin A0 of the Arduino 2560 MEGA board and the VRY pin to A1 of the Arduino 2560 MEGA Board
- Connect a 3V and GND jumper wire between the GND/Voltage breadboard and the Arduino 2560 MEGA board 
- Place heatshrink tubes between the pins of the tacticle buttons to avoid shorts / false signals (see image below)
- Important: Only the VRX and VRY pins of the joystick need to be connected to the analogue A0 / A1 pins of the Arduino MEGA 2560. All other signal pins need to be attached to the digital pins of the Arduino 2560 MEGA
- Important: It does not matter to what digital pins you connect the jumper wires to, the Arduino sketch / code will tell you the pin numbers you need to write down (see instructions below)
- Leave the housing open for now
