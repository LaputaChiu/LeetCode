#include <stdio.h>
#include <stdbool.h>

static int bad = 0;
bool isBadVersion(int version){
	return (version >= bad)?true:false; 
}

long long innerCheck(long long start, long long end){
	long long middle = (end + start)/2;

	if(start == end) return 1;
	if((end - start) == 1) return (isBadVersion(start))?start:end;

	if(isBadVersion((int)middle)){
 		return innerCheck(start, middle);
	}else{
 		return innerCheck(middle, end);
	}

}

int firstBadVersion(int n) {
	return innerCheck(1, n);	
}

int main(){
	int n = 0;

	bad = 4;
	n = firstBadVersion(5);
	printf("First bad version: %d\n",n);
	
	bad = 45;
	n = firstBadVersion(100);
	printf("First bad version: %d\n",n);
	
	bad = 8;
	n = firstBadVersion(1000);
	printf("First bad version: %d\n",n);
	
	bad = 67437;
	n = firstBadVersion(1425123451);
	printf("First bad version: %d\n",n);
	
	bad = 1702766719;
	n = firstBadVersion(2126753390);
	printf("First bad version: %d\n",n);
	return 0;
}
