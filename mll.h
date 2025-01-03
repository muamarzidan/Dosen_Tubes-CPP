#ifndef MLL_H
#define MLL_H
#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define prev(P) P->prev
#define next(P) P->next
#define info(P) P->info
#define mataKuliah(P) P->mataKuliah
#define NULL nullptr

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
    bool isTaken;
};

typedef mataKuliah infotypeMataKuliah;
typedef struct elemenMataKuliah *addressMataKuliah;

struct elemenMataKuliah {
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

struct ListMataKuliah {
    addressMataKuliah first;
};

void menu();
bool isEmpty(ListDosen L);

void createListDosen(ListDosen &L);
addressDosen createElemenDosen(infotypeDosen X);
void insertFirstDosen(ListDosen &L, addressDosen P);
void insertLastDosen(ListDosen &L, addressDosen P);
void deleteFirstDosen(ListDosen &L, addressDosen &P, ListMataKuliah &M);
void deleteLastDosen(ListDosen &L, addressDosen &P, ListMataKuliah &M);
void showAllDosen(ListDosen L);
void searchDosen(ListDosen L, string param, string opsi);
int countMataKuliahBelumDiambilDosenTertentu(addressDosen P, ListMataKuliah M);
int countMataKuliahBelumDiambilDosenTertentuV2(addressDosen P, ListMataKuliah M);
void createListMataKuliah(ListMataKuliah &M);
addressMataKuliah createElemenMataKuliah(mataKuliah X);
void insertFirstMataKuliah(ListMataKuliah &M, addressMataKuliah PM);
void insertLastMataKuliah(ListMataKuliah &M, addressMataKuliah PM);
void showAllMataKuliah(ListMataKuliah M);
void hubungkanDosenKeMataKuliah(ListDosen &L, ListMataKuliah &M);
addressMataKuliah searchMatkulByCode(ListMataKuliah M, string kode);
void showMataKuliahBelumDiambilDosenTertentu(addressDosen P, ListMataKuliah M);
void showMataKuliahBelumDiambilDosenTertentuV2(addressDosen P, ListMataKuliah M);
void addMatkulToDosen(addressDosen P, addressMataKuliah PM);
void addMatkulToDosenV2(addressDosen P, addressMataKuliah PM);
void showAllDosenWithMataKuliah(ListDosen L);
addressDosen searchDosenByCode(ListDosen L, string kode);
addressDosen searchDosenByName(ListDosen L, string name);
void showMataKuliahYangDiajarDosenTertentu(addressDosen P);
void countMataKuliahDosenTertentu(ListDosen L);

string toLowerCase(string s);
void insertDataDummy(ListDosen &L, ListMataKuliah &M);


// void insertAfterDosen(ListDosen &L, addressDosen Prec, addressDosen P);
// void insertBeforeDosen(ListDosen &L, addressDosen Prec, addressDosen P);
// void deleteAfterDosen(ListDosen &L, addressDosen Prec, addressDosen &P);
// void deleteBeforeDosen(ListDosen &L, addressDosen Prec, addressDosen &P);
// void insertLastMataKuliah(addressDosen &D, addressMataKuliah P);
// void insertFirstMataKuliah(addressDosen &D, addressMataKuliah P);
// void insertAfterMataKuliah(addressDosen &D, addressMataKuliah Prec, addressMataKuliah P);
#endif