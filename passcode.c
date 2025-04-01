#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 20
#define MIN_LENGTH 8

int main() {
    char password[MAX_LENGTH + 1]; // +1 for null terminator

    // Prompt user for password
    printf("Please enter your password to test!\n");
    printf("Enter a string (max length %d): ", MAX_LENGTH);
    fgets(password, sizeof(password), stdin);

    // Remove newline character
    password[strcspn(password, "\n")] = 0;

    // Check for length
    if (strlen(password) > MAX_LENGTH) {
        printf("Password entered is too long!\n");
        return 1; // Exit on error
    }

    // Validate password criteria
    if (strlen(password) < MIN_LENGTH) {
        printf("Invalid password!\nMust have at least %d characters.\n", MIN_LENGTH);
    } else if (strpbrk(password, " ")) {
        printf("Invalid password!\nNo spaces allowed!\n");
    } else {
        int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;

        for (int i = 0; password[i] != '\0'; i++) {
            if (isupper(password[i])) has_upper = 1;
            else if (islower(password[i])) has_lower = 1;
            else if (isdigit(password[i])) has_digit = 1;
            else if (ispunct(password[i])) has_special = 1;
        }

        if (!has_upper) printf("Invalid password!\nMust have at least 1 uppercase character.\n");
        if (!has_lower) printf("Invalid password!\nMust have at least 1 lowercase character.\n");
        if (!has_digit) printf("Invalid password!\nMust have at least 1 number.\n");
        if (!has_special) printf("Invalid password!\nMust have at least 1 special character.\n");
        
        // Check if all criteria are met
        if (has_upper && has_lower && has_digit && has_special) {
            printf("This is a valid password.\n");
        }
    }

    return 0;
}
