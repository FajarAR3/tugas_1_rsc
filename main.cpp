#include "phonebook.h"

int main(){

    PhoneBook phone_book = PhoneBook();
    Contact fajar = Contact("Fajar Asyraf R", "Bandung", "Taman Sari", "Electro");
    Contact dinda = Contact("Adinda Putri", "Lampung", "Badak Singa", "Informatics");
    Contact vian = Contact("Afif Zalfaa Pavian", "Semarang", "Tubagus Ismail", "Electro");

    phone_book.tambahKontak(fajar);
    phone_book.tambahKontak(dinda);
    phone_book.tambahKontak(vian);
    phone_book.lihatSemuaNamaKontak();
    phone_book.hapusKontak("Adinda Putri");
    phone_book.lihatSemuaNamaKontak();

    return 0;
}