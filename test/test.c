#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Expected Output
    const char *expected = "sum = 30";

    // Run the program using system call and redirect output
    system("./test_prog < test-input.txt > prog-out.txt");

    // Read program output
    FILE *fp = fopen("prog-out.txt", "r");
    if (!fp) {
        printf("Error: Could not read prog-out.txt\n");
        return 1;
    }

    char output[100];
    fgets(output, sizeof(output), fp);
    fclose(fp);

    // Remove trailing newline if exists
    output[strcspn(output, "\n")] = '\0';

    // Compare
    if (strcmp(output, expected) == 0) {
        printf("TEST PASSED!\n");
        return 0;
    } else {
        printf("TEST FAILED!\n");
        printf("Expected: %s\n", expected);
        printf("Got: %s\n", output);
        return 1;
    }
}
