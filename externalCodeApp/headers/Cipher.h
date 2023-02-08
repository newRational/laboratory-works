#ifndef EXTERNALCODEAPP_CIPHER_H
#define EXTERNALCODEAPP_CIPHER_H

#include <string>

using namespace std;

class Cipher {
protected:
    string key;

public:
    Cipher(string key = "");
    virtual string encrypt(string &original);
    virtual string decrypt(string &encrypted);
};

#endif
