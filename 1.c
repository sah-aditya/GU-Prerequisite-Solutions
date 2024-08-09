/*Data Types and Type Casting
Problem Statement: Write a program that reads two integers and a floating-point number. Perform bitwise operations on the integers and arithmetic operations involving all three numbers. Use type casting where necessary to ensure correct results and avoid overflow/underflow.

Description: Ensure that you correctly cast between data types to avoid any potential overflow or underflow issues during arithmetic operations. Also, explore how different data types interact with each other.

Input Format:

Three lines, each containing one number. The first two lines contain integers, and the third line contains a floating-point number.
Output Format:

Print the result of ((int1 & int2) | (int1 ^ int2)) as an integer.
Print the result of (int1 * float_num + int2 / float_num) as a floating-point number.

Private Testcase Input 1:
8
7
3.3
Private Testcase Output 1:
15
28.5212*/



#include <stdio.h>

int main() {
    int int1, int2;
    float float_num, arithmetic_result;
    int bitwise_result;

    // Reading inputs
    scanf("%d", &int1);
    scanf("%d", &int2);
    scanf("%f", &float_num);

    // Bitwise operation on integers: ((int1 & int2) | (int1 ^ int2))
    bitwise_result = (int1 & int2) | (int1 ^ int2);

    // Arithmetic operation: (int1 * float_num + int2 / float_num)
    // Ensure type casting for correct arithmetic operations
    arithmetic_result = (int1 * float_num) + ((float)int2 / float_num);

    // Printing the results
    printf("%d\n", bitwise_result);
    printf("%.4f\n", arithmetic_result);

    return 0;
}
