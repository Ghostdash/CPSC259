/*
 File:           quiz4-v3.h
 Purpose:        Definitions for CPSC259 in-lab quiz 4
                 DO NOT MODIFY THIS FILE
                 THIS FILE WILL NOT BE SUBMITTED
 Author:         Your Name
 Student Number: 12345678
 CWL:            yourcwl
 Date:           Add the date here
 */

#pragma once

// Structure definition for a singly-linked list node
typedef struct Node {
  int data;
  struct Node* next;
} Node;

// Function to implement in quiz4-v3.c
int equalLengths(Node* list1, Node* list2);