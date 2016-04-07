// rsa.h - 

#include <string>
#include <gmp.h>
#include <gmpxx.h>

#ifndef RSAHOMEBREW
#define RSAHOMEBREW
#endif

const int KEYLENGTH = 4096;
const int BASE = 10;

typedef mpz_t LargePrime;
typedef mpz_t LargeInt;

typedef struct _RSAPublicKey {
    LargeInt e;
    LargeInt n;
} RSAPublicKey;

typedef struct _RSAPrivateKey {
    LargeInt d;
    LargeInt n;
} RSAPrivateKey;

typedef struct _RSAKey {
    RSAPublicKey publicKey;
    RSAPrivateKey privateKey;
} RSAKey;

typedef std::string Message;

bool validE(LargeInt e, LargeInt totient_n);
RSAKey generateRSAKey (void);
void runRSA (LargeInt result, LargeInt base, LargeInt exponent, LargeInt modulus);
void doTests (void);
void testGMP (void);
void testGLP (void);
void testRSA (void);


void getLargePrime (LargeInt putItHere);
void printLargeInt (LargeInt x);


std::string readStringFromFile (std::string filename);
int writeStringToFile (std::string filename, std::string data);
