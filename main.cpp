#include <iostream>
#include "program.h"

int main()
{
    ListPemain P;
    ListRelasi R;
    ListTurnament T;
    adrPemain pemain;
    adrRelasi relasi;
    adrTurnament turnament;
    infoTypePemain infoPemain;
    infoTypeTurnament infoTur;

    buatListPemain(P);
    buatListTurnament(T);

    int pilihan = -1;
    string idPemain, idTur;
    while (pilihan != 0) {
        cout << "========= MENU ==========" << endl;
        cout << "1. Tambah pemain" << endl;
        cout << "2. Tambah turnament" << endl;
        cout << "3. Daftarkan pemain" << endl;
        cout << "4. Hapus pemain" << endl;
        cout << "5. Hapus turnament dari pemain" << endl;
        cout << "6. Cari pemain" << endl;
        cout << "7. Cari turnament" << endl;
        cout << "8. Tampilkan pemain" << endl;
        cout << "9. Tampilkan seluruh turnament dari pemain" << endl;
        cout << "10. Tampilkan pemain dengan turnament terbanyak" << endl;
        cout << "0. Keluar" << endl;
        cout << "Plih menu: "; cin >> pilihan;
        cout << "=========================" << endl;

        if (pilihan == 1) {
            cout << "Tambah Pemain" << endl;
            cout << "=========================" << endl;
            cout << "ID: "; cin >> infoPemain.idPemain;
            cout << "Nama: "; cin >> infoPemain.nama;
            cout << "Umur: "; cin >> infoPemain.umur;
            cout << "Negara: "; cin >> infoPemain.negara;
            cout << "Jumlah gelar: "; cin >> infoPemain.jumlah_gelar;
            cout << "Peringkat: "; cin >> infoPemain.peringkat;
            pemain = buatPemain(infoPemain);
            tambahPemainFirst(P,pemain);
            cout << "Selesai tambah pemain" << endl;
            cout << "=========================" << endl;
            cout << endl;
        } else if (pilihan == 2) {
            cout << "Tambah turnament" << endl;
            cout << "=========================" << endl;
            cout << "ID: "; cin >> infoTur.idTurnament;
            cout << "Nama turnament: "; cin >> infoTur.nama_turnament;
            cout << "Negara: ";
             cin >> infoTur.negara_pelaksana;
            cout << "Tanggal: "; cin >> infoTur.tanggal_pelaksanaan;
            cout << "Biaya: "; cin >> infoTur.biaya_pendaftaran;
            turnament = buatTurnament(infoTur);
            tambahTurnamentLast(T,turnament);
            cout << "Selesai tambah turnament" << endl;
            cout << "=========================" << endl;
            cout << endl;
        } else if (pilihan == 3) {
            cout << "Daftarkan pemain" << endl;
            cout << "=========================" << endl;
            cout << "ID Pemain: "; cin >> idPemain;
            cout << "ID Turnament: "; cin >> idTur;
            daftarkanPemain(T,P,idTur,idPemain);
            cout << "Selesai daftar pemain" << endl;
            cout << "=========================" << endl;
            cout << endl;
        } else if (pilihan == 4) {
            cout << "Hapus pemain" << endl;
            cout << "=========================" << endl;
            cout << "ID Pemain: "; cin >> idPemain;
            hapusPemain(P,T,idPemain);
            cout << "Selesai hapus pemain" << endl;
            cout << "=========================" << endl;
            cout << endl;
        } else if (pilihan == 5) {
            cout << "Hapus turnament dari pemain" << endl;
            cout << "=========================" << endl;
            cout << "ID Pemain: "; cin >> idPemain;
            cout << "ID Turnament: "; cin >> idTur;
            hapusTurnamentDariPemain(T,P,idPemain,idTur);
            cout << "Selesai hapus turnament dari pemain" << endl;
            cout << "=========================" << endl;
            cout << endl;
        } else if (pilihan == 6) {
            cout << "Cari pemain" << endl;
            cout << "=========================" << endl;
            cout << "ID Pemain: "; cin >> idPemain;
            pemain = cariPemain(P,idPemain);
            tampilDataPemain(P,idPemain);
            cout << "Selesai cari pemain" << endl;
            cout << "=========================" << endl;
            cout << endl;
        } else if (pilihan == 7) {
            cout << "Cari turnament" << endl;
            cout << "=========================" << endl;
            cout << "ID Turnament: "; cin >> idTur;
            turnament = cariTurnament(T,idTur);
            if (turnament == NULL) {
                cout << "Turnament dengan ID " << idTur << " tidak tersedia" << endl;
            } else {
                cout << "ID Turnament: " << turnament->infoTurnament.idTurnament << endl;
                cout << "Nama Turnament: " << turnament->infoTurnament.nama_turnament << endl;
                cout << "Negara Turnament: " << turnament->infoTurnament.negara_pelaksana << endl;
                cout << "Tanggal Pelaksanaan: " << turnament->infoTurnament.tanggal_pelaksanaan << endl;
                cout << "Jumlah pendaftar: " << turnament->infoTurnament.jumlah_pendaftar << endl;
                cout << "Biaya: " << turnament->infoTurnament.biaya_pendaftaran << endl;
            }
            cout << "Selesai cari turnament" << endl;
            cout << "=========================" << endl;
            cout << endl;
        } else if (pilihan == 8) {
            cout << "Tampilkan pemain" << endl;
            cout << "=========================" << endl;
            cout << "ID Pemain: "; cin >> idPemain;
            cout << "====== Data pemain ======" << endl;
            tampilDataPemain(P,idPemain);
            cout << "Selesai tampilkan pemain" << endl;
            cout << "=========================" << endl;
            cout << endl;
        } else if (pilihan == 9) {
            cout << "Tampilkan seluruh turnament dari pemain" << endl;
            cout << "=========================" << endl;
            cout << "ID Pemain: "; cin >> idPemain;
            tampilSemuaTurnamentDariPemain(T,P,idPemain);
            cout << "Selesai tampilkan seluruh turnament dari pemain" << endl;
            cout << "=========================" << endl;
            cout << endl;
        } else if (pilihan == 10) {
            cout << "Tampilkan pemain dengan turnament terbanyak" << endl;
            cout << "=========================" << endl;
            tampilPemainTurnamentTerbanyak(T,P);
            cout << "Selesai tampilkan turnament terbanyak" << endl;
            cout << "=========================" << endl;
            cout << endl;
        } else {
            cout << "Inputan tidak valid" << endl;
        }
    }


    return 0;
}
