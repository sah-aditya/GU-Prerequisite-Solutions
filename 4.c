/*Complex Menu Navigation using Switch Statement
Problem Statement:
Write a C program that simulates a menu-driven application for a library management system using the switch statement. The menu should offer the following options:

Add a book
Display books
Search for a book by title
Exit
The twist is that each option should lead to a submenu with additional choices. For example, the "Add a book" option should allow the user to enter the title, author, and year of publication. The "Display books" option should display all books in a specific format. The "Search for a book by title" option should allow for a partial title search.

Description:

The program should use the switch statement to handle the main menu and each submenu.
Implement functions for each submenu operation.
Use dynamic memory allocation to store book details.
Use a struct to represent each book.

Input Format:

The user inputs the menu choice followed by submenu choices as required.
The input ends when the user selects the "Exit" option.

Output Format:

The output varies based on the selected menu and submenu options, including confirmation messages and book details.

The below are the output for corresponding operation:

Add a book:

Book added successfully.

Display books:

Case1:

No books in the library.

Case2:

Books in library:
Title: < Title >, Author: < Author >, Year: < Year >

Seach for a book by title:

Case1:

No book found with the given title.

Case2:

Books found:
Title: < Title >, Author: < Author >, Year: < Year >

Exit

Exiting...

Private Testcase Input 1:
1
C Programming
Dennis Ritchie
1978
4

Private Testcase Output 1:
Book added successfully.
Exiting...*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent each book
struct Book {
    char title[100];
    char author[100];
    int year;
    struct Book* next; // Pointer to the next book in the list
};

// Function prototypes
void addBook(struct Book** head);
void displayBooks(struct Book* head);
void searchBook(struct Book* head);
void exitProgram(struct Book** head);

// Helper function prototypes
struct Book* createBook(char* title, char* author, int year);
void freeBooks(struct Book* head);

int main() {
    int choice;
    struct Book* library = NULL;

    do {
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(&library);
                break;
            case 2:
                displayBooks(library);
                break;
            case 3:
                searchBook(library);
                break;
            case 4:
                exitProgram(&library);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addBook(struct Book** head) {
    char title[100], author[100];
    int year;

    scanf(" %[^\n]", title);
    scanf(" %[^\n]", author);
    scanf("%d", &year);

    struct Book* newBook = createBook(title, author, year);
    newBook->next = *head;
    *head = newBook;

    printf("Book added successfully.\n");
}

void displayBooks(struct Book* head) {
    if (head == NULL) {
        printf("No books in the library.\n");
        return;
    }

    struct Book* temp = head;
    printf("Books in library:\n");
    while (temp != NULL) {
        printf("Title: %s, Author: %s, Year: %d\n", temp->title, temp->author, temp->year);
        temp = temp->next;
    }
}

void searchBook(struct Book* head) {
    char searchTitle[100];
    int found = 0;

    scanf(" %[^\n]", searchTitle);

    struct Book* temp = head;
    while (temp != NULL) {
        if (strstr(temp->title, searchTitle) != NULL) {
            if (!found) {
                printf("Books found:\n");
                found = 1;
            }
            printf("Title: %s, Author: %s, Year: %d\n", temp->title, temp->author, temp->year);
        }
        temp = temp->next;
    }

    if (!found) {
        printf("No book found with the given title.\n");
    }
}

void exitProgram(struct Book** head) {
    freeBooks(*head);
    *head = NULL;
    printf("Exiting...\n");
}

struct Book* createBook(char* title, char* author, int year) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->year = year;
    newBook->next = NULL;
    return newBook;
}

void freeBooks(struct Book* head) {
    struct Book* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}