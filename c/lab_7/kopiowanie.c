#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 100

int main(void) 
{
    char linia[MAXLINE];
    int zakres = MAXLINE - 1;
    int znak;
    int i;

    for (i = 0; i < zakres && (znak = getchar()) != EOF && znak != '\n'; i++) 
    {
        linia[i] = znak;
        printf("Znak: %d\n", (int)linia[i]);
    }

    if (znak == '\n') 
    {
        linia[i] = znak;
        i++;
    }

    linia[i] = '\0'; // Zakończenie tablicy znakiem null
    printf("%s", linia);

    return 0;
}
