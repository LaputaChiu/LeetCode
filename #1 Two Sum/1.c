#include <stdio.h>
#include <time.h>   

int FindIndex(int size1, int size2, int *array1, int *array2, int numsSize, int target, int *index1, int *index2){
	int i = 0, j = 0;
	for(i=0;i<size1;i++){
			for(j=0;j<size2;j++){
				if(array1[i] + array2[j] == target && i != j){
					*index1 = (array1[numsSize+i] < array2[numsSize+j])?array1[numsSize+i]:array2[numsSize+j];
					*index2 = (array1[numsSize+i] < array2[numsSize+j])?array2[numsSize+j]:array1[numsSize+i];
					//printf("%d %d\n",array1[i],array2[j]);
					return 0;
				}
			}
	 }
	 return 2;
}

int* twoSum(int* nums, int numsSize, int target) {
	int i = 0, oddIndex = 0, evenIndex = 0;
	int *oddArray = (int*)malloc(numsSize*sizeof(int)*2);
	int *evenArray = (int*)malloc(numsSize*sizeof(int)*2);
	int *out = (int*)malloc(2*sizeof(int));
	
	for(i=0;i<numsSize;i++){
		if(nums[i] % 2 == 0){
			evenArray[evenIndex] = nums[i]; evenArray[numsSize + evenIndex] = i + 1; evenIndex++;
		}else{
			oddArray[oddIndex] = nums[i]; oddArray[numsSize + oddIndex] = i + 1; oddIndex++;
		}
	}
		
	if(target % 2 == 0){
		if(FindIndex(oddIndex, oddIndex, oddArray, oddArray, numsSize, target, &out[0], &out[1]) == 0){
			free(oddArray); free(evenArray); return out;
		}
		if(FindIndex(evenIndex, evenIndex, evenArray, evenArray, numsSize, target, &out[0], &out[1]) == 0){
			free(oddArray); free(evenArray); return out;
		}
	}else{
		if(FindIndex(oddIndex, evenIndex, oddArray, evenArray, numsSize, target, &out[0], &out[1]) == 0){
			free(oddArray); free(evenArray); return out;
		}
	}
	
	return out;
}

int main(){
	int *ans = NULL;
	int num[] = {-1,-2,-3,-4,-5};
	clock_t t1, t2;
	
	t1 = clock();
	ans = twoSum(num, sizeof(num)/sizeof(int), -8);
	printf("ans indice: %d %d\n",ans[0],ans[1]);
	
	t2 = clock();   
 	printf("%f ms",(((float)t2 - (float)t1) / 1000.0F )*1000);   
	
	if(ans) free(ans);
	return 0;
}
