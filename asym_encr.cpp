// asym_encr.cpp - encrypts RSA

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cassert>

#ifndef RSAHOMEBREW
#include "rsa.h"
#endif

using namespace std;



int main (void) {


    cout << "RSA: ENCRYPT............" << endl;

    cout << "Testing..." << endl;
    doTests();

    RSAKey key = generateRSAKey();    

    cout << "Key pair generated." << endl;
    cout << "Public: " << key.publicKey.e << endl;
    cout << "Private: " << key.privateKey.d << endl;


    cout << "RSA: ENCRYPT complete..." << endl;


    return EXIT_SUCCESS;
}
