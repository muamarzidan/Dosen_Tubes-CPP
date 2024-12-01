#include "mll.h"
#include <iostream>
using namespace std;

void menu() {
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
        cout << "Pilih: ";
        int pilihan;
        cin >> pilihan;
        if (pilihan == 11) {
            break;
        } else if (pilihan ==  1) {
            cout << "Insert data dosen dari depan/belakang" << endl;
        } else if (pilihan ==  2) {
            cout << "Show all data dosen" << endl;
        } else if (pilihan ==  3) {
            cout << "Menghapus data dosen dan Mata Kuliah yang diajarnya" << endl;
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

int tambah(int a, int b) {
    return a + b;
}

void createListDosen(ListDosen &L){
    first(L) = NULL;
    last(L) = NULL;
}

addressDosen createElemenDosen(infotypeDosen X){
    addressDosen P;
    P = new elemenDosen;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;
    mataKuliah(P) = NULL;

    return P;
}

void insertLastDosen(ListDosen &L, addressDosen P){
    if(first(L) != NULL && last(L) != NULL){
        next(last(L)) = P;
        next(P) = first(L);
        last(L) = P;
    } else {
        first(L) = P;
        last(L) = P;
    }
}

void insertFirstDosen(ListDosen &L, addressDosen P){
    if(first(L) != NULL && last(L) != NULL){
        next(P) = first(L);
        next(last(L)) = P;
        first(L) = P;
    } else {
        first(L) = P;
        last(L) = P;
    }
}

void insertAfterDosen(ListDosen &L, addressDosen Prec, addressDosen P){
    next(P) = next(Prec);
    next(Prec) = P;
}

void insertBeforeDosen(ListDosen &L, addressDosen Prec, addressDosen P){
    addressDosen Q = first(L);
    while(next(Q) != Prec){
        Q = next(Q);
    }
    next(P) = Prec;
    next(Q) = P;
}