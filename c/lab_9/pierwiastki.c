#include <stdio.h>
#include <math.h>


void pierwiastki2(double aF, double bF, double delta, double *tablicaF)
{
	
	double x1, x2;
	x1=(-bF-sqrt(delta))/2*aF;
	tablicaF[0]=x1;
	x2=(-bF+sqrt(delta))/2*aF;
	tablicaF[1]=x2;
	
	
}

double pierwiastek1(double aF, double bF)
{
	double x0;
	x0=-bF/(2*aF);
	
	return x0;
}

int main()
{
	double a, b, c, delta;
	double tablica[2];
	printf("Podaj a:");
	scanf("%lf", &a);
	printf("Podaj b:");
	scanf("%lf", &b);
	printf("Podaj c:");
	scanf("%lf", &c);
	delta=(b*b)-4*a*c;
	
	if(delta>0)
	{
	pierwiastki2(a, b, delta, tablica);
	printf("Delta = %lf\n", delta);
	printf("x1 = %lf\n", tablica[0]);
	printf("x2 = %lf\n", tablica[1]);
	}
	else if(delta==0)
	{
	printf("x0 = %lf\n",pierwiastek1(a, b));
	}
	else
	printf("Brak pierwiastkow rzeczywistych\n");
}
