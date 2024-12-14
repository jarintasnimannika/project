#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void toss();
void machineBatting();
void playerBatting();

int target = 0;
int tossWinner;
int isPlayerBatting;

int main() {
    srand(time(0));
    toss();
    if (tossWinner == 0) {
        printf("\nMachine chooses to bat first.\n");
        machineBatting();
        printf("\nNow you need to chase a target of %d runs.\n", target);
        isPlayerBatting = 1;
        playerBatting();
    } else { // Player won the toss
        int choice;
        printf("\nYou won the toss! Choose:\n1. Bat\n2. Bowl\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nYou chose to bat first.\n");
            isPlayerBatting = 1;
            playerBatting();
            printf("\nNow the machine will chase your target of %d runs.\n", target);
            machineBatting();
        } else {
            printf("\nYou chose to bowl first.\n");
            machineBatting();
            printf("\nNow you need to chase a target of %d runs.\n", target);
            isPlayerBatting = 1;
            playerBatting();
        }
    }
    return 0;
}

void toss() {
    printf("Welcome to the Cricket Game!\n");
    printf("Tossing the coin...\n");
    tossWinner = rand() % 2;  // 0 for machine, 1 for player
    if (tossWinner == 0) {
        printf("Machine won the toss!\n");
    } else {
        printf("You won the toss!\n");
    }
}

void machineBatting() {
    int machineRuns, playerGuess, balls = 6, machineScore = 0, wickets = 1;
    printf("\nMachine is batting...\n");
    while (balls > 0 && wickets > 0) {
        printf("\nGuess the machine's run (1-6): ");
        scanf("%d", &playerGuess);
        machineRuns = rand() % 6 + 1;  // Random runs between 1-6
        printf("Machine played: %d\n", machineRuns);

        if (playerGuess == machineRuns) {
            printf("You guessed it right! Machine is OUT!\n");
            wickets--;
        } else {
            machineScore += machineRuns;
        }
        balls--;
    }
    target = machineScore + 1;
    printf("\nMachine's innings ends. Score: %d\n", machineScore);
}

void playerBatting() {
    int playerRuns, machineGuess, balls = 6, playerScore = 0, wickets = 1;
    printf("\nYou are batting...\n");
    while (balls > 0 && wickets > 0) {
        printf("\nEnter your run (1-6): ");
        scanf("%d", &playerRuns);
        if (playerRuns < 1 || playerRuns > 6) {
            printf("Invalid run! Enter a number between 1 and 6.\n");
            continue;
        }
        machineGuess = rand() % 6 + 1;  // Random guess by machine
        printf("Machine guessed: %d\n", machineGuess);

        if (playerRuns == machineGuess) {
            printf("Machine guessed it right! You are OUT!\n");
            wickets--;
        } else {
            playerScore += playerRuns;
        }
        balls--;

        if (isPlayerBatting && playerScore >= target) {
            printf("\nCongratulations! You chased the target. You win!\n");
            return;
        }
    }
    if (isPlayerBatting) {
        if (playerScore < target) {
            printf("\nYou failed to chase the target. Machine wins!\n");
        }
    } else {
        printf("\nYour innings ends. Score: %d\n", playerScore);
    }
}


