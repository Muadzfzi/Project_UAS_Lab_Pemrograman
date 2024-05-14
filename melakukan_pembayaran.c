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

    for (int i = 0; i < jumlahProduk; i++) {
        if (strcmp(produk[i].nama, namaProduk) == 0) {
            if (produk[i].jumlah >= jumlah) {
                total = jumlah * produk[i].harga;

                total = hitungTotalDenganDiskon(namaPembeli, total);

                produk[i].jumlah -= jumlah; // Mengurangi stok
                printf("Total yang harus dibayar: Rp %.2f\n", total);
                printf("Pembayaran berhasil!\n");
                if (total > 50000 && !cekAnggota(namaPembeli)) {
                    tambahAnggota(namaPembeli);  // Menambahkan pembeli sebagai anggota jika belum
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
