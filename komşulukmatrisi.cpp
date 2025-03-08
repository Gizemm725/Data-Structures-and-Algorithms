#include <stdio.h>
#include <stdlib.h>

#define MAX_DUGUM 10
#define INF -1 // Aðýrlýk olmayan yerler için -1 kullanýyoruz.

// Komþuluk matrisini baþlatma fonksiyonu
void matrisBaslat(int matris[MAX_DUGUM][MAX_DUGUM]) {
    for (int i = 0; i < MAX_DUGUM; i++) {
        for (int j = 0; j < MAX_DUGUM; j++) {
            matris[i][j] = INF;  // Baþlangýçta tüm kenarlar yok, yani -1 ile baþlatýlýr.
        }
    }
}

// Düðüm ekleme fonksiyonu (Aðýrlýklý)
void dugumEkle(int matris[MAX_DUGUM][MAX_DUGUM], int src, int dest, int agirlik) {
    matris[src][dest] = agirlik; // src'den dest'e giden kenarýn aðýrlýðýný ekler.
}

// Komþuluk matrisini yazdýrma fonksiyonu
void yazdir(int matris[MAX_DUGUM][MAX_DUGUM]) {
    for (int i = 0; i < MAX_DUGUM; i++) {
        printf("Düðüm %d: ", i);
        int bos = 1;
        for (int j = 0; j < MAX_DUGUM; j++) {
            if (matris[i][j] != INF) { // INF olmayan yerleri yazdýrýyoruz.
                printf(" -> %d (Aðýrlýk: %d)", j, matris[i][j]);
                bos = 0;
            }
        }
        if (bos) {
            printf("Baðlantý yok.");
        }
        printf("\n");
    }
}

int main() {
    int matris[MAX_DUGUM][MAX_DUGUM]; // Komþuluk matrisi
    matrisBaslat(matris);  // Baþlangýçta tüm kenarlarý -1 ile baþlat

    // Aðýrlýklý kenarlarý ekleyelim
    dugumEkle(matris, 0, 1, 10);  // 0 -> 1 (Aðýrlýk: 10)
    dugumEkle(matris, 0, 4, 5);   // 0 -> 4 (Aðýrlýk: 5)
    dugumEkle(matris, 1, 2, 3);   // 1 -> 2 (Aðýrlýk: 3)
    dugumEkle(matris, 2, 3, 7);   // 2 -> 3 (Aðýrlýk: 7)

    // Komþuluk matrisini yazdýralým
    yazdir(matris);
    
    return 0;
}

