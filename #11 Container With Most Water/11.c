#include <stdio.h>

#define MIN(a,b) ((a<b)?a:b)
#define MAX(a,b) ((a>b)?a:b)

int maxArea(int* height, int heightSize) {
	int *begin = height, *end = height+heightSize-1, max_water = 0;
	while(begin<end){
		int height = MIN(*begin,*end);
		max_water = MAX(max_water,height*(end-begin));
		while(begin < end && *begin <= height) begin++;
		while(begin < end && *end <= height) end--;
	}
	return max_water;
}

int main(){
	int height[] = {6,99,474,3,1,6,7,78,56,4667,12523,123,352722,1231,4646,12,242,4,1212};
	printf("Max water : %d\n",maxArea(height,sizeof(height)/sizeof(int)));
	return 0;	
}
