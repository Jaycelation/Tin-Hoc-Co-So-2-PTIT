#include <stdio.h>
#include <string.h>

char* skip_zeros(char*s){
	while (*s == '0' && *(s+1)) s++;
	return s;
}

int cmp(char *a, char *b){
	a=skip_zeros(a);
	b=skip_zeros(b);
	int l1 = strlen(a), l2 = strlen(b);
	if (l1 > l2) return 1;
	if (l1 < l2) return -1;
	return strcmp(a, b);
}

void subtract(char *a, char *b, char *res){
	int l1 = strlen(a), l2 = strlen(b);
	int i = l1 - 1, j = l2 - 1, k = 0, r = 0;
	char temp[10000];
	
	while (i >= 0 || j >= 0){
		int da=0, db=0;
		if (i >= 0){
			da = a[i] - '0';
		}
		if (j >= 0){
			db = b[j] - '0';
		}
		int diff = da - db - r;
		
		if (diff < 0){
			diff += 10;
			r = 1;
		}
		else{
			r = 0;
		}
		temp[k++] = diff + '0';
		i--; j--;
	}
	while (k > 1 && temp[k-1] == '0') k--;
	for (int m = 0; m < k; m++){
		res[m] = temp[k-m-1];
	}
	res[k] = '\0';
}

int main(){
	char a[10000], b[10000], res[10000];
	scanf("%s\n%s", a, b);

	int ss = cmp(a, b);
	if (ss == 0){
		printf("0");
	}
	else if (ss > 0){
		subtract(a, b, res);
		printf("%s", res);
	}
	else{
		subtract(b, a, res);
		printf("-%s", res);
	}
}
