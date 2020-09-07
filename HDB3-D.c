#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(){
	
	char input[100], output[100], cpyin[100];
	char a, b, c;
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
			a = temp[i+1];
    		b = temp[i+2];
    		c = temp[i+3];
    		if(a == 0 && b == 0 && c == 1 && idle == -1){
    			strcat(output, "0000");
    			idle = 1;
    			i+=3;
			}
			else{
				strcat(output, "1");
				idle = 1;
			}
		}
		else if (temp[i] == -1){
			a = temp[i+1];
    		b = temp[i+2];
    		c = temp[i+3];
    		if(a == 0 && b == 0 && c == -1 && idle == 1){
    			strcat(output, "0000");
    			idle = -1;
    			i+=3;
			}
			else{
				strcat(output, "1");
				idle = -1;
			}
		}
		else if (temp[i] == 0){
			a = temp[i+1];
    		b = temp[i+2];
    		c = temp[i+3];
    		if(a == 0 && b == 0 && c == 1 && idle == 1){
    			strcat(output, "0000");
    			i+=3;
			}
			else if(a == 0 && b == 0 && c == -1 && idle == -1){
    			strcat(output, "0000");
    			i+=3;
			}
		}
		else{
				strcat(output, "0");
		}
	}
	
	printf("%s", output);
}
