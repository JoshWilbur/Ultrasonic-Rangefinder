# Ultrasonic-Rangefinder
**Developers**: Siddhartha Bajracharya and Joshua Wilbur

**Description**: A short distance ultrasonic rangefinder utilizing a Raspberry Pi 0 and HC-SR04 sensor. Distances from roughly 3cm to 400cm can be measured. A SSD1306 display is used to output readings. Credit to Ilia Penev for the ssd1306.c driver file. A schematic of this design can be found at docs/Rangefinder_schematic.pdf. This device has been benchmarked, results are shown below.

| Known Distance| Measured Distance|
| ------------- | ------------- |
| 10cm | 10.12cm |
| 28.7cm | 28.6cm |
| 63cm | 62cm |
| 100cm | 99.5cm |
| 150cm | 151.1cm |
| 184cm | 182.5cm |

Link to display library: https://github.com/iliapenev/ssd1306_i2c

# Operation Guide
1. Obtain the hardware listed in the bill of materials.
2. Construct the hardware according to the schematic. Breadboard or solderboard will both work.
3. Log into the Pi and run `git clone https://github.com/JoshWilbur/Ultrasonic-Rangefinder`
4. `cd Ultrasonic-Rangefinder/src`
5. Run `make` to compile and link the files. A binary named `US_range` will be generated.
6. To test the prototype, run `./US_range`
* Optional: Make the binary a cron job to start the program @reboot.

# Image of Prototype
![Soldered prototype](images/final_prototype.jpg)
