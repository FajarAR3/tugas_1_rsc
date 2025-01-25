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
    void lihatSortedBy(int sortBy, int ascending);
    
    private:
    Contact* kontak[MAX_CONTACT];
    Contact* displaying_purposed_kontak[MAX_CONTACT];
    int head;
    int tail;
    
};

#endif 