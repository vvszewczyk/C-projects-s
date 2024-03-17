#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int kodw;
    char nazwa_wydawnictwa[20];
    int oc_czyt;
    int liczba_pracownikow;
    int liczba_wydanych_ksiazek;
} Wydawnictwo;

typedef struct 
{
    int id;
    char tytul[20];
    char autor[20];
    int rok_wydania;
    Wydawnictwo sr_oc[3];
    int total;
    float per;
} Ksiazka;

void utworz() 
{
    int n;
    printf("Podaj ile ksiazek chcesz utworzyc: ");
    scanf("%d", &n);
    Ksiazka* s = (Ksiazka*)calloc(n, sizeof(Ksiazka));
    FILE* fp = fopen("plik.txt", "w+");
    for (int i = 0; i < n; i++) 
    {
        printf("Podaj ID, tytul, autora i rok wydania ksiazki: ");
        scanf("%d %19s %19s %d", &s[i].id, s[i].tytul, s[i].autor, &s[i].rok_wydania);
        for (int j = 0; j < 3; j++) 
        {
            printf("Podaj ocene %d czytelnika: ", j + 1);
            scanf("%d", &s[i].sr_oc[j].oc_czyt);
            s[i].total += s[i].sr_oc[j].oc_czyt;
        }
        s[i].per = (float)s[i].total / 3.0;
        fwrite(&s[i], sizeof(Ksiazka), 1, fp);
    }
    fclose(fp);
    free(s);
}

void dodaj() 
{
    int n;
    printf("Podaj ile ksiazek chcesz dodac: ");
    scanf("%d", &n);
    Ksiazka* s = (Ksiazka*)calloc(n, sizeof(Ksiazka));
    FILE* fp = fopen("plik.txt", "a");
    for (int i = 0; i < n; i++) 
    {
        printf("Podaj ID, tytul, autora i rok wydania ksiazki: ");
        scanf("%d %19s %19s %d", &s[i].id, s[i].tytul, s[i].autor, &s[i].rok_wydania);
        for (int j = 0; j < 3; j++) 
        {
            printf("Podaj ocene %d czytelnika: ", j + 1);
            scanf("%d", &s[i].sr_oc[j].oc_czyt);
            s[i].total += s[i].sr_oc[j].oc_czyt;
        }
        s[i].per = (float)s[i].total / 3.0;
        fwrite(&s[i], sizeof(Ksiazka), 1, fp);
    }
    fclose(fp);
    free(s);
}

void wyswietl() 
{
    Ksiazka s1;
    FILE* fp = fopen("plik.txt", "r");
    while (fread(&s1, sizeof(Ksiazka), 1, fp)) 
    {
        printf("\nID: %d, Tytul: %s, Autor: %s, Rok wydania: %d\n", s1.id, s1.tytul, s1.autor, s1.rok_wydania);
        for (int j = 0; j < 3; j++) 
        {
            printf("Ocena %d czytelnika: %d\n", j + 1, s1.sr_oc[j].oc_czyt);
        }
        printf("Srednia ocen: %.2f\n", s1.per);
    }
    fclose(fp);
}

void usun() 
{
    int id;
    printf("Podaj ID ksiazki do usuniecia: ");
    scanf("%d", &id);
    FILE* fp = fopen("plik.txt", "r"), * fp1 = fopen("temp.txt", "w");
    Ksiazka s1;
    int znaleziono = 0;
    while (fread(&s1, sizeof(Ksiazka), 1, fp)) 
    {
        if (s1.id != id) 
        {
            fwrite(&s1, sizeof(Ksiazka), 1, fp1);
        }
        else 
        {
            znaleziono = 1;
        }
    }
    fclose(fp);
    fclose(fp1);
    if (znaleziono) 
    {
        remove("plik.txt");
        rename("temp.txt", "plik.txt");
    }
    else 
    {
        printf("Nie znaleziono ksiazki o ID: %d\n", id);
        remove("temp.txt");
    }
}

void sortuj_malejaco() 
{
    FILE* fp = fopen("plik.txt", "r+");
    if (!fp) 
    {
        printf("Nie mozna otworzyc pliku.\n");
        return;
    }

    fseek(fp, 0, SEEK_END);
    long rozmiar = ftell(fp);
    int liczba_ksiazek = rozmiar / sizeof(Ksiazka);
    rewind(fp);

    Ksiazka* ksiazki = (Ksiazka*)calloc(liczba_ksiazek, sizeof(Ksiazka));
    if (!ksiazki) 
    {
        printf("Nie udalo sie zaalokowac pamieci.\n");
        fclose(fp);
        return;
    }

    for (int i = 0; i < liczba_ksiazek; i++) 
    {
        fread(&ksiazki[i], sizeof(Ksiazka), 1, fp);
    }

    for (int i = 0; i < liczba_ksiazek - 1; i++) 
    {
        for (int j = 0; j < liczba_ksiazek - i - 1; j++) 
        {
            if (ksiazki[j].per < ksiazki[j + 1].per) 
            {
                Ksiazka temp = ksiazki[j];
                ksiazki[j] = ksiazki[j + 1];
                ksiazki[j + 1] = temp;
            }
        }
    }

    rewind(fp);
    for (int i = 0; i < liczba_ksiazek; i++) 
    {
        fwrite(&ksiazki[i], sizeof(Ksiazka), 1, fp);
    }

    free(ksiazki);
    fclose(fp);
}


void sortuj_alfabetycznie() 
{
    FILE* fp = fopen("plik.txt", "r+");
    fseek(fp, 0, SEEK_END);
    long n = ftell(fp) / sizeof(Ksiazka);
    rewind(fp);
    Ksiazka* s = (Ksiazka*)calloc(n, sizeof(Ksiazka));
    for (long i = 0; i < n; i++) 
    {
        fread(&s[i], sizeof(Ksiazka), 1, fp);
    }

    for (long i = 0; i < n - 1; i++) 
    {
        for (long j = 0; j < n - i - 1; j++) 
        {
            if (strcmp(s[j].tytul, s[j + 1].tytul) > 0) 
            {
                Ksiazka temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    rewind(fp);
    for (long i = 0; i < n; i++) 
    {
        fwrite(&s[i], sizeof(Ksiazka), 1, fp);
    }
    fclose(fp);
    free(s);
}

void szukaj() 
{
    int id;
    printf("Podaj ID ksiazki do wyszukania: ");
    scanf("%d", &id);
    FILE* fp = fopen("plik.txt", "r");
    Ksiazka s1;
    int znaleziono = 0;
    while (fread(&s1, sizeof(Ksiazka), 1, fp)) 
    {
        if (s1.id == id) 
        {
            znaleziono = 1;
            break;
        }
    }
    if (!znaleziono) 
    {
        printf("Nie znaleziono ksiazki o ID: %d\n", id);
    }
    fclose(fp);
}



int main() 
{
    int wybor;
    do 
    {
        printf("\n\n1. Utworz");
        printf("\n2. Dodaj");
        printf("\n3. Wyswietl");
        printf("\n4. Usun");
        printf("\n5. Sortuj malejaco");
        printf("\n6. Sortuj alfabetycznie");
        printf("\n7. Wyszukiwanie poszczegolnej ksiazki");
        printf("\n0. Wyjscie");
        printf("\nWybierz opcje: ");
        scanf("%d", &wybor);
        switch (wybor) 
        {
        case 1: utworz(); break;
        case 2: dodaj(); break;
        case 3: wyswietl(); break;
        case 4: usun(); break;
        case 5: sortuj_malejaco(); break;
        case 6: sortuj_alfabetycznie(); break;
        case 7: szukaj(); break;
        case 0: exit(0); break;
        default: printf("\nNiepoprawna opcja. Sprobuj ponownie.\n");
        }
    } while (wybor != 0);

    return 0;
}

