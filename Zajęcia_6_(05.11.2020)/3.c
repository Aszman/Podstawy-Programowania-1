#include <stdio.h>
#include <stdlib.h>

void ddouble(int size, int *dynTablica)
{
    dynTablica = realloc(dynTablica, 2*size * sizeof(*dynTablica));
    
    for(int i = size; i < 2*size; ++i)
    {
        dynTablica[i] = dynTablica[i%size];
    }
}

int main()
{
    int tab[] = {4,8,2,8,35,7};
    const int size = sizeof(tab)/sizeof(tab[0]);
        
    int *dynTablica = malloc(size * sizeof(tab));
    
    for(int i = 0; i < size; ++i)
    {
        dynTablica[i] = tab[i];
    }
    
    ddouble(size, dynTablica);
    
    for(int i =0; i < 2*size; ++i)
    {
        printf("%d ",dynTablica[i]);
    }
    
    free(dynTablica);
    
    return 0;
}
