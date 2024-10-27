#include "inc/common_libs.h"
#include "inc/ssd1306.h"

void display_distance(double distance_cm, double distance_in) {
    char cm_buf[32];
    char in_buf[32];
    snprintf(cm_buf, sizeof(cm_buf), "%.2f cm\n", distance_cm);  // Print out distrance in cm 
    snprintf(in_buf, sizeof(in_buf), "%.2f in", distance_in);   //  Print out disrance in inches

    // Print out to display
    ssd1306_setTextSize(2);
    ssd1306_clearDisplay();
    ssd1306_drawString("Distance\n");
    ssd1306_drawString(cm_buf);
    ssd1306_drawString(in_buf);
    ssd1306_display();
}

void display_statistics(double *distances, int count) {
    double sum = 0, mean, stddev = 0;
    for (int i = 0; i < count; i++) {  // For loop to add all the measured distances in 3 seconds
        sum += distances[i]; // Sum for the mean
    }
    mean = sum / count; // Calcaute the mean

    for (int i = 0; i < count; i++) {
        stddev += pow(distances[i] - mean, 2); // Sum of the squared deviations
    }
    stddev = sqrt(stddev / count);  // Square root of the variance

    char mean_buf[32];
    char stddev_buf[32];
    snprintf(mean_buf, sizeof(mean_buf), "Avg:%.2f cm", mean);
    snprintf(stddev_buf, sizeof(stddev_buf), "StdDev:%.2f cm", stddev);

    // Print out to display
    ssd1306_setTextSize(1);
    ssd1306_clearDisplay();
    ssd1306_drawString(mean_buf);
    ssd1306_drawString("\n");
    ssd1306_drawString(stddev_buf);
    ssd1306_display();
}
