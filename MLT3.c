#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char in[30];
    char out[30];
    
    gets(in);
    // Get size of in
    int size = strlen(in);

 
    int arr[size];
    int i;
    
    // Populate intArray
    for(i=0; i<size; i++) {
        arr[i] = in[i]-'0';
    }

    // Actual MLT3
    strcpy(in,"");
    int prevprev = -1;
    int prev = 0;
    for(i=0; i<size; i++) {
    	if(arr[i] == 0) {
    		if(prev == -1) {
    			prev = -1;
    			strcat(in,"-1 ");
    		}
    		else if(prev == 0) {
    			prev = 0;
    			strcat(in,"0 ");
    		}
    		else {
    			prev = 1;
    			strcat(in,"1 ");
    		}
    	} 

    	else if(arr[i] == 1) {
    		if(prevprev == -1 && prev == 0) {
    			prevprev = 0;
    			prev = 1;
    			strcat(in,"1 ");

    		} else if(prevprev == 0 && prev == 1) {
    			prevprev = 1;
    			prev = 0;
    			strcat(in,"0 ");
    		} else if(prevprev == 0 && prev == -1) {
    			prevprev = -1;
    			prev = 0;
    			strcat(in,"0 ");
    		} else if(prevprev = 1 && prev == 0) {
    			prevprev = 0;
    			prev = -1;
    			strcat(in,"-1 ");
    		}
    	} 
	}

	// STDOUT
    printf("%s", in);    
    return 0;
}
