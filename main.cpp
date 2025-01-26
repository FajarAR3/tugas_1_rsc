#include <iostream>
#include "phonebook.h"
#include <string>

using namespace std;
PhoneBook phonebook = PhoneBook();
int lebar_display = 100;

void printPembatasHorizontal(){
    for (int i = 0;i < lebar_display;i++){
            cout << "-";
        }
    cout << endl;
}

void printCellTabel(string to_be_printed){
    int string_length = to_be_printed.length();
    int half_string_length = string_length / 2;
    int half_output_width = lebar_display/2;
    int leading_spaces  = half_output_width - half_string_length;

    cout << "|";
    for (int i = 0;i < leading_spaces-1;i++){
        cout << " ";
    }
    cout << to_be_printed;
    if (string_length % 2 != 0){
        for (int i = 0;i < leading_spaces-2;i++){
            cout << " ";
        }
    } else {
        for (int i = 0;i < leading_spaces-1;i++){
            cout << " ";
        }
    }
    cout << "|\n";
}

void newLine(){
    char nextChar;
    do {
        cin.get(nextChar);
    } while (nextChar != '\n');
}

int main(){

    int ascending = 1;
    int sortedBy = 1;
    while(true){

        printPembatasHorizontal();

        string to_be_printed = "PHONEBOOK";
        printCellTabel(to_be_printed);
        phonebook.lihatSortedBy(sortedBy, ascending);
        cout << endl;
        
        to_be_printed = "Daftar Perintah: [1] ADD [2] SEARCH [3] EXIT [4] SORT";
        printPembatasHorizontal();
        string inp;
        printCellTabel(to_be_printed);
        printPembatasHorizontal();
        cout << "Perintah: ";
        cin >> inp;
        newLine();
        if (inp == "1"){ // TAMBAH KONTAK
            string nama, tempat_tinggal, alamat, kekuatan;
            cout << "Masukkan nama: ";
            getline(cin, nama);
            cin.clear();
            cout << "Masukkan tempat tinggal: ";
            getline(cin, tempat_tinggal);
            cin.clear();
            cout << "Masukkan alamat: ";
            getline(cin, alamat);
            cin.clear();
            cout << "Masukkan kekuatan: ";
            getline(cin, kekuatan);
            cin.clear();
            cout << nama << endl;
            cout << tempat_tinggal << endl;
            cout << alamat << endl;
            cout << kekuatan << endl;
            Contact kontak = Contact(nama, tempat_tinggal, alamat, kekuatan);
            phonebook.tambahKontak(kontak);
        } else if (inp == "2"){ // SEARCHING BY NAME
            while (true){
                string searched_nama;
                cout << "Masukkan nama kontak yang dicari: ";
                getline(cin, searched_nama);
                cin.clear();
                Contact searched_kontak = phonebook.search(searched_nama);
                if (searched_kontak.getNama() == searched_nama){
                    while (true){
                        cout << "\nInformasi Kontak:\n";
                        cout << "Nama: " << searched_kontak.getNama() << endl;
                        cout << "Tempat tinggal: " << searched_kontak.getTempatTinggal() << endl;
                        cout << "Alamat: " << searched_kontak.getAlamat() << endl;
                        cout << "Kekuatan: " << searched_kontak.getKekuatan() << endl;
                        string cont;
                        cout << "Continue? [Y] : ";
                        getline(cin, cont);
                        cin.clear();
                        if (cont == "Y") break;
                    }
                } else {
                    cout << "Tidak ada kontak bernama " << searched_nama << " silahkan masukkan kembali nama!\n\n";
                    string back;
                    cout << "Back to Home? [Y]: ";
                    getline(cin, back);
                    cin.clear();
                    if (back == "Y"){
                        break;
                    }
                }
            }
        }
        else if(inp == "3"){ // EXIT
            break; //break while loop, program selesai, data otomatis terhapus
        }
        else if(inp == "4"){ // SORT
            cout << "Sorted by: [0] Urutan masuk [1] Nama";
            cin >> sortedBy;
            newLine();
            if (sortedBy == 1){ // jika sort by nama, akan dipilih descending atau ascending
                cout << "[0] Descending [1] Ascending";
                cin >> ascending;
                newLine();
            } else { // jika sort by urutan masuk/waktu, data otomatis terurut ascending
                ascending = 1;
            }
        }

    }
    
    return 0;
}