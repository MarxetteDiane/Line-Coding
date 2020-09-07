#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(){
	
	char input[100], output[100], cpyin[100];
	char a, b, c, d, e, f, g;
	int temp[100], in=0, i=0, idle=-1;
	bool st = true;
	
	gets(input);
    strcpy(cpyin, input);
	char* piece = strtok(cpyin," ");

	while(piece != NULL){
		temp[in] = atoi(piece);
		piece = strtok(NULL," ");
		in++;
	}
	
	
	for(i=0; i< in; i++){
		if (temp[i] == 1){
			strcat(output, "1");
			idle = 1;
		}
		else if (temp[i] == -1){
			strcat(output, "1");
			idle = -1;
		}
		else if (temp[i] == 0){
			a = temp[i+1];
    		b = temp[i+2];
    		c = temp[i+3];
    		d = temp[i+4];
    		e = temp[i+5];
    		f = temp[i+6];
    		g = temp[i+7];
    		if(a == 0 && b == 0 && c == -1 && d == 1 && e == 0 && f == 1 && g == -1 && idle == -1){
    			strcat(output, "00000000");
    			i+=7;
			}
			else if(a == 0 && b == 0 && c == 1 && d == -1 && e == 0 && f == -1 && g == 1 && idle == 1){
    			strcat(output, "00000000");
    			i+=7;
			}
		}
	}
	
	printf("%s", output);
}
