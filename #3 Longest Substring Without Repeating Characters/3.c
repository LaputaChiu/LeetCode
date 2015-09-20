#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
	register int i = 0, strLen = strlen(s), max_len = 0, tmp_len = 0;
	int table[0xFF] = {0};
	
	while(i < strLen){
		if(table[s[i]] != 0){
			max_len = (tmp_len>max_len)?tmp_len:max_len;
			tmp_len = 0;
			i = table[s[i]];
			memset(table, 0, sizeof(int)*0xFF);
		}
		table[s[i]] = i + 1; // record position
		tmp_len++;
		i++;
	}
	max_len = (tmp_len>max_len)?tmp_len:max_len;
		
	return max_len;
}

int main(){
	char s[] = "dvdvdvffdf";
	int len = lengthOfLongestSubstring(s);
	printf("Longest length: %d",len);
	return 0;	
}
