#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void*a, const void*b){
	return (*(char*)a - *(char*)b);
}

int main(){
	int t;
	scanf("%d", &t);
	for (int k = 1; k <= t; k++){
		char a[10000], b[10000];
		scanf("%s\n%s", a, b);
		qsort(a, strlen(a), sizeof(char), cmp);
		qsort(b, strlen(b), sizeof(char), cmp);
		
		for (int i = 0; i < strlen(a); i++){
			printf("%c", a[i]);
		}
		printf("\n");
		for (int i = 0; i < strlen(b); i++){
			printf("%c", b[i]);
		}
		printf("\n");
		
		printf("Test %d: ", k);
		
		if (strcmp(a, b)==0){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}
