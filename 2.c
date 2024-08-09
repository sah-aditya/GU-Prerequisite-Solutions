/* Operators and Associativity
Problem Statement: Write a program that reads an integer n, followed by n integers, and then applies a complex expression involving multiple operators and parentheses. The expression should be evaluated in a specific order demonstrating operator precedence and associativity.

Description: Define an expression like (((x1 + x2) - x3) * x4 / x5) % x6 and ensure the operators are applied correctly according to their precedence and associativity rules. The program should read the values and compute the result.

Input Format:

The first line contains an integer n, the number of elements.
The next n lines contain one integer each.

Output Format:
Print the result of the complex expression.

Private Testcase Input 1:
6
5
10
3
8
2
7
Private Testcase Output 2:
6 */

#include <stdio.h>

int main() {
    int n;
    
    // Reading the number of elements
    scanf("%d", &n);
    
    // Ensure n is at least 6, as we need 6 integers for the expression
    if (n < 6) {
        printf("Error: The number of elements must be at least 6.\n");
        return 1;
    }
    
    // Declare an array to hold the integers
    int nums[n];
    
    // Reading the n integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    // Define the complex expression using the first 6 integers
    // Expression: (((x1 + x2) - x3) * x4 / x5) % x6
    int result = (((nums[0] + nums[1]) - nums[2]) * nums[3] / nums[4]) % nums[5];
    
    // Printing the result
    printf("%d\n", result);
    
    return 0;
}
