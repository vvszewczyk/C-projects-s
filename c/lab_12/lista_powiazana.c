#include <stdio.h>
#include <stdlib.h>

typedef struct element_listy 
{
    char* nazwa_wezla;
    int klucz;
    struct element_listy* nastepny_wezel;
} el_list;

int wstaw_na_poczatek(el_list** glowa, el_list* nowyElement) 
{
    nowyElement->nastepny_wezel = *glowa;
    *glowa = nowyElement;
    return 0;
}

void drukuj_lista(el_list* glowa) 
{
    printf("wydruk listy:   ");
    while (glowa) 
    {
        printf("%d  , ", glowa->klucz);
        glowa = glowa->nastepny_wezel;
    }
    printf("koniec\n");
}

int usun_lista(el_list** glowa, int klucz) 
{
    el_list* tmp = *glowa, * poprzedni = NULL;

    if (tmp && tmp->klucz == klucz) 
    {
        *glowa = tmp->nastepny_wezel;
        free(tmp->nazwa_wezla);
        free(tmp);
        return 0;
    }

    while (tmp && tmp->klucz != klucz) 
    {
        poprzedni = tmp;
        tmp = tmp->nastepny_wezel;
    }

    if (tmp == NULL) return -1;

    poprzedni->nastepny_wezel = tmp->nastepny_wezel;
    free(tmp->nazwa_wezla);
    free(tmp);
    return 0;
}

el_list* wyszukaj_lista(el_list* glowa, int klucz) 
{
    while (glowa)
    {
        if (glowa->klucz == klucz) return glowa;
        glowa = glowa->nastepny_wezel;
    }
    return NULL;
}

int main() 
{
    el_list* glowa = NULL;
    printf("\nZabawa z listą\n");

    for (int i = 0; i < 5; i++) 
    {
        el_list* nowyElement = malloc(sizeof(el_list));
        nowyElement->nazwa_wezla = malloc(20 * sizeof(char));
        sprintf(nowyElement->nazwa_wezla, "Węzeł %d", i + 1);
        nowyElement->klucz = i;
        nowyElement->nastepny_wezel = NULL;

        wstaw_na_poczatek(&glowa, nowyElement);
    }

    drukuj_lista(glowa);

    int kluczDoUsuniecia = 2;
    if (usun_lista(&glowa, kluczDoUsuniecia) == 0) 
    {
        printf("Usunięto element o kluczu %d\n", kluczDoUsuniecia);
    }
    else {
        printf("Nie znaleziono elementu o kluczu %d\n", kluczDoUsuniecia);
    }

    drukuj_lista(glowa);

    while (glowa) 
    {
        el_list* tmp = glowa;
        glowa = glowa->nastepny_wezel;
        free(tmp->nazwa_wezla);
        free(tmp);
    }

    return 0;
}
