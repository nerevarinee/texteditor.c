#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000

void displayMenu() {
    printf("\nSimple Text Editor Menu:\n");
    printf("1. Read from file\n");
    printf("2. Write to file\n");
    printf("3. Exit\n");
}

int main() {
    char buffer[MAX_LINE_LENGTH];

    while (1) {
        displayMenu();

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char fileName[50];
                printf("Enter the file name to read: ");
                scanf("%s", fileName);

                FILE *file = fopen(fileName, "r");
                if (file == NULL) {
                    perror("Error opening file");
                    break;
                }

                printf("\nFile content:\n");
                while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
                    printf("%s", buffer);
                }

                fclose(file);
                break;
            }

            case 2: {
                char fileName[50];
                printf("Enter the file name to write: ");
                scanf("%s", fileName);

                FILE *file = fopen(fileName, "w");
                if (file == NULL) {
                    perror("Error opening file");
                    break;
                }

                printf("Enter text (Ctrl+D to end):\n");
                while (fgets(buffer, MAX_LINE_LENGTH, stdin) != NULL) {
                    fputs(buffer, file);
                }

                fclose(file);
                printf("\nText written to %s successfully.\n", fileName);
                break;
            }

            case 3:
                printf("Exiting the text editor. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
