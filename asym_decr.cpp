// asym_decr.cpp - decrypts RSA

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cassert>

#ifndef RSAHOMEBREW
#include "rsa.h"
#endif

using namespace std;

string fn1("file3");
string fn2("file4");
string fnplain("kevin-mulligan.plaintext");

int main (void) {


    cout << "RSA: DECRYPT............" << endl;

    doTests();
    


    cout << "RSA: DECRYPT complete..." << endl;


    return EXIT_SUCCESS;
}
