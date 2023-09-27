#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFERLENGTH 256
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
void ReplaceAll(char*, char*, char*);

int main(void) {
	char* text = "And we dance in a tempest of feathers for the rest of our lives";
	char* search = "tempest of feathers";
	char* replace = "garden of stones";

	ReplaceAll(text, search, replace);
	printf("%s\n", text);
	system("pause");
	return 0;

}


void ReplaceAll(char* text, char* search_for, char* replace_with) {
	// some useful local variable declarations
	char remainingtext[BUFFERLENGTH]; // temporary local string storage
	int search_length = strlen(search_for);
//	int replacement_length = strlen(replace_with);
	char* found; 
	char* temp1 = NULL; // address within text of a match

	// set an appropriate value for found to prepare for the loop
	while (strstr(text, search_for) != NULL) { // write an appropriate loop condition
	  // complete the loop body
		temp1 = text;
		found = strstr(text, search_for);
		for (int i = 0; i < BUFFERLENGTH; i++)
			remainingtext[i] = '\0';
		for (int i = 0; temp1 < found; i++) {
			remainingtext[i] = *temp1;
			temp1++;
		}
		strcat(remainingtext, replace_with);
		found += search_length;
		strcat(remainingtext, found);
		text = remainingtext;
	}
	text = remainingtext;
}
// and anything else that needs to happen after your loop
