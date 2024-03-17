#include <stdio.h>
#define S 100

int main()
{
	char znak, linia[S], podany[S];
	int i;
		
	printf("Podaj wyraz do zaszyfrowania: ");
	for (i = 0; i < S && (znak = getchar()) != EOF && znak != '\n'; i++)
	{
		linia[i] = znak + 3;
		podany[i] = znak;
	}
	
	linia[i]='\0';
	podany[i]='\0';
	int dlugosc=i;
	printf("\n");
	printf("Podany wyraz %s zostal zamieniony na %s\nIlosc znakow: %d\n", podany, linia, dlugosc);
	
	
	return 0;
}
