#include <stdio.h>

// Mendefinisikan konstanta untuk kapasitas maksimum produk dan anggota
#define MAKS_PRODUK 100
#define PANJANG_NAMA_PRODUK 50

// Struktur untuk menyimpan data produk
typedef struct {
    char nama[PANJANG_NAMA_PRODUK];
    float harga;
    int jumlah;
} Produk;

// Deklarasi array produk dan anggota, serta variabel untuk menyimpan jumlahnya
Produk produk[MAKS_PRODUK];
int jumlahProduk = 0, jumlahAnggota = 0;

// Fungsi untuk menambah produk
void tambahProduk(Produk produk[], int *jumlahProduk) {
    if (*jumlahProduk >= MAKS_PRODUK) {
        printf("Maaf, kapasitas produk penuh.\n");
        return;
    }

    printf("Masukkan nama produk: ");
    scanf("%s", produk[*jumlahProduk].nama);
    printf("Masukkan harga produk: ");
    scanf("%f", &produk[*jumlahProduk].harga);
    printf("Masukkan jumlah produk: ");
    scanf("%d", &produk[*jumlahProduk].jumlah);

    (*jumlahProduk)++;
}

int main (){
    tambahProduk(produk, &jumlahProduk);
    // Contoh output untuk verifikasi
    printf("Nama Produk: %s\n", produk[0].nama);
    printf("Harga Produk: %.2f\n", produk[0].harga);
    printf("Jumlah Produk: %d\n", produk[0].jumlah);
    return 0;
}