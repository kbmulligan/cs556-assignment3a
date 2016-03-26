// rsa.cpp - implements RSA asymmetric encryption algorithm

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cassert>
#include <ctime>

#ifndef RSAHOMEBREW
#include "rsa.h"
#endif

using namespace std;


LargePrime getLargePrime (void) {
    srand(time(NULL));
    LargePrime lp = rand(); 
    return lp;
}

long totient (LargePrime p, LargePrime q) {
     long phi = (p - 1) * (q - 1);
     return phi;
}

long selectE (long totient_n) {
    long e = rand() % totient_n;
    while (!validE(e, totient_n)) {
        e = selectE(totient_n); 
    }
    return e;
}

bool validE(long e, long totient_n) {
   
    // check for any common factors that are primes
    // if there are any, then e is not valid

    return true; 
}

long findD (long e, long totient_n) {
    long d = 0;


    // iterate from i to find d that satisfies 
    //                    i * e mod totient n == 1
    for (long i = 0; i < totient_n; i++) {
        if (i * e % totient_n == 1) {
            d = i;
            break;
        }
    }
    return d;
}

RSAKey generateRSAKey (void) {
    RSAKey key;

    LargePrime p = getLargePrime();
    LargePrime q = getLargePrime();

    long n = p * q;
    long phi_of_n = totient(p, q);
    long e = selectE(phi_of_n); 

    long d = findD(e, phi_of_n);

    return key;
}


Message runRSA (void) {
    Message msg;

    return msg;
}
