all: encrypt decrypt

encrypt: encrypt.cpp crypt.cpp
	g++ -o encrypt encrypt.cpp crypt.cpp

decrypt: decrypt.cpp crypt.cpp
	g++ -o decrypt decrypt.cpp crypt.cpp
