// encrypt.c - demonstrates a vigenere cipher and a transposition cipher 

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

const bool CL_ARGS = false;

const int ALPHABET_LENGTH = 26;

string ENCRYPTED_FILENAME("kevin-mulligan-encrypted-str");
string DECRYPTED_FILENAME("kevin-mulligan-decrypted-str");

string fileToEncrypt("default-file");

const int KEY_LENGTH = 10;
string key1 = "KEYONEKEYO";
string key2 = "KEYTWOKEYT";


// FUNCTION SIGNATURES //////////////////////////
char encryptChar (char m, char k);

int openFileForRead (string filename);
int closeFile (fstream);

string getKey (void);
int processArgs (int count, char* argv[]);



// HELPER FUNCTIONS /////////////////////////////
char encryptChar (char m, char k) {
    char c = 0;
    
    c = (m + k) % ALPHABET_LENGTH;

    return c;
}


int openFileForRead (string filename) {
    return 0;
}

int closeFile (fstream file) {
    file.close();
    return 0;
}


string getKey() {
    cout << "Enter key: " << endl;
    string keyBuffer("PLACEHOLDER STRING HERE");
    cin >> keyBuffer;
    cout << "keyBuffer now containts:" << keyBuffer << endl;

    return keyBuffer;
}
 
int processArgs(int count, char* argv[]) {

    return 0;
}

int printFile(FILE* file) {

    return 0;
}

int main (int argc, char* argv[]) {
    printf("Encrypt..................\n");

    ifstream fileInput;


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
    



    ifstream inputFile (fileToEncrypt.c_str(), ios::in | ios::binary);

    if (inputFile.is_open()) {
        cout << "File opened for read..." << endl;
        cout << "CONTENTS OF INPUT FILE:" << endl;
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }

    } else {
        cout << "Failed to open file!!!!!!" << endl;
    }







    return 0;
}
