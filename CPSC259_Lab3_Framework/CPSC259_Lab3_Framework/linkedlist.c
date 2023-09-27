/*
 File:         linkedlist.c
 Purpose:      Implements the linked list functions whose prototypes
               are declared in the linked_list.h header file
 Author:       John Ye
 Student #s:   43883347
 CWLs:         johnye
 Date:         11/05/2021
 */
 
/* Preprocessor directives */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

/******************************************************************
 PLEASE EDIT THIS FILE

 Comments that start with // should be replaced with code
 Comments that are surrounded by * are hints
 ******************************************************************/

/*
 Returns a pointer to a new, empty linked list of struct node.
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    A pointer to a new, empty linked list of struct node (NULL)
 */
node* create_linked_list()
{
	// Insert your code here
    node* head = NULL;
    return head;
}

/*
 Returns a dynamically allocated struct node that contains the specified
 struct airplane.  The node's next pointer doesn't point to anything
 e.g., it is equal to NULL.
 PARAM:     plane, a struct airplane
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    A pointer to a dynamically allocated struct node a) that contains
            the specified struct airplane, and b) whose next pointer points to NULL
 */
node* create_node(airplane plane)
{
    node* newNode = malloc(sizeof(node));
    newNode->next = NULL;
    newNode->plane = plane;
    return newNode;
}

/*
 Prepends a struct node passed as a parameter to the list passed as a
 parameter, and returns a pointer to the result.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     new_node is a pointer to a struct node
 PRE:       new_mode is not null
 POST:      The specified struct node is added to the beginning of the list
            and its next pointer points to the node that used to be first
 RETURN:    A pointer to a linked list which contains all of the nodes
            of the list passed as a parameter, plus a prepended node
 */
node* prepend_node(node* list, node* new_node)
{
    new_node->next = list;
    return new_node;
}

/*
 Deletes the first struct node in the specified list, and returns a pointer to
 the shortened list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL
 POST:      The list passed as a parameter has one fewer node, and the dynamically
            allocated memory which contained that removed node has been freed
 RETURN:    IF the list is empty
            THEN NULL
            ELSE a pointer to the shortened list
 */
node* delete_node(node* list)
{
    node* temp = NULL;
    if (list == NULL)
        return NULL;
    else {
        temp = list;
        list = list->next;
        free(temp);
        return list;
    }
}

/*
 Returns the number of nodes in the specified linked list of struct node.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    The length of the specified list, an int
 */
int get_length(node* list)
{
    node* temp = list;
    int count = 0;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

/*
 Deletes an entire list.  This function iterates along a list and deallocates the
 memory containing each struct node.  
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      The memory containing all of the nodes in the list has been freed
 RETURN:    an empty list (NULL)
 */
node* delete_list(node* list)
{
    node* temp = list;
    while (temp != NULL) {
        temp = list->next;
        free(list);
        list = temp;
    }
    return list;
}

/*
 Prints the data stored in a node.  For the struct airplane in the node,
 prints the fields on separate lines.  For each field, prints the field name
 and the field value.  For the pointer, prints "Link = NULL\n" if the pointer points
 to null, else prints "Link points to address xxx\n", where xxx is the pointer address
 in hexademical.
 If node_to_print is NULL, prints "The node is empty\n".
 PARAM:     node_to_print is a pointer to a (possibly null) struct node
 PRE:       NULL (no pre-conditions)
 POST:      Information about node_to_print has been printed to standard output
 RETURN:    NULL
 */
void print_node(node* node_to_print)
{
    if (node_to_print == NULL) {
        printf("Link = NULL\n");
    }
    else {
        printf("Link points to address %p\n", &node_to_print);
        printf("flight_number, %d\n", node_to_print->plane.flight_number);
        printf("city_origin, %s\n", node_to_print->plane.city_origin);
        printf("city_destination, %s\n", node_to_print->plane.city_destination);
        printf("priority, %d\n", node_to_print->plane.priority);
        printf("maximum_speed_kph, %d\n", node_to_print->plane.maximum_speed_kph);
        printf("capacity, %d\n", node_to_print->plane.capacity);
    }
    return;
}

/*
 Prints the data stored in all nodes in the specified list to print.
 For each node, prints the data inside the node the same way that it
 is printed by print_node.  If the list is empty, a suitable message
 is printed to standard output.
 PARAM:     node_to_print is a pointer to a (possibly empty) linked list of
            struct node
 PRE:       NULL (no pre-conditions)
 POST:      Information about list_to_print has been printed to standard output
 RETURN:    NULL
 */
void print_list(node* list_to_print)
{
    node* temp = list_to_print;
    while (temp != NULL) {
        print_node(temp);
        temp = temp->next;
    }
    return;
}

/*
 Reverses a list. 
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PRE:       NULL (no pre-conditions)
 POST:      The order of the nodes in the list passed as a parameter has been
            reversed
 RETURN:    a list of struct node that is the reverse of the list passed as a
            parameter
 */
node* reverse(node* list)
{
    node* before = NULL;
    node* after = NULL;
    node* current_node = list;

    while (current_node != NULL) {
        after = current_node->next;
        current_node->next = before;
        before = current_node;
        current_node = after;
    }
    list = before;                                    //make the head point to the original end of the list
    return list;
}

/*
 Removes every node from the list which contains an airplane destined for
 the city name passed in the second parameter.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     destination_city is a pointer to a null-terminated array of char
 PRE:       NULL (no pre-conditions)
 POST:      Any struct node in the list which contains an airplane struct
            destined for the destination_city is removed from the list, and
            the memory deallocated
 RETURN:    a list of struct node that does not contain any struct node that
            has an airplane destined for the destination_city
 */
node* remove_from_list(node* list, char* destination_city)
{

    if (list == NULL) {                                                                        //if list is empty
        return NULL; 
    }
    if (list->next == NULL && strcmp(list->plane.city_destination, destination_city) == 0){    //if head is the only item and is removed
        return NULL;
    }
    else {
        while (strcmp(list->plane.city_destination, destination_city) == 0) {                   //if head is removed and there is more items behind
            node* remove = list;
            list = list->next;
            free(remove);
        }
    }

    node* temp = list;

    while (temp ->next != NULL) {
        if (strcmp(temp->next->plane.city_destination, destination_city) == 0) {                    
            node* remove = temp->next;
            temp->next = temp->next->next;
            free(remove);                                                                    //deallocate memory 
        }
        else
            temp = temp->next;
    }
    return list;
}

/*
 Returns a reference to the nth node (but does not remove it ) in the
 specified list.  If the list is too short, returns NULL.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     ordinality is an integer
 PRE:       ordinality > 0
 POST:      NULL (no side-effects)
 RETURN:    IF ordinality <= length of list
            THEN a pointer to the nth node
            ELSE NULL
 */
node* retrieve_nth(node* list, int ordinality)
{
    node* temp = list;
    int count = 1;
    int length = get_length(list);
    if (ordinality > length)
        return NULL;
    else {
        while (count < ordinality) {                    //go to the correct position
            temp = temp->next;
            count++;
        }
        return temp;
    }
}

/*
 Inserts the specified node into the specified list of nodes at the specified
 ordinality.  For example, if ordinality = 1, this is a simple prepend_node
 operation.  If ordinality = 3, then when this function is finished, the third
 node in the list will be the node_to_insert.  If the ordinality = the length
 of the list + 1, then the node_to_insert is appended to the end of the list.
 If the ordinality > 1 + length of the list, the function returns a pointer
 to the unchanged list.
 PARAM:     list is a pointer to a (possibly empty) linked list of struct node
 PARAM:     ordinality is an integer
 PRE:       ordinality > 0
 PRE:       node_to_insert is NEVER a null (it is always a correct node pointer)
 POST:      NULL (no side-effects)
 RETURN:    IF ordinality <= length of list + 1
            THEN a pointer to the list which contains the node_to_insert in the
			correct location
            ELSE a pointer to the unchanged list
 */
node* insert_nth(node* list, node* node_to_insert, int ordinality)
{
    int length = get_length(list);
    int count = 0;
    node* temp = list;
    node* previous = NULL;
    if (ordinality > length+1)              
        return list;
    else {
        while (count < ordinality-1){               //go to the correct position
            previous = temp;
            temp = temp->next;
            count++;
        }
        if (previous != NULL) {                     
            node_to_insert->next = temp;
            previous->next = node_to_insert;
        }
        else {                                      //if the inserted node is the first item
            node_to_insert->next = list;
            list = node_to_insert;
        }
        return list;
    }
}
