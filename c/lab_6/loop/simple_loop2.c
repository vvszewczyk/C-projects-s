#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROZMIAR_TABLICY 10

void wczytajWartosci(int tablica[], int rozmiar);
void znajdzMaxIWyprintuj(int tablica[], int rozmiar);
void obliczSumeIWyprintuj(int tablica[], int rozmiar);
void inicjujTabliceLosowo(int tablica[], int rozmiar);
void obliczSredniaIWyprintuj(int tablica[], int rozmiar);
void wyszukajWartosc(int tablica[], int rozmiar);
void wyszukajWszystkieWartosci(int tablica[], int rozmiar, int szukana);

int main(void) 
{
    int tablica_int[ROZMIAR_TABLICY];

    wczytajWartosci(tablica_int, ROZMIAR_TABLICY);
    znajdzMaxIWyprintuj(tablica_int, ROZMIAR_TABLICY);
    obliczSumeIWyprintuj(tablica_int, ROZMIAR_TABLICY);
    inicjujTabliceLosowo(tablica_int, ROZMIAR_TABLICY);
    obliczSredniaIWyprintuj(tablica_int, ROZMIAR_TABLICY);
    wyszukajWartosc(tablica_int, ROZMIAR_TABLICY);

    return 0;
}

void wczytajWartosci(int tablica[], int rozmiar) 
{
    for (int i = 0; i < rozmiar; i++) 
    {
        printf("Podaj %d. wartość: ", i + 1);
        scanf("%d", &tablica[i]);
    }
}

void znajdzMaxIWyprintuj(int tablica[], int rozmiar) 
{
    int max = tablica[0];
    for (int i = 1; i < rozmiar; i++) 
    {
        if (tablica[i] > max) 
        {
            max = tablica[i];
        }
    }
    printf("Wartość max: %d\n", max);
}

void obliczSumeIWyprintuj(int tablica[], int rozmiar) 
{
    int suma = 0;
    for (int i = 0; i < rozmiar; i++) 
    {
        suma += tablica[i];
    }
    printf("Suma elementów tablicy: %d\n\n", suma);
}

void inicjujTabliceLosowo(int tablica[], int rozmiar) 
{
    srand(time(NULL));
    for (int i = 0; i < rozmiar; i++) 
    {
        tablica[i] = (rand() % ROZMIAR_TABLICY) + 1;
        printf("%d losowa liczba: %d\n", i + 1, tablica[i]);
    }
}

void obliczSredniaIWyprintuj(int tablica[], int rozmiar) 
{
    int licznik = 0;
    double srednia = 0;
    for (int i = 0; i < rozmiar; i++) 
    {
        licznik += tablica[i];
    }
    srednia = (double)licznik / rozmiar;
    double sredniaTeoretyczna = (126 + 33) / 2;
    printf("Średnia losowych liczb: %lf, średnia teoretyczna: %lf\n", srednia, sredniaTeoretyczna);
}

void wyszukajWartosc(int tablica[], int rozmiar) 
{
    int szukana;
    printf("Podaj szukaną wartość (1-20): ");
    scanf("%d", &szukana);
    int znaleziono = 0;
    for (int i = 0; i < rozmiar; i++) 
    {
        if (tablica[i] == szukana) 
        {
            printf("Znaleziono wartość %d w %d elemencie tablicy\n", szukana, i + 1);
            znaleziono = 1;
            break;
        }
    }
    if (!znaleziono) 
    {
        printf("Nie znaleziono szukanej wartości\n");
    }

    wyszukajWszystkieWartosci(tablica, rozmiar, szukana);
}

void wyszukajWszystkieWartosci(int tablica[], int rozmiar, int szukana) 
{
    printf("\nWyszukiwanie (i wypisywanie) wszystkich wartości\n");
    for (int i = 0; i < rozmiar; i++) 
    {
        if (tablica[i] == szukana) 
        {
            printf("Znaleziono wartość %d w %d elemencie tablicy\n", szukana, i + 1);
        }
    }
}
