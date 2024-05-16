#include <stdio.h>      // Menyertakan pustaka standar input/output
#include <stdlib.h>     // Menyertakan pustaka standar umum
#include <string.h>     // Menyertakan pustaka untuk manipulasi string
#include <time.h>       // Menyertakan pustaka untuk manipulasi waktu

#define MAKS_PRODUK 100             // Mendefinisikan konstanta kapasitas maksimum produk
#define PANJANG_NAMA_PRODUK 50      // Mendefinisikan konstanta panjang maksimum nama produk
#define MAKS_ANGGOTA 100            // Mendefinisikan konstanta kapasitas maksimum anggota
#define NAMA_FILE "produk.txt"      // Mendefinisikan konstanta nama file untuk menyimpan data produk

// Struktur untuk menyimpan data produk
typedef struct {
    char nama[PANJANG_NAMA_PRODUK]; // Menyimpan nama produk
    float harga;                    // Menyimpan harga produk
    int jumlah;                     // Menyimpan jumlah stok produk
} Produk;

// Struktur untuk menyimpan data anggota
typedef struct {
    char nama[100];                 // Menyimpan nama anggota
    char tanggalBergabung[11];      // Menyimpan tanggal bergabung dalam format YYYY-MM-DD
    int adalahAnggota;              // Menyimpan status keanggotaan, 1 jika anggota, 0 jika bukan
} Anggota;

// Deklarasi array produk dan anggota serta variabel untuk menyimpan jumlahnya
Produk produk[MAKS_PRODUK];
Anggota anggota[MAKS_ANGGOTA];
int jumlahProduk = 0, jumlahAnggota = 0;

// Fungsi untuk melakukan proses login
int login() {
    char namaPengguna[50];
    char kataSandi[50];

    // Meminta input dari pengguna untuk login
    printf("Masukkan nama pengguna: ");
    scanf("%s", namaPengguna);
    printf("Masukkan kata sandi: ");
    scanf("%s", kataSandi);

    if (strcmp(namaPengguna, "pegawai") == 0 && strcmp(kataSandi, "pegawai123") == 0) {
        return 1;  // Login berhasil
    } else {
        printf("Nama pengguna atau kata sandi salah!\n");
        return 0;  // Login gagal
    }
}

// Fungsi untuk menambah produk
void tambahProduk(Produk produk[], int *jumlahProduk) {
    if (*jumlahProduk >= MAKS_PRODUK) {   // Cek apakah kapasitas produk sudah penuh
        printf("Maaf, kapasitas produk penuh.\n");
        return;
    }

    // Meminta input dari pengguna untuk menambahkan produk
    printf("Masukkan nama produk: ");
    scanf("%s", produk[*jumlahProduk].nama);    // Membaca nama produk dari input pengguna
    printf("Masukkan harga produk: ");
    scanf("%f", &produk[*jumlahProduk].harga);  // Membaca harga produk dari input pengguna
    printf("Masukkan jumlah produk: ");
    scanf("%d", &produk[*jumlahProduk].jumlah); // Membaca jumlah produk dari input pengguna

    (*jumlahProduk)++;  // Menambah jumlah produk
}

// Fungsi untuk mengurangi jumlah produk
void kurangiJumlahProduk(Produk produk[], int jumlahProduk) {
    char namaProduk[PANJANG_NAMA_PRODUK];
    printf("Masukkan nama produk yang akan dikurangi stoknya: ");
    scanf("%s", namaProduk);  // Membaca nama produk dari input pengguna

    // Mencari produk berdasarkan nama
    for (int i = 0; i < jumlahProduk; i++) {
        if (strcmp(produk[i].nama, namaProduk) == 0) {  // Membandingkan nama produk
            int jumlahKurang;
            printf("Masukkan jumlah stok yang akan dikurangi: ");
            scanf("%d", &jumlahKurang);  // Membaca jumlah pengurangan dari input pengguna

            if (produk[i].jumlah >= jumlahKurang) {  // Cek apakah stok mencukupi
                produk[i].jumlah -= jumlahKurang;    // Mengurangi stok produk
                printf("Stok produk %s berhasil dikurangi.\n", namaProduk);
            } else {
                printf("Stok produk tidak mencukupi.\n");  // Jika stok tidak cukup
            }
            return;
        }
    }

    printf("Produk tidak ditemukan.\n");  // Jika produk tidak ditemukan
}

// Fungsi untuk menampilkan daftar produk
void tampilkanProduk(Produk produk[], int jumlahProduk) {
    printf("Daftar Produk:\n");
    printf("---------------------------------------------------\n");
    printf("No  Nama              Harga      Jumlah\n");
    printf("---------------------------------------------------\n");

    // Menampilkan semua produk yang ada
    for (int i = 0; i < jumlahProduk; i++) {
        printf("%-3d %-15s   %-6.2f   %-6d\n", i+1, produk[i].nama, produk[i].harga, produk[i].jumlah);
    }

    printf("---------------------------------------------------\n");
}

// Fungsi untuk menyimpan data produk ke file
void simpanProdukKeFile(Produk produk[], int jumlahProduk) {
    FILE *file = fopen(NAMA_FILE, "w");  // Membuka file untuk menulis data produk
    if (file == NULL) {
        printf("Gagal membuka file untuk menyimpan data produk.\n");
        return;
    }

    // Menyimpan data setiap produk ke file
    for (int i = 0; i < jumlahProduk; i++) {
        fprintf(file, "%s %.2f %d\n", produk[i].nama, produk[i].harga, produk[i].jumlah);
    }

    fclose(file);  // Menutup file
    printf("Data produk berhasil disimpan ke file.\n");
}

// Fungsi penambahan member jika melakukan pembelian produk > 50000
void tambahAnggota(const char *namaPembeli) {
    if (jumlahAnggota >= MAKS_ANGGOTA) {  // Cek apakah kapasitas anggota sudah penuh
        printf("Kapasitas anggota penuh.\n");
        return;
    }

    strcpy(anggota[jumlahAnggota].nama, namaPembeli);  // Menyimpan nama pembeli sebagai member baru
    time_t sekarang = time(NULL);                      // Mendapatkan waktu sekarang
    struct tm *tm_struct = localtime(&sekarang);       // Mengubah waktu ke struktur tm
    sprintf(anggota[jumlahAnggota].tanggalBergabung, "%04d-%02d-%02d",
            tm_struct->tm_year + 1900, tm_struct->tm_mon + 1, tm_struct->tm_mday);  // Format tanggal bergabung
    anggota[jumlahAnggota].adalahAnggota = 1;  // Menandakan bahwa pembeli merupakan member

    jumlahAnggota++;  // Menambah jumlah member
    printf("Selamat! %s sekarang adalah anggota baru kami.\n", namaPembeli);
    printf("Anggota akan memperoleh diskon sebesar 5 persen tiap pembeliannya. Silahkan berbelanja lagi untuk memperoleh diskon!\n");
}

// Fungsi untuk mengecek apakah pembeli merupakan member
int cekAnggota(const char* nama) {
    // Mencari anggota berdasarkan nama
    for (int i = 0; i < jumlahAnggota; i++) {
        if (strcmp(anggota[i].nama, nama) == 0) {
            return anggota[i].adalahAnggota;  // Mengembalikan status member
        }
    }
    return 0;  // Mengembalikan 0 jika tidak ditemukan
}

// Fungsi untuk memproses pembayaran produk
void prosesPembayaran(Produk produk[], int jumlahProduk) {
    char namaProduk[PANJANG_NAMA_PRODUK];
    char namaPembeli[100];
    int jumlah;
    float total = 0.0;

    // Meminta input dari pengguna untuk memproses pembayaran
    printf("Masukkan nama produk yang ingin dibeli: ");
    scanf("%s", namaProduk);
    printf("Masukkan jumlah yang ingin dibeli: ");
    scanf("%d", &jumlah);
    printf("Masukkan nama pembeli: ");
    scanf("%s", namaPembeli);

    // Mencari produk berdasarkan nama
    for (int i = 0; i < jumlahProduk; i++) {
        if (strcmp(produk[i].nama, namaProduk) == 0) {
            if (produk[i].jumlah >= jumlah) {
                total = jumlah * produk[i].harga;  // Menghitung total harga

                // Cek jika pembeli adalah anggota
                if (cekAnggota(namaPembeli)) {
                    total *= 0.95;  // Memberikan diskon 5% untuk anggota
                }

                produk[i].jumlah -= jumlah;  // Mengurangi stok produk
                printf("Total yang harus dibayar: Rp %.2f\n", total);
                printf("Pembayaran berhasil!\n");
                if (total > 50000 && !cekAnggota(namaPembeli)) {
                    tambahAnggota(namaPembeli);  // Menambahkan pembeli sebagai anggota jika belum
                }
                return;
            } else {
                printf("Stok tidak cukup!\n");  // Jika stok tidak mencukupi
                return;
            }
        }
    }
    printf("Produk tidak ditemukan!\n");  // Jika produk tidak ditemukan
}

// Fungsi utama program
int main() {
    Produk produk[MAKS_PRODUK];
    int jumlahProduk = 0;

    // Membuka file untuk membaca data produk
    FILE *file = fopen(NAMA_FILE, "r");
    if (file != NULL) {
        // Membaca data produk dari file
        while (fscanf(file, "%s %f %d", produk[jumlahProduk].nama, &produk[jumlahProduk].harga, &produk[jumlahProduk].jumlah) == 3) {
            jumlahProduk++;
            if (jumlahProduk >= MAKS_PRODUK) {
                break;  // Berhenti membaca jika kapasitas penuh
            }
        }
        fclose(file);  // Menutup file
    }

    // Memeriksa login
    if (!login()) {
        return 0;  // Keluar jika login gagal
    }

    int pilihan;
    do {
        // Menampilkan menu
        printf("\nMenu:\n");
        printf("1. Tambah Produk\n");
        printf("2. Kurangi Stok Produk\n");
        printf("3. Tampilkan Daftar Produk\n");
        printf("4. Simpan Data Produk ke File\n");
        printf("5. Lakukan Pembayaran\n");
        printf("6. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);  // Membaca pilihan dari input pengguna

        // Menjalankan fungsi berdasarkan pilihan pengguna
        switch (pilihan) {
            case 1:
                tambahProduk(produk, &jumlahProduk);
                break;
            case 2:
                kurangiJumlahProduk(produk, jumlahProduk);
                break;
            case 3:
                tampilkanProduk(produk, jumlahProduk);
                break;
            case 4:
                simpanProdukKeFile(produk, jumlahProduk);
                break;
            case 5:
                prosesPembayaran(produk, jumlahProduk);
                break;
            case 6:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 6);  // Ulangi sampai pengguna memilih untuk keluar

    return 0;  // Program selesai
}
