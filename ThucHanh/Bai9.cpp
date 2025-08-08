#include <stdio.h>
#include <string.h>

int checkPrime(int n){
	if (n < 2) return 0;
	for (int i = 2; i * i <= n; i++){
		if (n % i ==0){
			return 0;
		}
	}
	return 1;
}

int tong(char *s){
	int sum = 0;
	for (int i = 0; i < strlen(s); i++){
		sum += s[i] - '0';
	}
	return sum;
}

int checkIdx(int i, char c){
	if (i % 2 == 0 && (c - '0') % 2 == 0) return 1;
	if (i % 2 != 0 && (c - '0') % 2 != 0) return 1;
	return 0;
}

int check(char *s){
	if (!checkPrime(tong(s))) return 0;
	for (int i = 0; i < strlen(s); i++){
		if (!checkIdx(i, s[i])){
			return 0;
		}
	}
	return 1;
}

int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		getchar();
		char s[1000];
		scanf("%s", s);
		if (check(s)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		
		
	}	
}
