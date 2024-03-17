#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int elementy;

void wypelnijLosowo(int *tab, int rozm)
{

    srand(time(NULL));

	int a = 0;
	int b = 9;

    for(int i = 0; i < rozm; i++)
	{
		tab[i] = a + rand() % (b - a) + 1;
		printf("%d\n", tab[i]);

    }
}

int swap(int *tab1, int *tab2)
{
	int temp = *tab2;
	*tab2 = *tab1;
	*tab1 = temp;
}

void bubblesort(int table[], int size)
{
	int i, j, temp;
	for (i = 0; i<size-1; i++)
    {
		for (j=0; j<size-1-i; j++)
		{
			if (table[j] > table[j+1])
			{
				swap(&table[j], &table[j+1]);
			}
		}
    }
}


int main()
{
	printf("Podaj ilosc elementow: ");
	scanf(" %d", &elementy);
	int tab[elementy];
	printf("Elementy przed losowaniem: \n");
	wypelnijLosowo(tab, elementy);
	
	printf("Elementy po losowaniu: \n");
	bubblesort(tab, elementy);
	
	for(int i=0; i<elementy; i++)
	{
		printf("%d\n",tab[i]);
	}
}
