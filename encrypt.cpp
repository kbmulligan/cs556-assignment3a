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


using namespace std;



const bool CL_ARGS = false;
const int BITS_PER_BYTE = 8;
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
string cutKeyToLength (string key, unsigned int length);
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

string vigenereCipher(string ptext, string key1, string key2) {
   string ctext("");
   cout << "Starting Vigenere cipher..." << endl;

   cout << "Length key1: " << key1.length() << endl;
   cout << "Length plaintext: " << ptext.length() << endl;
   cout << "Bits plaintext: " << ptext.length()*BITS_PER_BYTE << endl;

   for (unsigned int i = 0; i < ptext.length(); i += key1.length()) {
       cout << ptext.substr(i, key1.length()) << endl;
       cout << key1 << endl;
       
       for (unsigned int j = 0; j < key1.length(); j++) {
           char cipherGroup = ptext[i+j]^key1[j];
           //cout << "0x" << hex << (int)(cipherGroup) << " "; 
           cout << (int)(cipherGroup) << " "; 
           ctext += cipherGroup;
       }
       cout << endl;
   }

   
   return ctext;
}

// TESTS ////////////////////////////////////////
int doTests (void) {
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

// MAIN /////////////////////////////////////////////////////////////
int main (int argc, char* argv[]) {
    printf("Encrypt..................\n");

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
    

    int fileSizeInput = getFileSize(fileToEncrypt);
    string ptext(0, '.');

    ifstream inputFile (fileToEncrypt.c_str(), ios::in | ios::binary);

    if (inputFile.is_open()) {
        cout << endl;
        cout << endl << "File opened for read..." << endl;
        cout << fileSizeInput << endl;
        cout << "CONTENTS OF INPUT FILE:" << endl;
        char c;
        while (inputFile.get(c)) {
            cout << c;
            ptext += c;
        }
        cout << endl;
        cout << ptext << endl;

    } else {
        cout << "Failed to open file!!!!!! " << fileToEncrypt << endl;
    }


    string intermediateText(vigenereCipher(ptext, key1, key2));

    cout << "V-Ciphertext length = " << intermediateText.length() << endl;
    cout << intermediateText << endl;



    ofstream outputFile (ENCRYPTED_FILENAME.c_str(), ios::out | ios::binary);

    if (outputFile.is_open()) {
        cout << endl;
        cout << endl << "File opened for write..." << endl;
        cout << endl;

        for (unsigned int i = 0; i < intermediateText.length(); i++ ) {
            outputFile.put(intermediateText[i]);
        }
        
    } else {
        cout << "Failed to open file!!!!!! " << ENCRYPTED_FILENAME << endl;
    }

    inputFile.close();
    cout << "Input file closed." << endl;
    outputFile.close();
    cout << "Output file closed." << endl;

    exit(EXIT_SUCCESS);
}
