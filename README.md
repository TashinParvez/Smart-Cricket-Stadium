#  Arduino-based Smart Cricket Stadium

**Abstract**— This report is about to an electronic hardware-based
project where we have implemented an Arduino-based Smart
Cricket Stadium. Our aim is to make cricket games more efficient
during unstable weather by implementing an automated pitch-covering system. To make this report understandable, We added
a flowchart, photographs, and descriptions. Our features can also
be applicable in other places.

**Index Terms**— Arduino, HDS, Stepper Motor, LDR, Servo, IR


##  PROJECT OVERVIEW

Our project is about an Arduino-based smart cricket stadium. The reason we implemented this project was to make
cricket more automated and accurate. We also ensure that our
automated feature is suitable during playtime. We secure the
pitch to be dry during rain time so that the play may start
after the rain using HDS and Stepper Motor. Also, we placed
the boundary line after displacement by fielders or others.
To detect that the line is displaced we used a weight sensor and
fixed the line using DC Motor Mechanism. To ensure the
power play rules, we get the count from IR sensor of how many
players are inside 30 yards and outside 30 yards. This will
help the umpire make the correct decision. Another feature is
the control of stadium light brightness according to sunlight based on
LDR sensor read. Apart from this, we implement a moveable
solar system according sun's position to absorb maximum power
using a servo motor and LDR sensor.

![Blue Circuit](https://github.com/TashinParvez/Smart-Cricket-Stadium/assets/84122972/2e8d4798-823a-490c-88e2-e4f1ca1317d7)

Project demonstration: https://www.youtube.com/watch?v=qhRFEcPciuE&t=25s

##  COMPONENT LIST

1) Arduino Uno
2) Humidity Detection Sensor
3) Stepper Motor
4) LDR Sensor
5) Servo Motor
6) IR Sensor
7) DC Motor
8) Resistor
9) Jumper Wire
10) Solar Panel
11) Li-ion Battery
12) Rain sensor


##  Features
- **Automate pitch covering**

    We detect rain using rain sensors. When rain is detected, our system provides a 5-second warning and activates our covering system.

- **Automated Boundary Line fixing** 

    First We detect whether the boundary line moved from its actual place or not then our system runs 2 DC motors to fix that system.

- **Power Play Player Count**
    Our system can count the player under 30 yards which helps umpire the run a game perfectly.

- **Maximum Sunlight absolve system**  

    LDR sensor tracks the sun, aligning solar-covered roofs for optimal power.

- **Automated Light Brightness Increase And Decrease**

    Using LDR sensors we measure sunlight depending on our system increases and decreases the power of stadium lights.

![Team Blue Circuit](https://github.com/TashinParvez/Smart-Cricket-Stadium/assets/84122972/b934245d-df22-445d-be51-ed4b4d792201)


##  IMPLEMENTATION
1. Automate pitch covering:

When the rain starts Humidity Detection sensor detects rain. It sends readings to the Arduino and Arduino command
the stepper motor to proceed.
Humidity Detection Sensor —–Arduino Uno —— Stepper Motor —–Cover Mechanism
Humidity Detection Sensor: Detect when rain starts.
Arduino Uno:
Read analog signal from sensor and analize reading.
Stepper Motor:
After receiving signal from aurduino motor takes the
commandig steps.

2. Automated Boundary Line fixing:

Weight sensor ——- Auruino Uno —— DC motor ——
Mechanism
Weight Sensor: Sense the rope weight
Aurduino Uno:
Receiving signal from weight sensor and give instruction
to DC Motor.
DC Motor:
After receiving signal from DC Motor follow command.

3) Power Play Player Count:

IR Sensor—-Arduino—-Display
IR Sensor: IR senor count from the start and sending
signal to arduino. Arduino Uno:
After getting signal, Arduino will show in LCD.
.LCD Display: Receiving command from Arduino.

4) Maximum Sunlight absolve system:

LDR Sensor —- Arduino Uno—– Servo Motor
LDR Sensor : Light Detection Photosensitive send analog signal to Arduino.
Arduino Uno : Arduino Receive signal from LDR and
send command to Servo Motor.
Servo Motor: Servo Motor receive signal from Arduino.

5) Automated Light Brightness Increase And Decrease:

LDR —- Arduino Uno— LED Light
LDR Sensor : Light Detection Photosensitive send analog signal to Arduino.
Arduino Uno : Arduino Receive signal from LDR and
send command to LED Light.
LED Light: LED light Ingres or decrease brightness
according Arduino Signal.


## Authors

- [@shafayetOvi](https://www.github.com/octokatherine](https://github.com/shafayetOvi)https://github.com/shafayetOvi)
- [@TashinParvez](https://github.com/TashinParvez)
- [@SharminLiza](https://github.com/SharminLiza)
- [@musfiqurR661](https://github.com/musfiqurR661)
- [@mnoman338](https://github.com/mnoman338)
  
![blueSnew](https://github.com/TashinParvez/Smart-Cricket-Stadium/assets/84122972/9fbc9f0a-64ab-48a9-a729-7031cbf5e191)
