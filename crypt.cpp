// crypt.cpp - this file contains the code for a Vigenere cipher and
//             a double columnar transposition cipher

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <vector>
#include <sys/stat.h>
#include <iomanip>
#include <algorithm>

#ifndef CRYPT 
#include "crypt.h"
#endif

using namespace std;


// UTILITY HELPERS //////////////////////////////
int getNthBit (char c, int bit) {
    int nthBit = -1;

    char result = c & bit;
  
    if (result > 0) {
        nthBit = 1;
    } else {
        nthBit = 0;
    }

    return nthBit;
}





// TESTS ////////////////////////////////////////
int doTests (void) {

    //cout << "Sizeof(char) = " << sizeof(char) << endl;

    cout << "Testing string methods..." << endl;

    assert(removeDuplicateChars(string("aabbbcdefghiiiijjkkl"))
            == string("abcdefghijkl"));
    assert(sanitizeKey(string("aabbbcdefghiiiijjkkl"))
            == string("abcdefghij"));
    assert(sanitizeKey(string("abcdefghijkl")) == string("abcdefghij"));
    assert(keyIsValid(string("abcdefghij")) == true);
    
    cout << "All string tests passed!" << endl;
    return 0;
}

int testTransposition (void ) {

    cout << "Testing transposition functions..." << endl;

    vector<char> key;
    string tester("This is a test string.");
    for (unsigned int i = 0; i < tester.length(); i++) {
        key.push_back(tester[i]);
    } 

    printVector(key);
    sort(key.begin(), key.end());
    printVector(key);

    return 0;
}

void printVector (vector<char> vec) {
    for (vector<char>::const_iterator i = vec.begin(); i != vec.end(); ++i)
        cout << *i << ' ';
    cout << endl;
}

// KEY FUNCTIONS ////////////////////////////////
string getKey() {
    cout << "Enter key: " << endl;
    string keyBuffer(MAX_KEYLENGTH, '.');
    cin >> keyBuffer;
    //cout << "keyBuffer now containts:" << keyBuffer << endl;

    string key(sanitizeKey(keyBuffer));

    if (key.length() < KEY_LENGTH) {
        cout << "Please enter longer key." << endl;
        key = getKey();
    }

    return key;
}

// FILE FUNCTIONS ///////////////////////////////
string readStringFromFile (string filename) {
    string text(0, '.');

    ifstream inputFile (filename.c_str(), ios::in | ios::binary);

    if (inputFile.is_open()) {
        cout << endl << "File opened for read..." << endl;

        char c;
        while (inputFile.get(c)) {
            //cout << c;
            text += c;
        }
        //cout << endl;

        cout << "Contents:" << endl;
        cout << text << endl;

    } else {
        cout << "Failed to open file!!!!!! " << filename << endl;
    }

    inputFile.close();
    cout << "Input file closed." << endl;

    return text;
}


int writeStringToFile (string filename, string data) {
    ofstream outputFile (filename.c_str(), ios::out | ios::binary);

    if (outputFile.is_open()) {
        cout << endl << "File opened for write..." << endl;

        for (unsigned int i = 0; i < data.length(); i++ ) {
            outputFile.put(data[i]);
        }
        
    } else {
        cout << "Failed to open file!!!!!! " << filename << endl;
    }

    outputFile.close();
    cout << "Output file closed." << endl;

    return 0;
}


// VIGENERE /////////////////////////////////////

string vigenereCipher(string ptext, string key) {
   string ctext("");
   cout << "Starting Vigenere cipher..." << endl;

   cout << "Length key: " << key.length() << endl;
   cout << "Length input text: " << ptext.length() << endl;
   cout << "Bits input text: " << ptext.length() * BITS_PER_BYTE << endl;

   for (unsigned int i = 0; i < ptext.length(); i += key.length()) {
       cout << ptext.substr(i, key.length()) << endl;
       cout << key << endl;
       
       unsigned int limit = 0;
       if (i + key.length() > ptext.length()) {
           limit = ptext.length() - i;
       } else {
           limit = key.length();
       }

       for (unsigned int j = 0; j < limit; j++) {
           
           // XOR key char with plaintext char and call it cipherGroup
           char cipherGroup = ptext[i+j] ^ key[j];
           
           //cout << "0x" << hex << (int)(cipherGroup) << " "; 
           // echo the cipher group
           printHex(cipherGroup);

           // append this to the overall ciphertext
           ctext += cipherGroup;
       }
       cout << endl;
   }

   
   return ctext;
}

// TRANSPOSITION ////////////////////////////////
string colTranspositionCipher(string ptext, string key) {

    return string();
}
