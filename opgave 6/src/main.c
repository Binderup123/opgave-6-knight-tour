#include <stdio.h>
#include "../include/pis.h"

int main() {
    int size;

    // spørger om størrese af borad
    printf("angiv størrelse på borad  ");
    scanf("%u", &size);

    if (size > DEFAULT_SIZE) {
        printf("Maximum allowed size is %d. Please change DEFAULT_SIZE in header if needed.\n", DEFAULT_SIZE);
        return 1;
    }

    // Run the greedy knight’s tour and print results
    greedy_tour(size);

    return 0;
}









