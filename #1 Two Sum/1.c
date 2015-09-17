#include <stdio.h>
#include<time.h>   

int* twoSum(int* nums, int numsSize, int target) {
	int i = 0, j = 0, oddIndex = 0, evenIndex = 0, index1 = 0, index2 = 0;
	int *oddArray = (int*)malloc(numsSize*sizeof(int)*2);
	int *evenArray = (int*)malloc(numsSize*sizeof(int)*2);
	int *out = (int*)malloc(2*sizeof(int));
	
	for(i=0;i<numsSize;i++){
		if(nums[i] % 2 == 0){
			evenArray[evenIndex] = nums[i]; evenArray[numsSize + evenIndex] = i + 1;
			//printf("even %d, index %d\n",nums[i],i+1);
			evenIndex++;
		}else{
			oddArray[oddIndex] = nums[i]; oddArray[numsSize + oddIndex] = i + 1;
			//printf("odd %d, index %d\n",nums[i],i+1);
			oddIndex++;
		}
	}
		
	if(target % 2 == 0){
		for(i=0;i<oddIndex;i++){
			for(j=0;j<oddIndex;j++){
				if(oddArray[i] + oddArray[j] == target && i != j){
					index1 = (oddArray[numsSize+i] < oddArray[numsSize+j])?oddArray[numsSize+i]:oddArray[numsSize+j];
					index2 = (oddArray[numsSize+i] < oddArray[numsSize+j])?oddArray[numsSize+j]:oddArray[numsSize+i];
					//printf("%d %d\n",oddArray[i],oddArray[j]);
				}
			}
		}
		for(i=0;i<evenIndex;i++){
			for(j=0;j<evenIndex;j++){
				if(evenArray[i] + evenArray[j] == target && i != j){
					index1 = (evenArray[numsSize+i] < evenArray[numsSize+j])?evenArray[numsSize+i]:evenArray[numsSize+j];
					index2 = (evenArray[numsSize+i] < evenArray[numsSize+j])?evenArray[numsSize+j]:evenArray[numsSize+i];
					//printf("%d %d\n",evenArray[i],evenArray[j]);
				}
			}
		}
	}else{
		for(i=0;i<oddIndex;i++){
			for(j=0;j<evenIndex;j++){
				if(oddArray[i] + evenArray[j] == target){
					index1 = (oddArray[numsSize+i] < evenArray[numsSize+j])?oddArray[numsSize+i]:evenArray[numsSize+j];
					index2 = (oddArray[numsSize+i] < evenArray[numsSize+j])?evenArray[numsSize+j]:oddArray[numsSize+i];
					//printf("%d %d\n",oddArray[i],evenArray[j]);
				}
			}
		}
	}
	
	out[0] = index1;
	out[1] = index2;
	if(oddArray) free(oddArray);
	if(evenArray) free(evenArray);
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
