#include <stdio.h>

void solve(int n, int b){
	char res[1000];
	int idx = 0;
	if (n == 0){
		printf("0\n");
		return;
	}
	while (n > 0){
		int r = n%b;
		if (r < 10){
			res[idx++] = '0' + r;
		}
		else{
			res[idx++] = 'A' + r - 10;
		}
		n /= b;
	}
	
	for (int i = idx - 1; i >= 0; i--){
		printf("%c", res[i]);
	}
	printf("\n");
}

int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n, b;
		scanf("%d%d", &n, &b);
		solve(n, b);
	}
}
