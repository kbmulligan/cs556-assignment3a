// rsa.cpp - implements RSA asymmetric encryption algorithm

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cassert>
#include <ctime>
#include <gmp.h>
#include <gmpxx.h>

#ifndef RSAHOMEBREW
#include "rsa.h"
#endif

using namespace std;


LargeInt getLargePrime (void) {
    srand(time(NULL));
    LargeInt lp = rand(); 
    return lp;
}

LargeInt totient (LargePrime p, LargePrime q) {
     LargeInt phi = (p - 1) * (q - 1);
     return phi;
}

LargeInt selectE (LargeInt totient_n) {
    LargeInt e = rand() % totient_n;
    while (!validE(e, totient_n)) {
        e = selectE(totient_n); 
    }
    return e;
}

bool validE(LargeInt e, LargeInt totient_n) {
   
    // check for any common factors that are primes
    // if there are any, then e is not valid

    return true; 
}

LargeInt findD (LargeInt e, LargeInt totient_n) {
    LargeInt d = 0;


    // iterate from i to find d that satisfies 
    //                    i * e mod totient n == 1
    for (LargeInt i = 0; i < totient_n; i++) {
        if (i * e % totient_n == 1) {
            d = i;
            break;
        }
    }
    return d;
}

RSAKey generateRSAKey (void) {
    RSAKey key;

    cout << "Getting large primes..." << endl;
    LargePrime p = getLargePrime();
    LargePrime q = getLargePrime();

    LargeInt n = p * q;

    
    cout << "Calculating totient..." << endl;
    LargeInt phi_of_n = totient(p, q);

    cout << "Selecting e..." << endl;
    LargeInt e = selectE(phi_of_n); 

    cout << "Finding d..." << endl;
    LargeInt d = findD(e, phi_of_n);

    return key;
}


Message runRSA (void) {
    Message msg;

    return msg;
}

void doTests (void) {
    cout << "getLargePrime(): " << getLargePrime() << endl;
    testGMP();
    return;
}

void testGMP (void) {

    cout << "GMP: " << endl;
    mpz_t n;
    mp_bitcnt_t bits;


    mpz_init(n);


    unsigned long int m = 123;
    mpz_set_ui(n, m);

    cout << "N = " << n << endl;


    mpz_clear(n);
    return;
}

