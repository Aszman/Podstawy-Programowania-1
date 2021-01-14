#include <stdio.h>

void swap(int *wsk1, int *wsk2)
{
    int tmp = *wsk2;
    *wsk2 = *wsk1;
    *wsk1 = tmp;
}

int main()
{
    int a = 8;
    int b = 15;

    printf("a:%d b:%d\n", a,b);
    swap(&a, &b);
    printf("a:%d b:%d\n", a,b);
    return 0;
}
