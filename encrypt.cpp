// encrypt.c - demonstrates a vigenere cipher and a transposition cipher 
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <vector>

#include <sys/stat.h>

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
string sanitizeKey (string key);
string removeDuplicateChars (string x);
bool keyIsValid (string key);
bool hasNoDuplicates (string key);
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

    return sanitizeKey(keyBuffer);
}

string sanitizeKey (string key) {
    string sanitized(key);
    sanitized = removeDuplicateChars(sanitized);
    
    return sanitized;
}
 
string removeDuplicateChars (string x) {
    string newString (x);
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


int main (int argc, char* argv[]) {
    printf("Encrypt..................\n");

    vector<unsigned char> plaintext(100, 0);
    vector<unsigned char> ciphertext(100, 0);



    cout << "Sizeof(char) = " << sizeof(char) << endl;

    cout << "Testing string methods..." << endl;
    //assert(sanitizeKey(string("aabbbcdefghiiiijjkkl")) == string("abcdefghij"));
    //assert(sanitizeKey(string("abcdefghijkl")) == string("abcdefghij"));
    assert(keyIsValid(string("abcdefghij")) == true);

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
        cout << endl;
        cout << endl << "File opened for read..." << endl;
        cout << getFileSize(fileToEncrypt) << endl;
        cout << "CONTENTS OF INPUT FILE:" << endl;
        char c;
        while (inputFile.get(c)) {
            cout << c;
        }
        cout << endl;

    } else {
        cout << "Failed to open file!!!!!! " << fileToEncrypt << endl;
    }








    ofstream outputFile (ENCRYPTED_FILENAME.c_str(), ios::out | ios::binary);

    if (outputFile.is_open()) {
        cout << endl;
        cout << endl << "File opened for write..." << endl;
        cout << endl;
    } else {
        cout << "Failed to open file!!!!!! " << ENCRYPTED_FILENAME << endl;
    }

    inputFile.close();
    cout << "Input file closed." << endl;
    outputFile.close();
    cout << "Output file closed." << endl;

    exit(EXIT_SUCCESS);
}
