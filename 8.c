/*Enumeration (enum) in C
Problem Statement:
Create a C program that uses an enumeration to represent the days of the week. The program should take a list of integers from the user, convert them to the corresponding days of the week using the enum, and then print the days in reverse order.

Description:
You will define an enumeration for the days of the week starting with Sunday as 0 and ending with Saturday as 6. The program should read a list of integers from the user, map them to the corresponding days, and print the days in reverse order.

Input Format:

An integer
𝑛
n representing the number of days.
A list of
𝑛
n integers representing the days of the week.
Output Format:

The days of the week in reverse order.

Private Testcase Input 1:
5
0 1 2 3 4
Private Testcase Output 1:
Days in reverse order:
Thursday Wednesday Tuesday Monday Sunday*/


#include <stdio.h>

// Define an enumeration for the days of the week
typedef enum {
    Sunday = 0,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
} Day;

int main() {
    int n;
    
    scanf("%d", &n);

    // Create an array to store the days
    Day days[n];

    // Read the list of integers from the user

    for (int i = 0; i < n; i++) {
        int day;
        scanf("%d", &day);
        days[i] = (Day)day;
    }

    // Print the label
    printf("Days in reverse order:\n");

    // Print the days in reverse order without a trailing space
    for (int i = n - 1; i >= 0; i--) {
        switch (days[i]) {
            case Sunday:    printf("Sunday"); break;
            case Monday:    printf("Monday"); break;
            case Tuesday:   printf("Tuesday"); break;
            case Wednesday: printf("Wednesday"); break;
            case Thursday:  printf("Thursday"); break;
            case Friday:    printf("Friday"); break;
            case Saturday:  printf("Saturday"); break;
        }
        if (i > 0) { // Print a space only if it's not the last element
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
