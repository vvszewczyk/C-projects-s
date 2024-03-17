#include <stdio.h>

char znak, wyraz[100], odwrocony[100];
int i;

void odwracanie(char *wyraz, int dlugosc)
{
	int k=0;
	for (int j = dlugosc - 1; j >= 0; j--)
	{
		odwrocony[k]=wyraz[j];
		printf("%c", odwrocony[k++]);
	}
}

int main()
{
	for (i = 0; i < 100 && (znak = getchar()) != EOF && znak != '\n'; i++)
	{
		wyraz[i]=znak;
	}
	printf(" ");
	odwracanie(wyraz, i);
	printf("\n");
}
