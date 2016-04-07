// asym_encr.cpp - encrypts RSA

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cassert>

#ifndef RSAHOMEBREW
#include "rsa.h"
#endif

using namespace std;

string fn1("file1");
string fn2("file2");
string fncipher("kevin-mulligan.ciphertext");

int main (void) {


    cout << "RSA: ENCRYPT............" << endl;

    doTests();


    cout << fn1 << " contains :" << endl;
    cout << readStringFromFile(fn1) << endl;
    cout << fn2 << " contains :" << endl;
    cout << readStringFromFile(fn2) << endl;

    string rawstr(readStringFromFile(fn1));
    size_t index = rawstr.find(',');

    string publickey_str(rawstr.substr(0, index));
    string modulus_str(rawstr.substr(index+1));

    LargeInt publickey, modulus;
    mpz_init(publickey); 
    mpz_init(modulus); 
    
    mpz_set_str(publickey, publickey_str.c_str(), BASE);
    mpz_set_str(modulus, modulus_str.c_str(), BASE);

    printLargeInt(publickey);
    printLargeInt(modulus);


    LargeInt plaintext;
    mpz_init(plaintext);

    string plaintext_str(readStringFromFile(fn2));
    string plaintext_num_str(convertStringToNumberStr(plaintext_str));
    mpz_set_str(plaintext, plaintext_num_str.c_str(), BASE); 


    LargeInt ciphertext;
    mpz_init(ciphertext);
    runRSA(ciphertext, plaintext, publickey, modulus);


    


    cout << "RSA: ENCRYPT complete..." << endl;


    return EXIT_SUCCESS;
}
