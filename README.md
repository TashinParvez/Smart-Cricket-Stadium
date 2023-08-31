#  Arduino based Smart Cricket Stadiun

**Abstract**— This report is about to an electronic hardware based
project where we have implemented an Arduino based Smart
Cricket Stadium. Our aim is to make cricket games more efficient
during unstable weather by implementing an automated pitch
covering system. To make this report understandable, We added
a flowchart, photographs, and descriptions. Our features can also
be applicable in other places.

**Index Terms**— Arduino,HDS,Stepper Motor, LDR, Servo, IR


##  PROJECT OVERVIEW

Our project is about an Arduino-based smart cricket stadium. The reason we implemented this project was to make
cricket more automated and accurate. We also ensure that our
automated feature is suitable during playtime. We secure the
pitch to be dry during rain time so that the play may start
after the rain using HDS and Stepper Motor. Also, we placed
the boundary line after displacement by fielders or others.
To detect that the line is displace we use weight sensor and
fixed the line using DC Motor Mechanism. And to ensure the
power play rules, we get count from IR sensor that how many
players are inside 30 yards and outside 30 yards . This will
help the umpire make the correct decision. Another feature is
control stadium light brightness according sunlight based on
LDR sensor read. Apart from this we implement move able
solar system according sun position to absorb maximum power
using servo motor and LDR sensor.

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

##  IMPLEMENTATION
1. Automate pitch covering:

When rain started Humidity Detection sensor detect rain
it send reading to the Arduino and Arduino command
the stepper motor to proceed.
Humidity Detection Sensor —–Arduino Uno —— Stepper Motor —–Cover Mechanism
Humidity Detection Sensor: Detect when rain started.
Aurduino Uno:
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

