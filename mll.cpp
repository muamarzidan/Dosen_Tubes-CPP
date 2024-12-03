#include "mll.h"
#include <iostream>
#include <limits>
using namespace std;

void menu() {
    ListDosen L;
    ListMataKuliah M;
    createListDosen(L);
    createListMataKuliah(M);

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
        string pilihan;
        cin >> pilihan;
        cout << endl;
        if (pilihan == "11") {
            break;
        } else if (pilihan == "1") {
            string loopInsert;
            loopInsert = "y";

            while (loopInsert == "y") {
                infotypeDosen X;
                string pilihInsertDosen;

                cout << "Masukkan nama dosen: ";
                cin >> X.nama;
                cout << "Masukkan kode dosen: ";
                cin >> X.kode;
                cout << "Masukan gender dosen: ";
                cin >> X.gender;
                cout << endl;

                addressDosen P = createElemenDosen(X);
                cout << "Pilih metode insert data" << endl;
                cout << "1 = insert first" << endl;
                cout << "2 = insert last" << endl;
                cout << "Pilih: ";
                cin >> pilihInsertDosen;
                while (pilihInsertDosen != "1" && pilihInsertDosen != "2") {
                    cout << "Pilihan tidak valid, mohon input angka 1 atau 2" << endl;
                    cout << "Pilih : ";
                    cin >> pilihInsertDosen;
                }

                if (pilihInsertDosen == "1") {
                    insertFirstDosen(L, P);
                    cout << endl;
                } else {
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
        } else if (pilihan == "2"){
            cout << "============ Daftar Dosen ============" << endl;
            showDosen(L);
        } else if (pilihan == "3") {
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
        } else if (pilihan == "4") {
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

                        searchDosen(L, namaDosen, pilihSearchDosen);
                    } else {
                        string kodeDosen;
                        cout << "Masukkan kode dosen : ";
                        cin >> kodeDosen;
                        cout << endl;

                        searchDosen(L, kodeDosen, pilihSearchDosen);
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
        } else if (pilihan == "5") {
            string loopInsert;
            loopInsert = "y";
            
            while (loopInsert == "y") {
                mataKuliah MK;
                cout << "Masukkan kode mata kuliah : ";
                cin >> MK.kode;
                cout << "Masukkan nama mata kuliah : ";
                cin >> MK.nama;
                cout << "Masukkan jumlah SKS : ";
                cin >> MK.sks;

                while (cin.fail() || MK.sks < 1 || MK.sks > 5) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Jumlah SKS harus berupa angka antara 1 sampai 5." << endl;
                    cout << "Masukkan jumlah SKS: ";
                    cin >> MK.sks;
                }

                addressMataKuliah kPm = createElemenMataKuliah(MK);
                cout << "1. Insert First" << endl;
                cout << "2. Insert Last" << endl;
                cout << "Pilih: ";
                string pilihInsertMatkul;
                cin >> pilihInsertMatkul;
                while (pilihInsertMatkul != "1" && pilihInsertMatkul != "2") {
                    cout << "Pilihan tidak valid, mohon input angka 1 atau 2" << endl;
                    cout << "Pilih : ";
                    cin >> pilihInsertMatkul;
                }

                if (pilihInsertMatkul == "1") {
                    insertFirstMataKuliah(M, kPm);
                } else {
                    insertLastMataKuliah(M, kPm);
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
        } else if (pilihan == "6") {
            hubungkanDosenKeMataKuliah(L, M);
        } else if (pilihan == "7") {
            showAllDosenWithMataKuliah(L);
        } else if (pilihan == "8") {
            cout << "Mencari data mata kuliah yang diajar oleh dosen tertentu" << endl;
        } else if (pilihan == "9") {
            cout << "Menghapus data mata kuliah yang diajar oleh dosen tertentu" << endl;
        } else if (pilihan == "10") {
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

void searchDosen(ListDosen L, string param, string opsi){
    if (opsi == "1") {
        addressDosen P = first(L);
        bool found = false;

        while (found == false && P != NULL) {
            if (info(P).nama == param){
                cout << "Data dosen ditemukan :" << endl;
                cout << "Nama   : " << info(P).nama << endl;
                cout << "Kode   : " << info(P).kode << endl;
                cout << "Gender : " << info(P).gender << endl;
                found = true;
            }
            P = next(P);
        }

        if (!found){
            cout << "Data dosen tidak ditemukan, coba ketikan nama dosen dengan benar" << endl;
            cout << endl;
        }
    } else {
        addressDosen P = first(L);
        bool found = false;

        while (found == false && P != NULL) {
            if (info(P).kode == param){
                cout << "Data dosen ditemukan :" << endl;
                cout << "Nama   : " << info(P).nama << endl;
                cout << "Kode   : " << info(P).kode << endl;
                cout << "Gender : " << info(P).gender << endl;
                found = true;
            }
            P = next(P);
        }

        if (!found){
            cout << "Data dosen tidak ditemukan, coba ketikan kode dosen dengan benar" << endl;
            cout << endl;
        }
    }
}

void createListMataKuliah(ListMataKuliah &M) {
    M.first = nullptr;
}

addressMataKuliah createElemenMataKuliah(mataKuliah X) {
    addressMataKuliah PM = new elemenMataKuliah;
    PM->info = X;
    PM->next = nullptr;
    return PM;
}

void insertFirstMataKuliah(ListMataKuliah &M, addressMataKuliah PM) {
    if (M.first == nullptr) {
        M.first = PM;
    } else {
        PM->next = M.first;
        M.first = PM;
    }
}

void insertLastMataKuliah(ListMataKuliah &M, addressMataKuliah PM) {
    if (M.first == nullptr) {
        M.first = PM;
    } else {
        addressMataKuliah Q = M.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = PM;
    }
}

void hubungkanDosenKeMataKuliah(ListDosen &L, ListMataKuliah &M) {
    if (isEmpty(L) || first(M) == NULL) {
        cout << "Data dosen atau mata kuliah kosong, tambahkan data terlebih dahulu\n";
        cout << endl;
        return;
    }

    string kodeDosen, kodeMatkul;
    char pilihan;

    do {
        cout << "\n============ Daftar Dosen ============\n";
        showDosen(L);
        cout << "Masukkan kode dosen untuk dihubungkan : ";
        cin >> kodeDosen;

        addressDosen P = cariDosen(L, kodeDosen);
        if (P == NULL) {
            cout << "Dosen dengan kode \"" << kodeDosen << "\" tidak ditemukan\n";
            cout << "Ingin mencari lagi? (y/t): ";
            cin >> pilihan;
            if (pilihan == 't' || pilihan == 'T') return;
            continue;
        }

        do {
            cout << "\n============ Daftar Mata Kuliah ============\n";
            showMataKuliahBelumDiambil(P, M);
            cout << "Masukkan kode mata kuliah untuk dihubungkan : ";
            cin >> kodeMatkul;

            addressMataKuliah PM = cariMataKuliah(M, kodeMatkul);
            if (PM == NULL) {
                cout << "Mata kuliah dengan kode \"" << kodeMatkul << "\" tidak ditemukan\n";
                cout << "Ingin mencari lagi? (y/t) : ";
                cin >> pilihan;
                if (pilihan == 't' || pilihan == 'T') return;
                continue;
            }

            tambahkanMataKuliah(P, PM);
            cout << "Mata kuliah \"" << info(PM).nama << "\" berhasil dihubungkan dengan dosen \""
                << info(P).nama << "\".\n";

            cout << "Ingin menambahkan mata kuliah lagi ke dosen ini? (y/t) : ";
            cin >> pilihan;
        } while (pilihan == 'y' || pilihan == 'Y');

        cout << "Ingin memilih dosen lain? (y/t) : ";
        cin >> pilihan;
    } while (pilihan == 'y' || pilihan == 'Y');

    cout << "Kembali ke menu utama\n";
    cout << endl;
}

addressDosen cariDosen(ListDosen L, string kode) {
    addressDosen P = first(L);
    while (P != NULL) {
        if (info(P).kode == kode) return P;
        P = next(P);
    }
    return NULL;
}

addressMataKuliah cariMataKuliah(ListMataKuliah M, string kode) {
    addressMataKuliah PM = first(M);
    while (PM != NULL) {
        if (info(PM).kode == kode) return PM;
        PM = next(PM);
    }
    return NULL;
}

void showMataKuliahBelumDiambil(addressDosen P, ListMataKuliah M) {
    addressMataKuliah PM = first(M);
    bool ada = false;

    cout << "=========== Mata Kuliah Tersedia ===========\n";
    while (PM != NULL) {
        addressMataKuliah temp = mataKuliah(P);
        bool sudahDiambil = false;
        int i = 1;

        while (temp != NULL) {
            if (temp == PM) {
                sudahDiambil = true;
                break;
            }
            temp = next(temp);
        }

        if (!sudahDiambil) {
            cout << "Mata kuliah ke " << i++ << endl;
            cout << "Kode : " << info(PM).kode << endl;
            cout << "Nama : " << info(PM).nama << endl;
            cout << "SKS  : " << info(PM).sks << endl;
            cout << endl;
            ada = true;
        }
        PM = next(PM);
    }

    if (!ada) {
        cout << "Semua mata kuliah sudah diambil oleh dosen ini";
    }
}

void tambahkanMataKuliah(addressDosen P, addressMataKuliah PM) {
    if (mataKuliah(P) == NULL) {
        mataKuliah(P) = PM;
    } else {
        addressMataKuliah temp = mataKuliah(P);
        while (next(temp) != NULL) {
            temp = next(temp);
        }
        next(temp) = PM;
    }
    next(PM) = NULL;
}

void showAllDosenWithMataKuliah(ListDosen L) {
    addressDosen P = first(L);
    int i = 1;

    while (P != NULL) {
        cout << "Data Dosen : " << i << endl;
        cout << "Nama   : " << info(P).nama << endl;
        cout << "Kode   : " << info(P).kode << endl;

        addressMataKuliah PM = mataKuliah(P);

        if (PM == NULL) {
            cout << "Mata kuliah yang diajar: -\n";
        } else {
            cout << "Mata kuliah yang diajar: \n";
            while (PM != NULL) {
                cout << "Kode : " << info(PM).kode << endl;
                cout << "Nama : " << info(PM).nama << endl;
                cout << "SKS  : " << info(PM).sks << endl;
                cout << endl;
                PM = next(PM);
            }
        }

        P = next(P);
        i++;
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

// void insertAfterMataKuliah(addressDosen &D, addressMataKuliah Prec, addressMataKuliah P){
//     next(P) = next(Prec);
//     next(Prec) = P;
// }