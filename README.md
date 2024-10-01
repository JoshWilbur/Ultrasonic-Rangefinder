# Ultrasonic-Rangefinder

Description coming soon

Connections (RPi 0W): VCC = 5V, GND = 0V, TRIG = GPIO18, ECHO = GPIO6, SCL = GPIO5, SDA = GPIO3
Compile display with: gcc ssd_1306.c fontx.c -o s -lwiringPi

# TODO

* Make schematic, update block diagrams (Josh)
* Impliment display code into main function (Josh)
* Program to input readings from sensor (Siddhartha)
* Program to process readings, output avg. distance, mean, std (both)
* Move makefile out of src, header files to /inc
* 3D print case? If so, ask Amir for help
