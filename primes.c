#include <stdio.h>
#include <stdlib.h>
#include <apr_getopt.h>
#include "dbg.h"
#include "primes_up_to.h"
#include "prime_factors_for.h"
#include "array_access.h"

int main(int argc, const char* const argv[])
{
    char ch = '\0';
    const char *optarg = NULL;
    int target_value = 0;

    apr_pool_t *p = NULL;
    apr_pool_initialize();
    apr_pool_create(&p, NULL);
    apr_getopt_t *opt;
    apr_status_t rv;

    rv = apr_getopt_init(&opt, p, argc, argv);
    while(apr_getopt(opt, "u:f:", &ch, &optarg) == APR_SUCCESS) {
        switch (ch) {
            case 'u':
                target_value = atoi(optarg);
                print_primes_up_to(target_value);
                break;

            case 'f':
                target_value = atoi(optarg);
                print_prime_factors_for(target_value);
                break;
        }

    }
    return 0;
}
