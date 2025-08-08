#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char name[20];
	char date[11];
} Nguoi;

int cmp(Nguoi a, Nguoi b){
	return strcmp(a.date, b.date);
}

int compare(const void *x, const void *y){
	Nguoi a = *(Nguoi*)x;
	Nguoi b = *(Nguoi*)y;
	return cmp(a, b);
}

int main(){
	int n;
	scanf("%d", &n);
	Nguoi a[n];
	for (int i = 0; i < n; i++){
		getchar();
		int d, m, y;
		scanf("%s %d/%d/%d", a[i].name, &d, &m, &y);
		sprintf(a[i].date, "%04d/%02d/%02d", y, m, d);
	}
	
	qsort(a, n, sizeof(Nguoi), compare);
	printf("%s\n%s", a[n-1].name, a[0].name);
//	for (int i = 0; i < n; i++){
//		printf("%s %s\n", a[i].name, a[i].date);
//	}
	
}
