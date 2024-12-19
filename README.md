RC Car Based on AVR Microcontroller

This README provides an overview of the RC Car project based on an AVR microcontroller. The car features Bluetooth control, ultrasonic obstacle detection, and line tracking functionality.

Table of Contents

Introduction

Features

Hardware Requirements

Software Requirements

Wiring and Circuit Design

Code and Programming

How to Use

Troubleshooting

Introduction

This RC Car project uses an AVR microcontroller to integrate multiple functionalities, making it a versatile and interactive system. The car can be remotely controlled via Bluetooth, detect obstacles with ultrasonic sensors, and follow a predefined path using a line tracking module.

Features

Bluetooth Control: Remotely control the car via a smartphone or Bluetooth-enabled device.

Ultrasonic Obstacle Detection: Avoids collisions by detecting obstacles within a specific range.

Line Tracking: Follows a predefined path using a line tracking sensor.

Hardware Requirements

Microcontroller: AVR (e.g., ATmega328P or ATmega32).

Bluetooth Module: HC-05 or HC-06.

Ultrasonic Sensor: HC-SR04.

Line Tracker Module: Array of IR sensors or a TCRT5000 module.

Motor Driver: L298N or equivalent.

DC Motors: Two or four, depending on the design.

Power Supply: Battery pack (7.4V to 12V, depending on motor and microcontroller).

Chassis: RC car chassis with mounting points for components.

Additional Components:

Resistors, capacitors, and LEDs.

Jumper wires and breadboard/PCB.

Software Requirements

Compiler: AVR GCC 

Programmer: USBasp or similar.

Drivers:

DIO
Timers
ICU

Wiring and Circuit Design

Microcontroller:

Connect the Bluetooth module to the UART pins (TX and RX) of the microcontroller.

Connect the ultrasonic sensor’s trigger and echo pins to GPIO pins.

Connect the line tracker module to analog or digital pins, depending on the sensor type.

Motor Driver:

Connect the motor driver inputs to the microcontroller’s PWM pins.

Connect the motor driver outputs to the DC motors.

Power Supply:

Ensure a common ground among all components.

Supply appropriate voltage levels to the microcontroller, sensors, and motor driver.

Code and Programming

Write or upload firmware to the AVR microcontroller that:

Handles Bluetooth communication for receiving commands.

Processes ultrasonic sensor input to detect obstacles.

Reads line tracking sensor values to adjust motor speeds for following a path.

Use libraries or create functions for:

Bluetooth communication.

Calculating distances from ultrasonic sensor readings.

Program the microcontroller using a USBasp or similar programmer.

How to Use

Setup:

Mount all components securely on the RC car chassis.

Power up the system and ensure all components are connected.

Bluetooth Control:

Pair your Bluetooth-enabled device with the HC-05/HC-06 module.

Use a Bluetooth terminal app to send control commands (e.g., forward, backward, left, right).

Obstacle Detection:

Test the ultrasonic sensor by placing obstacles at different distances and observing the car’s response.

Line Tracking:

Place the car on a path with a black line on a white background and test its ability to follow the line.

Troubleshooting

No response from the car:

Check power supply connections and ensure the microcontroller is running the correct code.

Verify the Bluetooth module pairing and connectivity.

Line tracking is inaccurate:

Adjust the sensitivity of the line tracker sensors.

Obstacle detection is unreliable:

Ensure the ultrasonic sensor is aligned properly.

Test with different obstacles to check sensor performance.

