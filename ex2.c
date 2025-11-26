/******************
Name: Stav Hili Shitrit
ID: 211894092
Assignment: ex2
*******************/

#include <stdio.h>

int main() {
    int selection = 0;
    do {
        printf("Welcome to our games, please choose an option:\n");
        printf("1. Ducky's Unity Game\n");
        printf("2. The Memory Game\n");
        printf("3. Professor Pat's Power Calculation\n");
        printf("4. The Duck Parade\n");
        printf("5. The Mystery of the Repeated Digits\n");
        printf("6. Good Night Ducks\n");
        scanf("%d", &selection);
        switch (selection) {
            case 1: { // TASK 1 - Ducky's Unity Game
                int number = 0;
                printf("please enter a positive number:\n");
                scanf("%d", &number);
                while (number < 0) {
                    printf("Invalid option, please try again\n");
                    scanf("%d", &number);
                }
                int contains = 0;
                int temp = number;
                while (temp > 0) {
                    if (temp % 2 == 1) {
                        contains++;
                    }
                    temp = temp / 2;
                }
                printf("Ducky earns %d corns\n", contains);
                break;
            }
            case 2: { // TASK 2 - The Memory Game
                int numberDucks;
                int answer;
                unsigned long long ducks = 0;  // 64 bits, enough for up to 64 ducks
                printf("please enter the number of ducks:\n");
                scanf("%d", &numberDucks);
                while (numberDucks <= 0 || numberDucks > 64) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &numberDucks);
                }
                printf("you entered %d ducks\n", numberDucks);
                // input for each duck and saving in bits
                for (int i = 1; i <= numberDucks; i++) {
                    printf("duck %d do QUAK? 1 for yes, 0 for no\n", i);
                    scanf("%d", &answer);
                    while (answer != 0 && answer != 1) {
                        printf("Invalid number, please try again\n");
                        scanf("%d", &answer);
                    }
                    // shift all ducks one to the left and add the new answer
                    ducks = (ducks << 1) | answer;
                }
                for (int i = numberDucks - 1; i >= 0; i--) {
                    int bit = (ducks >> i) & 1;
                    if (bit == 1) {
                        printf("duck number %d do Quak\n", numberDucks - i);
                    } else {
                        printf("duck number %d do Sh...\n", numberDucks - i);
                    }
                }
                break;
            }
            case 3: { // TASK 3 - Proffer Pat's Power Calculation
                int base;
                int exponent = 0;
                printf("please enter the number\n");
                scanf("%d", &base);
                while (base < 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &base);
                }
                printf("please enter the exponent\n");
                scanf("%d", &exponent);
                while (exponent < 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &exponent);
                }
                int answer = base;
                if (exponent == 0) {
                    answer = 1;
                } else {
                    for (int i = 1; i < exponent; i++) {
                        answer = answer * base;
                    }
                }
                printf("your power is: %d\n", answer);
                break;
            }
            case 4: { // TASK 4 - The Duck Parade
                int numOfDucks = 0;
                printf("please enter number of ducks:\n");
                scanf("%d", &numOfDucks);
                while (numOfDucks < 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &numOfDucks);
                }
                //10 ducks per row
                for (int start = 0; start < numOfDucks; start += 10) {
                    int ducksInRow = numOfDucks - start;
                    if (ducksInRow > 10) {
                        ducksInRow = 10;
                    }
                    // loop over the 3 lines of the duck drawing
                    for (int line = 1; line <= 3; line++) {
                        // loop over the ducks in the current row
                        for (int i = 0; i < ducksInRow; i++) {
                            if (line == 1) {
                                printf("   _");
                            } else if (line == 2) {
                                printf("__(o)>");
                            } else { // line == 3
                                printf("\\___)");
                            }

                            if (i < ducksInRow - 1) {
                                printf("\t\t");
                            }
                        }
                        printf("\n");
                    }
                }
                break;
            }
            case 5: // TASK 5 - The Mystery of the Repeated Digits
                int numberMystery = 1;
                printf("please enter number\n");
                scanf("%d", &numberMystery);
                while (numberMystery <= 0) {
                    printf("Invalid number, please try again\n");
                    scanf("%d", &numberMystery);
                }
                int outerNumber = numberMystery;  // will scan the number from right to left
                //choose the current digit from right to left
                while (outerNumber > 0) {
                    int currentDigit = outerNumber % 10;
                    int inner = outerNumber / 10;
                    int appearsAgain = 0;

                    // check if currentDigit appears again later in the number
                    while (inner > 0) {
                        int d = inner % 10;
                        if (d == currentDigit) {
                            appearsAgain = 1;
                            break;
                        }
                        inner = inner / 10;
                    }
                    if (appearsAgain) {
                        printf("%d appears more than once!\n", currentDigit);
                    }

                    // move to the next digit (left)
                    outerNumber = outerNumber / 10;
                }
                break;

            case 6: { // Good Night Ducks
                printf("Good night! See you at the pond tomorrow.\n");
                break;
            }

            default: {
                printf("Invalid option, please try again\n");
                break;
            }
        }

    } while (selection != 6);

    return 0;
}

