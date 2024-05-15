#include <stdio.h>

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
int main(){};