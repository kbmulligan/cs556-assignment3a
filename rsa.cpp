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

void printLargeInt (LargeInt x) {
    char* str_x;
    str_x = (char*)malloc(mpz_sizeinbase(x, BASE) + 2);
    cout << mpz_get_str(str_x, BASE, x) << endl;
    free(str_x);
}

void getLargePrime (LargeInt putItHere) {
    srand(time(NULL));
    unsigned long largeNum = rand(); 
   
    LargeInt lp;
    mpz_init(lp); 
    mpz_set_ui(lp, largeNum);
    mpz_nextprime(lp, lp);
    mpz_set(putItHere, lp);

    return;
}

void totient (LargeInt totientx, LargeInt p, LargeInt q) {

     // cout << "Started totient function..." << endl;

     LargeInt product, p1, q1;
     mpz_init(product);
     mpz_init(p1);
     mpz_init(q1);

     // cout << "Initialized vars ..." << endl;

     mpz_set(p1, p);
     mpz_set(q1, q);
     mpz_sub_ui(p1, p1, 1);
     mpz_sub_ui(q1, q1, 1);
 
     // cout << "Multiplying p-1 and q-1 ..." << endl;

     mpz_mul(product, (p1 - 1),  (q1 - 1));
     mpz_set(totientx, product);
     return;
}

void selectE (LargeInt e, LargeInt totient_n) {
    LargeInt initial, step;
    mpz_init(initial);
    mpz_init(step);
    mpz_set_ui(step, (unsigned long)1);
    mpz_sub(initial, totient_n, step);
    mpz_set(e,initial);
    while (!validE(e, totient_n)) {
        mpz_sub(e, e, step); 
    }
    return;
}

bool validE(LargeInt e, LargeInt totient_n) {
    bool result = false;
  
    // check for any common factors that are primes
    // if there are any, then e is not valid
    LargeInt common;
    mpz_init(common);
    mpz_gcd(common, e, totient_n);

    if (mpz_cmp_ui(common, 1) == 0) {
        result = true;
    } else {
        result = false;
    }
    return result; 
}

void findD (LargeInt d, LargeInt e, LargeInt totient_n) {

    //  find d that satisfies:   i * e mod totient n == 1
    
    return;
}

RSAKey generateRSAKey (void) {
    RSAKey key;

    cout << "Getting large primes..." << endl;
    LargePrime p, q, n;
    mpz_init(p);
    mpz_init(q);
    mpz_init(n);
    getLargePrime(p);
    getLargePrime(q);

    mpz_mul(n, p, q);

    cout << "p:" << endl;
    printLargeInt(p);
    cout << "q:" << endl;
    printLargeInt(q);
    cout << "n:" << endl;
    printLargeInt(n);
    
    cout << "Calculating totient..." << endl;
    LargeInt phi_of_n;
    mpz_init(phi_of_n);
    totient(phi_of_n, p, q);
    printLargeInt(phi_of_n);

    cout << "Selecting e..." << endl;
    LargeInt e;
    mpz_init(e);
    selectE(e, phi_of_n); 
    printLargeInt(e);

    cout << "Finding d..." << endl;
    LargeInt d;
    mpz_init(d);
    findD(d, e, phi_of_n);
    printLargeInt(d);

    return key;
}


void runRSA (LargeInt result, LargeInt base, LargeInt exponent, LargeInt modulus) {
    mpz_powm(result, base, exponent, modulus);
    return;
}

void doTests (void) {

    cout << "Testing..." << endl;

    testGLP();
    testGMP();
    testRSA();

    return;
}

void testRSA (void) {

     
    return;
}

void testGLP (void) {
    LargePrime lp;
    mpz_init(lp);
    getLargePrime(lp);
    cout << "getLargePrime(): " << lp << endl;
    return;
}

void testGMP (void) {
    
    cout << "Testing GMP ... " << endl;
    mpz_t n;
    mp_bitcnt_t bits;


    mpz_init(n);


    unsigned long int m = 123;
    mpz_set_ui(n, m);

    cout << "N = " << n << endl;


    mpz_clear(n);
    return;
}

// FILE FUNCTIONS ///////////////////////////////
string readStringFromFile (string filename) {
    string text(0, '.');

    ifstream inputFile (filename.c_str(), ios::in);

    if (inputFile.is_open()) {
        // cout << endl << "File opened for read..." << endl;

        char c;
        while (inputFile.get(c)) {
            //cout << c;
            text += c;
        }
        //cout << endl;

        // cout << "Contents:" << endl;
        // cout << text << endl;

    } else {
        cout << "Failed to open file!!!!!!!" << filename << endl;
    }

    inputFile.close();
    // cout << "Input file closed." << endl;

    return text;
}


int writeStringToFile (string filename, string data) {
    ofstream outputFile (filename.c_str(), ios::out); 

    if (outputFile.is_open()) {
        // cout << endl << "File opened for write..." << endl;

        for (unsigned int i = 0; i < data.length(); i++ ) {
            outputFile.put(data[i]);
        }
        
    } else {
        cout << "Failed to open file!!!!!!!" << filename << endl;
    }

    outputFile.close();
    // cout << "Output file closed." << endl;

    return 0;
}

string convertStringToNumberString(string text) {
    string str();

    return str;
}
