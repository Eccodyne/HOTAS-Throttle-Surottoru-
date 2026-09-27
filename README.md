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
- 3D print the required components
- Using a soldering iron, install the M3 heat-set threaded inserts into the printed parts as shown in the images below.
- Solder two jumper wires (GND and SIGNAL) to each of the four tactile buttons. Use two adjacent pins on the same side of the button (see image below).
- Insert the linear potentiometer into the printed holder, ensuring the four pins of the potentiometer face the front of the housing.
- Attach a GND jumper wire to the lower pin at the far end of the potentiometer (facing the back of the housing, see image). I recommend soldering the connection, but you can also use hot glue to keep the wire in place. This is what I did.
- Attach a 3.3V jumper wire to the lowest of the four pins at the opposite end of the potentiometer.
- Attach a SIGNAL jumper wire to the pin directly above the 3.3V pin.
- Mount the potentiometer holder to the housing using two M3 screws.
- Install the ESP32-S3 board upside down in the housing by pressing it down onto the standoffs. The two USB-C ports should fit perfectly between the two rear standoffs.
- Secure the ESP32-S3 board in place using the printed fixation plate and screw.

