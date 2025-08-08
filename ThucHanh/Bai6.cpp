#include <stdio.h>
#include <string.h>
char P[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

int find(char c){
	for (int i = 0; i < strlen(P); i++){
		if (P[i] == c){
			return i;
		}
	}
	return -1;
}

int main(){
	int k;
	char s[100000];
	while (1){
		scanf("%d", &k);
		if (k == 0) break;
		scanf("%s", s);
		int l = strlen(s);
		
		char res[100000];
		
		for (int i = 0; i < l; i++){
			int idx = find(s[i]);
			int nidx = (idx + k) % 28;
			res[i] = P[nidx];
		}
		for (int i = l - 1; i >= 0; i--){
			printf("%c", res[i]);
		}
		printf("\n");
	}
}
