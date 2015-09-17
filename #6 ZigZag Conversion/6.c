#include <stdio.h>

char* convert(char* s, int numRows) {
	int i = 0, j = 0, reverse_count = 0, reverse_flag = 0;
	char *output = NULL;
	int outLen = 0;
	int *tempSize = NULL;
	char **temp = NULL;
	int *tempCount = NULL;
	
	if(numRows == 1) return s;
	
	tempSize = (int*)calloc(numRows,sizeof(int));
	temp = (char**)calloc(numRows,sizeof(char*));
	tempCount = (int*)calloc(numRows,sizeof(int));
	
	for(i=0;i<numRows;i++){
		temp[i] = (char*)calloc(100,sizeof(char));
		tempSize[i] = 100;
	}
		
	for(i=0;i<strlen(s);i++){
		if(reverse_count == numRows-1) reverse_flag = 1;
		if(reverse_count == 0) reverse_flag = 0;
		temp[reverse_count][tempCount[reverse_count]] = s[i];
		if(++tempCount[reverse_count] >= tempSize[reverse_count]){
			temp[reverse_count] = (char*)realloc(temp[reverse_count], tempSize[reverse_count] *= 2);
		}
		reverse_count = (reverse_flag)?reverse_count-1:reverse_count+1;
	}
	
	for(i=0;i<numRows;i++){
		outLen = outLen + strlen(temp[i]);
	}
	output = (char*)calloc(outLen+1,sizeof(char));
	
	for(i=0;i<numRows;i++){
		memcpy(output+j,temp[i],strlen(temp[i]));
		j+=strlen(temp[i]);
		free(temp[i]);
	}
	free(temp);
	free(tempCount);
	return output;
}

int main(){
	char* res = convert("AB", 1);
	printf("Output: %s\n", res);
	return 0;
}
