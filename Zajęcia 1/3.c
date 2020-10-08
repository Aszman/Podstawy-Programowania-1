#include <stdio.h>

int main()
{
    char im[50];
    char naz[50];
    
    printf("Wpisz imię i nazwisko: ");
    scanf("%49s %49s", im, naz);
    printf("%s %s\n", naz, im);
    
    return 0;    
}
