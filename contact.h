#ifndef CONTACT_H
#define CONTACT_H

#include <string>
using namespace std;

class Contact {

    public:
    // CONTRUCTOR
    Contact(string param_nama, string param_tempat_tinggal, string param_alamat, string param_kekuatan);

    // ACCESSOR
    const string& getNama() const;
    const string& getTempatTinggal() const;
    const string& getAlamat() const;
    const string& getKekuatan() const;

    // MUTATOR
    void setNama(string nama_baru);
    void setTempatTinggal(string tempat_tinggal_baru);
    void setAlamat(string alamat_baru);
    void setKekuatan(string kekuatan_baru);

    private:
    string nama;
    string tempat_tinggal;
    string alamat;
    string kekuatan;
};

#endif