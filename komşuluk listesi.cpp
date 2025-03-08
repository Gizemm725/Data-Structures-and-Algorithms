#include <stdio.h>
#include <stdlib.h>
#define MAX_DUGUM 10


// Aðýrlýklý graf için düðüm yapýsý
typedef struct dugum {
    int dugum_no;
    int agirlik;          // Kenarýn aðýrlýðý
    struct dugum *pNext;  // Sonraki komþu
} DUGUMLER;

// Komþuluk listesi yapýsý
typedef struct liste {
    DUGUMLER *satir[MAX_DUGUM]; // Komþuluk listesi
} LISTELER;

// Düðüm ekleme fonksiyonu (Aðýrlýklý) - Yeni komþuyu baþa ekle
void dugumEkle(LISTELER *graf, int src, int dest, int agirlik) {
    DUGUMLER *yeniDugum = (DUGUMLER*) malloc(sizeof(DUGUMLER));
    if (yeniDugum == NULL) {
        printf("Bellek tahsisi baþarýsýz!\n");
        return;
    }
    yeniDugum->dugum_no = dest;
    yeniDugum->agirlik = agirlik; // Kenarýn aðýrlýðýný ekle
    yeniDugum->pNext = graf->satir[src];  // Yeni düðümün pNext'ini mevcut baþa baðla
    
    graf->satir[src] = yeniDugum; // Yeni düðümü baþa ekle
}

// Komþuluk listesini yazdýrma fonksiyonu
void yazdir(LISTELER *graf) {
    for (int i = 0; i < MAX_DUGUM; i++) {
        DUGUMLER *p = graf->satir[i];
        printf("Düðüm %d: ", i);
        while (p != NULL) {
            printf("-> %d (Aðýrlýk: %d) ", p->dugum_no, p->agirlik);
            p = p->pNext;
        }
        printf("-> NULL\n");
    }
}

// Belleði temizleme fonksiyonu (Gereksiz bellek kullanýmý önlenir)
void bellekTemizle(LISTELER *graf) {
    for (int i = 0; i < MAX_DUGUM; i++) {
        DUGUMLER *p = graf->satir[i];
        while (p != NULL) {
            DUGUMLER *temp = p;
            p = p->pNext;
            free(temp);
        }
        graf->satir[i] = NULL;
    }
}

int main() {
    LISTELER graf;
    
    // Komþuluk listesini NULL ile baþlat
    for (int i = 0; i < MAX_DUGUM; i++) {
        graf.satir[i] = NULL;
    }
    
    // Aðýrlýklý kenarlarý ekleyelim
    dugumEkle(&graf, 0, 1, 10);
    dugumEkle(&graf, 0, 4, 5);
    dugumEkle(&graf, 1, 2, 3);
    dugumEkle(&graf, 2, 3, 7);
    
    // Komþuluk listesini yazdýralým
    yazdir(&graf);

    // Belleði temizleyelim
    bellekTemizle(&graf);
    
    return 0;
}

