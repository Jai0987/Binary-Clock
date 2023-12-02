#include <stdio.h>
#include <time.h>
#include <unistd.h>

void decToBinary(int n, int binaryArray[]) {
    for (int i = 3; i >= 0; i--) {
        binaryArray[i] = n % 2;
        n = n / 2;
    }
}

int main() {
    int binaryRepresentation[4]; // Array to store binary representation of each digit

    while (1) { // Infinite loop to keep the clock ticking
        // Clear screen (platform dependent, works on Unix/Linux)
        printf("\033[H\033[J"); 

        // Get current time
        time_t currentTime = time(NULL);
        struct tm *timeInfo = localtime(&currentTime);

        int hours = timeInfo->tm_hour;
        int minutes = timeInfo->tm_min;
        int seconds = timeInfo->tm_sec;

        int timeArray[6] = {hours / 10, hours % 10, minutes / 10, minutes % 10, seconds / 10, seconds % 10};

        // Print table header
        printf("  Hours   Minutes  Seconds\n");
        printf("  --------------------------\n");

        // Print binary clock
        for (int row = 0; row < 4; row++) {
            printf(" |");
            for (int i = 0; i < 6; i++) {
                decToBinary(timeArray[i], binaryRepresentation);
                printf("%s", binaryRepresentation[row] ? " * " : " . ");
                if (i == 1 || i == 3) printf("|"); // Separators between hours, minutes, and seconds
            }
            printf("|\n");
        }
        printf("  --------------------------\n");

        // Print regular time format
        printf("  Current Time: %02d:%02d:%02d\n", hours, minutes, seconds);

        // Wait for one second
        sleep(1);
    }

    return 0;
}
