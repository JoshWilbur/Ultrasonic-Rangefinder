#include "inc/common_libs.h"

// Function prototype
void run_OLED(char *const argv[]);
void reset_OLED(void);
void text_OLED(char *line, char *text);
void show_OLED(void);

// Referenced COS331 HW2
// This program forks a new process to run the OLED executable
void run_OLED(char *const argv[]){
	pid_t pid = fork();

	// Move to OLED directory so fonts can be accessed
	if (chdir("/home/jlw/Ultrasonic-Rangefinder/src/ssd1306") != 0) {
		perror("chdir failed");
		exit(-1);
        }

	// Set correct path and error check
	if(pid < 0){
		perror("Fork failed");
		exit(-1);
	}else if(pid == 0){ // Child process path
		execv(argv[0], argv);
		perror("Exec failed");
		exit(-1);
	}else{ // Parent process path
		wait(NULL);
		printf("parent says child done\n");
	}
}

// This function will reset the OLED display
void reset_OLED(void){
        char *args_reset[] = {
	        "./oled",
		"r",
		NULL
        };
	printf("Resetting display...\n");
	run_OLED(args_reset);
}

// This function displays text to the OLED display
void text_OLED(char *line, char *text){
	char *args_text[] = {
		"./oled",
		"+1",
		"test",
		NULL
        };

	args_text[1] = line;
	args_text[2] = text;
	printf("Outputting text to display\n");
	run_OLED(args_text);
}

void show_OLED(void){
        char *args_show[] = {
                "./oled",
                "s",
                NULL
        };

	printf("Showing text on display\n");
	run_OLED(args_show);
}
