#include "inc/common_libs.h"
#include "inc/range.h"
#include "inc/ssd1306.h"

int main(){
	// Confirm root user is running program
        if (geteuid() != 0) {
                printf("Please run as root\n");
                exit(1);
        }

	setup_gpio();

	// Setup for display
	ssd1306_begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS);
	ssd1306_setTextSize(2);

	double distance_cm, distance_in;
	char cm_buf[32];
	char in_buf[32];

	// Obtain readings every second and update display
	while(1){
		distance_cm = getDistance();
		distance_in = distance_cm / 2.54; // Convert to inches
		snprintf(cm_buf, sizeof(cm_buf), "%.2f cm\n", distance_cm);
		snprintf(in_buf, sizeof(in_buf), "%.2f in", distance_in);

		// Display readings
		ssd1306_clearDisplay();
		ssd1306_drawString("Distance\n");
		ssd1306_drawString(cm_buf);
		ssd1306_drawString(in_buf);
		ssd1306_display();

		usleep(1000);
	}

	gpioTerminate();  // Clean up pigpio resources
	return 0;
}
