#include <bits/stdc++.h>

int main(){
	int t;
	scanf("%d", &t);
	getchar();
	while (t--){
		char s[100001];
		fgets(s, 100001, stdin);
		long long res = 0;
		long long cur_num = 0;
		int num = 0;
		
		for (int i = 0; i < strlen(s); i++){
			if (isdigit(s[i])){
				cur_num = cur_num * 10 + (s[i] - '0');
				num = 1;
			}
			else{
				if (num){
					if (cur_num > res){
						res = cur_num;
					}
					cur_num = 0;
					num = 0;
				}
			}
		}
		if (num && cur_num > res){
			res = cur_num;
		}
		printf("%lld\n", res);
	}
}
