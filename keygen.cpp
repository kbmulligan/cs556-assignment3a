// keygen.cpp - generates RSA keypair

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cassert>

#ifndef RSAHOMEBREW
#include "rsa.h"
#endif

using namespace std;

string fnpublic("kevin-mulligan.publickey");
string fnprivate("kevin-mulligan.privatekey");


int main (void) {


    cout << "RSA: KEYGEN............" << endl;

    doTests();

    RSAKey key = generateRSAKey();    

    cout << "Key pair generated." << endl;
    cout << "Public: " << endl;
    printLargeInt(key.publicKey.e);
    cout << "Private: " << endl;
    printLargeInt(key.privateKey.d);


    cout << "RSA: KEYGEN complete..." << endl;


    return EXIT_SUCCESS;
}
