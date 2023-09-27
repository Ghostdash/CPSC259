/*
 File:          main.c
 Purpose:       Driver for Lab4 Takehome
 Author:			  Your names
 Student #s:		12345678 and 12345678
 CWLs:      		cwl1 and cwl2
 Date:				  Add the date here
 */

/******************************************************************
YOU MAY EDIT THIS FILE WITH YOUR OWN TEST CODE,
BUT THIS FILE WILL NOT BE SUBMITTED FOR CREDIT

Comments that start with // should be replaced with code
Comments that are surrounded by * are hints
******************************************************************/

/* Preprocessor directives to include libraries */
#define _CRT_SECURE_NO_WARNINGS
#include "mazesolver.h"

/*
Main function drives the program.
PRE:       None
POST:      None
RETURN:    IF the program exits correctly
            THEN 0 ELSE 1
*/
int main(void)
{
  /* Hand off work to process function */
   process();

 /*   FILE* maze_file = NULL;
    maze_file = fopen(MAZE2, "r");

    maze_cell** maze = NULL;
    char* output [BUFFER];

    int length = get_maze_dimension(maze_file);
    maze = parse_maze(maze_file, length);

    char** paths = NULL;
    paths = (char**)calloc(5, sizeof(char*));
    paths[0] = "54321";
    paths[1] = "1211";
    paths[2] = "123456";
    paths[3] = "432";
    paths[4] = "1121";

    char* current_path = "";

    char** pathsref = NULL;
    pathsref = (char**)calloc(length, sizeof(char*));
    char*** pathsref_pointer = (char***)calloc(1, sizeof(char**));
    pathsref_pointer = &pathsref;

    int num_path = 0;
    int* pointer_to_num_path = NULL;
    pointer_to_num_path = (int*)calloc(1, sizeof(int));
    pointer_to_num_path = &num_path;

 //   int temp = *pointer_to_num_path;

 //   printf("%d", strlen(current_path));

    generate_all_paths(pathsref_pointer, pointer_to_num_path, maze, length, 0, 0, current_path);

    printf("Total number of solutions: %d\n", *pointer_to_num_path);

    construct_shortest_path_info(pathsref,*pointer_to_num_path, output);
    printf("%s\n", output);


    construct_cheapest_path_info(pathsref, *pointer_to_num_path, output);
    printf("%s\n", output);

  /*  for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++)
            printf("%c", maze[i][j].visited);
        printf("\n");
    }

    /* Ends main function */
    system("pause");
    return 0;
}