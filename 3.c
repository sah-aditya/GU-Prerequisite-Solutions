/*Character Frequency Swap
Question: Write a C program that reads a string from the user and swaps the most frequent character with the least frequent character in the string.

Description: The program should take a string input from the user, determine the most and least frequent characters (case insensitive), and swap their occurrences in the string.
Private Testcase Input 1:
abracadabra
Private Testcase Output 1:
cbrcacdcbrc*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 256

// Function to find the most and least frequent characters
void findMostAndLeastFrequent(char *str, char *mostFreq, char *leastFreq) {
    int freq[MAX] = {0};
    int i, max = -1, min = MAX;

    // Count the frequency of each character (case insensitive)
    for (i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        freq[ch]++;
    }

    // Find the most frequent character
    for (i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (freq[ch] > max) {
            max = freq[ch];
            *mostFreq = ch;
        }
    }

    // Find the least frequent character (ignore characters with zero frequency)
    for (i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (freq[ch] < min && freq[ch] > 0) {
            min = freq[ch];
            *leastFreq = ch;
        }
    }
}

// Function to swap the most frequent and least frequent characters
void swapCharacters(char *str, char mostFreq, char leastFreq) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (tolower(str[i]) == mostFreq) {
            str[i] = isupper(str[i]) ? toupper(leastFreq) : leastFreq;
        } else if (tolower(str[i]) == leastFreq) {
            str[i] = isupper(str[i]) ? toupper(mostFreq) : mostFreq;
        }
    }
}

int main() {
    char str[100];
    char mostFreq, leastFreq;

    // Reading the string from the user
    scanf("%s", str);

    // Find the most and least frequent characters
    findMostAndLeastFrequent(str, &mostFreq, &leastFreq);

    // Swap the most frequent and least frequent characters
    swapCharacters(str, mostFreq, leastFreq);

    // Print the resulting string
    printf("%s\n", str);

    return 0;
}
