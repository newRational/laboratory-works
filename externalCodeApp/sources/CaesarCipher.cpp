#include "CaesarCipher.h"

CaesarCipher::CaesarCipher(string &key, LANGUAGE language) : offset(key.size()), language(language) {

    cell russian(RUSSIAN, "абвгдежзиклмнопрстуфхцчшщъыьэюя");
    cell english(ENGLISH, "abcdefghijklmopqrstuvwxyz");
    cell deutsch(DEUTSCH, "aäbcdefghijklmnoöpqrsßtuüvwxyz");

    alphabets += russian;
    alphabets += english;
    alphabets += deutsch;
}

char CaesarCipher::findAssociatedSymbolEncrypt(int indexOfCurrentSymbol) {
    string alphabet = alphabets[language];

    int indexOfAssociatedSymbol = (indexOfCurrentSymbol + offset) % language;
    char associatedSymbol = alphabet[indexOfAssociatedSymbol];

    return associatedSymbol;
}

char CaesarCipher::findAssociatedSymbolDecrypt(int indexOfCurrentSymbol) {
    string alphabet = alphabets[language];

    int indexOfAssociatedSymbol = (indexOfCurrentSymbol - offset + language) % language;
    char associatedSymbol = alphabet[indexOfAssociatedSymbol];

    return associatedSymbol;
}

string CaesarCipher::encrypt(string &original) {
    for (int i = 0; i < original.size(); i++)
        original[i] = findAssociatedSymbolEncrypt(i);

    return original;
}

string CaesarCipher::decrypt(string &encrypted) {
    for (int i = 0; i < encrypted.size(); i++)
        encrypted[i] = findAssociatedSymbolDecrypt(i);

    return encrypted;
}

LANGUAGE CaesarCipher::getLanguage() const {
    return language;
}

int CaesarCipher::getOffset() const {
    return offset;
}