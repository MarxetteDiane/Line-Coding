#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int initSize = 5;
    char * str = (char *) malloc(initSize * sizeof(char));

    scanf("%s", str);

    // 1 bit per input bit
    int bits = strlen(str);
    char *nrz_l = (char *) malloc(initSize * sizeof(char));
    
    // 1 is high, 0 is low
    int i;
    int j = 0;
    for (i = 0; i < bits; i++) {
        if(str[j] == '1') {
        	nrz_l[i] = 1;
		} else if ((str[j] == '-') && (str[j+1] == '1')) {
			nrz_l[i] = 0;
			j++;
		} else {
			nrz_l[i] = ' ';
		}
		j++;
    }

    // Displays the output
    for (i = 0; i < sizeof(nrz_l); i++) {
        printf("%i ", nrz_l[i]);
    }

    // Frees up allocated memory
    free(str);

    return 0;
}
