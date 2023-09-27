/*
File:         lab1_inlab_exercises.c
Purpose:      Exercises for lab 1
Author:       John Ye, John Li
Student #s:   12345678 and 12345678
CS Accounts:  a1a1 and b2b2
Date:         Add the date here
*/

/* Preprocessor directives */
#include "lab1_inlab_exercises.h"
#include "stdlib.h"                     // For system command
#include "stdio.h"

/* See main.c for additional practices for C programming */

/*
Reverses the order of an array of integers
For example,
{ 1, 2, 3, 4 } -> {4, 3, 2, 1 }
{ 1, 2, 3 } -> { 3, 2, 1 }
{1} -> {1}
{} -> {}
PARAM:  array, an array of integers
PARAM:  length, the number of elements in array
PRE:    array is an array of integers
PRE:    length is the correct length of the array
POST:   the elements in array have been reversed in order
RETURN: N/A
*/
void reverse_array(int array[], int length) {           // Implement this function here
    int temp;
    for (int i = 0; i < length / 2; i++) {
        temp = array[i];
        array[i] = array[length - 1 - i];
        array[length - 1 - i] = temp;
    }
}

/*
Returns the length of the specified C string (an array of
characters that ends with the null character '\0')
PARAM:  string is a standard C array of characters that terminates
with the null character '\0'
PRE:    string is a null-terminated array of characters
POST:   NULL (no side-effects)
RETURN: number of char (excluding the terminating null) in string
*/
int length(const char string[])
{
    int len = strlen(string);
    return len;
}

/*
Returns the number of occurrences of the specified char in the specified
char array (string)
PARAM:  string is a standard C array of characters that terminates
with the null character '\0'
PARAM:  letter_sought, a char
PRE:    string is a null-terminated array of characters
POST:   NULL (no side-effects)
RETURN: number of occurences of letter_sought in string
*/
int count_letters(const char string[], char letter)
{
    int count = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (letter == string[i])
            count++;
    }
    return count;
}

/*
Determines if a string is a palindrome.  Skips spaces.
For example,
""     -> returns 1 (an empty string is a palindrome)
"the"  -> returns 0
"abba" -> returns 1
"Abba" -> returns 0
"never odd or even"
-> returns 1 ("neveroddoreven" reversed is the same!)
PARAM:  string is a standard C array of characters that terminates
with the null character '\0'
PRE:    string is a null-terminated array of characters
POST:   no side-effects, e.g., nothing is printed or changed
RETURN: IF string is a palindrome THEN 1
ELSE IF string is not a palindrome THEN 0
*/
int is_palindrome(const char string[]) {


  // This implementation is only partly correct
    const int string_length = length(string);
    char revised[100] = " ";
    int index = 0;;
    for (int k = 0; k < string_length; k++) {
        if (string[k] != ' ') {
            revised[index] = string[k];
            index++;
        }
    }
    index++;
    revised[index] = '\0';
    int nlength = length(revised)-1;

    for (int i = 0; i < nlength / 2;i++) {
        if (revised[i] != revised[nlength - i]) {
            return 0;
        }

    }
    return 1;
}