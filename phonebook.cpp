#include "phonebook.h"
#include <iostream>

// helping function untuk algoritma quicksort
namespace {

    void lihatSemuaNamaKontak(Contact* arr[], int head, int def){
    
        const int lebar_tabel = 100;
        for (int i = 0; i < lebar_tabel;i++){
            cout <<"-";
        }
        cout << "\n";
        int idx_ptr_contact;
        if (def == 1){
            idx_ptr_contact = head;
        } else if (def == 0){
            idx_ptr_contact = 0;
        }
        int count = -1;
        while (count < MAX_CONTACT){
            string to_be_printed;
            if (count == -1) {
                to_be_printed = "Daftar Nama Kontak";
            } else {
                to_be_printed = arr[idx_ptr_contact]->getNama();
            }

            bool isPanjangNamaGanjil = (to_be_printed.length() % 2 != 0);
            int half_string_length = to_be_printed.length() / 2;
            int half_output_width = lebar_tabel/2;
            int leading_spaces  = half_output_width - half_string_length; // dikurangi dua karena sudah dipakai oleh "|"
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
            if (count != -1){
                idx_ptr_contact = (idx_ptr_contact+1)%MAX_CONTACT;
            }
            count++;
        }
    }      
    void reset(Contact* arr1[], Contact* arr2[]){
        for (int i = 0;i < MAX_CONTACT;i++){
            arr2[i] = arr1[i];
        }
    }

    int getPivot(Contact* arr[], int low, int high, int ascending, int sort_by){

        bool swap = false;
        int i = low;

        if (ascending == 1){
            for (int j = low;j < high;j++){
                switch (sort_by){
                    case 1:
                        swap = (arr[j]->getNama()).compare(arr[high]->getNama()) <= 0;
                        break;
                    case 2:
                        swap = (arr[j]->getTempatTinggal()).compare(arr[high]->getTempatTinggal()) <= 0;
                        break;
                    case 3:
                        swap = (arr[j]->getAlamat()).compare(arr[high]->getAlamat()) <= 0;
                        break;
                    case 4:
                        swap = (arr[j]->getKekuatan()).compare(arr[high]->getKekuatan()) <= 0;
                        break;
                }
               
                if (swap){
                    Contact* temp =arr[j];
                    arr[j] =arr[i];
                    arr[i] = temp;
                    i = (i + 1) % MAX_CONTACT;
                }
            }
        } else {

            for (int j = low;j < high;j++){
                switch (sort_by){
                    case 1:
                        swap = (arr[j]->getNama()).compare(arr[high]->getNama()) >= 0;
                        break;
                    case 2:
                        swap = (arr[j]->getTempatTinggal()).compare(arr[high]->getTempatTinggal()) >= 0;
                        break;
                    case 3:
                        swap = (arr[j]->getAlamat()).compare(arr[high]->getAlamat()) >= 0;
                        break;
                    case 4:
                        swap = (arr[j]->getKekuatan()).compare(arr[high]->getKekuatan()) >= 0;
                        break;
                }

                if (swap){
                    Contact* temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                    i = (i + 1) % MAX_CONTACT;
                }
            }
        }

        Contact* temp = arr[i];
        arr[i] = arr[high];
        arr[high] = temp;

        return i;
    }

    void quickSortRecursive(Contact* arr[], int low, int high, int ascending, int sortBy){

        if ((low < high)){
            int pivot_idx = getPivot(arr, low, high, ascending, sortBy);
            quickSortRecursive(arr, low, pivot_idx-1, ascending, sortBy);
            quickSortRecursive(arr, pivot_idx+1, high, ascending, sortBy);
        } 

    }

}

Contact anonymous_contact = Contact("Belum ada informasi nama", "Belum ada informasi tempat tinggal", "Belum ada informasi alamat", "Belum ada informasi kekuatan");

PhoneBook::PhoneBook() {
    for (int idx_ptr_contact = 0; idx_ptr_contact < MAX_CONTACT; idx_ptr_contact++){
        kontak[idx_ptr_contact] = &anonymous_contact;
        displaying_purposed_kontak[idx_ptr_contact] = &anonymous_contact;
    }
    head = -1;
    tail = -1;

}


// MUTATOR
void PhoneBook::tambahKontak(Contact& kontak_baru){
    // cek apakah ini kontak pertama yang masuk
    if (head == -1){
        head += 1; // head = 0
        tail += 1;  // tail = 0
        kontak[tail] = &kontak_baru;
        displaying_purposed_kontak[tail] = &kontak_baru;
    } else {
        tail = (tail + 1) % MAX_CONTACT; // menggunakan circular array
        // cek apakah array sudah penuh (cek apakah tail sama dengan head)
        if (tail == head){
            // jika penuh, maka head/kontak terlama akan berubah jadi kontak berikutnya
            head = (head + 1) % MAX_CONTACT;
        }
        kontak[tail] = &kontak_baru; // kontak terlama akan diubah
        displaying_purposed_kontak[tail] = &kontak_baru;
    }

}

void PhoneBook::hapusKontak(string nama_kontak){
    int idx_ptr_contact = head;
    while ((kontak[idx_ptr_contact]->getNama() != nama_kontak) && (idx_ptr_contact != tail)) {
        idx_ptr_contact = (idx_ptr_contact + 1) % MAX_CONTACT;
    }
    // idx_ptr_contact == tail atau kontak ditemukan
    if (kontak[idx_ptr_contact]->getNama() == nama_kontak){ // kontak ditemukan 
        // geser array
        int current_idx = idx_ptr_contact;
        while (current_idx != tail){
            kontak[current_idx] = kontak[(current_idx+1) % MAX_CONTACT];
            displaying_purposed_kontak[current_idx] = displaying_purposed_kontak[(current_idx+1) % MAX_CONTACT];
            current_idx = (current_idx + 1) % MAX_CONTACT;
        }
        
        tail = (tail - 1 + MAX_CONTACT) % MAX_CONTACT;
        kontak[(tail + 1) % MAX_CONTACT] = &anonymous_contact;
        displaying_purposed_kontak[(tail + 1) % MAX_CONTACT] = &anonymous_contact;
        cout << "Kontak berhasil dihapus!\n\n";
    } else { // kontak tidak ditemukan (idx_ptr_contact >= MAX_CONTACT)
        cout << "Kontak tidak ditemukan!\n\n";
    }
}

void PhoneBook::lihatSortedBy(int sortBy, int ascending){
    if (sortBy == 0){
        lihatSemuaNamaKontak(kontak, head, 1);
    }else{
        quickSortRecursive(displaying_purposed_kontak, 0, MAX_CONTACT-1, ascending, sortBy);
        lihatSemuaNamaKontak(displaying_purposed_kontak, head, 0);
        reset(kontak, displaying_purposed_kontak);
    }
}

// void PhoneBook::lihatSemuaNamaKontak() const{
 
//     const int lebar_tabel = 100;
//     for (int i = 0; i < lebar_tabel;i++){
//         cout <<"-";
//     }
//     cout << "\n";
//     int idx_ptr_contact = head;
//     int count = 0;
//     while (count < MAX_CONTACT){
        
//         bool isPanjangNamaGanjil = (kontak[idx_ptr_contact]->getNama().length() % 2 != 0);
//         int half_string_length = kontak[idx_ptr_contact]->getNama().length() / 2;
//         int half_output_width = lebar_tabel/4;
//         int leading_spaces  = half_output_width - half_string_length; // dikurangi dua karena sudah dipakai oleh "|"
//         cout << "|";
//         for (int i = 0; i < leading_spaces-1;i++){
//             cout << " ";
//         }
//         cout << kontak[idx_ptr_contact]->getNama();
        
//         if (isPanjangNamaGanjil){
//             for (int i = 0; i < leading_spaces-2;i++){
//                 cout << " ";
//             }
//         } else {
//              for (int i = 0; i < leading_spaces-1;i++){
//                 cout << " ";
//             }
//         }
        
//         cout << "|";
//         for (int i = 0; i < leading_spaces-1;i++){
//             cout << " ";
//         }
//         cout << kontak[idx_ptr_contact]->getNama();
//         if (isPanjangNamaGanjil){
//             for (int i = 0; i < leading_spaces-1;i++){
//                 cout << " ";
//             }
//         } else {
//              for (int i = 0; i < leading_spaces;i++){
//                 cout << " ";
//             }
//         }
//         cout << "|\n";
//         for (int i = 0; i < lebar_tabel;i++){
//             cout <<"-";
//         }
//         cout << "\n";
//         idx_ptr_contact = (idx_ptr_contact+1)%MAX_CONTACT;
//         count++;
//         if (kontak[idx_ptr_contact] == NULL) {break;}
//     }
// }

