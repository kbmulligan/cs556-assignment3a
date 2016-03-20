// encrypt.c - demonstrates a vigenere cipher and a transposition cipher 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


const bool CL_ARGS = false;


const int ALPHABET_LENGTH = 26;

const char ENCRYPTED_FILENAME[] = "kevin-mulligan-encrypted-str";
const char DECRYPTED_FILENAME[] = "kevin-mulligan-decrypted-str";

char fileToEncrypt[] = "default-file";

const int KEY_LENGTH = 10;
char key1[] = "KEYONEKEYO";
char key2[] = "KEYTWOKEYT";



char encryptChar (char m, char k);

FILE* openFileForRead (const char* filename);
FILE* openFileForWrite (const char* filename);
int closeFile (FILE* pFile);

const char* getKey (char * keyBuffer);
int processArgs (int count, char* argv[]);

// HELPER FUNCTIONS /////////////////////////

char encryptChar (char m, char k) {
    char c = 0;
    
    c = (m + k) % ALPHABET_LENGTH;

    return c;
}


FILE* openFileForRead (const char* filename) {
    FILE* pFile = NULL;

    pFile = fopen(filename, "rb");
    if (pFile != NULL) {
        puts("File opened for read...");




    }
    return pFile;
}


FILE* openFileForWrite (const char* filename) {
    FILE* pFile = NULL;

    pFile = fopen(filename, "wb");
    if (pFile != NULL) {
        puts("File opened for write...");




        // fclose(pFile);
    }
    return pFile;
}

int closeFile (FILE* pFile) {
    fclose(pFile);
    return 0;
}


const char* getKey(char* keyBuffer) {
    puts("Enter key: ");
    printf("keyBuffer length before input is: %d\n", (int)sizeof(keyBuffer));
    fgets(keyBuffer, sizeof(keyBuffer), stdin);
    printf("keyBuffer length after input is: %d\n", (int)sizeof(keyBuffer));
    return keyBuffer;
}
 
int processArgs(int count, char* argv[]) {

    return 0;
}

int main (int argc, char* argv[]) {
    printf("Encrypt..................\n");

    FILE* fileInput = NULL;
    FILE* fileOutput = NULL;


    // get keys and filename
    if (CL_ARGS) {
        processArgs(argc, argv);    
    } else {
        char keyBuffer[64];
        
        printf("sizeof keyBuffer is : %d\n", (int)sizeof(keyBuffer));

        strncpy(key1, getKey(keyBuffer), strlen(key1));
        strncpy(key2, getKey(keyBuffer), strlen(key2));
    }

    printf("key1 length is : %d\n", (int)strlen(key1));
    printf("key2 length is : %d\n", (int)strlen(key2));
    puts(key1);
    puts(key2);

    assert(strlen(key1) == KEY_LENGTH);
    assert(strlen(key2) == KEY_LENGTH);

    fileInput = openFileForRead(fileToEncrypt);
    closeFile(fileInput);

    fileOutput = openFileForWrite(ENCRYPTED_FILENAME);
    closeFile(fileOutput);


    exit(0);
}
