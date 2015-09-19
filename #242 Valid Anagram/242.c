#include <stdio.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t) {
	int alphabet_s[26] = {0}, alphabet_t[26] = {0};
	int i = 0;
	
	if(strlen(s) != strlen(t)) return false;
		
	for(i=0;i<strlen(s);i++){
		alphabet_s[s[i]-0x61]++;
		alphabet_t[t[i]-0x61]++;
	}
	
	for(i=0;i<26;i++){
		if(alphabet_s[i] != alphabet_t[i]) return false;
	}
	return true;
}

int main(){
	char s[] = "anagram";
	char t[] = "nagaram";
	bool is = isAnagram(s, t);
	printf("Is Anagram?%s\n",is?"True":"False");
	return 0;
}
