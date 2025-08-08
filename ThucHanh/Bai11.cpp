#include <stdio.h>
#include <string.h>
#include <ctype.h>

void normalize(char *s){
	int len = strlen(s);
	char res[100000] = "";
	int j = 0, ns = 1, space = 0;
	
	for (int i = 0; i < len; ++i){
		char c = s[i];
		
		if (isspace(c)){
			space = 1;
		}
		else{
			if (ns && isalpha(c)){
				res[j++] = toupper(c);
				ns = 0;
			}
			else{
				if (space && j > 0 && res[j-1] != ' ') res[j++] = ' ';
				res[j++] = tolower(c);
			}
			space=0;
			
			if (c == '.' || c == '!' || c == '?'){
				while (i + 1 < len && isspace(s[i+1])) i++;
				res[j++] = '\n';
				ns = 1;
				space=0;
			}
		}
	}
	
	if (j > 0 && res[j-1] != '\n'){
		res[j++] = '.';
		res[j++] = '\n';
	}
	res[j] = '\0';
	printf("%s", res);
}

int main(){
	char line[100000];
	char s[100000] = "";
	while (fgets(line, sizeof(line), stdin)){
		line[strcspn(line, "\n")] = ' ';
		strcat(s, line);
	}
	normalize(s);
}
