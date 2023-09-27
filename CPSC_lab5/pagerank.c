//name: John Ye
//cwl: johnye
//studentnumber: 43883347


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"

#define  BUFSIZE 256

int main(void) {
    /* Variables */
    Engine* ep = NULL; // A pointer to a MATLAB engine object
    mxArray* testArray1 = NULL, * result = NULL; // mxArray is the fundamental type underlying MATLAB data
    mxArray* testArray2 = NULL; // mxArray is the fundamental type underlying MATLAB data
    double time1[3][3] = { { 1.0, 2.0, 3.0 }, {4.0, 5.0, 6.0 }, {7.0, 8.0, 9.0 } }; // Our test 'matrix', a 2-D array
    double time2[3][3] = { { 1.0, 1.0, 1.0 }, {2.0, 2.0, 2.0 }, {3.0, 3.0, 3.0 } };
    char buffer[BUFSIZE + 1];

    /* Starts a MATLAB process */
    if (!(ep = engOpen(NULL))) {
        fprintf(stderr, "\nCan't start MATLAB engine\n");
        system("pause");
        return 1;
    }

    testArray1 = mxCreateDoubleMatrix(3, 3, mxREAL);
    testArray2 = mxCreateDoubleMatrix(3, 3, mxREAL);

    memcpy((void*)mxGetPr(testArray1), (void*)time1, 9 * sizeof(double));
    memcpy((void*)mxGetPr(testArray2), (void*)time2, 9 * sizeof(double));

    if (engPutVariable(ep, "testArray1", testArray1)) {
        fprintf(stderr, "\nCannot write testarray1 to MATLAB \n");
        system("pause");
        exit(1); // Same as return 1;
    }

    if (engPutVariable(ep, "testArray2", testArray2)) {
        fprintf(stderr, "\nCannot write testarray2 to MATLAB \n");
        system("pause");
        exit(1); // Same as return 1;
    }

    if (engEvalString(ep, "testArrayMulti = testArray1 * testArray2")) {
        fprintf(stderr, "\nError calculating matrix multiplication.\n");
        system("pause");
        exit(1);
    }

    if ((result = engGetVariable(ep, "testArrayMulti")) == NULL) {
        fprintf(stderr, "\nFailed to retrieve multiplied matrix\n");
        system("pause");
        exit(1);
    }
    else {
        size_t i = 0;
        size_t j = 0;
        printf("The first matrix was:\n");
        for (i = 0; i < 3; i ++ ) {
            for (j = 0; j < 3; j++)
                printf("%f ", *(mxGetPr(testArray1) + i + j*3));
            printf("\n");
        }

        printf("The second matrix was:\n");
        for (i = 0; i < 3; i ++) {
            for (j = 0; j < 3; j++)
                printf("%f ", *(mxGetPr(testArray2) + i + j*3));
            printf("\n");
        }

        printf("The matrix product is:\n");
        for (i = 0; i < 3; i ++) {
            for (j = 0; j < 3; ++j)
                printf("%f ", *(mxGetPr(result) + i + j*3));
            printf("\n");
        }
    }

    if (engOutputBuffer(ep, buffer, BUFSIZE)) {
        fprintf(stderr, "\nCan't create buffer for MATLAB output\n");
        system("pause");
        return 1;
    }
    buffer[BUFSIZE] = '\0';

    engEvalString(ep, "whos"); // whos is a handy MATLAB command that generates a list of all current variables
    printf("%s\n", buffer);

    mxDestroyArray(testArray1);
    mxDestroyArray(testArray2);
    mxDestroyArray(result);
    testArray1 = NULL;
    testArray2 = NULL;
    result = NULL;
    if (engClose(ep)) {
        fprintf(stderr, "\nFailed to close MATLAB engine\n");
    }

    system("pause"); // So the terminal window remains open long enough for you to read it
    return 0; // Because main returns 0 for successful completion
}