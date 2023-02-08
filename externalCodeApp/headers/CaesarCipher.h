#ifndef EXTERNALCODEAPP_CAESARCIPHER_H
#define EXTERNALCODEAPP_CAESARCIPHER_H

#include "Cipher.h"
#include "library.h"

enum LANGUAGE {
    RUSSIAN = 33, ENGLISH = 26, DEUTSCH = 30
};

class CaesarCipher : public Cipher {
private:
    const LANGUAGE language;
    const int offset;
    table alphabets;

    char findAssociatedSymbolEncrypt(int indexOfCurrentSymbol);
    char findAssociatedSymbolDecrypt(int indexOfCurrentSymbol);

public:
    explicit CaesarCipher(string &key, LANGUAGE language = ENGLISH);

    string encrypt(string &original) override;
    string decrypt(string &encrypted) override;

    LANGUAGE getLanguage() const;
    int getOffset() const;
};

#endif
