#include <stdio.h>

int main(int argc, char **argv)
{
    for (int i =0; i<argc; ++i)  /* do repo */
    {   
        puts(argv[i]);
    }
    
    return 0;
} 
