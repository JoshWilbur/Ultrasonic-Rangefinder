#include "common_libs.h"
#include "PWM_setup.h"
#include "display.h"


int main(){
	setup_PWM();

	// OLED code
        reset_OLED();
        sleep(1);
        text_OLED("+1", "hello world");
        sleep(1);
        show_OLED();

	return 0;
}
