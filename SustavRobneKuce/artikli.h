#ifndef ARTIKLI_H
#define ARTIKLI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 50
#define MAX_KATEGORIJA 30

typedef struct {
    int id;
    char naziv[MAX_NAZIV];
    float cijena;
    int kolicina;
    char kategorija[MAX_KATEGORIJA];
} Artikl;

/* ===== LINKED LIST ===== */
typedef struct Node {
    Artikl data;
    struct Node* next;
} Node;

/* ===== GLOBALS ===== */
extern Node* head;
extern int brojArtikala;

/* ===== CRUD ===== */
int generirajID();
void dodajArtikl();
void ispisiArtikle();
void obrisiArtikl();
void azurirajArtikl();

/* ===== DYNAMIC ARRAY ===== */
void ucitajArtikleUDinamickoPolje();

/* ===== SORT ===== */
void sortirajArtiklePoCijeni();
void sortirajArtiklePoNazivu();

/* ===== SEARCH ===== */
void pretraziArtiklLinear(int id);
void pretraziArtiklBSearch(int id);

/* ===== LIST ===== */
Node* createNode(Artikl a);
void loadList();
void freeList();
void cleanup();

#endif