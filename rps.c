#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    int playerChoice, computerChoice;
    char choices[3][10] = {"Rock", "Paper", "Scissors"};
    int userScore = 0, computerScore = 0;

    srand(time(NULL));

    while (1) {
        printf("\nWelcome to Rock-Paper-Scissors!\n");
        printf("Enter your choice:\n");
        printf("1: Rock\n2: Paper\n3: Scissors\n4: Exit\n");

        scanf("%d", &playerChoice);

        if (playerChoice == 4) {
            printf("Exiting game...\n");
            break;
        }

        if (playerChoice < 1 || playerChoice > 3) {
            printf("Invalid choice. Please choose between 1 and 3.\n");
            continue;
        }

        computerChoice = rand() % 3;

        printf("You chose: %s\n", choices[playerChoice - 1]);
        printf("Computer chose: %s\n", choices[computerChoice]);

        if (playerChoice == computerChoice + 1) {
            printf("It's a tie!\n");
        } else if ((playerChoice == 1 && computerChoice == 2) ||
                   (playerChoice == 2 && computerChoice == 0) ||
                   (playerChoice == 3 && computerChoice == 1)) {
            printf("You win!\n");
            userScore++;
        } else {
            printf("Computer wins!\n");
            computerScore++;
        }

        printf("Scoreboard\nUser: %d\nComputer: %d\n", userScore, computerScore);
    }
}
