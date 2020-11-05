#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

int main()
{
    struct S1{
        bool b;
        double d;
        char c;
        int i;
    };
    
    struct S2{
        double d;                                  
        int i;
        bool b;
        char c;
    };
    
    printf("S1: %ld\n", sizeof(struct S1));
    printf("S2: %ld\n", sizeof(struct S2));
    
    return 0;
}
