#include <stdio.h>

#define BROJ_MESECI 12

int main() {
    int promet[BROJ_MESECI];
    int novi_niz[BROJ_MESECI];
    int i, unos;
    int pad_prometa = 0;

    // A + B) Unos sa kontrolom
    for (i = 0; i < BROJ_MESECI; i++) {
        do {
            printf("Unesite %% promene za mesec %d (dozvoljeni su jednocifreni i dvocifreni brojevi): ", i + 1);
            scanf("%d", &unos);
            if (unos < -99 || unos > 99) {
                printf("GRESKA: Unos mora biti jednocifren ili dvocifren broj (-99 do 99).\n");
            }
        } while (unos < -99 || unos > 99);

        promet[i] = unos;
    }

    // C) Formiranje novog niza (negativni napred, nenegativni pozadi)
    int indeks_novog_niza = 0;

    // Prvo negativni
    for (i = 0; i < BROJ_MESECI; i++) {
        if (promet[i] < 0) {
            novi_niz[indeks_novog_niza++] = promet[i];
        }
    }

    // Zatim nenegativni
    for (i = 0; i < BROJ_MESECI; i++) {
        if (promet[i] >= 0) {
            novi_niz[indeks_novog_niza++] = promet[i];
        }
    }

    // D) Broj meseci sa padom prometa
    for (i = 0; i < BROJ_MESECI; i++) {
        if (promet[i] < 0) {
            pad_prometa++;
        }
    }

    // Ispis novog niza
    printf("\nNovi niz (negativni napred, nenegativni pozadi):\n");
    for (i = 0; i < BROJ_MESECI; i++) {
        printf("%d ", novi_niz[i]);
    }

    // Ispis broja meseci sa padom
    printf("\n\nBroj meseci sa padom prometa: %d\n", pad_prometa);

    return 0;
}

