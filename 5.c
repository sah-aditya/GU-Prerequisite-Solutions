/*Unconventional Use of Goto Statement
Problem Statement:
Create a C program that calculates the factorial of a number using the goto statement. The twist is to implement error handling for negative inputs using the goto statement to jump to an error handling section.

Description:

The program should prompt the user to enter a number.
If the number is negative, use goto to jump to an error message.
If the number is positive, calculate the factorial using a loop and goto.
Input Format:

The user inputs a single integer.
Output Format:

The output is either the factorial of the number or an error message for negative inputs.

Private Testcase Input 1:
5
Private Testcase Output 1:
Factorial of 5 is 120*/

#include <stdio.h>

int main() {
    int number, factorial = 1;

    // Prompt user to enter a number

    scanf("%d", &number);

    // Check for negative input and jump to error handling if needed
    if (number < 0) {
        goto error;
    }

    // Calculate the factorial using a loop and goto
    int i = 1;
    factorial_loop:
    if (i <= number) {
        factorial *= i;
        i++;
        goto factorial_loop;
    }

    // Print the factorial result
    printf("Factorial of %d is %d\n", number, factorial);
    return 0;

    // Error handling section
    error:
    printf("Error: Negative number entered. Factorial is not defined for negative numbers.\n");
    return 1;
}
