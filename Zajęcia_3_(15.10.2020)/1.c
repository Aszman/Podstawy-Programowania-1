#include <stdio.h>
#include <math.h>

int main()
{
    char tablica[4][50]={"chuligan", "zbój", "chłystek", "leń"};
    
    unsigned int index;
        
    scanf("%d", &index);
    if (index <4)
    {
        printf("%s\n", tablica[index]);
    }
    else
    {
        printf("Indeks spoza przedziału\n");
    }

    return 0;
}
