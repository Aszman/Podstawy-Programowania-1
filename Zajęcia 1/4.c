#include <stdio.h>

int main()
{
    float liczba1=0;
    int liczba2=0;
    scanf("%f", &liczba1);
    liczba2 = liczba1;
    printf("%f",liczba1-=liczba2);
    
    return 0;
}
