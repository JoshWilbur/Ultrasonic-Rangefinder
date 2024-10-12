#include "inc/common_libs.h"
#include "inc/display.h"
#include "inc/range.h"

int main(){
	// Confirm root user is running program
        if (geteuid() != 0) {
                printf("Please run as root\n");
                exit(1);
        }

	setup_gpio();
	reset_OLED();
	double distance_cm, distance_in;
	char cm_buf[32];
	char in_buf[32];

	// Obtain readings every second and update display
	while(1){
		distance_cm = getDistance();
		distance_in = distance_cm / 2.54; // Convert to inches
		snprintf(cm_buf, sizeof(cm_buf), "%.2f cm", distance_cm);
		snprintf(in_buf, sizeof(in_buf), "%.2f in", distance_in);

		// Display reading on OLED
		reset_OLED();
		text_OLED("+1", "Rangefinder");
		text_OLED("+2", cm_buf);
		text_OLED("+3", in_buf);
		show_OLED();

		usleep(1000);
	}

	gpioTerminate();  // Clean up pigpio resources
	return 0;
}
