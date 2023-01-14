#include "program.h"

// circullar single linked list
void buatListTurnament(ListTurnament &T) {
    T.first = NULL;
    T.last = NULL;
}

// single linked list
void buatListPemain(ListPemain &P) {
    P.first = NULL;
}


adrTurnament buatTurnament(infoTypeTurnament turnament) {
    adrTurnament T = new ElmTurnament;
    turnament.jumlah_pendaftar = 0;
    T->infoTurnament = turnament;
    T->nextTurnament = NULL;
    T->relasi.first = NULL;
    return T;
}

adrPemain buatPemain(infoTypePemain pemain) {
    adrPemain P = new ElmPemain;
    P->infoPemain = pemain;
    P->nextPemain = NULL;
    return P;
}

adrRelasi buatRelasi(adrPemain pemain) {
    adrRelasi R = new ElmRelasi;
    R->pemain = pemain;
    R->nextRelasi = NULL;
    return R;
}

void tambahPemainFirst(ListPemain &P, adrPemain pemain) {
    pemain->nextPemain = P.first;
    P.first = pemain;
}

void tambahPemainLast(ListPemain &P, adrPemain pemain) {
    if (P.first == NULL) {
        P.first = pemain;
    } else {
        adrPemain q = P.first;
        while (q->nextPemain != NULL) {
            q = q->nextPemain;
        }
        q->nextPemain = pemain;
    }
}

adrPemain cariPemain(ListPemain P, string idPemain) {
    adrPemain q = P.first;
    while (q != NULL) {
        if (q->infoPemain.idPemain == idPemain) {
            return q;
        }
        q = q->nextPemain;
    }
    return NULL;
}

void tampilDataPemain(ListPemain P, string idPemain) {
    adrPemain q = cariPemain(P,idPemain);
    if (q == NULL) {
        cout << "Data pemain dengan ID " << idPemain << " tidak ditemukan" << endl;
    } else {
        cout << "ID Pemain: " << q->infoPemain.idPemain << endl;
        cout << "Nama: " << q->infoPemain.nama << endl;
        cout << "Umur: " << q->infoPemain.umur << endl;
        cout << "Negara: " << q->infoPemain.negara << endl;
        cout << "Jumlah Gelar: " << q->infoPemain.jumlah_gelar << endl;
        cout << "Peringkat: " << q->infoPemain.peringkat << endl;
        cout << endl;
    }
}

void keluarkanPemain(ListTurnament &T, string idPemain) {
    adrTurnament q = T.first;
    do {
        adrRelasi r = q->relasi.first;
        if (r != NULL) {
            if (r->pemain->infoPemain.idPemain == idPemain) {
                q->relasi.first = q->relasi.first->nextRelasi;
            } else {
                while (r->nextRelasi != NULL) {
                    if (r->nextRelasi->pemain->infoPemain.idPemain == idPemain) {
                        r->nextRelasi = r->nextRelasi->nextRelasi;
                        q->infoTurnament.jumlah_pendaftar--;
                        break;
                    }
                    r = r->nextRelasi;
                }
            }
        }
        q = q->nextTurnament;
    } while (q != T.first);
}

void hapusPemain(ListPemain &P, ListTurnament &T, string idPemain) {
    adrPemain q = P.first;
    bool ketemu = false;
    if (q == NULL) {
        cout << "Pemain Belum Tersedia" << endl;
    } else {
        if (T.first == NULL) {
            cout << "Turnament Belum Tersedia" << endl;
        } else {
            if (q->infoPemain.idPemain == idPemain) {
                keluarkanPemain(T,idPemain);
                P.first = P.first->nextPemain;
                ketemu = true;
            } else {
                while (q->nextPemain != NULL) {
                    if (q->nextPemain->infoPemain.idPemain == idPemain) {
                        keluarkanPemain(T,idPemain);
                        q->nextPemain = q->nextPemain->nextPemain;
                        ketemu = true;
                        break;
                    }
                    q = q->nextPemain;
                }

            }

            if (!ketemu) {
                cout << "Data pemain dengan ID " << idPemain << " tidak ditemukan" << endl;
            }

        }

    }

}


void tambahTurnamentFirst(ListTurnament &T, adrTurnament turnament) {
    adrTurnament q = T.first;
    if (q == NULL) {
        T.first = turnament;
        T.last = turnament;
        T.first->nextTurnament = T.last;
        T.last = T.first;
    } else {
        turnament->nextTurnament = T.first;
        T.last->nextTurnament = turnament;
        T.first = turnament;
    }
}

void tambahTurnamentLast(ListTurnament &T, adrTurnament turnament) {
    adrTurnament q = T.first;
    if (q == NULL) {
        T.first = turnament;
        T.last = turnament;
        T.first->nextTurnament = T.last;
        T.last = T.first;
    } else {
        T.last->nextTurnament = turnament;
        turnament->nextTurnament = T.first;
        T.last = turnament;
    }
}

adrTurnament cariTurnament(ListTurnament T, string idTurnament) {
    adrTurnament turnament = T.first;
    if (turnament != NULL) {
        do {
            if (turnament->infoTurnament.idTurnament == idTurnament) {
                return turnament;
            }
            turnament = turnament->nextTurnament;
        } while (turnament != T.first);
    }
    return NULL;
}


void daftarkanPemain(ListTurnament &T, ListPemain P, string idTurnament, string idPemain) {
    adrPemain pemain = cariPemain(P,idPemain);
    adrTurnament turnament = cariTurnament(T,idTurnament);

    if (T.first == NULL) {
        cout << "Turnament Belum Tersedia" << endl;
    } else if (turnament == NULL) {
        cout << "Turnament dengan ID " << idTurnament << " tidak tersedia" << endl;
    } else if (pemain == NULL) {
        cout << "Pemain dengan ID " << idPemain << " tidak tersedia" << endl;
    } else {
        adrRelasi r = buatRelasi(pemain);
        r->nextRelasi = turnament->relasi.first;
        turnament->relasi.first = r;
        turnament->infoTurnament.jumlah_pendaftar++;
    }
}

adrTurnament cariTurnamentBerdasarkanPemain(ListTurnament T, ListPemain P, string idPemain, string idTurnament) {
    adrTurnament turnament = cariTurnament(T,idTurnament);
    adrPemain pemain = cariPemain(P,idPemain);
    if (turnament != NULL && pemain != NULL) {
        adrRelasi r = turnament->relasi.first;
        while (r != NULL) {
            if (r->pemain->infoPemain.idPemain == idPemain) {
                return turnament;
            }
            r = r->nextRelasi;
        }
    }

    return NULL;
}

void hapusTurnamentDariPemain(ListTurnament &T, ListPemain P, string idPemain, string idTurnament) {
    adrPemain pemain = cariPemain(P,idPemain);
    adrTurnament turnament = cariTurnamentBerdasarkanPemain(T,P,idPemain,idTurnament);

    if (T.first == NULL) {
        cout << "Turnament Belum Tersedia" << endl;
    } else if (turnament == NULL) {
        cout << "Turnament dan Pemain tidak saling berelasi" << endl;
    } else {
        adrRelasi r = turnament->relasi.first;
        if (r->pemain->infoPemain.idPemain == idPemain) {
            turnament->relasi.first = turnament->relasi.first->nextRelasi;
            turnament->infoTurnament.jumlah_pendaftar++;
        } else {
            while (r->nextRelasi != NULL) {
                if (r->nextRelasi->pemain->infoPemain.idPemain == idPemain) {
                    r->nextRelasi = r->nextRelasi->nextRelasi;
                    turnament->infoTurnament.jumlah_pendaftar++;
                    break;
                }
                r = r->nextRelasi;
            }
        }

    }
}

void tampilSemuaTurnamentDariPemain(ListTurnament T, ListPemain P, string idPemain) {
    adrPemain pemain = cariPemain(P,idPemain);
    if (T.first == NULL) {
        cout << "Turnament Belum Tersedia" << endl;
    } else if (pemain == NULL) {
        cout << "Pemain dengan ID " << idPemain << " tidak tersedia" << endl;
    } else {
        tampilDataPemain(P,idPemain);
        cout << "===== List Turnament Yang Diikuti =====" << endl;
        adrTurnament turnament = T.first;
        do {
            adrRelasi r = turnament->relasi.first;
            while (r != NULL) {
                if (r->pemain == pemain) {
                    cout << "ID Turnament: " << turnament->infoTurnament.idTurnament << endl;
                    cout << "Nama: " << turnament->infoTurnament.nama_turnament << endl;
                    cout << "Negara: " << turnament->infoTurnament.negara_pelaksana << endl;
                    cout << "Tanggal: " << turnament->infoTurnament.tanggal_pelaksanaan << endl;
                    cout << "Biaya: " << turnament->infoTurnament.biaya_pendaftaran << endl;
                    cout << "Jumlah Pendaftar: " << turnament->infoTurnament.jumlah_pendaftar << endl;
                    cout << endl;
                    break;
                }
                r = r->nextRelasi;
            }
            turnament = turnament->nextTurnament;
        } while (turnament != T.first);
    }
}


int hitungTurnamentYangDiikuti(ListTurnament T, string idPemain) {
    int total = 0;
    adrTurnament turnament = T.first;
    if (turnament != NULL) {
        do {
            adrRelasi r = turnament->relasi.first;
            while (r != NULL) {
                if (r->pemain->infoPemain.idPemain == idPemain) {
                    total++;
                }
                r = r->nextRelasi;
            }
            turnament = turnament->nextTurnament;
        } while (turnament != T.first);
    }

    return total;
}


void tampilPemainTurnamentTerbanyak(ListTurnament T, ListPemain P) {
    adrPemain pemain = P.first;
    if (T.first == NULL) {
        cout << "Turnament Belum Tersedia" << endl;
    } else if (P.first == NULL) {
        cout << "Pemain Belum Tersedia" << endl;
    } else {
        adrPemain turTerbanyak = pemain;
        int turTerbanyakSementara = hitungTurnamentYangDiikuti(T, pemain->infoPemain.idPemain);
        pemain = pemain->nextPemain;
        while (pemain != NULL) {
            int totalTurnament = hitungTurnamentYangDiikuti(T, pemain->infoPemain.idPemain);
            if (totalTurnament > turTerbanyakSementara) {
                turTerbanyakSementara = totalTurnament;
                turTerbanyak = pemain;
            }
            pemain = pemain->nextPemain;
        }

        cout << "Total turnament: " << turTerbanyakSementara << endl;
        cout << endl;
        tampilSemuaTurnamentDariPemain(T,P,turTerbanyak->infoPemain.idPemain);
    }
}
