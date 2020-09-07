#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int initSize = 5;
    char * str = (char *) malloc(initSize * sizeof(char));

    scanf("%s", str);

    // 1 bit per input bit
    int bits = strlen(str);
    int nrz_s[bits];
    
    // Idle state is low level
    int currState = -1;
    
    // 1 is idle
    int i;
    for (i = 0; i < bits; i++) {
        switch(str[i]) {
            case '1': //idle
                nrz_s[i] = currState;
                break;
            case '0': //transitions from high to low or low to high
                nrz_s[i] = currState = -currState;
                break;
            default:
                break;
        }
    }

    // Displays the output
    for (i = 0; i < bits; i++) {
        printf("%i ", nrz_s[i]);
    }

    // Frees up allocated memory
    free(str);

    return 0;
}
