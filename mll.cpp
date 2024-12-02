#include "mll.h"
#include <iostream>
using namespace std;

void menu() {
    ListDosen L;
    createListDosen(L);

    while (true) {
        cout << "============================== Menu =================================" << endl;
        cout << "1. Insert data dosen dari depan/belakang" << endl;
        cout << "2. Show all data dosen" << endl;
        cout << "3. Menghapus data dosen dan Mata Kuliah yang diajarnya" << endl;
        cout << "4. Mencari data dosen" << endl;
        cout << "5. Insert data Mata Kuliah" << endl;
        cout << "6. Menghubungkan data dosen ke data Mata Kuliah" << endl;
        cout << "7. Menampilkan seluruh data dosen beserta Mata Kuliah yang diajarnya" << endl;
        cout << "8. Mencari data Mata Kuliah yang diajar oleh dosen tertentu" << endl;
        cout << "9. Menghapus data Mata Kuliah yang diajar oleh dosen tertentu" << endl;
        cout << "10. Menghitung jumlah data Mata Kuliah yang diajar oleh dosen tertentu" << endl;
        cout << "11. Exit" << endl;
        cout << "Pilih : ";
        int pilihan;
        cin >> pilihan;
        if (pilihan == 11) {
            break;
        } else if (pilihan ==  1) {
            string loopInsert;
            loopInsert = "y";

            while (loopInsert == "y") {
                string pilihInsertDosen;
                cout << "Input 1 = insert first data dosen" << endl;
                cout << "Input 2 = insert last data dosen" << endl;
                cout << "Pilih: ";
                cin >> pilihInsertDosen;
                while (pilihInsertDosen != "1" && pilihInsertDosen != "2") {
                    cout << "Pilihan tidak valid, mohon input angka 1 atau 2" << endl;
                    cout << "Pilih : ";
                    cin >> pilihInsertDosen;
                }

                if (pilihInsertDosen == "1") {
                    infotypeDosen X;
                    cout << "Masukkan nama dosen: ";
                    cin >> X.nama;
                    cout << "Masukkan kode dosen: ";
                    cin >> X.kode;
                    cout << "Masukan gender dosen: ";
                    cin >> X.gender;

                    addressDosen P = createElemenDosen(X);
                    insertFirstDosen(L, P);
                    cout << endl;
                } else if (pilihInsertDosen == "2") {
                    infotypeDosen X;
                    cout << "Masukkan nama dosen: ";
                    cin >> X.nama;
                    cout << "Masukkan kode dosen: ";
                    cin >> X.kode;
                    cout << "Masukan gender dosen: ";
                    cin >> X.gender;

                    addressDosen P = createElemenDosen(X);
                    insertLastDosen(L, P);
                    cout << endl;
                }

                cout << "Ingin memasukkan data lagi? (y/t): ";
                cin >> loopInsert;
                while (loopInsert != "y" && loopInsert != "t") {
                    cout << "Pilihan tidak valid, mohon input huruf y atau t" << endl;
                    cout << "Pilih : ";
                    cin >> loopInsert;
                }

                if (loopInsert == "t") {
                    cout << endl;
                    break;
                } else {
                    cout << endl;
                    continue;
                }
            }
        } else if (pilihan ==  2) {
            cout << "DATA DOSEN PADA LIST : " << endl;
            showDosen(L);
        } else if (pilihan ==  3) {
            
        } else if (pilihan ==  4) {
            cout << "Mencari data dosen" << endl;
        } else if (pilihan ==  5) {
            cout << "Insert data Mata Kuliah" << endl;
        } else if (pilihan ==  6) {
            cout << "Menghubungkan data dosen ke data Mata Kuliah" << endl;
        } else if (pilihan ==  7) {
            cout << "Menampilkan seluruh data dosen beserta Mata Kuliah yang diajarnya" << endl;
        } else if (pilihan ==  8) {
            cout << "Mencari data Mata Kuliah yang diajar oleh dosen tertentu" << endl;
        } else if (pilihan ==  9) {
            cout << "Menghapus data Mata Kuliah yang diajar oleh dosen tertentu" << endl;
        } else if (pilihan ==  10) {
            cout << "Menghitung jumlah data Mata Kuliah yang diajar oleh dosen tertentu" << endl;
        } else {
            cout << "Pilihan tidak valid" << endl;
        }
    }
}

void createListDosen(ListDosen &L){
    first(L) = NULL;
    last(L) = NULL;
}

addressDosen createElemenDosen(infotypeDosen X){
    addressDosen P = new elemenDosen;

    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;
    mataKuliah(P) = NULL;

    return P;
}

void insertFirstDosen(ListDosen &L, addressDosen P){
    if (first(L) != NULL && last(L) != NULL) {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    } else {
        first(L) = P;
        last(L) = P;
    }
}

void insertLastDosen(ListDosen &L, addressDosen P){
    if (first(L) != NULL && last(L) != NULL) {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    } else {
        first(L) = P;
        last(L) = P;
    }
}

void deleteFirstDosen(ListDosen &L, addressDosen &P){
    if (first(L) != NULL && last(L) != NULL){
        P = first(L);
        if(next(P) == first(L)){
            first(L) = NULL;
            last(L) = NULL;
        } else {
            first(L) = next(P);
            next(last(L)) = first(L);
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
}

void deleteLastDosen(ListDosen &L, addressDosen &P){
    if (first(L) != NULL && last(L) != NULL){
        P = last(L);
        if(next(P) == first(L)){
            first(L) = NULL;
            last(L) = NULL;
        } else {
            addressDosen Q = first(L);
            while(next(Q) != last(L)){
                Q = next(Q);
            }

            last(L) = Q;
            next(Q) = first(L);
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
}

void showDosen(ListDosen L){
    int i = 1;
    addressDosen P = first(L);

    if (first(L) != NULL && last(L) != NULL){
        while (P != NULL){
            cout << "Data Dosen : " << i << endl;
            cout << "Nama   : " << info(P).nama << endl;
            cout << "Kode   : " << info(P).kode << endl;
            cout << "Gender : " << info(P).gender << endl;

            P = next(P);
            i++;
            cout << endl;
        }
    } else {
        cout << "Data dosen kosong" << endl;
        cout << endl;
    }
}


// void insertAfterDosen(ListDosen &L, addressDosen Prec, addressDosen P){
//     next(P) = next(Prec);
//     next(Prec) = P;
// }


// void insertBeforeDosen(ListDosen &L, addressDosen Prec, addressDosen P){
//     addressDosen Q = first(L);

//     while (next(Q) != Prec){
//         Q = next(Q);
//     }

//     next(P) = Prec;
//     next(Q) = P;
// }


// void deleteBeforeDosen(ListDosen &L, addressDosen Prec, addressDosen &P){
//     addressDosen Q = first(L);

//     while(next(Q) != Prec){
//         Q = next(Q);
//     }

//     P = next(Q);
//     next(Q) = next(P);
//     next(P) = NULL;
//     prev(P) = NULL;
// }


// void deleteAfterDosen(ListDosen &L, addressDosen Prec, addressDosen &P){
//     P = next(Prec);
//     next(Prec) = next(P);
//     next(P) = NULL;
//     prev(P) = NULL;
// }


// void insertLastMataKuliah(addressDosen &D, addressMataKuliah P){
//     if (mataKuliah(D) != NULL){
//         addressMataKuliah Q = mataKuliah(D);

//         while(next(Q) != mataKuliah(D)){
//             Q = next(Q);
//         }
//         next(Q) = P;
//     } else {
//         mataKuliah(D) = P;
//     }
// }


// void insertFirstMataKuliah(addressDosen &D, addressMataKuliah P){
//     if (mataKuliah(D) != NULL){
//         addressMataKuliah Q = mataKuliah(D);

//         while(next(Q) != mataKuliah(D)){
//             Q = next(Q);
//         }
//         next(Q) = P;
//     } else {
//         mataKuliah(D) = P;
//     }
// }


// void insertAfterMataKuliah(addressDosen &D, addressMataKuliah Prec, addressMataKuliah P){
//     next(P) = next(Prec);
//     next(Prec) = P;
// }