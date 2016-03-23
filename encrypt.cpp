// encrypt.c - demonstrates a vigenere cipher and a transposition cipher 
//             This file encrypts data from a given file and stores it
//             in ENCRYPTED_FILENAME.
// 
// Author: kbmulligan
// Date: March 2016
// CSU CS556
// Dr. Ray

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <vector>
#include <sys/stat.h>
#include <iomanip>

#ifndef CRYPT 
#include "crypt.h"
#endif

using namespace std;


const bool CL_ARGS = false;

string ENCRYPTED_FILENAME("kevin-mulligan-encrypted-str");
string DECRYPTED_FILENAME("kevin-mulligan-decrypted-str");

string fileToEncrypt("default-file");

string key1 = "KEYONEKEYO";
string key2 = "KEYTWOKEYT";



// HELPER FUNCTIONS /////////////////////////////



// ask user for filename
string requestFilename (void) {
    string filenameBuffer(MAX_FILENAME_LENGTH, '.');
    cout << "Enter filename of file to be encrypted: ";
    cin >> filenameBuffer;

    return filenameBuffer;
}


string sanitizeKey (string key) {
    string sanitized(key);
    sanitized = removeDuplicateChars(sanitized);
    sanitized = cutKeyToLength(sanitized, (unsigned int)KEY_LENGTH); 
    return sanitized;
}

string cutKeyToLength (string key, unsigned int length) {
    string cutKey(key);
    if (key.length() > length) {
       cutKey = cutKey.substr(0, length); 
    }    
    return cutKey;
}
 
string removeDuplicateChars (string x) {
    string newString (x, 0, 1);

    //cout << "Removing duplicates" << endl;
    //cout << x << endl;
 
    for (unsigned int i = 1; i < x.length(); i++) {
        size_t found = newString.find(x[i]);
        if (found != string::npos) {
            //cout << x[i] << " found at: " << found << '\n';
            ;
        } else {
            //cout << "Adding this to the newString..""" << endl;
            newString += x[i];    
        }
    }
    
    //cout << newString << endl;

    return newString;
}

bool keyIsValid (string key) {
    bool valid = false;
    if (key.length() == KEY_LENGTH && hasNoDuplicates(key)) {
        valid = true;
    }
    return valid;
}

bool hasNoDuplicates (string key) {
    
    for (unsigned int i = 0; i < key.length(); i++) {
        ;    
    }
 
    return true;
}

int processArgs(int count, char* argv[]) {

    return 0;
}

long getFileSize(string filename)
{
    long size = -1;
    struct stat stat_buffer;
    int status = stat(filename.c_str(), &stat_buffer);
    if (status == 0) {
        size = stat_buffer.st_size;
    } else {
        size = -1;
    }
    return size;
}


void printHex (char c) {

           cout << hex;
           cout << "0x";

           // padding 0 if less than 0x10
           if (c < 0x10) {
               cout << "0";
           }

           cout << (int)(c) << " "; 
           cout << dec;

}



// MAIN /////////////////////////////////////////////////////////////
int main (int argc, char* argv[]) {
    printf("ENCRYPT..................\n");

    doTests();
    testTransposition();

    // get keys and filename
    if (CL_ARGS) {
        processArgs(argc, argv);    
    } else {
        key1 = getKey();
        key2 = getKey();
        fileToEncrypt = requestFilename();
    }

    cout << "Key1 is: " << key1 << " -- LEN: " << (int)key1.length() << endl;
    cout << "Key2 is: " << key2 << " -- LEN: " <<  (int)key2.length() << endl;



    assert(keyIsValid(key1));
    assert(keyIsValid(key2));
    cout << "GOOD KEYS!" << endl;
    
    

    int fileSizeInput = getFileSize(fileToEncrypt);
    string ptext(0, '.');

    ptext = readStringFromFile(fileToEncrypt);


    string c1Text(vigenereCipher(ptext, key1));

    cout << "V-Ciphertext length = " << c1Text.length() << endl;
    cout << c1Text << endl;


    writeStringToFile(ENCRYPTED_FILENAME, c1Text);

    exit(EXIT_SUCCESS);
}
