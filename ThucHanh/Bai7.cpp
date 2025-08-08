#include <stdio.h>
#include <string.h>
#include <ctype.h>

int convert(char c){
	if (c == 'A' || c == 'B' || c == 'C'){
		return 2;
	}
	if (c == 'D' || c == 'E' || c == 'F'){
		return 3;
	}
	if (c == 'G' || c == 'H' || c == 'I'){
		return 4;
	}
	if (c == 'J' || c == 'K' || c == 'L'){
		return 5;
	}
	if (c == 'M' || c == 'N' || c == 'O'){
		return 6;
	}
	if (c == 'P' || c == 'Q' || c == 'R' || c == 'S'){
		return 7;
	}
	if (c == 'T' || c == 'U' || c == 'V'){
		return 8;
	}
	return 9;
}

int check(int*s, int l){
	int left = 0;
	int right = l - 1;
	while (left < right){
		if (s[left] != s[right]){
			return 0;
		}
		left++; right--;
	}
	return 1;
	
}

int main(){
	int t;
	scanf("%d", &t);
	
	while (t--){
		char s[10000];
		getchar();
		scanf("%s", s);
		int res[10000];
		for (int i = 0; i < strlen(s); i++){
			res[i] = convert(toupper(s[i]));
		}
		if (check(res, strlen(s))){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		
	}
}
