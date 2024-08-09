/*C Structures
Problem Statement:
Write a C program that reads student records from the user and stores them in a structure. The program should also calculate and print the average marks of the students using a pointer to the structure.

Description:
This question tests the ability to use structures to store data and manipulate it using pointers. It requires reading multiple student records, storing them in an array of structures, and using a pointer to calculate the average marks.

Input Format:
First line: an integer n (number of students)
Next n lines: each containing a student's name and marks (space-separated)
Output Format:
First line: average marks of the students

Private Testcase Input 1:
2
David 60
Eva 75
Private Testcase Output 1:
Average Marks: 67.50*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 100

// Define the structure to store student data
typedef struct {
    char name[MAX_NAME_LENGTH];
    int marks;
} Student;

// Function to calculate the average marks
float calculateAverageMarks(Student *students, int numStudents) {
    int totalMarks = 0;
    for (int i = 0; i < numStudents; i++) {
        totalMarks += students[i].marks;
    }
    return (float)totalMarks / numStudents;
}

int main() {
    int n;
    
    // Read the number of students
    
    scanf("%d", &n);
    
    // Allocate memory for student records
    Student *students = (Student *)malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Read student records
    
    for (int i = 0; i < n; i++) {
        scanf("%s %d", students[i].name, &students[i].marks);
    }
    
    // Calculate average marks
    float averageMarks = calculateAverageMarks(students, n);
    
    // Print the average marks
    printf("Average Marks: %.2f\n", averageMarks);
    
    // Free allocated memory
    free(students);
    
    return 0;
}
