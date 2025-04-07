#include <stdio.h>

#define MAX_IME_PREZIME 30

#define MAX_IGRACI 100

typedef struct igrac
{
	char ime[MAX_IME_PREZIME];
	int visina;
	int tezina;
	int brKoseva;
	int brAsistencija;
	int brUkradenihLopti;
	int brBlokada;
	float ukupanBrBodova;
}igrac;

igrac igraci[MAX_IGRACI];

int br_igrac = 0;
int brBodova = 0;

igrac najbolji;

int ucitaj_igraca(FILE* f,igrac *i)
{
	fscanf (f,"%s%d%d%d%d%d%d", i->ime,&(i->visina),&(i->tezina),&(i->brKoseva),&(i->brAsistencija),&(i->brUkradenihLopti),&(i->brBlokada));
	
	if(feof(f))
	return 0;
	return 1;
}


float ukupanBrBodova(igrac i)
{
	float poeniKoseva = i.brKoseva * 1;
	float poeniAsistencije = i.brAsistencija * 0.5;
	float poeniUkradenihLopti = i.brUkradenihLopti * 0.3;
	float poeniBlokada = i.brBlokada * 0.2;
	
	i.ukupanBrBodova = poeniKoseva + poeniAsistencije + poeniUkradenihLopti + poeniBlokada;
	
	if(i.ukupanBrBodova > brBodova)
	{
		brBodova = i.ukupanBrBodova;
		najbolji = i;
		}	
		return i.ukupanBrBodova;
}

void ispisi_igrace() {
    int r;

    printf("IGRACI TURNIRA: V T K A U B        BROJ BODOVA\n");
    printf("*******************************************************\n");

    for (r = 0; r < br_igrac; r++) {
        printf("%-10s \t%d %d %d %d %d %d \t %.2f \n",
               igraci[r].ime, igraci[r].visina, igraci[r].tezina,
               igraci[r].brKoseva, igraci[r].brAsistencija,
               igraci[r].brUkradenihLopti, igraci[r].brBlokada,
               ukupanBrBodova(igraci[r]));
    }

    printf("\nNAJBOLJI IGRAC TURNIRA:\n");
    printf("*******************************************************\n");
    printf("LEGENDA:\n");
    printf("V - Visina igraca\n");
    printf("T - Tezina igraca\n");
    printf("K - Broj ostvarenih koseva igraca\n");
    printf("A - Broj asistencija igraca\n");
    printf("U - Broj ukradenih lopti igraca\n");
    printf("B - Broj blokada igraca\n\n");
}

main()
{
	FILE *f;
	
	char ime_datoteke[256];
	
	printf("U kojoj datoteci se nalaze podaci o igracima: ");
	scanf("%s", ime_datoteke);
	
	if((f = fopen(ime_datoteke, "r"))==NULL)
	{
		printf("Greska prilikom otvaranja datoteke %s\n", ime_datoteke);
		return;
	}
	
	while(ucitaj_igraca(f,&igraci[br_igrac]))
		br_igrac++;
		
	ispisi_igrace();
	
	fclose(f);
	
}































