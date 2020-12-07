#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Dane.h"
#include "ruchyFigur.c"

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


void ruchGracza(bierka szachownica[8][8], int flaga)
{
    char litera,liczba;

    if(flaga == 1)
    {
        printf("====Tura białych====\n");
    }
    else if(flaga == -1)
    {
        printf("====Tura czarnych====\n");
    }

    while (1)
    {
        printf("Podaj wspolrzedne figury, którą chcesz przemieścić format[litera|liczba]: ");

        scanf("%c%c", &litera, &liczba);
        getchar();

        int m_F = toupper(litera)-65;
        int n_F = liczba - 49;

        if (0<=n_F && n_F<=7 && 0<=m_F && m_F<=7)
        {
            bierka poleF = szachownica[7-n_F][m_F];

            if(poleF.druzyna==flaga)
            {
                printf("Wybrana figura to %s, wskaż punkt docelowy: ", poleF.nazwa);
                scanf("%c%c", &litera, &liczba);
                getchar();
                int m_K = toupper(litera)-65;
                int n_K = liczba - 49;

                if (n_K == n_F && m_K == m_F)
                {
                    printf("Wybrałeś te samo pole, spróbuj ponownie\n ");
                }
                else if (0<=n_K && n_K<=7 && 0<=m_K && m_K<=7)
                {

                    if (ruchFigury(n_F, m_F, n_K, m_K, szachownica)==1)
                    {
                        break;
                    }
                    else
                    {
                        printf("Ruch nie jest możliwy, sporobuj ponownie.\n");
                    }
                }
                else
                {
                    printf("Niepoprawny format wspolrzednych, sprobuj ponownie\n");
                }
            }
            else if (poleF.druzyna==-flaga)
            {
                printf("Wybrales figure przeciwnika, podaj wspolrzedne jeszcze raz\n");
            }
            else
            {
                printf("Wybrales puste pole, podaj wspolrzedne jeszcze raz\n");
            }
        }
        else
        {
            printf("Niepoprawny format wspolrzednych, podaj je jeszcze raz\n");
        }
    }
}



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

    while (1)
    {
        ruchGracza(szachownica, 1);
        wyswietlanie(szachownica);
        if (sprawdzenie(szachownica, -1)  == 1)
        {
            printf("\nWygrały figury białe!!\n\n");
            break;
        }

        ruchGracza(szachownica, -1);
        wyswietlanie(szachownica);
        if (sprawdzenie(szachownica, 1)  == 1)
        {
            printf("\nWygrały figury czarne!!\n\n");
            break;
        }
    }
    return 0;
}
