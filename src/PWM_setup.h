// Header file for PWM_setup.c
// Guards used to prevent multiple imports of the same file
#ifndef PWM_SET_H
#define PWM_SET_H

void write_PWM_file(const char *path, int value);
void setup_PWM(void);

#endif
