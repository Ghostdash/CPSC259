//name: John Ye
//CWL: johnye
//student num: 43883347
//purpose: To calculate the page rank
//Note: I notice sometimes when running the program, the program can end unexpectly at some points
//(notably at engopen and engclose). Therefore sometimes the result is not displayed. If you encountered this problem,
//run the debugger again and again (eventually it will work). I am not sure what is the cause of problem, therefore I could
//not find a way to fix it. :(

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"

#define BUFFERSIZE 256

int getdimension(FILE*);
int** setup(FILE*,int size,int dimension);
int get_string_size(FILE*);

int main(void) {
	int dimension;
	int size;
	FILE* pagefile;
	Engine* ep = NULL; // A pointer to a MATLAB engine object
	mxArray* result = NULL, *input = NULL; // mxArray is the fundamental type underlying MATLAB data

	int** connectivity = NULL;
	char input_string[BUFFERSIZE] = "ConnectivityMatrix = [";
	char buffer[BUFFERSIZE];
	
	pagefile = fopen("web.txt", "r");
	dimension = getdimension(pagefile);
	printf("The dimension of the matrix is %d\n", dimension);

	size = get_string_size(pagefile);
	printf("The size of a line is %d\n", size);

	connectivity = setup(pagefile,size,dimension);

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++)
			printf("%d ", connectivity[i][j]);
		printf("\n");
	}

	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			sprintf(buffer, "%d ", connectivity[i][j]);
			strcat(input_string, buffer);
		}
		strcat(input_string, ";");
	}
	strcat(input_string, "];");
	printf("%s\n", input_string);

	if (!(ep = engOpen(NULL))) {
		fprintf(stderr, "\nCan't start MATLAB engine\n");
		system("pause");
		return 1;
	}

	if (engEvalString(ep, input_string) ){
		fprintf(stderr, "\nError inputting connectivitymatrix.\n");
		system("pause");
		exit(1);
	}

	if (engEvalString(ep, "dimension = size (ConnectivityMatrix,1);")) {
		fprintf(stderr, "\nError setting dimension.\n");
		system("pause");
		exit(1);
	}

	if (engEvalString(ep, "columnsums = sum (ConnectivityMatrix,1);")) {
		fprintf(stderr, "\nError calculating columnsums.\n");
		system("pause");
		exit(1);
	}

	if (engEvalString(ep, "p = 0.85;")) {
		fprintf(stderr, "\nError inputting p\n");
		system("pause");
		exit(1);
	}

	if (engEvalString(ep, "zerocolumns = find(columnsums~=0);")) {
		fprintf(stderr, "\nError finding zerocolumns p\n");
		system("pause");
		exit(1);
	}

	if (engEvalString(ep, "D = sparse( zerocolumns, zerocolumns, 1./columnsums(zerocolumns), dimension, dimension);")) {
		fprintf(stderr, "\nError calculating D\n");
		system("pause");
		exit(1);
	}

	if (engEvalString(ep, "StochasticMatrix = ConnectivityMatrix * D;")) {
		fprintf(stderr, "\nError calculating stochasticmatrix\n");
		system("pause");
		exit(1);
	}

	if (engEvalString(ep, "[row, column] = find(columnsums==0);")) {
		fprintf(stderr, "\nError setting row and column\n");
		system("pause");
		exit(1);
	}

	if (engEvalString(ep, "StochasticMatrix(:, column) = 1./dimension;")) {
		fprintf(stderr, "\nError setting up StochoasticMatrix\n");
		system("pause");
		exit(1);
	}

	if (engEvalString(ep, "Q = ones(dimension, dimension);")) {
		fprintf(stderr, "\nError setting Q \n");
		system("pause");
		exit(1);
	}

	if (engEvalString(ep, "TransitionMatrix = p * StochasticMatrix + (1 - p) * (Q/dimension);")) {
		fprintf(stderr, "\nError setting transition matrix\n");
		system("pause");
		exit(1);
	}

	if (engEvalString(ep, "PageRank = ones(dimension, 1);")) {
		fprintf(stderr, "\nError setting pagerank variable\n");
		system("pause");
		exit(1);
	}

	if (engEvalString(ep, "for i = 1:100 PageRank = TransitionMatrix * PageRank; end")) {
		fprintf(stderr, "\nError multiplying pagerank with transitionmatrix\n");
		system("pause");
		exit(1);
	}

	if (engEvalString(ep, "PageRank = PageRank / sum(PageRank);")) {
		fprintf(stderr, "\nError calculating pagerank\n");
		system("pause");
		exit(1);
	}

	if ((result = engGetVariable(ep, "PageRank")) == NULL) {
		fprintf(stderr, "\nFailed to retrieve calculated pagerank\n");
		system("pause");
		exit(1);
	}
	else {
		size_t sizeOfResult = mxGetNumberOfElements(result);
		size_t i = 0;
		printf("NODE  RANK\n");
		printf("-- - ----\n");
		for (i = 0; i < sizeOfResult; ++i) {
			printf("%zd     %.4f\n", i+1,*(mxGetPr(result) + i));
		}
	}
	mxDestroyArray(input);
	mxDestroyArray(result);
	input = NULL;
	result = NULL;

	if (engClose(ep)) {
		fprintf(stderr, "\nFailed to close MATLAB engine\n");
	}

	system("pause"); // So the terminal window remains open long enough for you to read it
	return 0; // Because main returns 0 for successful completion
}

int** setup(FILE* page, int size, int dimension) {
	int** connectivity = NULL;
	char line_buffer[BUFFERSIZE];
	int row = 0;
	int column = 0;

	connectivity = (int**)calloc(dimension, sizeof(int*));

	for (row = 0; row < size; ++row) {
		connectivity[row] = (int*)calloc(dimension, sizeof(int));
	}

	/* Copies maze file to memory */
	row = 0;
	int index = 0;
	while (fgets(line_buffer,BUFFERSIZE,page)) {
		column = 0;
		for (index = 0; index < size; ++index) {
			if (line_buffer[index] != ' '){
				connectivity[row][column] = line_buffer[index] - '0';
				column++;
			}
		}
		row++;
	}
	return connectivity;
}

int get_string_size(FILE* web) {
	int size = 0;
	char buffer[BUFFERSIZE];

	fgets(buffer, BUFFERSIZE, web);
	int i = 0;

	while (buffer[i] != '\n') {
		size++;
		i++;
	}
	fseek(web, 0, SEEK_SET);
	return size;
}


int getdimension(FILE* web) {
	int dimension = 0;
	char buffer[BUFFERSIZE];

	fgets(buffer,BUFFERSIZE,web);
	int i = 0;

	while (buffer[i] != '\n') {
		if (buffer[i] != ' ')
			dimension++;
		i++;
	}
	fseek(web, 0, SEEK_SET);
	return dimension;
}