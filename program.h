#ifndef PROGRAM_H_INCLUDED
#define PROGRAM_H_INCLUDED

#include <iostream>
using namespace std;


struct Pemain {
    string idPemain, nama, negara;
    int umur, jumlah_gelar, peringkat;
};

struct Turnament {
    string idTurnament, nama_turnament, negara_pelaksana, tanggal_pelaksanaan;
    int jumlah_pendaftar, biaya_pendaftaran;
};

typedef Pemain infoTypePemain;
typedef Turnament infoTypeTurnament;
typedef struct ElmPemain *adrPemain;
typedef struct ElmTurnament *adrTurnament;
typedef struct ElmRelasi *adrRelasi;

struct ListRelasi {
    adrRelasi first;
};

struct ElmTurnament {
    infoTypeTurnament infoTurnament;
    adrTurnament nextTurnament;
    ListRelasi relasi;
};

struct ElmPemain {
    infoTypePemain infoPemain;
    adrPemain nextPemain;
};

struct ElmRelasi {
    adrPemain pemain;
    adrRelasi nextRelasi;
};

struct ListTurnament {
    adrTurnament first, last;
};

struct ListPemain {
    adrPemain first;
};


void buatListTurnament(ListTurnament &T);
void buatListPemain(ListPemain &P);
adrTurnament buatTurnament(infoTypeTurnament infoTurnament);
adrPemain buatPemain(infoTypePemain infoPemain);
adrRelasi buatRelasi(adrPemain pemain);
void tambahPemainFirst(ListPemain &P, adrPemain pemain);
void tambahPemainLast(ListPemain &P, adrPemain pemain);
adrPemain cariPemain(ListPemain P, string idPemain);
void tampilDataPemain(ListPemain P, string idPemain);
void keluarkanPemain(ListTurnament &T, string idPemain);
void hapusPemain(ListPemain &P, ListTurnament &T, string idPemain);
void tambahTurnamentFirst(ListTurnament &T, adrTurnament turnament);
void tambahTurnamentLast(ListTurnament &T, adrTurnament turnament);
adrTurnament cariTurnament(ListTurnament T, string idTurnament);
void daftarkanPemain(ListTurnament &T, ListPemain P, string idTurnament, string idPemain);
adrTurnament cariTurnamentBerdasarkanPemain(ListTurnament T, ListPemain P, string idPemain, string idTurnament);
void hapusTurnamentDariPemain(ListTurnament &T, ListPemain P, string idPemain, string idTurnament);
void tampilSemuaTurnamentDariPemain(ListTurnament T, ListPemain P, string idPemain);

// Belum
int hitungTurnamentYangDiikuti(ListTurnament T, string idPemain);
void tampilPemainTurnamentTerbanyak(ListTurnament T, ListPemain P);


#endif // PROGRAM_H_INCLUDED
