#include <stdio.h>

int main(void) 
{
    char c;

    for (;;) 
{
        printf("Podaj liczbe 0-5 lub wpisz q zeby wyjsc: ");
        scanf(" %c", &c); // Użycie " %c" pochłania biały znak (np. enter)

        if (c >= '0' && c <= '5') 
        {
            printf("Wprowadzono: %c\n", c);
        } 
        else if (c == 'q') 
        {
            printf("Wyjscie z programu.\n");
            return 0;
        } 
        else 
        {
            printf("Wprowadzono: znak spoza zakresu 0-5\n");
        }
    }
}
