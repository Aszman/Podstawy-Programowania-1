#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Dane.h"
#include "ruchyFigur.c"
#include "ruchyGraczy.c"


int main()
{
    bierka szachownica[8][8]= {
                            {W_c, S_c, G_c, H_c,  K_c,  G_c, S_c, W_c},
                            {P_c, P_c, P_c, P_c,  P_c,  P_c, P_c, P_c},
                            {N,   N,   N,   N,    N,    N,   N,   N  },
                            {N,   N,   N,   N,    N,    N,   N,   N  },
                            {N,   N,   N,   N,    N,    N,   N,   N  },
                            {N,   N,   N,   N,    N,    N,   N,   N  },
                            {P_b, P_b, P_b, P_b,  P_b,  P_b, P_b, P_b},
                            {W_b, S_b, G_b, H_b,  K_b,  G_b, S_b, W_b}
                            };

    wyswietlanie(szachownica);
    int stara_ocena = -2000;

    while (1)
    {
        ruchGracza(szachownica, 1);
        wyswietlanie(szachownica);

        if (sprawdzenie(szachownica, -1)  == 1)
        {
            printf("\nWygrały figury białe!\n\n");
            break;
        }
        printf("\nRuch AI\n\n");
        stara_ocena = ruchAI(szachownica, -1, -1, 4, 4, stara_ocena);
        wyswietlanie(szachownica);
        if (sprawdzenie(szachownica, 1)  == 1)
        {
            printf("\nWygrały figury czarne!\n\n");
            break;
        }
    }
    return 0;
}


void wyswietlanie(bierka szachownica[8][8])
{
    printf("   A B C D E F G H\n");

    for (int i = 0; i<=7; ++i)
    {
        printf("%d  ", 8-i);
        for(int j = 0; j<=7; ++j)
        {
            printf("%s ", szachownica[i][j].symbol);
        }
        printf(" %d\n", 8-i);
    }
    printf("   A B C D E F G H\n");
}


int sprawdzenie(bierka szachownica[8][8], int flaga)
{
    for (int i = 0; i<=7; ++i)
    {
        for (int j = 0; j<=7; ++j)
        {
            if (szachownica[i][j].druzyna == flaga && szachownica[i][j].ID == 5)
            {
                return 0;
            }
        }
    }

    return 1;
}


int oceniajaca(bierka szachownica[8][8], int flaga)
{
    int suma = 0;
    for (int i = 0; i<=7; ++i)
    {
        for (int j = 0; j<=7; ++j)
        {
            suma += szachownica[i][j].wartosc;
        }
    }
    suma *= flaga;

    return suma;
}
