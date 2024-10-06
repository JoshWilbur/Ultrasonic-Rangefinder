#include "common_libs.h"
#include "PWM_setup.h"
#include "display.h"


int main(){
	setup_PWM();

	// OLED code
        reset_OLED();
        sleep(1);
        text_OLED("+1", "ECE498");
	text_OLED("+2", "U.S. Rangefinder");
	text_OLED("+3", "Sid & Josh");
        sleep(1);
        show_OLED();

	return 0;
}
