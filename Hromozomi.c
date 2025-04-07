#include <stdio.h>

void sortiraj(int niz[], int n) {
    int i, j, temp;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(niz[i] > niz[j]) {
                temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }
}

int main() {
    int hromozomi[23];
    int broj = 0;
    int unos;
    char nastavi;

    printf("Unesite redne brojeve hromozomskih parova za analizu (od 1 do 23).\n");

    do {
        do {
            printf("Unesite broj hromozomskog para: ");
            scanf("%d", &unos);
            if(unos < 1 || unos > 23) {
                printf("GRESKA: Broj mora biti u opsegu 1-23.\n");
            }
        } while(unos < 1 || unos > 23);

        hromozomi[broj++] = unos;

        if(broj == 23) {
            printf("Uneli ste maksimalan broj hromozomskih parova (23).\n");
            break;
        }

        printf("Zelite li da unesete jos jedan hromozomski par? (d/n): ");
        scanf(" %c", &nastavi);

    } while(nastavi == 'd' || nastavi == 'D');

    // Sortiranje
    sortiraj(hromozomi, broj);

    // Ispis kariograma
    printf("\nKariogram (sortirani hromozomski parovi):\n");
    
    int i;
    for(i = 0; i < broj; i++) {
        printf("%d ", hromozomi[i]);
    }
    printf("\n");

    // Provera za 21. hromozom
    int nadjen21 = 0;
    for(i = 0; i < broj; i++) {
        if(hromozomi[i] == 21) {
            nadjen21 = 1;
            break;
        }
    }

    if(nadjen21) {
        printf("Analiza rizika za Daunov sindrom je ukljucena (hromozom 21 je u analizi).\n");
    } else {
        printf("Hromozom 21 NIJE ukljucen u analizu. Nema provere rizika za Daunov sindrom.\n");
    }

    return 0;
}

