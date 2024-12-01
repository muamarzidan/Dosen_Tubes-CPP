#ifndef MLL_H
#define MLL_H

#define first(L) L.first
#define last(L) L.last
#define prev(P) P->prev
#define next(P) P->next
#define info(P) P->info
#define mataKuliah(P) P->mataKuliah

using namespace std;

struct dosen {
    string nama;
    string kode;
    string gender;
};

typedef dosen infotypeDosen;
typedef struct elemenDosen *addressDosen;

struct mataKuliah {
    string nama;
    string kode;
    int sks;
};

typedef mataKuliah infotypeMataKuliah;
typedef struct elemenMataKuliah *addressMataKuliah;

struct elemenMataKuliah {
    addressMataKuliah prev;
    infotypeMataKuliah info;
    addressMataKuliah next;
};

struct elemenDosen {
    addressDosen prev;
    infotypeDosen info;
    addressMataKuliah mataKuliah;
    addressDosen next;
};

struct ListDosen {
    addressDosen first;
    addressDosen last;
};

int tambah(int a, int b);
void menu();

#endif