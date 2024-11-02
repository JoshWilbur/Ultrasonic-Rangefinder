#include "inc/common_libs.h"

//#define TRIG  23  // GPIO 23 for Trigger
//#define ECHO  24  // GPIO 24 for Echo

// For RPi 0:
#define TRIG  18  // GPIO 18 for Trigger
#define ECHO  6  // GPIO 6 for Echo

// Function prototypes
void setup_gpio(void);
double getDistance(void);

void setup_gpio(void){

    gpioInitialise(); // Initialize pgpio library

    gpioSetMode(TRIG, PI_OUTPUT);  // Set TRIG pin as OUTPUT
    gpioSetMode(ECHO, PI_INPUT);   // Set ECHO pin as INPUT

    // Ensure TRIG pin is low initially
    gpioWrite(TRIG, PI_OFF);
    usleep(30000);  // Wait for sensor to settle
}

double getDistance(void) {

    // Send a 100 microsecond pulse to TRIG
    gpioWrite(TRIG, PI_ON);
    usleep(100);  // Send pulse for 100 microseconds
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
    if (distance < 0 || distance > 400) distance = -1; // Send invalid distance if error
    return distance;

}
