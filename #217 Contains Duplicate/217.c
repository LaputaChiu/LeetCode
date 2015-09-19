#include <stdio.h>
#include <stdbool.h>

bool findDup(int* nums, int numsSize, int find_num){
	int i = 0;
	for(i=0;i<numsSize && nums[i] != 0;i++){
		if(nums[i] == find_num) return true;
	}
	return false;
}

void addNum(int** nums, int* numsSize, int num){
	int cur = 0;
	for(cur=0;cur<(*numsSize) && (*nums)[cur] != 0;cur++);
	if(cur == (*numsSize)) (*nums) = (int*)realloc(*nums, *numsSize = (*numsSize)*2);
	(*nums)[cur] = num;
}

bool containsDuplicate(int* nums, int numsSize) {
	int i = 0;
	bool zero_set = false; // to check duplication of zero
	
	// create a 1000 slots hash table and initialized with NULL
	int table_size = 1000;
	int **hashtable = (int**)calloc(table_size, sizeof(int*));
	
	int slot_init_size = 100;
	int *slot_cur_size = (int*)calloc(table_size, sizeof(int));
	for(i=0;i<table_size;i++){
		slot_cur_size[i] = slot_init_size;
	}
	
	for(i=0;i<numsSize;i++){
		int slot = ((unsigned int)nums[i]) % table_size; // to avoid negative number
		//printf("num: %d, slot:%d\n",nums[i],slot);
		if(nums[i] == 0){
			if(zero_set) return true;
			else zero_set = true;
		}
			
		if(!hashtable[slot]){
			hashtable[slot] = (int*)calloc(slot_init_size, sizeof(int));
			hashtable[slot][0] = nums[i];
		}else{
			if(findDup(hashtable[slot], slot_cur_size[slot], nums[i])){
				//printf("%d is duplicated!!\n",nums[i]);
				return true;
			}else{
				addNum(&hashtable[slot], &slot_cur_size[slot], nums[i]);
			}
		}
	}   
	
	for(i=0;i<table_size;i++){
		if(hashtable[i]) free(hashtable[i]);
	}
	free(hashtable);
	
	return false;
}

int main(){
	int nums[] = {1,5,-2,-4,0};
	bool isDup = containsDuplicate(nums, sizeof(nums)/sizeof(int));
	printf("is dup? %s\n",isDup?"True":"False");
	return 0;
}
