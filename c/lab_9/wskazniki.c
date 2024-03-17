#include <stdio.h>

int main()
{
	int zmienna1 = 5;
	float zmienna2 = 4.75f;
	double zmienna3 = 2.00;
	char zmienna4 = 'w';
	
	int* wskaznik1 = &zmienna1;
	float* wskaznik2 = &zmienna2;
	double* wskaznik3 = &zmienna3;
	char* wskaznik4 = &zmienna4;
	int a,b,c,d,e,f,g,h;
	a=sizeof(wskaznik1);
	b=sizeof(wskaznik2);
	c=sizeof(wskaznik3);
	d=sizeof(wskaznik4);
	e=sizeof(zmienna1);
	f=sizeof(zmienna2);
	g=sizeof(zmienna3);
	h=sizeof(zmienna4);
	
	
	printf("Adresy zmiennych: \tint %p\tfloat %p \tdouble %p \tchar %p\n", &zmienna1, &zmienna2, &zmienna3, &zmienna4);
	printf("Adresy wskaznikow: \tint %p \tfloat %p \tdouble %p \tchar %p\n", &wskaznik1, &wskaznik2, &wskaznik3, &wskaznik4);
	printf("Rozmiary wskaznikow: \t%d \t%d \t%d \t%d\n",a,b,c,d);
	printf("Rozmiary zmiennych: \t%d \t%d \t%d \t%d\n",e,f,g,h);
	
}
