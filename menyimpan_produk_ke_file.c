#include <stdio.h>

#define MAKS_PRODUK 100             // Mendefinisikan konstanta kapasitas maksimum produk
#define PANJANG_NAMA_PRODUK 50      // Mendefinisikan konstanta panjang maksimum nama produk
#define NAMA_FILE "produk.txt"      // Mendefinisikan konstanta nama file untuk menyimpan data produk

// Struktur untuk menyimpan data produk
typedef struct {
    char nama[PANJANG_NAMA_PRODUK]; // Menyimpan nama produk
    float harga;                    // Menyimpan harga produk
    int jumlah;                     // Menyimpan jumlah stok produk
} Produk;

// Deklarasi array produk dan anggota serta variabel untuk menyimpan jumlahnya
Produk produk[MAKS_PRODUK];
int jumlahProduk = 0;

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
int main(){
    simpanProdukKeFile(produk, jumlahProduk); // memanggil fungsi
};
