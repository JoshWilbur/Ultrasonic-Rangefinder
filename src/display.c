#include "common_libs.h"

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

int main(int argc, char *argv[]) {
	// Arrays to hold arguments to run display
	char *args1[] = {
	        "./oled",
	        "r",
		NULL
	};

	char *args2[] = {
		"./oled",
		"+1",
		"test",
		NULL
	};

	char *args3[] = {
	        "./oled",
		"s",
		NULL
	};

	// Run arguments in order to get desired output
	run_OLED(args1);
	sleep(1);
	run_OLED(args2);
	sleep(1);
	run_OLED(args3);

	return 0;
}
