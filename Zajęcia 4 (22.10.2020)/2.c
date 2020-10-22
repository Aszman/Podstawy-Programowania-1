#include <stdio.h>

int main()
{
    char napis[]="kapelusz"; 
    char podnapis[]="kapelusza";
    
    int jest = 0;
    if (sizeof(napis) >= sizeof(podnapis))
    {
        for (int i=0; i <= sizeof(napis)-sizeof(podnapis);++i)
        {
            int niema = 0;
            
            for (int j=0; j < sizeof(podnapis)-1;++j)
            {
                if  (napis[i+j] != podnapis[j])
                {
                    niema = 1;
                    break;
                }
            }
            
            if (niema == 1)
            {
                continue;
            }
            
            printf("istnieje dany podciag w tym slowie\n");
            jest = 1;
            break;
        }
    }
    
    if (jest != 1)
    {
        printf("nie istnieje dany podciag w tym slowie\n");
    }
    
    return 0;
}
