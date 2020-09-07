#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int initSize = 5;
    char * str = (char *) malloc(initSize * sizeof(char));

    scanf("%s", str);

    // 1 bit per input bit
    int bits = strlen(str);
    int nrz_l[bits];
    
    // 1 is high, 0 is low
    int i;
    for (i = 0; i < bits; i++) {
        switch(str[i]) {
            case '1': //high
                nrz_l[i] = 1;
                break;
            case '0': //low
                nrz_l[i] = -1;
                break;
            default:
                break;
        }
    }

    // Displays the output
    for (i = 0; i < bits; i++) {
        printf("%i ", nrz_l[i]);
    }

    // Frees up allocated memory
    free(str);

    return 0;
}
