#include <stdio.h>
#include <stdlib.h>

void zlozenie(char *a, char *b)
{
    static int count = 1;
    printf("%i: %s %s\n",count,a, b);
    ++count;
}

int main()
{
    zlozenie("error","komunikat");
    zlozenie("informacja","komunikat");
    
    return 0;
}
