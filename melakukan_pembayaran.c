// Fungsi untuk memproses pembayaran produk
void prosesPembayaran(Produk produk[], int jumlahProduk) {
    char namaProduk[PANJANG_NAMA_PRODUK];
    char namaPembeli[100];
    int jumlah;
    float total = 0.0;

    printf("Masukkan nama produk yang ingin dibeli: ");
    scanf("%s", namaProduk);
    printf("Masukkan jumlah yang ingin dibeli: ");
    scanf("%d", &jumlah);
    printf("Masukkan nama pembeli: ");
    scanf("%s", namaPembeli);

    // Melakukan iterasi verdasarkan array produk
    for (int i = 0; i < jumlahProduk; i++) { 
        if (strcmp(produk[i].nama, namaProduk) == 0) {
            if (produk[i].jumlah >= jumlah) {
                total = jumlah * produk[i].harga;

                // Menjumlahkan total pembayaran setelah memperhitungkan diskon khusus member
                total = hitungTotalDenganDiskon(namaPembeli, total);
                produk[i].jumlah -= jumlah; // Mengurangi stok produk setelah pembelian
                printf("Total yang harus dibayar: Rp %.2f\n", total);
                printf("Pembayaran berhasil!\n");
                // Menambahkan pembeli sebagai member jika pembelian mencapai lebih dari 50000
                if (total > 50000 && !cekAnggota(namaPembeli)) {
                    tambahAnggota(namaPembeli);  
                }
                return;
            } else {
                printf("Stok tidak cukup!\n");
                return;
            }
        }
    }
    printf("Produk tidak ditemukan!\n");
}
