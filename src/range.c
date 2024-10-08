#include <stdio.h>
#include <stdlib.h>
#include <pigpio.h>
#include <unistd.h>

#define TRIG  23  // GPIO 23 for Trigger
#define ECHO  24  // GPIO 24 for Echo

void setup() {

    gpioInitialise() < 0; // Initialize pgpio library
    
    gpioSetMode(TRIG, PI_OUTPUT);  // Set TRIG pin as OUTPUT
    gpioSetMode(ECHO, PI_INPUT);   // Set ECHO pin as INPUT

    // Ensure TRIG pin is low initially
    gpioWrite(TRIG, PI_OFF);
    usleep(30000);  // Wait for sensor to settle
}

double getDistance() {

    // Send a 10 microsecond pulse to TRIG
    gpioWrite(TRIG, PI_ON);
    usleep(10);  // Send pulse for 10 microseconds
    gpioWrite(TRIG, PI_OFF);

    // Wait for the ECHO pin to go high and start timing
    uint32_t startTick = gpioTick();
    while (gpioRead(ECHO) == 0) {
	if (gpioTick() - startTick > 200000){
	   return -1;
 	}
    }
	
    uint32_t startTime = gpioTick();

    // Wait for the ECHO pin to go low and stop timing
    startTick = gpioTick();
    while (gpioRead(ECHO) == 1) {
	if (gpioTick() - startTick > 200000){
           return -1;
        }
    }

    uint32_t travelTime = gpioTick() - startTime;

    // Calculate distance in cm (speed of sound is 34300 cm/s)
    double distance = (travelTime / 2.0) / 29.1;
    return distance;

}

int main(void) {
    setup();

    while (1) {
        double distance = getDistance();

        if (distance < 0 || distance > 400) {
            printf("Out of range or invalid measurement\n");
        } else {
            printf("Distance: %.2f cm\n", distance);
        }

        sleep(1);  // Wait for a second before the next measurement
    }

    gpioTerminate();  // Clean up pigpio resources
    return 0;
}

