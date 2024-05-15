// Fungsi penambahan member jika melakukan pembelian produk > 50000
void tambahAnggota(const char *namaPembeli) { 
    if (jumlahAnggota >= MAKS_ANGGOTA) {
        printf("Kapasitas member penuh.\n");
        return;
    }

    // Menyimpan nama pembeli sebagai member baru
    strcpy(anggota[jumlahAnggota].nama, namaPembeli);
    time_t sekarang = time(NULL);
    struct tm *tm_struct = localtime(&sekarang);
    // Mengubah tanggal saat ini pada string dan menyimpannya pada data member baru
    sprintf(anggota[jumlahAnggota].tanggalBergabung, "%04d-%02d-%02d",
            tm_struct->tm_year + 1900, tm_struct->tm_mon + 1, tm_struct->tm_mday);
    anggota[jumlahAnggota].adalahAnggota = 1;  // Menandakan bahwa ini adalah member
    jumlahAnggota++;
    
    printf("Selamat! %s sekarang adalah member baru kami.\n", namaPembeli);
    printf("Member akan memperoleh diskon sebesar 5 persen tiap pembeliannya. Silahkan berbelanja lagi untuk memperoleh diskon!\n");
}

// Fungsi untuk pengecekan member
int cekAnggota(const char* nama) { 
    for (int i = 0; i < jumlahAnggota; i++) {
        if (strcmp(anggota[i].nama, nama) == 0) {
            return anggota[i].adalahAnggota;
        }
    }
    return 0; // Mengembalikan nilai 0 apabila pembeli bukan member
}
