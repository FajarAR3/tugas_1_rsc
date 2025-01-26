#include "contact.h"

// CONSTRUCTOR kontak default
Contact::Contact(){
    nama = "Belum ada informasi nama";
    tempat_tinggal = "Belum ada informasi tempat tinggal";
    alamat = "Belum ada informasi alamat";
    kekuatan = "Belum ada informasi kekuatan";
}

Contact::Contact(string param_nama, string param_tempat_tinggal, string param_alamat, string param_kekuatan) :
   nama(param_nama), tempat_tinggal(param_tempat_tinggal), alamat(param_alamat), kekuatan(param_kekuatan)
{
    // CONSTUCTOR
}

// ACCESSOR
const string& Contact::getNama() const {return nama;}
const string& Contact::getTempatTinggal() const {return tempat_tinggal;}
const string& Contact::getAlamat() const {return alamat;}
const string& Contact::getKekuatan() const {return kekuatan;}

// MUTATOR
void Contact::setNama(string nama_baru) {nama = nama_baru;}
void Contact::setTempatTinggal(string tempat_tinggal_baru) {tempat_tinggal = tempat_tinggal_baru;}
void Contact::setAlamat(string alamat_baru) {alamat = alamat_baru;}
void Contact::setKekuatan(string kekuatan_baru) {kekuatan = kekuatan_baru;}


