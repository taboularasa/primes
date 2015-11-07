#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int last_index(int* result, int size)
{
    for(int i = 0; i < size; i++){
        if(result[i] == '\0') {
            return i;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    if(argc < 1) {
        exit(EXIT_FAILURE);
    }
    int upper_bound = atoi(argv[1]);
    int lower_bound = 2;

    int* result = malloc(sizeof(int)*upper_bound);
    result[0] = lower_bound;
    result[1] = '\0';

    for(int i = lower_bound + 1; i < upper_bound; i++) {
        int not_prime = 0;
        int last_result_index = last_index(result, upper_bound);
        if(last_result_index == -1) {
            exit(EXIT_FAILURE);
        }
        for(int j = 0; j < last_result_index; j++) {
            if(i % result[j] == 0) {
                not_prime = 1;
                break;
            }
        }
        if(not_prime == 1) {
            continue;
        }
        result[last_result_index] = i;
        result[last_result_index + 1] = '\0';
    }

    int last_result_index = last_index(result, upper_bound);
    if(last_result_index == -1) {
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < last_result_index; i++) {
        printf("%d", result[i]);
        if(i != last_result_index - 1) {
            printf(", ");
        }
    }
    printf("\n");
}
