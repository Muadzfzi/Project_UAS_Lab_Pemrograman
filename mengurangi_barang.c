#include <stdio.h>
#include <string.h> 

#define MAKS_PRODUK 100             // Mendefinisikan konstanta kapasitas maksimum produk
#define PANJANG_NAMA_PRODUK 50      // Mendefinisikan konstanta panjang maksimum nama produk

// Struktur untuk menyimpan data produk
typedef struct {
    char nama[PANJANG_NAMA_PRODUK]; // Menyimpan nama produk
    float harga;                    // Menyimpan harga produk
    int jumlah;                     // Menyimpan jumlah stok produk
} Produk;

// Deklarasi array produk dan anggota serta variabel untuk menyimpan jumlahnya
Produk produk[MAKS_PRODUK];
int jumlahProduk = 0;

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

int main(){
    kurangiJumlahProduk(produk, jumlahProduk); // memanggil fungsi
};
