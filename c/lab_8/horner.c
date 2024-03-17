#include <stdio.h>
#include <stdlib.h>

int horner(int wsp[], int st, int x) 
{
    int wynik = wsp[0];
    for (int i = 1; i <= st; i++)
    {
        wynik = wynik * x + wsp[i];
    }
    return wynik;
}

int main() 
{
    int stopien, argument;
    int* wspolczynniki;

    printf("Podaj stopień wielomianu: ");
    scanf("%d", &stopien);

    wspolczynniki = (int*)malloc((stopien + 1) * sizeof(int));


    for (int i = 0; i <= stopien; i++) 
    {
        printf("Podaj współczynnik stojący przy potędze %d: ", stopien - i);
        scanf("%d", &wspolczynniki[i]);
    }

    printf("Podaj argument: ");
    scanf("%d", &argument);

    printf("W( %d ) = %d", argument, horner(wspolczynniki, stopien, argument));

    free(wspolczynniki);

    return 0;
}
