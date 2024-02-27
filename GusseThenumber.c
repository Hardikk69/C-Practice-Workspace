#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    int guess, number, attempts = 0;
    srand(time(NULL));
    number = rand() % 100 + 1;

    printf("Welcome to the Guessing Game!\n");
    printf("THe number is between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < number) {
            printf("The number is Bigger!Try again.\n");
        } else if (guess > number) {
            printf("The number is Smaller!Try again.\n");
        }
    } while (guess != number);

    printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
}
