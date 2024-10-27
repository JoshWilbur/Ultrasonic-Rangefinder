#include "inc/common_libs.h"
#include "inc/range.h"
#include "inc/ssd1306.h"
#include "inc/reading.h"
#include "inc/user_input.h"

#define SWITCH_PIN 17

int main(){
	// Confirm root user is running program
        if (geteuid() != 0) {
                printf("Please run as root\n");
                exit(1);
        }

	setup_gpio();
	input_setup();

	// Setup for display
	ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);

	double distance_cm, distance_in;
	double distances[2]; // An array storing 3 values of distances
	int count = 0;
	int sw = 0;

	// Obtain readings every second and update display
	while(1){
		distance_cm = getDistance();
		distance_in = distance_cm / 2.54; // Convert to inches
		sw = read_input();

		if (sw == 1){    // Check if switch is closed
			distances[count] = distance_cm;
			count++;

			if (count == 2) {
				display_statistics(distances, 2);
				count = 0;
				usleep(3000000); // Wait three seconds to process 3 distance measurements
			}
		} else {
			display_distance(distance_cm, distance_in);
			usleep(1000);
		}
	}

	gpioTerminate();  // Clean up pigpio resources
	return 0;
}
