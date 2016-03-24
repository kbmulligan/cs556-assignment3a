// crypt.h - includes all declarations for crypto code
#define CRYPT

// BITMASKS
const char ONE = 0x01;
const char TWO = 0x02;
const char THREE = 0x04;
const char FOUR = 0x08;
const char FIVE = 0x10;
const char SIX = 0x20;
const char SEVEN = 0x40;
const char EIGHT = 0x80;

// CONSTANTS
const int BITS_PER_BYTE = 8;
const int ALPHABET_LENGTH = 26;
const int MAX_KEYLENGTH = 256;
const int MAX_FILENAME_LENGTH = 256;
const int KEY_LENGTH = 10;



// FUNCTION DECLARATIONS
std::string getKey (void);
std::string sanitizeKey (std::string key);
std::string cutKeyToLength (std::string key, unsigned int length);
std::string removeDuplicateChars (std::string x);
bool keyIsValid (std::string key);
bool hasNoDuplicates (std::string key);

int processArgs (int count, char* argv[]);
std::string requestFilename (void);

void printHex (char c);
void printVector (std::vector<char> vec);


int getNthBit (char c, int bit);

int doTests (void);
int testTransposition (void);


std::string readStringFromFile (std::string filename);
int writeStringToFile (std::string filename, std::string data);

std::string vigenereCipher(std::string ptext, std::string key);
std::string columnTxCipher(std::string ptext, std::string key);
std::string selectNthElements(std::string ptext, unsigned int nth, std::string key);
