#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int initSize = 5;
    char * str = (char *) malloc(initSize * sizeof(char));

    scanf("%s", str);

    // 2 bits per input bit
    int bits = strlen(str);
    int bplr[bits*2];

    // previous state
    int prevState = -1;
    
    // Transitions at the beginning of every bit
    int i;
    for (i = 0; i < bits; i++) {
        switch(str[i]) {
            case '1': //half bit: high to 0 or low to 0
                bplr[i*2] = prevState = -prevState;
                bplr[(i*2)+1] = 0;
                break;
            case '0': //idle
                bplr[i*2] = 0;
                bplr[(i*2)+1] = 0;
                break;
            default:
                break;
        }
    }

    // Displays the output
    for (i = 0; i < bits*2; i++) {
        printf("%i ", bplr[i]);
    }

    // Frees up allocated memory
    free(str);

    return 0;
}
