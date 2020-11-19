#include <stdio.h>


void swaptext(char *t1, char *t2)
{
    int i = 0;
    while (*t1 != '\0')
    {
        char tmp = *t1;
        *t1 = *t2;
        *t2 = tmp;
        t1 = t1 + 1;
        t2 = t2 + 1;                            /*do repo */
    }    
}


int main()
{
    char text1[] = "slowo1";
    char text2[] = "drugie";
    
    printf("%s %s\n", text1, text2);
    
    swaptext(text1, text2);
    
    printf("%s %s\n", text1, text2);
    
    return 0;
}
