#include<stdio.h>

int main(){
	char s[1001];
	int f[26] = {0};
	int count = 0;
	scanf("%s", s);
	
	for (int i = 0; s[i] != '\0'; i++){
		int j = s[i] - 'a';
		if (f[j] == 0){
			f[j] = 1;
			count++;
		}
	}
	
	printf("%d", count);
}
