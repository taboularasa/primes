#include <stdlib.h>
#include <math.h>
#include "dbg.h"
#include "array_access.h"

int primes_up_to(int* result, int upper_bound)
{
    int lower_bound = 2;

    result[0] = lower_bound;
    result[1] = '\0';

    for(int i = lower_bound + 1; i < upper_bound; i++) {
        int not_prime = 0;
        int last_result_index = last_index(result, upper_bound);
        check(last_result_index, "Messed up trying to get last index");

        if(last_result_index == -1) {
            return(EXIT_FAILURE);
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

    return 0;
error:
    return -1;
}

int print_primes_up_to(int upper_bound)
{
    int* result = malloc(sizeof(int)*upper_bound);
    int rc = primes_up_to(result, upper_bound);
    check(rc, "Primes up to messed up.");

    int last_result_index = last_index(result, upper_bound);
    check(last_result_index, "Messed up trying to get last index");

    for(int i = 0; i < last_result_index; i++) {
        printf("%d", result[i]);
        if(i != last_result_index - 1) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
error:
    exit(EXIT_FAILURE);
}
