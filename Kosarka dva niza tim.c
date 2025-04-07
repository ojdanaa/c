#include <stdio.h>

#define CETVRTINE 4

// Funkcija koja proverava da li je broj dvocifren i nenegativan
int unosPoena(int brojCetvrtine, int tim) {
    int poeni;
    do {
        printf("Unesite broj poena za cetvrtinu %d (Tim %d): ", brojCetvrtine + 1, tim);
        scanf("%d", &poeni);
        if (poeni < 10 || poeni > 99) {
            printf("GRESKA: Poeni moraju biti dvocifren broj (od 10 do 99)!\n");
        }
    } while (poeni < 10 || poeni > 99);
    return poeni;
}

// Funkcija za racunanje ukupnog rezultata
int ukupnoPoena(int niz[], int duzina) {
    int suma = 0;
    int i;
    for (i = 0; i < duzina; i++) {
        suma += niz[i];
    }
    return suma;
}

 main() {
    int tim1[CETVRTINE], tim2[CETVRTINE], razlika[CETVRTINE];
	int i;
    // Unos poena za prvi tim
    for ( i = 0; i < CETVRTINE; i++) {
        tim1[i] = unosPoena(i, 1);
    }

    // Unos poena za drugi tim
    for (i = 0; i < CETVRTINE; i++) {
        tim2[i] = unosPoena(i, 2);
    }

    // Kreiranje treceg niza sa razlikom poena
    printf("\nRazlika poena po cetvrtinama:\n");
    for ( i = 0; i < CETVRTINE; i++) {
        if (tim1[i] > tim2[i]) {
            razlika[i] = tim1[i] - tim2[i];
        } else {
            razlika[i] = tim2[i] - tim1[i];
        }
        printf("Cetvrtina %d: %d\n", i + 1, razlika[i]);
    }

    // Ukupni poeni i pobednik
    int ukupno1 = ukupnoPoena(tim1, CETVRTINE);
    int ukupno2 = ukupnoPoena(tim2, CETVRTINE);

    printf("\nUkupno poena:\n");
    printf("Tim 1: %d\n", ukupno1);
    printf("Tim 2: %d\n", ukupno2);

    if (ukupno1 > ukupno2) {
        printf("Pobednik je Tim 1!\n");
    } else if (ukupno2 > ukupno1) {
        printf("Pobednik je Tim 2!\n");
    } else {
        printf("Utakmica je neresena!\n");
    }

    return 0;
}

