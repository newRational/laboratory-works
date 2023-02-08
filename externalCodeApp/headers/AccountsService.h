#ifndef EXTERNALCODEAPP_ACCOUNTSSERVICE_H
#define EXTERNALCODEAPP_ACCOUNTSSERVICE_H

#include <string>
#include <library.h>
#include "Cipher.h"

using namespace std;

class AccountsService {
private:
    table addresses;
    table passwords;

    Cipher cipher;
    int findIdByAddress(string &address);

public:
    explicit AccountsService(string &keyForCipher);
    explicit AccountsService(Cipher &cipher);

    void addEntry(string &address, string &password);
    void deleteEntry(string &address);

    string &findAddress(int id);
    string &findPassword(int id);
    string &findPassword(string &address);

    table &findAllAddresses();
    table &findAllAddressesByDomain(string &domain);
    table &findAllAddressesByCountryCode(string &countryCode);
    table *findAllAddressesPaginated(int cellsPerPage);

    void sortById();
    void sortByAddressName();
    void sortByAddressDomain();
    void sortByAddressCountryCode();
    void sortByAddressLength();

    bool contains(string &address);
    int getSize();

    friend ostream &operator << (ostream &, AccountsService &);
};

#endif
