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

    // Actual B8ZS
    int a,b,c,d,e,f,g;
    strcpy(in,"");
    int prev = -1;
    for(i=0; i<size; i++) {
    	if(arr[i] == 0) {
    		if(i+7 < size) {
	    		a = arr[i+1];
	    		b = arr[i+2];
	    		c = arr[i+3];
	    		d = arr[i+4];
	    		e = arr[i+5];
	    		f = arr[i+6];
	    		g = arr[i+7];
	    		if(a == 0 && b == 0 && c == 0 && d == 0 &&
	    			e == 0 && f == 0 && g == 0) {
	    			if(prev == -1) {
	    				strcat(in, "0 0 0 -1 1 0 1 -1 ");
	    			} else {
	    				strcat(in, "0 0 0 1 -1 0 -1 1 ");
	    			}
	    			i+=7;
	    		}

	    		else strcat(in,"0 ");
    		}

    		else strcat(in,"0 ");
    	} 

    	else if(arr[i] == 1) {
    		if(prev == -1) {
    			prev = 1;
    			strcat(in,"1 ");
    		} else if(prev == 1) {
    			prev = -1;
    			strcat(in,"-1 ");
    		}
    	} 
    	
	}

	// STDOUT
    printf("%s", in);    
    return 0;
}
