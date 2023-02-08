#include "AccountsService.h"

#include <cstring>
#include <iostream>
#include "CaesarCipher.h"

AccountsService::AccountsService(string &keyForCipher) {
    cipher = CaesarCipher(keyForCipher);
}

AccountsService::AccountsService(Cipher &cipher) : cipher(cipher) {}

void AccountsService::addEntry(string &address, string &password) {
    cell newAddress(addresses.getSize(), address.c_str());
    cell newPassword(passwords.getSize(), cipher.encrypt(password).c_str());

    addresses += newAddress;
    passwords += newPassword;
}

void AccountsService::deleteEntry(string &address) {
    int id = findIdByAddress(address);

    addresses -= id;
    passwords -= id;
}

string &AccountsService::findAddress(int id) {
    string address = addresses[id];
    return address;
}

int AccountsService::findIdByAddress(string &address) {
    for (int i = 0; i < addresses.getSize(); i++)
        if (!strcmp(address.c_str(), addresses[i]))
            return i;

    throw invalid_argument("no such address");
}

string &AccountsService::findPassword(int id) {
    string password = passwords[id];
    return password;
}

string &AccountsService::findPassword(string &address) {
    int id = findIdByAddress(address);
    string password = passwords[id];
    return password;
}

table &AccountsService::findAllAddresses() {
    return addresses;
}

bool AccountsService::contains(string &address) {
    try {
        findIdByAddress(address);
        return true;
    } catch (invalid_argument e) {
        return false;
    }
}

int AccountsService::getSize() {
    return addresses.getSize();
}

ostream &operator << (ostream &os, AccountsService &ac) {
    for (int i = 0; i < ac.getSize(); i++)
        cout << ac.addresses[i] << "\t" << ac.passwords[i] << endl;
}
