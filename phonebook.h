#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#define MAX_CONTACT 8
#include "contact.h"

class PhoneBook {

    public:
    // CONSTRUCTOR
    PhoneBook();

    // MUTATOR
    void tambahKontak(Contact& kontak_baru);
    void hapusKontak(string nama_kontak);
    void lihatSemuaNamaKontak() const;
    void printElmtpertama() const;
    
    private:
    Contact* kontak[MAX_CONTACT];
    int head;
    int tail;
    
};

#endift stat