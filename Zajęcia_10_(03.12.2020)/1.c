#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("%d",miesiac());
}

int miesiac(void)  // do repo
{
    time_t czas;
    struct tm *aktualny;

    time( &czas);
    aktualny = localtime(&czas);

    return (aktualny->tm_mon+1);
}
