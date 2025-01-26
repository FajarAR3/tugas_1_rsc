#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#define MAX_CONTACT 8
#include "contact.h"

class PhoneBook {

    public:
    // CONSTRUCTOR
    PhoneBook(); // mengisi PhoneBook dengan kontak default

    // MUTATOR
    void tambahKontak(Contact kontak_baru); 
    // menambah kontak spesifik dengan cara mengganti kontak default tertentu pada PhoneBook
    void hapusKontak(string nama_kontak);
    // menghapus kontak spesifik dengan cara mengubahnya ke kontak default
    void lihatSortedBy(int sortBy, int ascending);
    // print kontak-kontak pada PhoneBook terurut berdasarkan:
    // 0 = waktu/urutan masuk kontak
    // 1 = berdasarkan nama
    // ascending = 1 : terurut membesar
    // asceding = 0 : terurut mengecil
    const Contact& search(string nama); // searching kontak by nama
    
    private:
    Contact kontak[MAX_CONTACT]; // array of Contact, array ini digunakan untuk keperluan output berdasarkan waktu
    Contact displaying_purposed_kontak[MAX_CONTACT]; // array of Contact untuk keperluan output selain berdasarkan waktu
    int head; // menunjukkan indeks kontak terlama yang ditambahkan
    int tail; // menunjukkan indeks kontak terbaru
    
};

#endif 