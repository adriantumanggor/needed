#include <stdio.h>
#include <time.h>

int main() {
    // Step 2: Get the current time
    time_t now;
    time(&now);

    // Step 3: Convert it to local time
    struct tm *local = localtime(&now);

    // Step 4: Access and print the date and time components
    printf("Current Date and Time:\n");
    printf("Date: %02d-%02d-%d\n", local->tm_mday, local->tm_mon + 1, local->tm_year + 1900); // tm_mon is 0-based; tm_year is years since 1900
    printf("Time: %02d:%02d:%02d\n", local->tm_hour, local->tm_min, local->tm_sec);

    return 0;
}