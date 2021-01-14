#include <stdio.h>
#include <stdlib.h>

int* createTab(int *tab, int size)
{
    int *dynTablica = malloc(size * sizeof(*tab));
    
    for(int i = 0; i < size; ++i)
    {
        dynTablica[i] = tab[i];
    }
    
    return dynTablica;
}

int main()
{
    int tab[] = {4,8,2,8,35,7};
    const int size = sizeof(tab)/sizeof(tab[0]);  
        
    int *newTab = createTab(tab, size);
    
    for(int i =0; i < size; ++i)
    {
        printf("%d\n",newTab[i]);
    }
    
    free(newTab);
    
    return 0;
}
