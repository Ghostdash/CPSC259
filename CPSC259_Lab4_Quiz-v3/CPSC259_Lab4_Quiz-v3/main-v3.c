/*
 File:           main-v3.c
 Purpose:        Driver for CPSC259 in-lab quiz 4
                 YOU MAY ADD TEST CODE TO THIS FILE
                 BUT DO NOT SUBMIT TO PRAIRIELEARN
 Author:         Your Name
 Student Number: 12345678
 CWL:            yourcwl
 Date:           Add the date here
*/

/* Preprocessor directives */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "quiz4-v3.h"

/* Forward function declarations */
Node* createList(int length);
Node* destroyList(Node* head);
void  printListContents(Node* head);
void  printEqualityMessage(int flag);

/*
 * Main function drives the program.
 * PRE:       NULL (no pre-conditions)
 * POST:      NULL (no side-effects)
 * RETURN:    IF the program exits correctly
 *            THEN 0 ELSE 1
 */
int main(void)
{
  int result;

  printf("Test case 1: two empty lists\n");
  Node* test_list1 = NULL;
  Node* test_list2 = NULL;
  result = equalLengths(test_list1, test_list2);
  printEqualityMessage(result);
  printf("\n");
  // cleanup
  test_list1 = destroyList(test_list1);
  test_list2 = destroyList(test_list2);

  printf("Test case 2: empty list and large non-empty list\n");
  test_list1 = NULL;
  test_list2 = createList(15);
  result = equalLengths(test_list1, test_list2);
  printEqualityMessage(result);
  printf("\n");
  // cleanup
  test_list1 = destroyList(test_list1);
  test_list2 = destroyList(test_list2);

  printf("Test case 3: large non-empty list and empty list\n");
  test_list1 = createList(15);
  test_list2 = NULL;
  result = equalLengths(test_list1, test_list2);
  printEqualityMessage(result);
  printf("\n");
  // cleanup
  test_list1 = destroyList(test_list1);
  test_list2 = destroyList(test_list2);

  printf("Test case 4: two lists of length 1\n");
  test_list1 = createList(1); test_list1->data = 10;
  test_list2 = createList(1);
  result = equalLengths(test_list1, test_list2);
  printEqualityMessage(result);
  printf("\n");
  // cleanup
  test_list1 = destroyList(test_list1);
  test_list2 = destroyList(test_list2);

  printf("Test case 5: non-empty lists with equal lengths\n");
  test_list1 = createList(50);
  test_list2 = createList(50);
  result = equalLengths(test_list1, test_list2);
  printEqualityMessage(result);
  printf("\n");
  // cleanup
  test_list1 = destroyList(test_list1);
  test_list2 = destroyList(test_list2);

  printf("Test case 6: non-empty lists with unequal lengths\n");
  test_list1 = createList(100);
  test_list2 = createList(99);
  result = equalLengths(test_list1, test_list2);
  printEqualityMessage(result);
  printf("\n");
  // cleanup
  test_list1 = destroyList(test_list1);
  test_list2 = destroyList(test_list2);

  system("pause");
  return 0;
}

/*
 * Returns a list with length elements containing data 0 to n-1
 *
 * PARAM:  length, the number of nodes to be added to the list
 * RETURN: the head node of the new list
 */
Node* createList(int length)
{
  int i;
  Node* current;
  Node* newNode;
  Node* head;

  if (length == 0) {
    return NULL;
  }
  else {
    head = (Node*) malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    current = head;
    for (i = 1; i < length; i++) {
      newNode = (Node*) malloc(sizeof(Node));
      newNode->data = i;
      newNode->next = NULL;
      current->next = newNode;
      current = newNode;
    }
    return head;
  }
}

/*
 * Deletes a list
 *
 * PARAM:  head node of list to delete
 * RETURN: NULL, to be assigned to the list which calls the function
 * POST:   list with head node at head has been deallocated
 */
Node* destroyList(Node* head)
{
  Node* temp = head;
  while (head != NULL)
  {
    head = head->next;
    free(temp);
    temp = head;
  }
  return NULL;
}

/*
 * Prints the contents of the list
 *
 * PARAM:  head node of the list to print
 * POST:   contents of the list have been printed to the console
 */
void  printListContents(Node* head)
{
  while (head != NULL)
  {
    printf("%3d ", head->data);
    head = head->next;
  }
  printf("\n");
}

/*
 * Prints information about the equality of the length of two lists
 *
 * PARAM: flag, the output from the equalLengths function
 */
void printEqualityMessage(int flag)
{
  printf("Your function reports the lengths as: ");
  switch (flag)
  {
  case 0:
    printf("not equal");
    break;
  case 1:
    printf("equal");
    break;
  default:
    printf("neither equal nor not equal???");
    break;
  }
  printf("\n");
}