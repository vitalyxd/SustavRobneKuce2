#define _CRT_SECURE_NO_WARNINGS
#include "artikli.h"


Node* head = NULL;
int brojArtikala = 0;

static int brojPoziva = 0;


Node* createNode(Artikl a) {

    Node* n = (Node*)malloc(sizeof(Node));
    if (!n) return NULL;

    n->data = a;
    n->next = NULL;

    return n;
}


int generirajID() {

    FILE* fp = fopen("artikli.txt", "r");
    if (!fp) return 1;

    Artikl t;
    int last = 0;

    while (fscanf(fp,
        "%d|%49[^|]|%f|%d|%29[^\n]\n",
        &t.id, t.naziv, &t.cijena, &t.kolicina, t.kategorija) == 5) {
        last = t.id;
    }

    fclose(fp);
    return last + 1;
}


void dodajArtikl() {

    brojPoziva++;

    FILE* fp = fopen("artikli.txt", "a");
    if (!fp) {
        perror("FILE ERROR");
        return;
    }

    Artikl a;
    a.id = generirajID();

    printf("ID: %d\n", a.id);

    printf("Naziv: ");
    scanf(" %49[^\n]", a.naziv);

    printf("Cijena: ");
    scanf("%f", &a.cijena);

    printf("Kolicina: ");
    scanf("%d", &a.kolicina);

    printf("Kategorija: ");
    scanf(" %29[^\n]", a.kategorija);

    fprintf(fp, "%d|%s|%.2f|%d|%s\n", a.id, a.naziv, a.cijena, a.kolicina, a.kategorija);

    fclose(fp);

    printf("Broj dodavanja: %d\n", brojPoziva);
}


void ispisiArtikle() {

    FILE* fp = fopen("artikli.txt", "r");
    if (!fp) return;

    Artikl a;

    while (fscanf(fp,
        "%d|%49[^|]|%f|%d|%29[^\n]\n", &a.id, a.naziv, &a.cijena, &a.kolicina, a.kategorija) == 5) {

        printf("\n%d | %s | %.2f | %d | %s", a.id, a.naziv, a.cijena, a.kolicina, a.kategorija);
    }

    fclose(fp);
}


void obrisiArtikl() {

    FILE* fp = fopen("artikli.txt", "r");
    FILE* tmp = fopen("temp.txt", "w");

    if (!fp || !tmp) {
        perror("FILE ERROR");
        return;
    }

    int id;
    printf("ID za brisanje: ");
    scanf("%d", &id);

    Artikl a;
    int found = 0;

    while (fscanf(fp,
        "%d|%49[^|]|%f|%d|%29[^\n]\n", &a.id, a.naziv, &a.cijena, &a.kolicina, a.kategorija) == 5) {

        if (a.id == id) {
            found = 1;
            continue;
        }

        fprintf(tmp, "%d|%s|%.2f|%d|%s\n", a.id, a.naziv, a.cijena, a.kolicina, a.kategorija);
    }

    fclose(fp);
    fclose(tmp);

    remove("artikli.txt");
    rename("temp.txt", "artikli.txt");

    printf(found ? "Obrisano\n" : "Nije nadeno\n");
}


void azurirajArtikl() {

    FILE* fp = fopen("artikli.txt", "r");
    FILE* tmp = fopen("temp.txt", "w");

    if (!fp || !tmp) {
        perror("FILE ERROR");
        return;
    }

    int id;
    printf("ID za update: ");
    scanf("%d", &id);

    Artikl a;
    int found = 0;

    while (fscanf(fp,"%d|%49[^|]|%f|%d|%29[^\n]\n", &a.id, a.naziv, &a.cijena, &a.kolicina, a.kategorija) == 5) {

        if (a.id == id) {
            found = 1;

            printf("NOVI NAZIV: ");
            scanf(" %49[^\n]", a.naziv);

            printf("NOVA CIJENA: ");
            scanf("%f", &a.cijena);

            printf("NOVA KOLICINA: ");
            scanf("%d", &a.kolicina);

            printf("NOVA KATEGORIJA: ");
            scanf(" %29[^\n]", a.kategorija);
        }

        fprintf(tmp, "%d|%s|%.2f|%d|%s\n", a.id, a.naziv, a.cijena, a.kolicina, a.kategorija);
    }

    fclose(fp);
    fclose(tmp);

    remove("artikli.txt");
    rename("temp.txt", "artikli.txt");

    printf(found ? "UPDATE OK\n" : "NOT FOUND\n");
}

// dinamicka lista
void ucitajArtikleUDinamickoPolje() {

    FILE* fp = fopen("artikli.txt", "r");
    if (!fp) return;

    Artikl* arr = NULL;
    int n = 0;
    Artikl t;

    while (fscanf(fp,"%d|%49[^|]|%f|%d|%29[^\n]\n", &t.id, t.naziv, &t.cijena, &t.kolicina, t.kategorija) == 5) {

        Artikl* tmp = realloc(arr, (n + 1) * sizeof(Artikl));
        if (!tmp) {
            free(arr);
            fclose(fp);
            return;
        }

        arr = tmp;
        arr[n++] = t;
    }

    fclose(fp);

    printf("\nDINAMICKO POLJE:\n");

    for (int i = 0; i < n; i++) {
        printf("%d | %s | %.2f | %d | %s\n",arr[i].id, arr[i].naziv, arr[i].cijena,arr[i].kolicina, arr[i].kategorija);
    }

    free(arr);
}

// usporedba
int cmpCijena(const void* a, const void* b) {
    float x = ((Artikl*)a)->cijena;
    float y = ((Artikl*)b)->cijena;
    return (x > y) - (x < y);
}

int cmpNaziv(const void* a, const void* b) {
    return strcmp(((Artikl*)a)->naziv,
        ((Artikl*)b)->naziv);
}


void sortirajArtiklePoCijeni() {

    FILE* fp = fopen("artikli.txt", "r");
    if (!fp) return;

    Artikl* arr = NULL;
    int n = 0;
    Artikl t;

    while (fscanf(fp,"%d|%49[^|]|%f|%d|%29[^\n]\n",&t.id, t.naziv, &t.cijena, &t.kolicina, t.kategorija) == 5) {

        Artikl* tmp = realloc(arr, (n + 1) * sizeof(Artikl));
        if (!tmp) {
            free(arr);
            fclose(fp);
            return;
        }

        arr = tmp;
        arr[n++] = t;
    }

    fclose(fp);

    qsort(arr, n, sizeof(Artikl), cmpCijena);

    printf("\nSORT CIJENA:\n");

    for (int i = 0; i < n; i++)
        printf("%d | %s | %.2f\n",arr[i].id, arr[i].naziv, arr[i].cijena);

    free(arr);
}

void sortirajArtiklePoNazivu() {

    FILE* fp = fopen("artikli.txt", "r");
    if (!fp) return;

    Artikl* arr = NULL;
    int n = 0;
    Artikl t;

    while (fscanf(fp,"%d|%49[^|]|%f|%d|%29[^\n]\n", &t.id, t.naziv, &t.cijena, &t.kolicina, t.kategorija) == 5) {

        Artikl* tmp = realloc(arr, (n + 1) * sizeof(Artikl));
        if (!tmp) {
            free(arr);
            fclose(fp);
            return;
        }

        arr = tmp;
        arr[n++] = t;
    }

    fclose(fp);

    qsort(arr, n, sizeof(Artikl), cmpNaziv);

    printf("\nSORT NAZIV:\n");

    for (int i = 0; i < n; i++)
        printf("%d | %s\n", arr[i].id, arr[i].naziv);

    free(arr);
}


void pretraziArtiklLinear(int id) {

    FILE* fp = fopen("artikli.txt", "r");
    if (!fp) return;

    Artikl a;

    while (fscanf(fp,"%d|%49[^|]|%f|%d|%29[^\n]\n", &a.id, a.naziv, &a.cijena, &a.kolicina, a.kategorija) == 5) {

        if (a.id == id) {
            printf("FOUND: %s\n", a.naziv);
            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("NOT FOUND\n");
}

int cmpID(const void* a, const void* b) {
    return ((Artikl*)a)->id - ((Artikl*)b)->id;
}

void pretraziArtiklBSearch(int id) {

    FILE* fp = fopen("artikli.txt", "r");
    if (!fp) return;

    Artikl* arr = NULL;
    int n = 0;
    Artikl t;

    while (fscanf(fp,"%d|%49[^|]|%f|%d|%29[^\n]\n", &t.id, t.naziv, &t.cijena, &t.kolicina, t.kategorija) == 5) {

        Artikl* tmp = realloc(arr, (n + 1) * sizeof(Artikl));
        if (!tmp) {
            free(arr);
            fclose(fp);
            return;
        }

        arr = tmp;
        arr[n++] = t;
    }

    fclose(fp);

    qsort(arr, n, sizeof(Artikl), cmpID);

    Artikl key = { id, "", 0, 0, "" };

    Artikl* res = bsearch(&key, arr, n, sizeof(Artikl), cmpID);

    printf(res ? "FOUND\n" : "NOT FOUND\n");

    free(arr);
}


void loadList() {

    FILE* fp = fopen("artikli.txt", "r");
    if (!fp) return;

    Artikl t;

    while (fscanf(fp, "%d|%49[^|]|%f|%d|%29[^\n]\n", &t.id, t.naziv, &t.cijena, &t.kolicina, t.kategorija) == 5) {

        Node* n = createNode(t);
        if (!n) continue;

        n->next = head;
        head = n;
    }

    fclose(fp);
}

void freeList() {

    Node* tmp;

    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void cleanup() {
    freeList();
}


void ispisiListuRekurzivno(Node* current) {

    if (current == NULL)
        return;

    printf("%d | %s | %.2f | %d | %s\n", 
        current->data.id,
        current->data.naziv,
        current->data.cijena,
        current->data.kolicina,
        current->data.kategorija);

    ispisiListuRekurzivno(current->next);
}