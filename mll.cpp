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
        cout << "3. Menghapus data dosen dan mata kuliah yang diajarnya" << endl;
        cout << "4. Mencari data dosen" << endl;
        cout << "5. Insert data mata kuliah" << endl;
        cout << "6. Menghubungkan data dosen ke data mata kuliah" << endl;
        cout << "7. Menampilkan seluruh data dosen beserta mata kuliah yang diajarnya" << endl;
        cout << "8. Mencari data mata kuliah yang diajar oleh dosen tertentu" << endl;
        cout << "9. Menghapus data mata kuliah yang diajar oleh dosen tertentu" << endl;
        cout << "10. Menghitung jumlah data mata kuliah yang diajar oleh dosen tertentu" << endl;
        cout << "11. Exit" << endl;
        cout << "Pilih : ";
        int pilihan;
        cin >> pilihan;
        cout << endl;
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
            if (isEmpty(L)){
                cout << "Data dosen kosong, tidak ada data dosen yang bisa dihapus" << endl;
                cout << endl;
            } else { 
                string loopDelete;
                loopDelete = "y";

                while (loopDelete == "y") {
                    string pilihDeleteDosen;
                    cout << "Input 1 = delete first data dosen" << endl;
                    cout << "Input 2 = delete last data dosen" << endl;
                    cout << "Pilih : ";
                    cin >> pilihDeleteDosen;
                    cout << endl;

                    while (pilihDeleteDosen != "1" && pilihDeleteDosen != "2") {
                        cout << "Pilihan tidak valid, mohon input angka 1 atau 2" << endl;
                        cout << "Pilih : ";
                        cin >> pilihDeleteDosen;
                    }

                    if (pilihDeleteDosen == "1") {
                        addressDosen P;
                        deleteFirstDosen(L, P);
                        cout << "Data dosen berhasil dihapus" << endl;
                        cout << endl;
                    } else {
                        addressDosen P;
                        deleteLastDosen(L, P);
                        cout << "Data dosen berhasil dihapus" << endl;
                        cout << endl;
                    }

                    cout << "Ingin menghapus data dosen lagi? (y/t): ";
                    cin >> loopDelete;
                    while (loopDelete != "y" && loopDelete != "t") {
                        cout << "Pilihan tidak valid, mohon input huruf y atau t" << endl;
                        cout << "Pilih : ";
                        cin >> loopDelete;
                    }

                    if (loopDelete == "t") {
                        cout << endl;
                        break;
                    } else {
                        if (isEmpty(L)){
                            cout << endl;
                            cout << "Data dosen kosong, tidak ada data dosen yang bisa dihapus" << endl;
                            cout << "Anda akan dikembalikan ke MENU" << endl;
                            cout << endl;
                            break;
                        } else {
                            cout << endl;
                            continue;
                        }
                    }
                }
            }
        } else if (pilihan ==  4) {
            if (isEmpty(L)){
                cout << "Data dosen kosong, tidak ada data dosen yang bisa dicari" << endl;
                cout << endl;
            } else {
                string loopSearch;
                loopSearch = "y";

                while (loopSearch == "y") {
                    string pilihSearchDosen;
                    cout << "Pilih opsi mencari data dosen berdasarkan opsi dibawah :" << endl;
                    cout << "1. Nama" << endl;
                    cout << "2. Kode" << endl;
                    cout << "Pilih : ";
                    cin >> pilihSearchDosen;
                    cout << endl;

                    while (pilihSearchDosen != "1" && pilihSearchDosen != "2") {
                        cout << "Pilihan tidak valid, mohon input angka 1 atau 2" << endl;
                        cout << "Pilih : ";
                        cin >> pilihSearchDosen;
                    }

                    if (pilihSearchDosen == "1") {
                        string namaDosen;
                        cout << "Masukkan nama dosen : ";
                        cin >> namaDosen;
                        cout << endl;

                        searchDosen(L, namaDosen);
                    } else {
                        string kodeDosen;
                        cout << "Masukkan kode dosen : ";
                        cin >> kodeDosen;
                        cout << endl;

                        searchDosen(L, kodeDosen);
                    }

                    cout << "Ingin mancari data dosen lagi? (y/t) : ";
                    cin >> loopSearch;
                    while (loopSearch != "y" && loopSearch != "t") {
                        cout << "Pilihan tidak valid, mohon input huruf y atau t" << endl;
                        cout << "Pilih : ";
                        cin >> loopSearch;
                    }

                    if (loopSearch == "t") {
                        cout << endl;
                        break;
                    } else {
                        cout << endl;
                        continue;
                    }
                }
            }
        } else if (pilihan ==  5) {
            cout << "Insert data mata kuliah" << endl;
        } else if (pilihan ==  6) {
            cout << "Menghubungkan data dosen ke data mata kuliah" << endl;
        } else if (pilihan ==  7) {
            cout << "Menampilkan seluruh data dosen beserta mata kuliah yang diajarnya" << endl;
        } else if (pilihan ==  8) {
            cout << "Mencari data mata kuliah yang diajar oleh dosen tertentu" << endl;
        } else if (pilihan ==  9) {
            cout << "Menghapus data mata kuliah yang diajar oleh dosen tertentu" << endl;
        } else if (pilihan ==  10) {
            cout << "Menghitung jumlah data mata kuliah yang diajar oleh dosen tertentu" << endl;
        } else {
            cout << "Pilihan tidak valid" << endl;
        }
    }
}

bool isEmpty(ListDosen L){
    return (first(L) == NULL && last(L) == NULL);
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
    if (!isEmpty(L)){
        P = first(L);
        if (first(L) == last(L)){
            first(L) = NULL;
            last(L) = NULL;
        } else {
            first(L) = next(P);
            prev(first(L)) = NULL;
        }

        next(P) = NULL;
    }
}

void deleteLastDosen(ListDosen &L, addressDosen &P){
    if (!isEmpty(L)){
        P = last(L);
        if (first(L) == last(L)){
            first(L) = NULL;
            last(L) = NULL;
        } else {
            last(L) = prev(P);
            next(last(L)) = NULL;
        }

        prev(P) = NULL;
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

void searchDosen(ListDosen L, string param){
    addressDosen P = first(L);
    bool found = false;

    while (found == false && P != NULL) {
        if (info(P).nama == param || info(P).kode == param){
            cout << "Data dosen ditemukan :" << endl;
            cout << "Nama   : " << info(P).nama << endl;
            cout << "Kode   : " << info(P).kode << endl;
            cout << "Gender : " << info(P).gender << endl;
            found = true;
        }
        P = next(P);
    }

    if (!found){
        cout << "Data dosen tidak ditemukan, coba ketikan nama / kode dengan benar" << endl;
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