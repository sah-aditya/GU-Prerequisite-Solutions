/*Dot (.) Operator in C
Problem Statement:
Write a C program that manages a list of students using structures and the dot (.) operator. The program should allow the user to input the details of multiple students, display these details, and find the student with the highest GPA.

Description:
Define a structure Student that contains the following fields:

name (a string)
age (an integer)
gpa (a float)
The program should:

Read the number of students from the user.
Read the details of each student (name, age, and GPA).
Display the details of all students.
Find and display the details of the student with the highest GPA.
Input Format:

An integer
𝑛
n representing the number of students.
For each student, a string (name), an integer (age), and a float (GPA).
Output Format:

The details of all students.
The details of the student with the highest GPA.

Private Testcase Input 1:
3
Alice 20 3.5
Bob 22 3.9
Charlie 19 3.7
Private Testcase Output 1:
All Students:
Name: Alice, Age: 20, GPA: 3.5
Name: Bob, Age: 22, GPA: 3.9
Name: Charlie, Age: 19, GPA: 3.7

Student with the highest GPA:
Name: Bob, Age: 22, GPA: 3.9*/


#include <stdio.h>
#include <string.h>

// Define a structure to represent a student
typedef struct {
    char name[100];
    int age;
    float gpa;
} Student;

int main() {
    int numStudents;
    
    scanf("%d", &numStudents);

    Student students[numStudents];

    // Read details of each student
    for (int i = 0; i < numStudents; i++) {
       
        scanf("%s %d %f", students[i].name, &students[i].age, &students[i].gpa);
    }

    // Display details of all students
    printf("All Students:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s, Age: %d, GPA: %.1f\n", students[i].name, students[i].age, students[i].gpa);
    }

    // Find and display student with highest GPA
    Student highestGPA = students[0];
    for (int i = 1; i < numStudents; i++) {
        if (students[i].gpa > highestGPA.gpa) {
            highestGPA = students[i];
        }
    }
    printf("\nStudent with the highest GPA:\n");
    printf("Name: %s, Age: %d, GPA: %.1f\n", highestGPA.name, highestGPA.age, highestGPA.gpa);

    return 0;
}