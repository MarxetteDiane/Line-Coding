#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(){
	
	char input[100], output[100], cpyin[100];
	int temp[100], in=0;
	int i=0;
	bool st = true;
	
    gets(input);
    strcpy(cpyin, input);
	char* piece = strtok(cpyin," ");

	while(piece != NULL){
		temp[in] = atoi(piece);
		piece = strtok(NULL," ");
		in++;
	}
	
	
	if(temp[0] == 1){
		strcat(output, "1");
	}
	else if(temp[0] == -1){
		strcat(output, "0");
	}
	
	for(i=1; i< in; i++){
		if (temp[i] == temp[i-1]){
			strcat(output, "0");
		}
		else{
			strcat(output, "1");
		}
	}
	
	
	printf("%s", output);
}
