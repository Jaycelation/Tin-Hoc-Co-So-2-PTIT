#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int h, m, s;
} Time;

int cmp(Time a, Time b){
	if (a.h != b.h)
		return a.h - b.h;
	else if (a.m != b.m)
		return a.m - b.m;
	else
		return a.s - b.s;
}

int compare (const void *x, const void *y){
	Time a = *(Time*)x;
	Time b = *(Time*)y;
	return cmp(a, b);
}

int main(){
	int n;
	scanf("%d", &n);
	Time t[5000];
	for (int i = 0; i < n; i++){
		scanf("%d %d %d", &t[i].h, &t[i].m, &t[i].s);
	}
	qsort(t, n, sizeof(Time), compare);
	for (int i = 0; i < n; i++){
		printf("%d %d %d \n", t[i].h, t[i].m, t[i].s);
	}
}
