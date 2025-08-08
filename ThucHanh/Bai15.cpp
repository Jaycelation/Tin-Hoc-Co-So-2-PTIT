#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char id[100], name[100];
	long long sluong;
	long long dongia, chietkhau, tong;
} HD;

int cmp(const void *x, const void *y){
	HD a = *(HD*)x;
	HD b = *(HD*)y;
	return b.tong - a.tong;
}

void chuanhoa(char *s){
	int i = 0, j = 0;
	int l = strlen(s);
	while (s[i] == ' ') i++;
	
	while (i < l){
		if (s[i] != ' ' || (j > 0 && s[j-1] != ' ')) s[j++] = s[i];
		i++;
	}
	if (j > 0 && s[j-1] == ' ') j--;
	s[j] = '\0';
}

int main(){
	long long n;
	scanf("%lld", &n);
	getchar();

	HD hd[n];
	for (long long i = 0; i < n; i++){
		scanf("%s", hd[i].id);
		getchar();
		fgets(hd[i].name, sizeof(hd[i].name), stdin);
		hd[i].name[strcspn(hd[i].name, "\n")] = '\0';
		chuanhoa(hd[i].name);
		scanf("%lld", &hd[i].sluong);
		scanf("%lld", &hd[i].dongia);
		scanf("%lld", &hd[i].chietkhau);
		getchar();
		hd[i].tong = hd[i].dongia * hd[i].sluong - hd[i].chietkhau;		
//		printf("%lld %lld %lld\n", hd[i].sluong, hd[i].dongia, hd[i].chietkhau);
	
	}
	
	qsort(hd, n, sizeof(HD), cmp);
	
	for (long long i = 0; i < n; i++){
		printf("%s %s %lld %lld %lld %lld\n", hd[i].id, hd[i].name, hd[i].sluong, hd[i].dongia, hd[i].chietkhau, hd[i].tong);
	}	
	
}

