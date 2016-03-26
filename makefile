all: encrypt decrypt asymmetrickey_encr asymmetrickey_decr

encrypt: encrypt.cpp crypt.cpp
	g++ -o encrypt encrypt.cpp crypt.cpp

decrypt: decrypt.cpp crypt.cpp
	g++ -o decrypt decrypt.cpp crypt.cpp


asymmetrickey_encr: rsa.cpp asym_encr.cpp
	g++ -o asymmetrickey_encr rsa.cpp asym_encr.cpp

asymmetrickey_decr: rsa.cpp asym_decr.cpp
	g++ -o asymmetrickey_decr rsa.cpp asym_decr.cpp
