#include "mll.h"
#include <iostream>
#include <limits>
using namespace std;

void menu() {
    ListDosen L;
    ListMataKuliah M;
    createListDosen(L);
    createListMataKuliah(M);
    insertDataDummy(L, M);

    cout << "=========================================================================" << endl;
    cout << "==== Selamat datang di Program Manajemen Data Dosen dan Mata Kuliah! ====" << endl;
    cout << "=========================================================================" << endl;
    while (true) {
        cout << "================================ Menu ===================================" << endl;
        cout << "1. Insert data dosen dari depan/belakang" << endl;
        cout << "2. Show all data dosen" << endl;
        cout << "3. Menghapus data dosen dan mata kuliah yang diajarnya" << endl;
        cout << "4. Mencari data dosen" << endl;
        cout << "5. Insert data mata kuliah" << endl;
        cout << "6. Show all data mata kuliah" << endl;
        cout << "7. Menghubungkan data dosen ke data mata kuliah" << endl;
        cout << "8. Menampilkan seluruh data dosen beserta mata kuliah yang diajarnya" << endl;
        cout << "9. Mencari data mata kuliah yang diajar oleh dosen tertentu" << endl;
        cout << "10. Menghapus data mata kuliah yang diajar oleh dosen tertentu" << endl;
        cout << "11. Menghitung jumlah data mata kuliah yang diajar oleh dosen tertentu" << endl;
        cout << "12. Developer" << endl;
        cout << "13. Exit" << endl;
        cout << "Pilih : ";
        string pilihan;
        cin >> pilihan;
        cout << endl;
        if (pilihan == "13") {
            cout << "Terima kasih telah menggunakan program kami!" << endl;
            break;
        } else if (pilihan == "1") {
            string loopInsert;
            loopInsert = "y";

            while (loopInsert == "y") {
                infotypeDosen X;
                string pilihInsertDosen;

                cout << "Masukkan nama dosen: ";
                cin.ignore();
                getline(cin, X.nama);
                cout << "Masukkan kode dosen: ";
                cin >> X.kode;
                while (searchDosenByCode(L, X.kode) != NULL) {
                    cout << "Kode dosen sudah ada, mohon masukkan kode dosen yang berbeda." << endl;
                    cout << "Masukkan kode dosen: ";
                    cin >> X.kode;
                }
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
                loopInsert = toLowerCase(loopInsert);
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
            cout << "============ Daftar Semua Dosen ============" << endl;
            showAllDosen(L);
            cout << "=======================================" << endl;
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
                    loopDelete = toLowerCase(loopDelete);
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
                    cout << "0. Kembali ke MENU" << endl;
                    cout << "Pilih : ";
                    cin >> pilihSearchDosen;
                    cout << endl;

                    while (pilihSearchDosen != "1" && pilihSearchDosen != "2" && pilihSearchDosen != "0") {
                        cout << "Pilihan tidak valid, mohon input angka 1 atau 2" << endl;
                        cout << "Pilih : ";
                        cin >> pilihSearchDosen;
                    }

                    if (pilihSearchDosen == "1") {
                        string namaDosen;
                        cout << "Masukkan nama dosen : ";
                        cin.ignore();
                        getline(cin, namaDosen);
                        cout << endl;

                        searchDosen(L, namaDosen, pilihSearchDosen);
                    } else if (pilihSearchDosen == "0") {
                        cout << endl;
                        break;
                    } else {
                        string kodeDosen;
                        cout << "Masukkan kode dosen : ";
                        cin >> kodeDosen;
                        cout << endl;

                        searchDosen(L, kodeDosen, pilihSearchDosen);
                    }

                    cout << "Ingin mencari data dosen lagi? (y/t) : ";
                    cin >> loopSearch;
                    loopSearch = toLowerCase(loopSearch);
                    while (loopSearch != "y" && loopSearch != "t") {
                        cout << "Pilihan tidak valid, mohon input huruf y atau t" << endl;
                        cout << "Pilih : ";
                        cin >> loopSearch;
                        loopSearch = toLowerCase(loopSearch);
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
                cout << "Masukkan nama mata kuliah : ";
                cin.ignore();
                getline(cin, MK.nama);
                cout << "Masukkan kode mata kuliah : ";
                cin >> MK.kode;
                while (searchMatkulByCode(M, MK.kode) != NULL) {
                    cout << "Kode mata kuliah sudah ada, mohon masukkan kode mata kuliah yang berbeda." << endl;
                    cout << "Masukkan kode mata kuliah: ";
                    cin >> MK.kode;
                }
                cout << "Masukkan jumlah SKS : ";
                cin >> MK.sks;

                while (MK.sks < 1 || MK.sks > 5) {
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
                loopInsert = toLowerCase(loopInsert);
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
        } else if (pilihan == "6"){
            cout << "============ Daftar Mata Kuliah Yang Terdaftar ============\n" << endl;
            showAllMataKuliah(M);
            cout << "=============================================================" << endl;
        } else if (pilihan == "7") {
            hubungkanDosenKeMataKuliah(L, M);
        } else if (pilihan == "8") {
            showAllDosenWithMataKuliah(L);
        } else if (pilihan == "9") {
            if (isEmpty(L)){
                cout << "Data dosen kosong, tidak ada data dosen yang bisa dicari" << endl;
                cout << endl;
            } else {
                string loopSearch;
                loopSearch = "y";

                while (loopSearch == "y") {
                    string pilihSearchDosen;
                    cout << "============ Daftar Dosen ============" << endl;
                    showAllDosen(L);
                    cout << "=======================================" << endl;
                    cout << "Pilih opsi mencari data dosen berdasarkan opsi dibawah :" << endl;
                    cout << "1. Nama" << endl;
                    cout << "2. Kode" << endl;
                    cout << "0. Kembali ke MENU" << endl;
                    cout << "Pilih : ";
                    cin >> pilihSearchDosen;
                    cout << endl;
                    addressDosen P;

                    while (pilihSearchDosen != "1" && pilihSearchDosen != "2" && pilihSearchDosen != "0") {
                        cout << "Pilihan tidak valid, mohon input angka 1 atau 2" << endl;
                        cout << "Pilih : ";
                        cin >> pilihSearchDosen;
                    }

                    if (pilihSearchDosen == "1") {
                        string namaDosen;
                        cout << "Masukkan nama dosen : ";
                        cin.ignore();
                        getline(cin, namaDosen);
                        cout << endl;

                        P = searchDosenByName(L, namaDosen);

                        if (P == NULL){
                            cout << "Data dosen tidak ditemukan, coba ketikan nama dosen dengan benar" << endl;
                            cout << endl;
                        }
                    } else if (pilihSearchDosen == "0") {
                        cout << endl;
                        break;
                    } else {
                        string kodeDosen;
                        cout << "Masukkan kode dosen : ";
                        cin >> kodeDosen;
                        cout << endl;

                        P = searchDosenByCode(L, kodeDosen);

                        if (P == NULL){
                            cout << "Data dosen tidak ditemukan, coba ketikan kode dosen dengan benar" << endl;
                            cout << endl;
                        }
                    }

                    if (P != NULL){
                        showMataKuliahYangDiajarDosenTertentu(P);
                    }

                    cout << "Ingin mencari data dosen lagi? (y/t) : ";
                    cin >> loopSearch;
                    loopSearch = toLowerCase(loopSearch);
                    while (loopSearch != "y" && loopSearch != "t") {
                        cout << "Pilihan tidak valid, mohon input huruf y atau t" << endl;
                        cout << "Pilih : ";
                        cin >> loopSearch;
                        loopSearch = toLowerCase(loopSearch);
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
            

        } else if (pilihan == "10") {
            if (isEmpty(L)){
                cout << "Data dosen kosong, tidak ada data dosen yang bisa dicari" << endl;
                cout << endl;
            } else {
                string loopSearch;
                loopSearch = "y";

                while (loopSearch == "y") {
                    string pilihSearchDosen;
                    cout << "============ Daftar Dosen ============" << endl;
                    showAllDosen(L);
                    cout << "=======================================" << endl;
                    cout << "Pilih opsi mencari data dosen berdasarkan opsi dibawah :" << endl;
                    cout << "1. Nama" << endl;
                    cout << "2. Kode" << endl;
                    cout << "0. Kembali ke MENU" << endl;
                    cout << "Pilih : ";
                    cin >> pilihSearchDosen;
                    cout << endl;
                    addressDosen P;

                    while (pilihSearchDosen != "1" && pilihSearchDosen != "2" && pilihSearchDosen != "0") {
                        cout << "Pilihan tidak valid, mohon input angka 1 atau 2" << endl;
                        cout << "Pilih : ";
                        cin >> pilihSearchDosen;
                    }

                    if (pilihSearchDosen == "1") {
                        string namaDosen;
                        cout << "Masukkan nama dosen : ";
                        cin.ignore();
                        getline(cin, namaDosen);
                        cout << endl;

                        P = searchDosenByName(L, namaDosen);

                        if (P == NULL){
                            cout << "Data dosen tidak ditemukan, coba ketikan nama dosen dengan benar" << endl;
                            cout << endl;
                        }
                    } else if (pilihSearchDosen == "0") {
                        cout << endl;
                        break;
                    } else {
                        string kodeDosen;
                        cout << "Masukkan kode dosen : ";
                        cin >> kodeDosen;
                        cout << endl;

                        P = searchDosenByCode(L, kodeDosen);

                        if (P == NULL){
                            cout << "Data dosen tidak ditemukan, coba ketikan kode dosen dengan benar" << endl;
                            cout << endl;
                        }
                    }

                    if (P != NULL) {
                        if (mataKuliah(P) == NULL) {
                            cout << "Data mata kuliah yang diajar oleh dosen ini kosong" << endl;
                            cout << endl;
                        } else {
                            cout << "Data mata kuliah yang diajar oleh dosen ini:" << endl;
                            showMataKuliahYangDiajarDosenTertentu(P);
                            cout << "Masukkan kode mata kuliah yang ingin dihapus: ";
                            string kodeMatkul;
                            cin >> kodeMatkul;

                            addressMataKuliah PM = mataKuliah(P);
                            addressMataKuliah prev = NULL;
                            bool found = false;

                            while (PM != NULL && !found) {
                                if (info(PM).kode == kodeMatkul) {
                                    found = true;
                                } else {
                                    prev = PM;
                                    PM = next(PM);
                                }
                            }

                            if (!found) {
                                cout << "Data mata kuliah dengan kode " << kodeMatkul << " tidak ditemukan." << endl;
                            } else {
                                if (prev == NULL) {
                                    mataKuliah(P) = next(PM);
                                } else {
                                    next(prev) = next(PM);
                                }
                                info(PM).isTaken = false;
                                delete PM;
                                cout << "Data mata kuliah berhasil dihapus." << endl;
                            }
                            cout << endl;
                        }
                    }

                    cout << "Ingin mencari data dosen lagi? (y/t) : ";
                    cin >> loopSearch;
                    loopSearch = toLowerCase(loopSearch);
                    while (loopSearch != "y" && loopSearch != "t") {
                        cout << "Pilihan tidak valid, mohon input huruf y atau t" << endl;
                        cout << "Pilih : ";
                        cin >> loopSearch;
                        loopSearch = toLowerCase(loopSearch);
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
        } else if (pilihan == "11") {
            countMataKuliahDosenTertentu(L);
        } else if (pilihan == "12") {
            cout << "Berikut adalah data developer dari program ini : " << endl;
            cout << "Developer 1 : " << endl;
            cout << "Nama  : Muamar Zidan" << endl;
            cout << "NIM   : " << endl;
            cout << "Kelas : IF-47-11\n" << endl;

            cout << "Developer 2 : " << endl;
            cout << "Nama  : Faiz Elfahad Kurniawan" << endl;
            cout << "NIM   : 103012300408" << endl;
            cout << "Kelas : IF-47-11" << endl;
            cout << endl;
        } else {
            cout << "Pilihan tidak valid" << endl;
        }
    }
}

bool isEmpty(ListDosen L){
    return (first(L) == NULL && last(L) == NULL);
}

bool isEmptyMatkul(ListMataKuliah M){
    return (first(M) == NULL);
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

void showAllDosen(ListDosen L){
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
    } else if(opsi == "2") {
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
    PM->info.isTaken = false;
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
    if (isEmpty(L)) {
        cout << "Data Dosen Masih Kosong, silakan tambahkan data dosen terlebih dahulu.\n";
        return;
    }
    if (first(M) == NULL) {
        cout << "Data Mata Kuliah Masih Kosong, silakan tambahkan data mata kuliah terlebih dahulu.\n";
        return;
    }

    string loopSearch = "y";
    while (loopSearch == "y") {
        string pilihSearchDosen, kodeDosen, namaDosen;
        addressDosen P = NULL;
        cout << "\n============ Daftar Dosen ============\n";
        showAllDosen(L);
        cout << "======================================\n";
        cout << "Pilih opsi mencari data dosen berdasarkan opsi di bawah:\n";
        cout << "1. Nama\n";
        cout << "2. Kode\n";
        cout << "0. Kembali ke MENU\n";
        cout << "Pilih: ";
        cin >> pilihSearchDosen;
        cout << endl;

        if (pilihSearchDosen == "1") {
            cout << "Masukkan nama dosen: ";
            cin.ignore();
            getline(cin, namaDosen);
            P = searchDosenByName(L, namaDosen);
        } else if (pilihSearchDosen == "2") {
            cout << "Masukkan kode dosen: ";
            cin >> kodeDosen;
            P = searchDosenByCode(L, kodeDosen);
        } else if (pilihSearchDosen == "0") {
            cout << "Kembali ke MENU.\n";
            break;
        } else {
            cout << "Pilihan tidak valid.\n";
            continue;
        }

        if (P == NULL) {
            cout << "Data dosen tidak ditemukan\n";
            cout << "Ingin mencari data dosen lagi? (y/t): ";
            cin >> loopSearch;
            loopSearch = toLowerCase(loopSearch);
            continue;
        }

        cout << "Data dosen ditemukan:\n";
        cout << "Nama   : " << info(P).nama << endl;
        cout << "Kode   : " << info(P).kode << endl;
        cout << "Gender : " << info(P).gender << endl;

        string loopInsertV2 = "y";
        while (loopInsertV2 == "y") {
            int countMataKuliahBelumDiambil = countMataKuliahBelumDiambilDosenTertentuV2(P, M);
            if (countMataKuliahBelumDiambil == 0){
                cout << "\nData mata kuliah telah terhubung semua.\nSilahkan tambahkan data mata kuliah terlebih dahulu untuk menambahkan mata kuliah ke dosen ini.\n";
                break;
            }
            
            cout << "\n============ Daftar Mata Kuliah Yang Belum Diambil ============\n";
            showMataKuliahBelumDiambilDosenTertentuV2(P, M);
            cout << "Total mata kuliah yang belum diambil: " << countMataKuliahBelumDiambil << endl;
            cout << "================================================================\n";

            cout << "Masukkan kode mata kuliah untuk dihubungkan: ";
            string kodeMatkul;
            cin >> kodeMatkul;
            addressMataKuliah PM = searchMatkulByCode(M, kodeMatkul);

            if (PM == NULL) {
                cout << "Data mata kuliah tidak ditemukan.\n";
                continue;
            }
            addMatkulToDosenV2(P, PM);
            cout << "\nData mata kuliah berhasil dihubungkan dengan dosen.\n\n";

            cout << "Ingin menghubungkan data dosen dengan mata kuliah lagi? (y/t): ";
            cin >> loopInsertV2;
            loopInsertV2 = toLowerCase(loopInsertV2);
        }

        cout << "Ingin mencari data dosen lagi? (y/t): ";
        cin >> loopSearch;
        loopSearch = toLowerCase(loopSearch);
    }
}

addressDosen searchDosenByCode(ListDosen L, string kode) {
    addressDosen P = first(L);
    while (P != NULL) {
        if (info(P).kode == kode) return P;
        P = next(P);
    }
    return NULL;
}

addressDosen searchDosenByName(ListDosen L, string name) {
    addressDosen P = first(L);
    while (P != NULL) {
        if (info(P).nama == name) return P;
        P = next(P);
    }
    return NULL;
}

addressMataKuliah searchMatkulByCode(ListMataKuliah M, string kode) {
    addressMataKuliah PM = first(M);
    while (PM != NULL) {
        if (info(PM).kode == kode) return PM;
        PM = next(PM);
    }
    return NULL;
}

void showAllMataKuliah(ListMataKuliah M) {
    addressMataKuliah PM = first(M);
    int i = 1;

    while (PM != NULL) {
        cout << "Data Mata Kuliah " << i << " : " << endl;
        cout << "Nama : " << info(PM).nama << endl;
        cout << "Kode : " << info(PM).kode << endl;
        cout << "SKS  : " << info(PM).sks << endl;
        cout << endl;

        PM = next(PM);
        i++;
    }
}

void showMataKuliahBelumDiambilDosenTertentu(addressDosen P, ListMataKuliah M) {
    addressMataKuliah PM = first(M);
    while (PM != NULL) {
        bool found = false;
        addressMataKuliah temp = mataKuliah(P);

        while (temp != NULL && !found) {
            if (info(temp).kode == info(PM).kode) {
                found = true;
            }
            temp = next(temp);
        }
        if (!found) {
            cout << "Kode : " << info(PM).kode << endl;
            cout << "Nama : " << info(PM).nama << endl;
            cout << "SKS  : " << info(PM).sks << endl;
            cout << endl;
        }

        PM = next(PM);
    }
}

void showMataKuliahBelumDiambilDosenTertentuV2(addressDosen P, ListMataKuliah M) {
    addressMataKuliah PM = first(M);

    while (PM != NULL) {
        if (!info(PM).isTaken) {
            cout << "Kode : " << info(PM).kode << endl;
            cout << "Nama : " << info(PM).nama << endl;
            cout << "SKS  : " << info(PM).sks << endl;
            cout << endl;
        }
        PM = next(PM);
    }
}

int countMataKuliahBelumDiambilDosenTertentu(addressDosen P, ListMataKuliah M) {
    int count = 0;
    addressMataKuliah PM = first(M);
    while (PM != NULL) {
        bool found = false;
        addressMataKuliah temp = mataKuliah(P);

        while (temp != NULL && !found) {
            if (info(temp).kode == info(PM).kode) {
                found = true;
            }
            temp = next(temp);
        }

        if (!found) {
            count++;
        }

        PM = next(PM);
    }

    return count;
}

int countMataKuliahBelumDiambilDosenTertentuV2(addressDosen P, ListMataKuliah M) {
    int count = 0;
    addressMataKuliah PM = first(M);

    while (PM != NULL) {
        if (!info(PM).isTaken) {
            count++;
        }
        PM = next(PM);
    }

    return count;
}

void addMatkulToDosenV2(addressDosen P, addressMataKuliah PM) {
    if (info(PM).isTaken) {
        cout << "Mata kuliah ini sudah diambil oleh dosen lain.\n";
        return;
    }

    addressMataKuliah Q = createElemenMataKuliah(info(PM));
    info(PM).isTaken = true;

    if (mataKuliah(P) == NULL) {
        mataKuliah(P) = Q;
    } else {
        addressMataKuliah R = mataKuliah(P);
        while (next(R) != NULL) {
            R = next(R);
        }
        next(R) = Q;
    }
}

void addMatkulToDosen(addressDosen P, addressMataKuliah PM) {
    addressMataKuliah Q = createElemenMataKuliah(info(PM));

    if (mataKuliah(P) == NULL) {
        mataKuliah(P) = Q;
    } else {
        addressMataKuliah R = mataKuliah(P);
        while (next(R) != NULL) {
            R = next(R);
        }
        next(R) = Q;
    }
}

void showMataKuliahYangDiajarDosenTertentu(addressDosen P) {
    addressMataKuliah PM = mataKuliah(P);
    int i = 1;
    int totalSKS = 0;
    while (PM != NULL) {
        totalSKS += info(PM).sks;
        cout << "Mata Kuliah " << i << " : " << endl;
        cout << "Kode : " << info(PM).kode << endl;
        cout << "Nama : " << info(PM).nama << endl;
        cout << "SKS  : " << info(PM).sks << endl;
        cout << endl;

        PM = next(PM);
        i++;
    }
    cout << "Total SKS yang diajar: " << totalSKS << endl;
}

void showAllDosenWithMataKuliah(ListDosen L) {
    if (isEmpty(L)){
        cout << "Data dosen kosong, tidak ada data dosen yang bisa ditampilkan" << endl;
        cout << endl;
    } else {
        addressDosen P = first(L);
        int i = 1;
        cout << "============ Daftar Dosen ============" << endl;
        while (P != NULL) {
            cout << "DATA DOSEN " << i << " : " << endl;
            cout << "Nama   : " << info(P).nama << endl;
            cout << "Kode   : " << info(P).kode << endl;
            cout << "Gender : " << info(P).gender << endl;

            addressMataKuliah PM = mataKuliah(P);

            if (PM == NULL) {
                cout << "Mata kuliah yang diajar: -\n";
            } else {
                cout << "Mata kuliah yang diajar: \n";
                int j = 1;
                int totalSKS = 0;
                while (PM != NULL) {
                    totalSKS += info(PM).sks;
                    cout << "   MATA KULIAH " << j << " : " << endl;
                    cout << "       Kode : " << info(PM).kode << endl;
                    cout << "       Nama : " << info(PM).nama << endl;
                    cout << "       SKS  : " << info(PM).sks << endl;
                    cout << endl;
                    PM = next(PM);
                    j++;
                }
                cout << "Total SKS yang diajar: " << totalSKS << endl;
            }

            P = next(P);
            i++;
            cout << endl;
        }
    }
    

    
}

void countMataKuliahDosenTertentu(ListDosen L) {
    string loopSearch = "y";

    while (loopSearch == "y") {
        cout << "Data seluruh dosen" << endl;
        showAllDosen(L);
        cout << "Cari data dosen berdasarkan KODE, untuk dihitung mata kuliahnya" << endl;
        cout << "Masukkan kode dosen : ";
        string kodeDosen;
        cin >> kodeDosen;

        addressDosen P = searchDosenByCode(L, kodeDosen);
        if (P == NULL) {
            cout << "Data dosen tidak ditemukan, coba ketikan kode dosen dengan benar" << endl;
            cout << endl;
        } else {
            cout<< "Data dosen ditemukan :" << endl;
            cout << "Total mata kuliah yang diajar oleh dosen : " << info(P).nama << " adalah ";
            addressMataKuliah PM = mataKuliah(P);
            int count = 0;
            while (PM != NULL) {
                count++;
                PM = next(PM);
            }
            cout << count << " mata kuliah" << endl;
            cout << endl;
        }

        cout << "Ingin mencari data dosen lagi? (y/t): ";
        cin >> loopSearch;
        loopSearch = toLowerCase(loopSearch);
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

void insertDataDummy(ListDosen &L, ListMataKuliah &M) {
    infotypeDosen DummyDosen;
    DummyDosen.nama = "Faiz Elfahad Kurniawan";
    DummyDosen.kode = "FEK";
    DummyDosen.gender = "Laki-Laki";

    addressDosen P = createElemenDosen(DummyDosen);
    insertFirstDosen(L, P);

    DummyDosen.nama = "Muamar Zidan";
    DummyDosen.kode = "MZD";
    DummyDosen.gender = "Laki-Laki";

    P = createElemenDosen(DummyDosen);
    insertFirstDosen(L, P);

    infotypeMataKuliah DummyMatkul;
    DummyMatkul.nama = "Algoritma Pemrograman 1";
    DummyMatkul.kode = "ALPRO-1";
    DummyMatkul.sks = 4;

    addressMataKuliah PM = createElemenMataKuliah(DummyMatkul);
    insertFirstMataKuliah(M, PM);

    DummyMatkul.nama = "Struktur Data";
    DummyMatkul.kode = "STD";
    DummyMatkul.sks = 4;

    PM = createElemenMataKuliah(DummyMatkul);
    insertFirstMataKuliah(M, PM);

    addMatkulToDosenV2(searchDosenByCode(L, "FEK"), searchMatkulByCode(M, "STD"));
    addMatkulToDosenV2(searchDosenByCode(L, "MZD"), searchMatkulByCode(M, "ALPRO-1"));
}

string toLowerCase(string s) {
    for (char &c : s) {
        if (c >= 'A' && c <= 'Z') {
            c += 32;
        }
    }

    return s;
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