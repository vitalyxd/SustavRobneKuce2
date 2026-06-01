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

typedef struct Node {
    Artikl data;
    struct Node* next;
} Node;


extern Node* head;
extern int brojArtikala;


int generirajID();
void dodajArtikl();
void ispisiArtikle();
void obrisiArtikl();
void azurirajArtikl();

// polje
void ucitajArtikleUDinamickoPolje();

void sortirajArtiklePoCijeni();
void sortirajArtiklePoNazivu();


void pretraziArtiklLinear(int id);
void pretraziArtiklBSearch(int id);

//lista
Node* createNode(Artikl a);
void loadList();
void freeList();
void cleanup();


void ispisiListuRekurzivno(Node* current);

#endif