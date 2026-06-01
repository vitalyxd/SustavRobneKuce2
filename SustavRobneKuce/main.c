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
    SORT_NAZIV = 7,
    REKURZIJA = 8
} Izbornik;

int main(void)
{
    int izbor = -1;

    do {

        printf("\n===== ROBNA KUCA =====\n");
        printf("1. Dodaj artikl\n");
        printf("2. Ispisi artikle\n");
        printf("3. Obrisi artikl\n");
        printf("4. Dinamicko polje\n");
        printf("5. Azuriraj artikl\n");
        printf("6. Sortiraj po cijeni\n");
        printf("7. Sortiraj po nazivu\n");
        printf("8. Rekurzivni ispis liste\n");
        printf("0. Izlaz\n");

        printf(">> ");

        if (scanf("%d", &izbor) != 1) {
            printf("Neispravan unos!\n");
            while (getchar() != '\n');
            continue;
        }

        if (izbor < 0 || izbor > 8) {
            printf("Neispravan izbor!\n");
            continue;
        }

        switch (izbor) {

        case DODAJ:
            dodajArtikl();
            break;

        case ISPIS:
            ispisiArtikle();
            break;

        case OBRISI:
            obrisiArtikl();
            break;

        case DINAMICKO_POLJE:
            ucitajArtikleUDinamickoPolje();
            break;

        case AZURIRAJ:
            azurirajArtikl();
            break;

        case SORT_CIJENA:
            sortirajArtiklePoCijeni();
            break;

        case SORT_NAZIV:
            sortirajArtiklePoNazivu();
            break;

        case REKURZIJA:
            loadList();

            printf("\nREKURZIVNI ISPIS:\n");
            ispisiListuRekurzivno(head);

            freeList();
            break;

        case IZLAZ:
            cleanup();
            printf("Izlaz iz programa.\n");
            break;
        }

    } while (izbor != IZLAZ);

    return 0;
}