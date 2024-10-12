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
	double distance_cm = 0;
	char oled_buf[64];

	// Obtain readings every second and update display
	while(1){
		distance_cm = getDistance();
		snprintf(oled_buf, sizeof(oled_buf), "%.2f cm", distance_cm);

		// Display reading on OLED
		reset_OLED();
		text_OLED("+1", "Rangefinder");
		text_OLED("+2", oled_buf);
		text_OLED("+3", "Sid & Josh");
		show_OLED();

		sleep(1);
	}

	gpioTerminate();  // Clean up pigpio resources
	return 0;
}
