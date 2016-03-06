#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
	int row = 0, col = 0;
	bool isFirstRowZeros = false;
	bool isFirstColumnZeros = false;
	
	// if first column contatins zero 
	for(row=0;row<matrixRowSize;row++){
		if(matrix[row][0] == 0){
			isFirstColumnZeros = true;
			break;
		}
	} 
	
	// if first row contatins zero 
	for(col=0;col<matrixColSize;col++){
		if(matrix[0][col] == 0){
			isFirstRowZeros = true;
			break;
		}
	}

	// using first row and column to record if matrix[row][col] is zero
	for(row=1;row<matrixRowSize;row++){
		for(col=1;col<matrixColSize;col++){
			if(matrix[row][col] == 0){
				matrix[row][0] = 0;
				matrix[0][col] = 0;
			}
		}
	}

	// set zeros if the row has a zero
	for(row=1;row<matrixRowSize;row++){
		if(matrix[row][0] == 0){
			for(col=1;col<matrixColSize;col++){
				matrix[row][col] = 0;
			}
		}
		if(isFirstColumnZeros) matrix[row][0] = 0;
	}
	
	// set zeros if the column has a zero
	for(col=1;col<matrixColSize;col++){
		if(matrix[0][col] == 0){
			for(row=1;row<matrixRowSize;row++){
				matrix[row][col] = 0;
			}
		}
		if(isFirstRowZeros) matrix[0][col] = 0;
	}

	matrix[0][0] = (isFirstRowZeros | isFirstColumnZeros)?0:matrix[0][0]; 
}

int main(){
	int **matrix = (int**)calloc(4, sizeof(int*));
	for(int i=0;i<4;i++){
		matrix[i] = (int*)calloc(5, sizeof(int));
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			matrix[i][j] = 1;
		}
	}
	matrix[1][1] = 0;
	matrix[3][2] = 0;

	//	{1,1,1,1,1},
	//	{1,0,1,1,1},
	//	{1,1,1,1,1},
	//	{1,1,0,1,1}

	printf("Before setting ...\n");
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
	
	setZeroes(matrix,4,5);

	printf("After setting ...\n");
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}

	if(matrix){
		for(int i=0;i<4;i++){
			if(matrix[i]) free(matrix[i]);
		}
		free(matrix);
	}
	return 0;
}
