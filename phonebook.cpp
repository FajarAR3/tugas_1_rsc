#include "phonebook.h"
#include <iostream>

Contact anonymous = Contact(); // untuk kontak default, place holder isi phonebook, dan sebagai representasi kontak yang belum diisi
// helping function untuk algoritma quicksort dan print nama sesuai kategori (waktu atau nama)
namespace {

    void lihatSemuaNamaKontak(Contact arr[], int head, int def){ //def = 1 berdasarkan waktu, def = 0 berdasarkan nama

        const int lebar_tabel = 100; // lebar tabel
        for (int i = 0; i < lebar_tabel;i++){
            cout <<"-";
        }
        cout << "\n";
        int idx_contact;
        if (def == 1){
            idx_contact = head;
        } else if (def == 0){
            idx_contact = 0;
        }
        int count = -1; // untuk print "Daftar Nama Kontak"
        while (count < MAX_CONTACT + 1){
            string to_be_printed;
            if (count == -1) {
                to_be_printed = "Daftar Nama Kontak";
            } else if (count == MAX_CONTACT){ // Kontak sudah diprint semua, menampilkan "Currenty sorted by"
                if (def == 1) {to_be_printed = "Currently sorted by time";}
                else if (def == 0) {to_be_printed = "Currently sorted by name";}
            }
            else {
                to_be_printed = arr[idx_contact].getNama();
            }

            if (head == -1 && count != -1){ // Jika kontak masih kosong
                to_be_printed = "Kontak Kosong";
            } else if (to_be_printed== "Belum ada informasi nama") // sudah ada kontak cek apakah current kontak sudah diisi
            { // jika masih kontak default, skip iterasi
                count++;
                idx_contact = (idx_contact+1)%MAX_CONTACT;
                continue;
            }

            bool isPanjangNamaGanjil = (to_be_printed.length() % 2 != 0);
            int half_string_length = to_be_printed.length() / 2;
            int half_output_width = lebar_tabel/2;
            int leading_spaces  = half_output_width - half_string_length;
            cout << "|";
            for (int i = 0; i < leading_spaces-1;i++){
                cout << " ";
            }
            cout << to_be_printed;
            
            if (isPanjangNamaGanjil){
                for (int i = 0; i < leading_spaces-2;i++){
                    cout << " ";
                }
            } else {
                for (int i = 0; i < leading_spaces-1;i++){
                    cout << " ";
                }
            }
            
            cout << "|\n";
            for (int i = 0; i < lebar_tabel;i++){
                cout <<"-";
            }
            cout << "\n";

            if (head == -1 && count != -1){
                break;
            }

            if (count != -1){
                idx_contact = (idx_contact+1)%MAX_CONTACT;
            }
            count++;
        }
    }      
 
    int getPivot(Contact arr[], int low, int high, int ascending, int sort_by){
        // algortima pertukaran quicksort untuk mengurutkan kontak berdasarkan nama
        int i = low;

        if (ascending == 1){
            for (int j = low;j < high;j++){
                if ((arr[j].getNama()).compare(arr[high].getNama()) <= 0){
                    Contact temp =arr[j];
                    arr[j] =arr[i];
                    arr[i] = temp;
                    i = (i + 1) % MAX_CONTACT;
                }
            }
        } else {
            for (int j = low;j < high;j++){
                if ((arr[j].getNama()).compare(arr[high].getNama()) >= 0){
                    Contact temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                    i = (i + 1) % MAX_CONTACT;
                }
            }
        }
        Contact temp = arr[i];
        arr[i] = arr[high];
        arr[high] = temp;

        return i;
    }

    void quickSortRecursive(Contact arr[], int low, int high, int ascending, int sortBy){

        if ((low < high)){
            int pivot_idx = getPivot(arr, low, high, ascending, sortBy);
            quickSortRecursive(arr, low, pivot_idx-1, ascending, sortBy);
            quickSortRecursive(arr, pivot_idx+1, high, ascending, sortBy);
        } 

    }

    // untuk sinkronisasi kontak dan displaying purpose kontak
    void synchronize(Contact arr1[], Contact arr2[]){
        for (int i = 0;i < MAX_CONTACT;i++){
            arr1[i] = arr2[i];
        }
    }
}


PhoneBook::PhoneBook() {
    // Inisialisasi PhoneBook kosong dengan kontak default
    for (int idx_contact = 0; idx_contact < MAX_CONTACT; idx_contact++){
        kontak[idx_contact] = Contact();
        displaying_purposed_kontak[idx_contact] = Contact();
    }
    head = -1;
    tail = -1;

}


// MUTATOR
void PhoneBook::tambahKontak(Contact kontak_baru){
    // cek apakah ini kontak pertama yang masuk
    if (head == -1){
        head += 1; // head = 0
        tail += 1;  // tail = 0
        kontak[tail] = kontak_baru;
        displaying_purposed_kontak[tail] = kontak_baru;
    } else {
        tail = (tail + 1) % MAX_CONTACT; // menggunakan circular array
        // cek apakah array sudah penuh (cek apakah tail sama dengan head)
        if (tail == head){
            // jika penuh, maka head/kontak terlama akan berubah jadi kontak berikutnya
            head = (head + 1) % MAX_CONTACT;
        }
        kontak[tail] = kontak_baru; // kontak terlama akan diubah
        displaying_purposed_kontak[tail] = kontak_baru;
    }
    cout << "Kontak berhasil dibuat!\n\n";
}

void PhoneBook::hapusKontak(string nama_kontak){
    int idx_contact = head;
    // searching
    while ((kontak[idx_contact].getNama() != nama_kontak) && (idx_contact != tail)) {
        idx_contact = (idx_contact + 1) % MAX_CONTACT;
    }
    // idx_contact == tail atau kontak ditemukan
    if (kontak[idx_contact].getNama() == nama_kontak){ // kontak ditemukan 
        // hapus kontak (ubah ke kontak default) dan geser array
        int current_idx = idx_contact;
        while (current_idx != tail){
            kontak[current_idx] = kontak[(current_idx+1) % MAX_CONTACT];
            displaying_purposed_kontak[current_idx] = displaying_purposed_kontak[(current_idx+1) % MAX_CONTACT];
            current_idx = (current_idx + 1) % MAX_CONTACT;
        }
        
        tail = (tail - 1 + MAX_CONTACT) % MAX_CONTACT;
        kontak[(tail + 1) % MAX_CONTACT] = Contact();
        displaying_purposed_kontak[(tail + 1) % MAX_CONTACT] = Contact();
        cout << "Kontak berhasil dihapus!\n\n";
    } else { // kontak tidak ditemukan (idx_contact >= MAX_CONTACT)
        cout << "Kontak tidak ditemukan!\n\n";
    }
}

void PhoneBook::lihatSortedBy(int sortBy, int ascending){
    if (sortBy == 0){
        lihatSemuaNamaKontak(kontak, head, 1);
    }else if (sortBy == 1){
        quickSortRecursive(displaying_purposed_kontak, 0, MAX_CONTACT-1, ascending, sortBy);
        lihatSemuaNamaKontak(displaying_purposed_kontak, head, 0);
        synchronize(displaying_purposed_kontak, kontak);
    }
}

Contact& PhoneBook::search(string nama){
    if (head == -1){
        cout << "Belum ada kontak!\n\n";
        return anonymous;
    }
    int idx_contact = head;
    while (idx_contact != tail && kontak[idx_contact].getNama() != nama){
        idx_contact = (idx_contact + 1) % MAX_CONTACT;
    }
    // idx_contact == tail or kontak[idx_contact] == nama
    if (kontak[idx_contact].getNama() == nama){
        return kontak[idx_contact];
    } else {
        return anonymous;
    }
}

void PhoneBook::editKontak(Contact& searched_kontak){
    string kategori;
    cout << "\nApa yang ingin Anda ubah dari kontak ini\n";
    cout << "Nama [NAMA]\nTempat Tinggal [TEMPAT_TINGGAL]\nAlamat [ALAMAT]\nKekuatan [KEKUATAN]\nMasukkan opsi:";
    getline(cin, kategori);
    cin.clear();
    if (kategori == "NAMA"){
        string nama_baru;
        cout << "Masukkan nama baru: ";
        getline(cin, nama_baru);
        cin.clear();
        searched_kontak.setNama(nama_baru);
        cout << "Nama berhasil diubah!\n";
    }
    else if (kategori == "TEMPAT_TINGGAL"){
        string tempat_tinggal_baru;
        cout << "Masukkan tempat tinggal baru: ";
        getline(cin, tempat_tinggal_baru);
        cin.clear();
        searched_kontak.setTempatTinggal(tempat_tinggal_baru);
        cout << "Tempat tinggal berhasil diubah!\n";
    }
    else if (kategori == "ALAMAT"){
        string alamat_baru;
        cout << "Masukkan alamat baru: ";
        getline(cin, alamat_baru);
        cin.clear();
        searched_kontak.setAlamat(alamat_baru);
        cout << "Alamat berhasil diubah!\n";
    }
    else if (kategori == "KEKUATAN"){
        string kekuatan_baru;
        cout << "Masukkan kekuatan baru: ";
        getline(cin, kekuatan_baru);
        cin.clear();
        searched_kontak.setKekuatan(kekuatan_baru);
        cout << "Kekuatan berhasil diubah!\n";
    } else {
        cout << "Masukkan pilihan yang valid!\n";
    }
    synchronize(displaying_purposed_kontak, kontak);
}