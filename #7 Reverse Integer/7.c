#include <stdio.h>
#include <limits.h>

static int decimal_exp[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int reverse(int x) {
	long long sum = 0;
	int sign = 0, i = 0, d = 0;
	if(x == 0 || x > INT_MAX || x < INT_MIN) return 0;
		
	sign = (x > 0)?1:(x -= x*2,0);

	for(i=0;i<sizeof(decimal_exp)/sizeof(int);i++){
		if(x/decimal_exp[i] == 0){ d = i-1; break; }
	}
	if(i == 10) d = 9;

	for(i=0;i<=d;i++){
		long long tmp = 0, before = 0;
		sum += (tmp = x/decimal_exp[d-i])*decimal_exp[i];
		//printf("%lld\n",sum);
		x -= tmp*decimal_exp[d-i];
		if(sum > INT_MAX || sum < INT_MIN) return 0;
	}
	
	if(sign == 0) sum -= sum*2;
	
	if(sum > INT_MAX || sum < INT_MIN) return 0;

	return sum;
}

int main(){
  printf("Reverse: %d\n",reverse(-1));
	return 0;	
}
