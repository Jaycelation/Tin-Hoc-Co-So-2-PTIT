#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	char id[100], name[100], d[100];
	int v, h, m;
} ThiSinh;

int cmp(const void *x, const void *y){
	ThiSinh a = *(ThiSinh*)x;
	ThiSinh b = *(ThiSinh*)y;
	if (b.v != a.v){
		return b.v - a.v;
	}
	if (a.h != b.h){
		return a.h - b.h;
	}
	return a.m - b.m;
}

void cId(char *name, char *res){
	char *token = strtok(name, " ");
	int i = 0;
	while (token != NULL){
		res[i++] = token[0];
		token = strtok(NULL, " ");
	}
	res[i] = '\0';
}

int main(){
	int n;
	scanf("%d", &n);
	ThiSinh ts[n];
	
	for (int i = 0; i < n; i++){
		getchar();
		char name[100], d[100];
		
		fgets(name, sizeof(name), stdin);
		name[strcspn(name, "\n")] = '\0';
		fgets(d, sizeof(d), stdin);
		d[strcspn(d, "\n")] = '\0';
		strcpy(ts[i].name, name);
		strcpy(ts[i].d, d); 
		char temp[100];
		cId(d, ts[i].id);
		cId(name, temp);
		strcat(ts[i].id, temp);
		
		int h, m;
		scanf("%d:%d", &h, &m);
		double v = 120.0 / ((h-6.0) + m/60.0);
//		printf("%d %d %lf", h, m, v);
		ts[i].v = (int)round(v);
//		printf("%s %s %s %d Km/h\n", ts[i].id, ts[i].name, ts[i].d, ts[i].v);
	}
	
	qsort(ts, n, sizeof(ThiSinh), cmp);
	
	for (int i = 0; i < n; i++){
		printf("%s %s %s %d Km/h\n", ts[i].id, ts[i].name, ts[i].d, ts[i].v);
	}
}
