// decrypt.c - demonstrates a vigenere cipher and a transposition cipher 
//             This program decrypts the file ENCRYPTED_FILENAME and
//             stores the decrypted binary data in DECRYPTED_FILENAME.
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


// FUNCTION SIGNATURES //////////////////////////


// HELPER FUNCTIONS /////////////////////////////
char encryptChar (char m, char k) {
    char c = 0;
    
    c = (m + k) % ALPHABET_LENGTH;

    return c;
}

string encryptGroup (char* plain, char* key, int bits, int keyLength) {
    string ciphertext(bits/BITS_PER_BYTE, '.');
    //const char* c = "" ;
    

    return ciphertext;
}

int openFileForRead (string filename) {
    return 0;
}

int closeFile (fstream file) {
    file.close();
    return 0;
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

// TESTS ////////////////////////////////////////

// MAIN /////////////////////////////////////////////////////////////
int main (int argc, char* argv[]) {
    printf("DECRYPT..................\n");

    vector<unsigned char> plaintext(100, 0);
    vector<unsigned char> ciphertext(100, 0);



    cout << "Sizeof(char) = " << sizeof(char) << endl;

    doTests();

    // get keys and filename
    if (CL_ARGS) {
        processArgs(argc, argv);    
    } else {
        key1 = getKey();
        key2 = getKey();
    }

    printf("key1 length is : %d\n", (int)key1.length());
    printf("key2 length is : %d\n", (int)key2.length());
    cout << "Key1 is: " << key1 << endl;
    cout << "Key2 is: " << key2 << endl;

    assert(key1.length() == KEY_LENGTH);
    assert(key1.length() == KEY_LENGTH);
    cout << "GOOD KEYS!" << endl;
    

    int fileSizeInput = getFileSize(ENCRYPTED_FILENAME);
    string ctext(0, '.');

    ifstream inputFile (ENCRYPTED_FILENAME.c_str(), ios::in | ios::binary);

    if (inputFile.is_open()) {
        cout << endl;
        cout << endl << "File opened for read..." << endl;
        cout << fileSizeInput << endl;
        cout << "CONTENTS OF INPUT FILE:" << endl;
        char c;
        while (inputFile.get(c)) {
            cout << c;
            ctext += c;
        }
        cout << endl;
        cout << ctext << endl;

    } else {
        cout << "Failed to open file!!!!!! " << ENCRYPTED_FILENAME << endl;
    }


    string pText(vigenereCipher(ctext, key1));

    cout << "Plaintext length = " << pText.length() << endl;
    cout << pText << endl;


    writeStringToFile(DECRYPTED_FILENAME, pText);



    inputFile.close();
    cout << "Input file closed." << endl;

    exit(EXIT_SUCCESS);
}
