#include <stdio.h>


void rotate(int *wska, int *wskb, int *wskc)                    
{
    int tmp = *wskc;
    *wskc = *wskb;
    *wskb = *wska;
    *wska = tmp;
}


int main()
{
    int a = 8;
    int b = 15;
    int c = 235;
    printf("a:%d b:%d c:%d\n", a,b, c);
    rotate(&a, &b, &c);
    printf("a:%d b:%d c:%d\n", a,b, c);
    return 0;
}
