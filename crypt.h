// crypt.h - includes all declarations for crypto code

// BITMASKS
const char ONE = 0x01;
const char TWO = 0x02;
const char THREE = 0x04;
const char FOUR = 0x08;
const char FIVE = 0x10;
const char SIX = 0x20;
const char SEVEN = 0x40;
const char EIGHT = 0x80;


// FUNCTION DECLARATIONS
char encryptChar (char m, char k);

int openFileForRead (std::string filename);
int closeFile (std::fstream);

std::string getKey (void);
std::string sanitizeKey (std::string key);
std::string cutKeyToLength (std::string key, unsigned int length);
std::string removeDuplicateChars (std::string x);
bool keyIsValid (std::string key);
bool hasNoDuplicates (std::string key);

int processArgs (int count, char* argv[]);
std::string requestFilename (void);

void printHex (char c);



int getNthBit (char c, int bit);

int doTests (void);
