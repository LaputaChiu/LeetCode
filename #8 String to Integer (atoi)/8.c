#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

static int decimal_exp[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int myAtoi(char* str) {
	bool sign = true;
	int begin = 0, strLen = strlen(str), i = 0;
	long long sum = 0;
	char *buf = (char*)calloc(strLen,sizeof(char));
	
	if(!strLen) return 0;
		
	// identify sign
	for(begin=0;begin<strLen && str[begin] == ' ' ;begin++);
	if(begin >= strLen) return 0;
	switch(str[begin]){
		case '-': sign = false; if(begin+1 == strLen || str[begin+1] < '0' || str[begin+1] > '9') return 0; begin++;
			break;
		case '+': sign = true; if(begin+1 == strLen || str[begin+1] < '0' || str[begin+1] > '9') return 0; begin++;
			break;
		default:
			if(str[begin] < '0' || str[begin] > '9') return 0;
			break;			
	}
	
	// find end
	int end = 0;
	for(end = begin;end<strLen && str[end] >= '0' && str[end] <= '9' ;end++);

	// find out first non-zero integer
	for(;begin<end && str[begin] == '0';begin++);
		
	// collect integer
	int j = 0;
	//printf("Begin %d, End %d\n",begin,end);
	for(;begin<end;begin++){
		if(str[begin] >= '0' && str[begin] <= '9'){ 
			buf[j] = str[begin]; j++;
		}else break;
	}

	// calculate
	if((j-1) > 9) return (sign)?INT_MAX:INT_MIN;
	for(i=0;i<j;i++){
		if(sign){
			sum += (buf[i]-0x30)*decimal_exp[(j-1)-i];
			//printf("%d\n",sum);
			if(sum > INT_MAX) return INT_MAX;
		}else{
			sum -= (buf[i]-0x30)*decimal_exp[(j-1)-i];
			//printf("%d\n",sum);
			if(sum < INT_MIN) return INT_MIN;
		}
	}
	
	free(buf);
	return sum;
}

int main(){
	char str[] = " 1 x01x10x";
	printf("Integer: %d\n",myAtoi(str));
	return 0;	
}
