#include <stdio.h>
#include <stdlib.h>

int main() {
    int secretNumber = rand() % 100 + 1; // The function rand() generates random number
    int guess;

    printf("Guess the secret number (between 1 and 100): ");
    scanf("%d", &guess);

    if (guess == secretNumber) {
        printf("Congratulations! You guessed the secret number.\n");
    } else {
        printf("Sorry, the secret number was %d. Better luck next time!\n", secretNumber);
    }

    return 0;
}
