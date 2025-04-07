#include <stdio.h>

typedef struct {
    int pobede;
    int originalni_index;
} Reprezentacija;

void sortirajOpadajuce(Reprezentacija niz[], int duzina) {
    int i, j;
    Reprezentacija temp;
    for(i = 0; i < duzina - 1; i++) {
        for(j = i + 1; j < duzina; j++) {
            if(niz[i].pobede < niz[j].pobede) {
                temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }
}

int main() {
    Reprezentacija reprezentacije[8];
    int i;    
    int unos;

    // Unos broja pobeda za 8 reprezentacija
    for(i = 0; i < 8; i++) {
        do {
            printf("Unesite broj pobeda za reprezentaciju %d: ", i + 1);
            scanf("%d", &unos);
            if(unos < 0 || unos > 9) {
                printf("GRESKA: Broj mora biti jednocifren (0-9).\n");
            }
        } while(unos < 0 || unos > 9);

        reprezentacije[i].pobede = unos;
        reprezentacije[i].originalni_index = i + 1; // Spremamo originalni indeks
    }

    // Sortiramo reprezentacije po broju pobeda
    sortirajOpadajuce(reprezentacije, 8);
    
    // Izdvajamo najbolje 4 i najgore 4 reprezentacije
    printf("\nNajbolje 4 reprezentacije su: \n");
    for(i = 0; i < 4; i++) {
        printf("Reprezentacija %d sa %d pobeda\n", reprezentacije[i].originalni_index, reprezentacije[i].pobede);
    }

    printf("\nNajslabije 4 reprezentacije su: \n");
    for(i = 4; i < 8; i++) {
        printf("Reprezentacija %d sa %d pobeda\n", reprezentacije[i].originalni_index, reprezentacije[i].pobede);
    }
    
    return 0;
}

