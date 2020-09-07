#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int initSize = 5;
    char * str = (char *) malloc(initSize * sizeof(char));

    scanf("%s", str);

    // 2 bits per input bit
    int bits = strlen(str);
    int bami[bits*2];

    // Idle state is 0
    int idle = 0;
    int currState = -1;
    
    // Transitions at the beginning of every bit
    int i;
    for (i = 0; i < bits; i++) {
        switch(str[i]) {
            case '1': //Level changes for every high
                bami[i] = currState = -currState;
                break;
            case '0': //idle is 0
                bami[i] = idle;
                break;
            default:
                break;
        }
    }

    // Displays the output
    for (i = 0; i < bits; i++) {
        printf("%i ", bami[i]);
    }

    // Frees up allocated memory
    free(str);

    return 0;
}
