/*
 File:          main.c
 Purpose:       Driver for CPSC259 lab 4
 Author:			  Your names
 Student #s:		12345678 and 12345678
 CWLs:		      cwl1 and cwl2
 Date:				  Add the date here
 */

 /******************************************************************

  YOU MAY EDIT THIS FILE IF YOU WISH TO ADD ADDITIONAL TEST CODE
  BUT THIS WILL NOT BE SUBMITTED TO GRADESCOPE

  ******************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <stdlib.h>
#include "recursion.h"

#define BUFFERLENGTH 1024

/*
 Main function drives the program.
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    IF the program exits correctly
            THEN 0 ELSE 1
 */
int main(void)
{
  char outputbuffer[BUFFERLENGTH];
  int index;
  int count;

 for (index = 0; index < BUFFERLENGTH; index++)
      outputbuffer[index] = '\0';


  // initialize outputbuffer
  for (index = 0; index < BUFFERLENGTH; index++)
    outputbuffer[index] = '\0';
  printf("Testing output from draw_ramp() function:\n");
  printf("draw_ramp(1):\n");
  count = draw_ramp(1, outputbuffer);
  printf("length of string is %d\n", count);
  printf("%s", outputbuffer);

  // clear / re-initialize outputbuffer
  for (index = 0; index < BUFFERLENGTH; index++)
    outputbuffer[index] = '\0';

  printf("\ndraw_ramp(2):\n");
  count = draw_ramp(2, outputbuffer);
  printf("length of string is %d\n", count);
  printf("%s", outputbuffer);

  // clear / re-initialize outputbuffer
  for (index = 0; index < BUFFERLENGTH; index++)
    outputbuffer[index] = '\0';

  printf("\ndraw_ramp(3):\n");
  count = draw_ramp(3, outputbuffer);
  printf("length of string is %d\n", count);
  printf("%s", outputbuffer);

  // clear / re-initialize outputbuffer
  for (index = 0; index < BUFFERLENGTH; index++)
    outputbuffer[index] = '\0';

  printf("\ndraw_ramp(4):\n");
  count = draw_ramp(4, outputbuffer);
  printf("length of string is %d\n", count);
  printf("%s", outputbuffer);

  // clear / re-initialize outputbuffer
  for (index = 0; index < BUFFERLENGTH; index++)
    outputbuffer[index] = '\0';

  printf("\ndraw_ramp(5):\n");
  count = draw_ramp(5, outputbuffer);
  printf("length of string is %d\n", count);
  printf("%s", outputbuffer);

  system("pause");
  return 0;
}