#include <stdio.h>

int czyszczenie(int tab[])
{
    for (int i=0; i<5; ++i)
    {
        tab[i]=0;
        printf("tab[%d]: %d ",i , tab[i]);
    }
    printf("\n");
    
}

int main()
{
    int tab[5] = {0,34,77,24,7};
    for (int i=0; i<5; ++i)
    {
        printf("tab[%d]: %d ",i , tab[i]); 
    }
    printf("\n");
    
    czyszczenie(tab);
    
    for (int i=0; i<5; ++i)
    {
        printf("tab[%d]: %d ",i , tab[i]);
    }
    
    return 0;
}
