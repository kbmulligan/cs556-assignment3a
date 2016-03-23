// crypt.cpp - this file contains the code for a Vigenere cipher and
//             a double columnar transposition cipher

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <vector>
#include <sys/stat.h>
#include <iomanip>
 
#include "crypt.h"



int getNthBit (char c, int bit) {
    int nthBit = -1;

    char result = c & bit;
  
    if (result > 0) {
        nthBit = 1;
    } else {
        nthBit = 0;
    }

    return nthBit;
}



int doTests (void) {
    std::cout << "Testing string methods..." << std::endl;

    assert(removeDuplicateChars(std::string("aabbbcdefghiiiijjkkl"))
            == std::string("abcdefghijkl"));
    assert(sanitizeKey(std::string("aabbbcdefghiiiijjkkl"))
            == std::string("abcdefghij"));
    assert(sanitizeKey(std::string("abcdefghijkl")) == std::string("abcdefghij"));
    assert(keyIsValid(std::string("abcdefghij")) == true);
    
    std::cout << "All string tests passed!" << std::endl;
    return 0;
}
