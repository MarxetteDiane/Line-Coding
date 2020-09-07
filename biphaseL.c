 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int initSize = 5;
    char * str = (char *) malloc(initSize * sizeof(char));

    scanf("%s", str);

    // 2 bits per input bit
    int bits = strlen(str);
    int bi_l[bits*2];
    
    // Transitions at the beginning of every bit
    int i;
    for (i = 0; i < bits; i++) {
        switch(str[i]) {
            case '1': //half bit: high-low
                bi_l[i*2] = 1;
                bi_l[(i*2)+1] = -1;
                break;
            case '0': //half bit: low-high
                bi_l[i*2] = -1;
                bi_l[(i*2)+1] = 1;
                break;
            default:
                break;
        }
    }

    // Displays the output
    for (i = 0; i < bits*2; i++) {
        printf("%i ", bi_l[i]);
    }

    // Frees up allocated memory
    free(str);

    return 0;
}
