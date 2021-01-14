#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int( * dzialanieT )( int);


int wskfunkcji(dzialanieT pdzialanie, int n)
{   time_t start, koniec;
    time(&start);
    pdzialanie(n);
    int s;
    scanf("%d",&s);
    time(&koniec);

    return (difftime(koniec,start));
}

void petla(int n)
{
    int count = 0;
    for(int i = 0; i<=n; ++i)
    {
        ++count;
    }
}

int main()
{
    int powtorzenia = 100000;
    printf("%d",wskfunkcji(petla, powtorzenia));
}
