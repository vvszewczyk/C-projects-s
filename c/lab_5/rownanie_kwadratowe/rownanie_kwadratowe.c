#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SCALAR float
#define SMALL_NUMBER 1.e-20
#define TOLERANCJA 1.e-15

int main(void) 
{
    printf("\nProgram rozwiazywania rownania kwadratowego ax^2 + bx + c = 0\n");

    SCALAR a, b, c;
    printf("\nPodaj parametr a: "); scanf("%f", &a);
    printf("Podaj parametr b: "); scanf("%f", &b);
    printf("Podaj parametr c: "); scanf("%f", &c);

    if (fabs(a) < SMALL_NUMBER && fabs(b) < SMALL_NUMBER) 
    {
        printf("Bledne dane: a i b rowne 0 (zbyt bliskie 0). Przerwanie programu.\n");
        exit(-1);
    }

    if (fabs(a) < TOLERANCJA) 
    {
        // Rozwiązanie dla równania liniowego bx + c = 0
        SCALAR xl = -c / b;
        printf("Pierwiastek rownania liniowego: x = %f\n", xl);
    } 
    else 
    {
        SCALAR delta = b * b - 4 * a * c;
        SCALAR x0 = -b / (2 * a);

        if (delta < 0) 
        {
            // Równanie ma pierwiastki zespolone
            SCALAR czlon_imaginarny = sqrt(fabs(delta)) / (2 * a);
            printf("\nDwa pierwiastki zespolone: x1 = %f + %fi, x2 = %f - %fi\n", x0, czlon_imaginarny, x0, czlon_imaginarny);
        } 
        else if (delta == 0) 
        {
            printf("\nJeden pierwiastek rzeczywisty: x = %.12le\n", x0);
        } 
        else 
        {
            // Równanie ma dwa pierwiastki rzeczywiste
            SCALAR sqrt_delta = sqrt(delta);
            SCALAR x1 = (-b - sqrt_delta) / (2 * a);
            SCALAR x2 = (-b + sqrt_delta) / (2 * a);
            printf("\nDwa pierwiastki rzeczywiste: x1 = %.12le, x2 = %.12le\n", x1, x2);
        }
    }

    return 0;
}
