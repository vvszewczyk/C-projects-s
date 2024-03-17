#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SCALAR float
#define SMALL_NUMBER 1.e-20
#define TOLERANCJA 1.e-15

// Funkcja do wczytywania parametrów równania kwadratowego
void wczytajParametry(SCALAR *a, SCALAR *b, SCALAR *c) 
{
    printf("\nPodaj parametr a: ");
    scanf("%f", a);
    printf("Podaj parametr b: ");
    scanf("%f", b);
    printf("Podaj parametr c: ");
    scanf("%f", c);
}

// Funkcja do rozwiązywania równania kwadratowego
void rozwiazRownanieKwadratowe(SCALAR a, SCALAR b, SCALAR c) 
{
    if (fabs(a) < SMALL_NUMBER) 
    {
        if (fabs(b) < SMALL_NUMBER) 
        {
            printf("Rownanie nieoznaczone lub sprzeczne.\n");
        } 
        else 
        {
            SCALAR xl = -c / b;
            printf("Pierwiastek rownania liniowego: x = %.12f\n", xl);
        }
    } 
    else 
    {
        SCALAR delta = b * b - 4 * a * c;

        if (delta < -SMALL_NUMBER) 
        {
            SCALAR realPart = -b / (2 * a);
            SCALAR imaginaryPart = sqrt(-delta) / (2 * a);
            printf("Dwa pierwiastki zespolone: x1 = %.12f + %.12fi, x2 = %.12f - %.12fi\n",
                   realPart, imaginaryPart, realPart, imaginaryPart);
        } 
        else if (fabs(delta) < SMALL_NUMBER) 
        {
            SCALAR x0 = -b / (2 * a);
            printf("Jeden pierwiastek rzeczywisty: x = %.12f\n", x0);
        } 
        else 
        {
            SCALAR sqrtDelta = sqrt(delta);
            SCALAR x1 = (-b - sqrtDelta) / (2 * a);
            SCALAR x2 = (-b + sqrtDelta) / (2 * a);
            printf("Dwa pierwiastki rzeczywiste: x1 = %.12f, x2 = %.12f\n", x1, x2);
        }
    }
}

int main(void) 
{
    printf("\nProgram rozwiazywania rownania kwadratowego ax^2 + bx + c = 0\n");

    SCALAR a, b, c;
    wczytajParametry(&a, &b, &c);
    rozwiazRownanieKwadratowe(a, b, c);

    return 0;
}
