// rsa.h - 

#include <string>

#ifndef RSAHOMEBREW
#define RSAHOMEBREW
#endif

typedef long LargePrime;

typedef struct _RSAPublicKey {
    long e;
    long n;
} RSAPublicKey;

typedef struct _RSAPrivateKey {
    long d;
    long n;
} RSAPrivateKey;

typedef struct _RSAKey {
    RSAPublicKey publicKey;
    RSAPrivateKey privateKey;
} RSAKey;

typedef std::string Message;

bool validE(long e, long totient_n);
RSAKey generateRSAKey (void);
Message runRSA (void);
