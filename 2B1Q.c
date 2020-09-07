#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//four signal levels

int main(){
	
	char in[30];
    char out[30];
    
    gets(in);
    
    // Get input size
    int size = strlen(in);
 
    int biq2[size];
    int i;
    
    for(i=0; i<size; i++) {
        biq2[i] = in[i]-'0';
    }

    strcpy(in,"");
    int prev = -1;
    for(i=0; i<size; i+=2) {
        if(biq2[i] == 0 && biq2[i+1] == 0) strcat(in,"-3 ");
        else if(biq2[i] == 0 && biq2[i+1] == 1) strcat(in,"-1 ");
        else if(biq2[i] == 1 && biq2[i+1] == 0) strcat(in,"3 ");
        else if(biq2[i] == 1 && biq2[i+1] == 1) strcat(in,"1 ");        
    }

	// display output
    printf("%s", in);    
    return 0;

}

