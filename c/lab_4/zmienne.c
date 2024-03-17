#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define dokladnosc 0.0001
#define funkcja(x,y) (((y - dokladnosc) < x) && (x < (y + dokladnosc)))
#define SIEDEM 7
#define marzec 3
#define pi 3.14
#define JednaTrzeciaFloat (1.0f/3.0f)
#define JednaTrzecia (1.0/3.0)
#define przykladDefine1 1.1234f
#define przykladDefine2 1.4321f
#define TOLERANCE 1e-12

int main(void) {
    int n = 7;
    char znak_do_testowania = 'a';
    printf("\nwartosc zmiennej n = %d, wartosc zmiennej znak_do_testowania = %c\n", n, znak_do_testowania);

    float zmienna1 = 3.1f;
    long double zmienna2 = 3.14;
    unsigned int zmienna3 = 7;
    unsigned char znak1 = 'h';
    bool prawda = true;
    printf("\nWartosc floata: %f, wartosc double: %Lf, wartosc inta: %d, wartosc chara: %c, wartosc boola: %d\n", zmienna1, zmienna2, zmienna3, znak1, prawda);

    int m = 2 * n + 3;
    int o = 2 * (n + 3);
    printf("\nn = %d, (2 * n + 3) = %d != (2 * (n + 3)) = %d\n", n, m, o);

    int wyrazenie1 = 2 + 2 * 2;
    int wyrazenie2 = (2 + 2) * 2;
    int dzialanie = wyrazenie1 + wyrazenie2 - 7;
    printf("\nWynik wyrazenia1 2+2*2: %d, wynik wyrazenia2 (2+2)*2: %d, wynik przykladowego dzialania: %d\n", wyrazenie1, wyrazenie2, dzialanie);

    int p = n++;
    n--;
    int q = ++n;
    n--;
    printf("\nn = %d, wynik podstawienia: 'p = n++;' - %d, wynik podstawienia: 'q = ++n;' - %d\n", n, p, q);

    n = 1574;
    m = n % 7;
    o = n / 7;
    printf("\nn = %d, m = %d, o = %d\n", n, m, o);

    int r = SIEDEM;
    printf("\nr = %d, stała SIEDEM = %d\n", r, SIEDEM);

    float f = 1.0f / 3.0f;
    float g = 1.0f / 3.0;
    double d = 1.0 / 3.0;
    double e = 1.0f / 3.0;
    printf("\nliczby zmiennoprzecinkowe:\n");
    printf("float - f = 1.0f/3.0f = %f (dokładnie: %20.15f)\n", f, f);
    printf("float - g = 1.0f/3.0 = %f (dokładnie: %20.15f)\n", g, g);
    printf("double - d = 1.0/3.0 = %lf (dokładnie: %20.15lf)\n", d, d);
    printf("double - e = 1.0f/3.0 = %lf (dokładnie: %20.15lf)\n", e, e);

    int a = n < m;
    _Bool b = n < m || n > m;
    printf("\nWartość logiczna wyrażenia: %d<%d wynosi %d (int a = n<m = %d)\n", n, m, n < m, a);
    printf("\nWartość logiczna wyrażenia: %d<%d lub %d>%d wynosi %d (_Bool b = n<m||n>m = %d)\n", n, m, n, m, (n < m) || (n > m), b);

    e = f; // e typu double, f typu float
    d = 1111 + 1000 * n; // d = (double) ...;
    n = f + 2.5; // n = (int) ...;
    printf("\nNiejawne i jawne konwersje typów:\n");
    printf("n = %d, f = %f, d = %lf, e = %le\n", n, f, d, e);

    d = JednaTrzecia * 3.0;
    e = JednaTrzeciaFloat * 3.0;
    printf("\nPrecyzja stałych i niejawne konwersje:\n");
    printf("(1.0/3.0)*3.0: \tJednaTrzecia -> d = %20.15lf; \n\t\tJednaTrzeciaFloat -> e = %20.15lf\n", d, e);

    printf("\nn = %d, m = %d\n", n, m);
    o = m+++n;
    printf("\tpo operacji o = m+++n = %d: n = %d, m = %d\n", o, n, m);

    printf("\nProgram dotarł do końca\n");
    return 0;
}
