#include <stdio.h>
#include <stdlib.h>

int main()
{
    enum DNI_TYGODNIA {poniedzialek=1, wtorek , sroda, czwartek, piatek, sobota, niedziela};  
    
    enum DNI_TYGODNIA dzien;   
    
    scanf("%u",&dzien);  
    
    switch(dzien)
    {
        case poniedzialek:
            printf("pon");
            break;
        case wtorek:
            printf("wt");
            break;   
        case sroda:
            printf("sr");
            break;
        case czwartek:
            printf("czw");
            break;    
        case piatek:
            printf("pt");
            break;
        case sobota:
            printf("sb");
            break;
        case niedziela:
            printf("nd");
            break;
    }
            
    return 0;
}
