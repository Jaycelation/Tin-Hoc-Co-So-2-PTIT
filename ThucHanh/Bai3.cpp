#include <stdio.h>
#include <string.h>

int convert(char a, char b, char c){
	return (a - '0') * 4 + (b - '0') * 2 + (c - '0');
}

int main(){
	char s[1000];
	scanf("%s", s);
	
	int length = strlen(s);
	
	int p = (3 - (length % 3)) % 3;
	
	if (p > 0){
		for (int i = length - 1; i >= 0; i--){
			s[i + p] = s[i];
		}
		for (int i = 0; i < p; i++){
			s[i] = '0';
		}
		s[length + p] = '\0';
		length += p;
	}
	
	for (int i = 0; i < length; i += 3){
		
		printf("%d", convert(s[i], s[i+1], s[i+2]));
	}
	
}
