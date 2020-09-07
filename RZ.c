 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int initSize = 5;
    char * str = (char *) malloc(initSize * sizeof(char));

    scanf("%s", str);

    // 2 bits per input bit
    int bits = strlen(str);
    int rz[bits*2];

    // Idle state is low level
    int currState = -1;
    
    // Transitions at the beginning of every bit
    int i;
    for (i = 0; i < bits; i++) {
        switch(str[i]) {
            case '1': //half bit: high-low
                rz[i*2] = currState = -currState;
                rz[(i*2)+1] = currState = -currState;
                break;
            case '0': //idle
                rz[i*2] = currState;
                rz[(i*2)+1] = currState;
                break;
            default:
                break;
        }
    }

    // Displays the output
    for (i = 0; i < bits*2; i++) {
        printf("%i ", rz[i]);
    }

    // Frees up allocated memory
    free(str);

    return 0;
}
