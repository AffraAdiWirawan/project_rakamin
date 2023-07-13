// Belajarrrrrrrr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

const int MAX_MAHASISWA = 100;
int NIM[MAX_MAHASISWA];
string nama[MAX_MAHASISWA];
string jurusan[MAX_MAHASISWA];
int tahunMasuk[MAX_MAHASISWA];
int jumlahMahasiswa = 0;

void tambahMahasiswa() {
	if (jumlahMahasiswa < MAX_MAHASISWA) {
		cout << "Masukkan NIM: ";
		cin >> NIM[jumlahMahasiswa];
		cin.ignore();

		cout << "Masukkan nama: ";
		getline(cin, nama[jumlahMahasiswa]);

		cout << "Masukkan jurusan: ";
		getline(cin, jurusan[jumlahMahasiswa]);

		cout << "Masukkan tahun masuk: ";
		cin >> tahunMasuk[jumlahMahasiswa];

		jumlahMahasiswa++;

		cout << "Data mahasiswa berhasil ditambahkan!" << endl;
	}
	else {
		cout << "Kapasitas maksimum mahasiswa telah tercapai." << endl;
	}
}

void tampilkanSemuaMahasiswa() {
	if (jumlahMahasiswa > 0) {
		cout << "Data Mahasiswa:" << endl;
		for (int i = 0; i < jumlahMahasiswa; i++) {
			cout << "NIM     : " << NIM[i] << endl;
			cout << "Nama    : " << nama[i] << endl;
			cout << "Jurusan : " << jurusan[i] << endl;
			cout << "Tahun Masuk: " << tahunMasuk[i] << endl;
			cout << endl;
		}
	}
	else {
		cout << "Belum ada data mahasiswa." << endl;
	}
}

void cariMahasiswaByNIM() {
	if (jumlahMahasiswa > 0) {
		int nimCari;
		cout << "Masukkan NIM yang ingin dicari: ";
		cin >> nimCari;

		bool ditemukan = false;
		for (int i = 0; i < jumlahMahasiswa; i++) {
			if (NIM[i] == nimCari) {
				cout << "Data Mahasiswa:" << endl;
				cout << "NIM     : " << NIM[i] << endl;
				cout << "Nama    : " << nama[i] << endl;
				cout << "Jurusan : " << jurusan[i] << endl;
				cout << "Tahun Masuk: " << tahunMasuk[i] << endl;
				cout << endl;
				ditemukan = true;
				break;
			}
		}

		if (!ditemukan) {
			cout << "Mahasiswa dengan NIM " << nimCari << " tidak ditemukan." << endl;
		}
	}
	else {
		cout << "Belum ada data mahasiswa." << endl;
	}
}

void algorithmSortByTahunMasuk() {
	if (jumlahMahasiswa > 0) {
		// Sorting data berdasarkan tahun masuk menggunakan algoritma bubble sort
		for (int i = 0; i < jumlahMahasiswa - 1; i++) {
			for (int j = 0; j < jumlahMahasiswa - i - 1; j++) {
				if (tahunMasuk[j] > tahunMasuk[j + 1]) {
					// Swap data
					swap(NIM[j], NIM[j + 1]);
					swap(nama[j], nama[j + 1]);
					swap(jurusan[j], jurusan[j + 1]);
					swap(tahunMasuk[j], tahunMasuk[j + 1]);
				}
			}
		}

		cout << "Data Mahasiswa berdasarkan Tahun Masuk:" << endl;
		for (int i = 0; i < jumlahMahasiswa; i++) {
			cout << "NIM     : " << NIM[i] << endl;
			cout << "Nama    : " << nama[i] << endl;
			cout << "Jurusan : " << jurusan[i] << endl;
			cout << "Tahun Masuk: " << tahunMasuk[i] << endl;
			cout << endl;
		}
	}
	else {
		cout << "Belum ada data mahasiswa." << endl;
	}
}

int main() {
	int pilihan;
	do {
		cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
		cout << "1. Tambah Mahasiswa" << endl;
		cout << "2. Tampilkan Semua Mahasiswa" << endl;
		cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
		cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore();

		switch (pilihan) {
		case 1:
			tambahMahasiswa();
			break;
		case 2:
			tampilkanSemuaMahasiswa();
			break;
		case 3:
			cariMahasiswaByNIM();
			break;
		case 4:
			algorithmSortByTahunMasuk();
			break;
		case 5:
			cout << "Terima kasih! Program selesai." << endl;
			break;
		default:
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		}
		cout << endl;
	} while (pilihan != 5);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
