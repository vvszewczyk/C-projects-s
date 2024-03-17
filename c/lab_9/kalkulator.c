#include <stdio.h>

double a, b;


double dodawanie(double aF, double bF)
{
	return aF+bF;
}

double odejmowanie(double aF, double bF)
{
	return aF-bF;
}

double mnozenie(double aF, double bF)
{
	return aF*bF;
}

double dzielenie(double aF, double bF)
{
	return aF/bF;
}

int main()
{
	printf("Podaj a: ");
	scanf("%lf", &a);
	printf("Podaj b: ");
	scanf("%lf", &b);
	
	double (*tablica_funkcji[4])(double, double)={&dodawanie, &odejmowanie, &mnozenie, &dzielenie};
	printf("\nDodawanie: %lf\n",tablica_funkcji[0](a, b));
	printf("Odejmowanie: %lf\n",tablica_funkcji[1](a, b));
	printf("Mnozenie: %lf\n",tablica_funkcji[2](a, b));
	printf("Dzielenie: %lf\n",tablica_funkcji[3](a, b));
}
