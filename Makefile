PREFIX?=/usr/local
CFLAGS=-g -Wall -I${PREFIX}/apr/include/apr-1 -I${PREFIX}/apr/include/apr-util-1
LDFLAGS=-L${PREFIX}/apr/lib -lapr-1 -pthread -laprutil-1

primes: primes_up_to.o prime_factors_for.o array_access.o

primes_up_to: array_access.o

prime_factors_for: array_access.o
