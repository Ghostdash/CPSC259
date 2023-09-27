/*
 File:           MT1
 Purpose:	     Q
 Author:         John Ye
 Student Number: 43883347
 CS Account:     u0w8u
 Date:		     Oct 07 2021
*/

#define _CRT_SECURE_NO_WARNINGS

/* Preprocessor directives */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAMELENGTH 14;

typedef struct {
	char* firstname;
	char* lastname;
	char lettergrade;
	char trxt_filename[14];
} Student259;

void SetFlatGrades(Student259*, int);
void ReplaceAll(char* text, char* search_for, char* replace_with);


void SetFlatGrades(Student259* classlist, int class_size) {
	/* complete this function according to problem specification */
	for (int i = 1; i < (207 + 1); i++) {
		classlist[i].lettergrade = 'c';
		sprintf(classlist[i].trxt_filename, "%s", "trxt_");
		sprintf(classlist[i].trxt_filename, "%d", i);
		sprintf(classlist[i].trxt_filename, "%s", ".pdf");
	}
}
/*
 * Replaces all occurrences of search_for within a long string with replace_with
 *
 * Assume that a symbolic constant BUFFERLENGTH has already been defined to describe
 * the maximum length of a string
 *
 * PARAM: text - a character array containing the original text
 * PARAM: search_for - a string to be searched for within the text parameter
 * PARAM: replace_with - a string to be substituted in place of each occurrence
 *        of search_for within the text parameter
 * PRE:   the array in which the text parameter is found has enough size to
 *        receive all replacements of search_for (e.g. if replace_with is longer
 *        than search_for)
 *
 * Example 1:
 * text =                  "A goat in a boat swore an oath of vengeance."
 * search_for =            "oat"
 * replace_with =          "orilla"
 * text (post execution) = "A gorilla in a borilla swore an orillah of vengeance."
 *
 * Example 2:
 * text =                  "And we dance in a tempest of feathers for the rest of our lives"
 * search_for =            "tempest of feathers"
 * replace_with =          "garden of stones"
 * text (post execution) = "And we dance in a garden of stones for the rest of our lives"
 */
void ReplaceAll(char* text, char* search_for, char* replace_with) {
	// some useful local variable declarations
	char remainingtext[30]; // temporary local string storage
	int search_length = strlen(search_for);
	int replacement_length = strlen(replace_with);
	int verify = 0;
	char* found; // address within text of a match

	// set an appropriate value for found to prepare for the loop
	int index = 0;
	strncpy(remainingtext, text, 100);
	while (remainingtext[index] != '\0') { // write an appropriate loop condition
	  // complete the loop body
		found = strstr(remainingtext, search_for);
		for (int i = 0; i < replacement_length; i++) {
			*(text + index + i) = *(replace_with + i);
		}
		index += replacement_length;
	}
	// and anything else that needs to happen after your loop
}

int main() {
/*	int i = 100;
	char str [14];
	char* num = (char*)malloc(sizeof(char*));
	sprintf(str, "%s", "trxt_");
	sprintf(num, "%d", i);
	strcat(str, num);
	strcat(str, ".pdf");

	printf("%s\n", str);
*/
	char* text = "A goat in a boat swore an oath of vengeance.";
	char* search_for = "oat";
	char* replace_with = "orilla";

	ReplaceAll(text, search_for, replace_with);

	printf("%s", text);

	system("pause");
	return 0;
}


