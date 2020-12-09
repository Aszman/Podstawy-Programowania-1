#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Dane.h"
#include "ruchyFigur.c"
#include "ruchyGraczy.c"


int main()
{
    while (1)
    {
        printf("Wybierz z kim chcesz zagrać:\n");
        printf("[1] przeciwko AI\n");
        printf("[2] przeciwko innemu graczowi\n");
        printf("[3] wyjdź z programu\n");
        printf(":");
        char tryb;
        scanf("%c", &tryb);
        getchar();

        switch (tryb)
        {
            case '1':
                vsAI();
                break;
            case '2':
                vsPlayer();
                break;
            case '3':
                return 0;
            default:
                printf("Nie ma podanej możliwości, spróbuj ponownie:\n\n");
                break;
        }
    }
    return 0;
}

void vsAI()
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

    while (1)
    {
        printf("\n===Tura białych===\n\n");
        ruchGracza(szachownica, 1);

        wyswietlanie(szachownica);

        if (sprawdzenie(szachownica, -1)  == 1)
        {
            printf("\nWygrały figury białe!\n\n");
            break;
        }

        printf("\n===Tura czarnych===");
        printf("\nRuch AI\n\n");

        ruchAI(szachownica, -1, -1, GLEBOKOSC, GLEBOKOSC, -20000, 20000);

        wyswietlanie(szachownica);
        if (sprawdzenie(szachownica, 1)  == 1)
        {
            printf("\nWygrały figury czarne!\n\n");
            break;
        }
    }
}

void vsPlayer()
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

    while (1)
    {
        printf("\n===Tura białych===\n\n");

        ruchGracza(szachownica, 1);
        wyswietlanie(szachownica);

        if (sprawdzenie(szachownica, -1)  == 1)
        {
            printf("\nWygrały figury białe!\n\n");
            break;
        }

        printf("\n===Tura czarnych===\n\n");

        ruchGracza(szachownica, -1);
        wyswietlanie(szachownica);

        if (sprawdzenie(szachownica, 1)  == 1)
        {
            printf("\nWygrały figury czarne!\n\n");
            break;
        }
    }
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
            suma += heurystyka[szachownica[i][j].wartosc][i][j];
        }
    }
    suma *= flaga;

    return suma;
}
