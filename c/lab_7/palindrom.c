#include <stdio.h>
#define S 100

int i = 0, k = 0, q = 0;
char znak, linia[S], palindrom[S];

int main()
{
	printf("Podaj wyraz: ");
	for (i = 0; i < S && (znak = getchar()) != EOF && znak != '\n'; i++)
	{
		linia[i]=znak;
	}
	printf("Podano slowo od tylu: ");
	while (i > 0)
	{
		palindrom[k]=linia[i-1];
		i--;
		printf("%c",palindrom[k]);
		k++;	
	}
	printf("\n");
	while (q < k)
	{
		if (palindrom[q] != linia[q])
		{
			printf("Podany wyraz nie jest palindromem.\n");
			return 0;
		}
		q++;
	}
	printf("Podany wyraz jest palindromem\n");
}
