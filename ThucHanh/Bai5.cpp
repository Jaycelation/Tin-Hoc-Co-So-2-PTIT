#include <stdio.h>
#include <string.h>

void solve(char *s){
	char st[101];
	int top = -1;
	for (int i = 0; i < strlen(s); i++){
		if (top >= 0 && st[top] == s[i]){
			top--;
		}
		else{
			st[++top] = s[i];
		}
	}
	if (top == -1){
		printf("Empty String\n");
	}
	else{
		st[top+1] = '\0';
		printf("%s", st);
	}
}

int main(){
	char s[101];
	scanf("%s", s);
	solve(s);
}
