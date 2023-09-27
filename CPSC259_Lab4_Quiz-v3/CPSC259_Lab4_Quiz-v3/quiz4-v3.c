/*
 File:           quiz4-v3.c
 Purpose:        Implementation for CPSC259 in-lab quiz 4
                 COMPLETE THE REQUIRED FUNCTION RECURSIVELY
                 SUBMIT THIS FILE TO PRAIRIELEARN
 Author:         John YE
 Student Number: 43883347
 CWL:            johnye
 Date:           11/16/2021
*/

/* Preprocessor directives */
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include "quiz4-v3.h"

/*
 *  Recursively checks whether two lists have the same length
 *
 *  PARAM:  the front of the first list to compare
 *  PARAM:  the front of the second list to compare
 *  RETURN: 1 if list1 and list2 have the same length,
 *          0 otherwise
 */
int equalLengths(Node* list1, Node* list2)
{
    if (list1 != NULL && list2 != NULL) {
        list1 = list1->next;
        list2 = list2->next;
        equalLengths(list1, list2);
    }
    else if (list1 == NULL && list2 == NULL)
        return 1;
    else
        return 0;
}