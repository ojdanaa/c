#include <stdio.h>

int main() {
    float rezultati[10];
    int i;
    float zbir = 0;
    int pobede = 0, porazi = 0;

    // A) Unos rezultata
    for (i = 0; i < 10; i++) {
        do {
            printf("Unesite rezultat za partiju %d (1 - pobeda, 0.5 - remi, 0 - poraz): ", i + 1);
            scanf("%f", &rezultati[i]);
            if (rezultati[i] != 0 && rezultati[i] != 0.5 && rezultati[i] != 1) {
                printf("GRESKA: Dozvoljene vrednosti su samo 0, 0.5 ili 1.\n");
            }
        } while (rezultati[i] != 0 && rezultati[i] != 0.5 && rezultati[i] != 1);

        zbir += rezultati[i];
        if (rezultati[i] == 1) pobede++;
        else if (rezultati[i] == 0) porazi++;
    }

    // B) Ukupan broj poena
    printf("\nUkupan broj poena: %.1f\n", zbir);

    // C) Poredenje broja pobeda i poraza
    if (pobede > porazi) {
        printf("Igrac ima vise dobijenih nego izgubljenih partija.\n");
    } else if (porazi > pobede) {
        printf("Igrac ima vise izgubljenih nego dobijenih partija.\n");
    } else {
        printf("Igrac ima jednak broj dobijenih i izgubljenih partija.\n");
    }

    return 0;
}

