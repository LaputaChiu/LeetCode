#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findPeakElement(int* nums, int numsSize) {
	if(!nums) return 0;
	if(numsSize == 1) return 0;
	if(numsSize == 2) return (nums[0] > nums[1])?0:1;

	int midIndex = numsSize/2;
	bool goLeft = false;	

	int cmpIndex = (nums[midIndex - 1] > nums[midIndex])?
		(goLeft = true, midIndex - 1):
		(goLeft = false, midIndex);

	while((0 <= cmpIndex-1) && (cmpIndex+1 < numsSize)){
		if( (goLeft) ? (nums[cmpIndex] > nums[cmpIndex-1]) : (nums[cmpIndex] > nums[cmpIndex+1]) ){
			break;	
		}else{
			(goLeft) ? cmpIndex-- : cmpIndex++;
		}
	}

	return cmpIndex;
}

int main(){

	int nums1[10] = {2,4,6,5,1,3,7,4};
	int index1 = findPeakElement(nums1, 8);
	printf("Peek index: %d\n", index1);
	
	int nums2[10] = {2};
	int index2 = findPeakElement(nums2, 1);
	printf("Peek index: %d\n", index2);
	
	int nums3[10] = {2,4};
	int index3 = findPeakElement(nums3, 2);
	printf("Peek index: %d\n", index3);
	
	int nums4[10] = {9,4,6};
	int index4 = findPeakElement(nums4, 3);
	printf("Peek index: %d\n", index4);
	
	int nums5[10] = {1,2,1};
	int index5 = findPeakElement(nums5, 3);
	printf("Peek index: %d\n", index5);
	return 0;
}

