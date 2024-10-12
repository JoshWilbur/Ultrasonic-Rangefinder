// Header file for display.c
#ifndef DISPLAY_H
#define DISPLAY_H

void run_OLED(char *const argv[]);
void reset_OLED(void);
void text_OLED(char *line, char *text);
void show_OLED(void);

#endif
