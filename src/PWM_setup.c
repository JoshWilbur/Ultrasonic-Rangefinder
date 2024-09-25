#include "common_libs.h"

// Function prototypes
void write_PWM_file(const char *path, int value);
void setup_PWM(void);

// This function can write values to the various PWM config files
void write_PWM_file(const char *path, int value){
        // Open config file and error check
        FILE *fp = fopen(path, "w");
        if (fp == NULL){
                perror("Error opening file");
                exit(1);
        }
        fprintf(fp, "%d", value); // Output argument to desired PWM file
	fclose(fp);
}

void setup_PWM(void){
        // Confirm root user is running program since config files are modified
        if (geteuid() != 0) {
                printf( "Please run as root");
                exit(1);
        }

	// Constants for period and duty cycle (ns)
	const int period = 50000000; // 50ms/20Hz
	const int duty = period * 0.2; // 20% duty cycle

	// File paths for PWM on my RPi 0W
	write_PWM_file("/sys/class/pwm/pwmchip0/export", 0); // Enable PWM channel 0
	write_PWM_file("/sys/class/pwm/pwmchip0/pwm0/period", period);
	write_PWM_file("/sys/class/pwm/pwmchip0/pwm0/duty_cycle", duty);
	write_PWM_file("/sys/class/pwm/pwmchip0/pwm0/enable", 1);
}
