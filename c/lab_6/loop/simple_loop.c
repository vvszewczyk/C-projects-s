#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROZMIAR_TABLICY 10

void wypelnijTablice(int tablica[], int rozmiar);
void drukujTablice(int tablica[], int rozmiar);
void znajdzMaxISume(int tablica[], int rozmiar);
void tablicaLosowaIZnaki(char tablicaChar[], int tablicaInt[], int rozmiar);
void sprawdzenieLosowosci(int tablica[], int rozmiar);
void wyszukajZadanaWartosc(int tablica[], int rozmiar);

int main(void) 
{
    int tablica_int[ROZMIAR_TABLICY];
    char tablica_char[ROZMIAR_TABLICY];

    wypelnijTablice(tablica_int, ROZMIAR_TABLICY);
    drukujTablice(tablica_int, ROZMIAR_TABLICY);
    znajdzMaxISume(tablica_int, ROZMIAR_TABLICY);

    tablicaLosowaIZnaki(tablica_char, tablica_int, ROZMIAR_TABLICY);
    sprawdzenieLosowosci(tablica_int, ROZMIAR_TABLICY);
    wyszukajZadanaWartosc(tablica_int, ROZMIAR_TABLICY);

    return 0;
}

void wypelnijTablice(int tablica[], int rozmiar) 
{
    for (int i = 0; i < rozmiar; i++) 
    {
        printf("\nPodaj %d wartosc: ", i + 1);
        scanf("%d", &tablica[i]);
    }
}


void drukujTablice(int tablica[], int rozmiar) 
{
    for (int i = 0; i < rozmiar; i++) 
    {
        printf("%d ", tablica[i]);
    }
    printf("\n");
}

void znajdzMaxISume(int tablica[], int rozmiar) 
{
    int max = 0;
    int suma = 0;
    for (int i = 0; i < rozmiar; i++) 
    {
        if (tablica[i] > max) 
        {
            max = tablica[i];
        }

        suma += tablica[i];
    }
    printf("\nWartosc max: %d\n", max);
    printf("Suma elementow tablicy: %d\n", suma);
}

void tablicaLosowaIZnaki(char tablicaChar[], int tablicaInt[], int rozmiar) 
{
    srand(time(NULL));
    for (int i = 0; i < rozmiar; i++) 
    {
        tablicaInt[i] = (rand() % rozmiar) + 1;
        tablicaChar[i] = (rand() % (126 - 33 + 1)) + 33;
        printf("\n%d losowa liczba: %d, losowy znak: %c\n", i + 1, tablicaInt[i], tablicaChar[i]);
    }
}

void sprawdzenieLosowosci(int tablica[], int rozmiar) 
{
    int licznik = 0;
    double srednia = 0;
    for (int i = 0; i < rozmiar; i++) 
    {
        licznik += tablica[i];
    }
    srednia = (double)licznik / rozmiar;
    double sredniaTeoretyczna = (126 + 33) / 2.0;
    printf("\nSrednia losowych liczb: %lf, srednia teoretyczna: %lf\n", srednia, sredniaTeoretyczna);
}

void wyszukajZadanaWartosc(int tablica[], int rozmiar) 
{
    int szukana;
    printf("Podaj szukana wartosc (1-20): ");
    scanf("%d", &szukana);
    for (int i = 0; i < rozmiar; i++) 
    {
        if (tablica[i] == szukana) 
        {
            printf("Znaleziono wartosc %d w %d elemencie tablicy\n", szukana, i + 1);
            return; // Zakończenie po znalezieniu pierwszej wartości
        }
    }
    printf("Nie znaleziono szukanej wartosci\n");
}
