#include "phonebook.h"

int main(){

    PhoneBook phone_book = PhoneBook();
    Contact fajar = Contact("Fajar Asyraf R", "Bandung", "Taman Sari", "Electro");
    Contact dinda = Contact("Adinda Putri", "Lampung", "Badak Singa", "Informatics");
    Contact vian = Contact("Afif Zalfaa Pavian", "Semarang", "Tubagus Ismail", "Electro");
    Contact gifari = Contact("Ghipari", "Jakarta", "Tubis", "EL");
    Contact nadia = Contact("Nadia", "Buah batu", "bandung", "infor");

    phone_book.tambahKontak(fajar);
    phone_book.tambahKontak(dinda);
    phone_book.tambahKontak(vian);
    phone_book.tambahKontak(gifari);
    phone_book.tambahKontak(nadia);
    phone_book.lihatSortedBy(0, 1);
    phone_book.hapusKontak("Adinda Putri");
    phone_book.lihatSortedBy(1, 1);

    return 0;
}