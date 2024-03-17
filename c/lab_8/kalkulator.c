#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define ACCURACY (1.e-5)

double dodawanie(double a, double b) 
{
    return a + b;
}

double odejmowanie(double a, double b) 
{
    return a - b;
}

double mnozenie(double a, double b) 
{
    return a * b;
}

double dzielenie(double a, double b) 
{
    if (b == 0) 
    {
        printf("B³¹d: dzielenie przez 0!\n");
        return 0;
    }
    return a / b;
}

double pierwiastekF(double liczba) 
{
    if (liczba < 0.0) 
    {
        printf("Podano wartosc ujemna. Podaj wartosc dodatnia... \n");
        return -1;
    }
    double pierwiastek = 1.0;
    double temp;
    do 
    {
        temp = pierwiastek;
        pierwiastek = 0.5 * (temp + liczba / temp);
    } 
    while (fabs(pierwiastek * pierwiastek - liczba) / liczba > ACCURACY);
    return pierwiastek;
}

double potegowanie(int x, int y) 
{
    double wynik = 1;
    for (int i = 0; i < y; i++)
    {
        wynik *= x;
    }
    return wynik;
}

double silnia(int x) 
{
    double wynik = 1;
    for (int i = 2; i <= x; i++) 
    {
        wynik *= i;
    }
    return wynik;
}

int main() 
{
    for (;;) 
    {
        char wybor;
        double a, b, wynik;
        int x, y;
        printf("\nWybierz dzialanie: \n 1 - dodawanie\n 2 - odejmowanie\n 3 - mnozenie\n 4 - dzielenie\n 5 - pierwiastek kwadratowy\n 6 - potegowanie\n 7 - silnia\n q - wyjscie z programu \n");
        scanf(" %c", &wybor);

        switch (wybor) 
        {
        case '1':
            printf("Podaj a i b: ");
            scanf("%lf %lf", &a, &b);
            wynik = dodawanie(a, b);
            printf("Wynik: %lf\n", wynik);
            break;
        case '2':
            printf("Podaj a i b: ");
            scanf("%lf %lf", &a, &b);
            wynik = odejmowanie(a, b);
            printf("Wynik: %lf\n", wynik);
            break;
        case '3':
            printf("Podaj a i b: ");
            scanf("%lf %lf", &a, &b);
            wynik = mnozenie(a, b);
            printf("Wynik: %lf\n", wynik);
            break;
        case '4':
            printf("Podaj a i b: ");
            scanf("%lf %lf", &a, &b);
            wynik = dzielenie(a, b);
            printf("Wynik: %lf\n", wynik);
            break;
        case '5':
            printf("Podaj liczbe: ");
            scanf("%lf", &a);
            wynik = pierwiastekF(a);
            if (wynik >= 0)
                printf("Pierwiastek: %lf\n", wynik);
            break;
        case '6':
            printf("Podaj podstawe i wykladnik: ");
            scanf("%d %d", &x, &y);
            wynik = potegowanie(x, y);
            printf("Wynik: %lf\n", wynik);
            break;
        case '7':
            printf("Podaj liczbe: ");
            scanf("%d", &x);
            wynik = silnia(x);
            printf("%d! = %lf\n", x, wynik);
            break;
        case 'q':
            return 0;
        default:
            printf("Niepoprawny wybor!\n");
            break;
        }
    }
    return 0;
}
