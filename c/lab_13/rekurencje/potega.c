#include <stdio.h>
#include <assert.h>

int rekur()
{
    static int liczba_wywolan = 0;
    return ++liczba_wywolan;
}

int my_atoi(char s[])
{
    int sign = 1; // = (s[0]=='-') ? -1 : 1;
    if (s[0] == '-') sign = -1;
    int i = 0;
    if (s[0] == '+' || s[0] == '-') i++;
    int n = 0;
    while (s[i] >= '0' && s[i] <= '9') 
    {
        n = 10 * n + (s[i] - '0');
        i++;
    }
    return sign * n;
}

int power_int(int base, int n)
{
    int i, p;
    p = 1;
    for (i = 1; i <= n; ++i) 
    {
        p = p * base;
    }
    return p;
}

int power_int_rekur(int x, int n)
{
    printf("Wywolanie rekurencyjne, nr wywolania: %d\n", rekur());

    assert(n >= 0);

    if (n == 0) return 1;
    else if (n == 1) return(x);

    int intiger = power_int_rekur(x, n - 1);

    return intiger * x;
}

int main(int argc, char** argv)
{
    printf("Podaj podstawe: ");
    scanf("%d", &argc);
    printf("Podaj wykladnik: ");
    scanf("%s", *argv);

    int base = argc;
    int exp = my_atoi(*argv);

    printf("Dane z terminala: %d^%d=%d liczba wywolan rekurencyjnie:", base, exp, power_int_rekur(base, exp));
    printf(" %d\n", rekur() - 1);


    for (int i = 0; i < 10; ++i)
    {
        printf("iteracyjnie:   \t%d^%d = %3d \t%d^%d = %6d\n",
            2, i, power_int(2,i), -3, i, power_int(-3,i));

        printf("rekurencyjnie: \t%d^%d = %3d \t%d^%d = %6d\n",
            2, i, power_int_rekur(2,i), -3, i, power_int_rekur(-3,i));

    }
    */


    FILE* plik;
    plik = fopen("dane.txt", "r");
    if (plik == NULL) {
        puts("Brak pliku"); return 0;
    }
    fscanf(plik, "%d", &argc);
    fscanf(plik, "%s", *argv);

    fclose(plik);

    int base_f = argc;
    int exp_f = atoi(*argv);

    printf("Dane z pliku: %d^%d=%d\n", base_f, exp_f, power_int_rekur(base_f, exp_f));

    return 0;
}
