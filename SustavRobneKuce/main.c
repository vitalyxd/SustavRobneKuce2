#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "artikli.h"

typedef enum {
    IZLAZ = 0,
    DODAJ = 1,
    ISPIS = 2,
    OBRISI = 3,
    DINAMICKO_POLJE = 4,
    AZURIRAJ = 5,
    SORT_CIJENA = 6,
    SORT_NAZIV = 7
} Izbornik;

int main() {

    int izbor;

    do {
        printf("\n===== ROBNA KUCA =====\n");
        printf("1. Dodaj\n2. Ispis\n3. Obrisi\n4. Dinamicko polje\n5. Update\n6. Sort cijena\n7. Sort naziv\n0. Exit\n");
        printf(">> ");
        scanf("%d", &izbor);

        switch (izbor) {

        case DODAJ: dodajArtikl(); break;
        case ISPIS: ispisiArtikle(); break;
        case OBRISI: obrisiArtikl(); break;
        case DINAMICKO_POLJE: ucitajArtikleUDinamickoPolje(); break;
        case AZURIRAJ: azurirajArtikl(); break;
        case SORT_CIJENA: sortirajArtiklePoCijeni(); break;
        case SORT_NAZIV: sortirajArtiklePoNazivu(); break;

        case IZLAZ:
            cleanup();
            printf("Exit...\n");
            break;

        default:
            printf("Krivi unos\n");
        }

    } while (izbor != 0);

    return 0;
}