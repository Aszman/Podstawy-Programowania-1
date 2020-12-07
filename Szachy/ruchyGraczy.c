int ruchAI(bierka szachownica[8][8],int flaga_pier, int flaga, int glebokosc, int glebokosc_pier, int stara_ocena)
{
    int max_ocena = -2000;
    int max_i, max_j, max_k, max_l;
    bierka szachownicaKopia[8][8];

     for (int i = 0; i<=7; ++i)
    {
        for (int j = 0; j<=7; ++j)
        {
            szachownicaKopia[i][j] = szachownica[i][j];
        }
    }


    for (int i = 0; i<=7; ++i)
    {
        for (int j = 0; j<=7; ++j)
        {
            bierka poleF = szachownicaKopia[i][j];

            if(poleF.druzyna==flaga)
            {
                for (int k = 0; k<=7; ++k)
                {
                    for (int l = 0; l<=7; ++l)
                    {
                        bierka poleK = szachownicaKopia[k][l];

                        if (k == i && l == j)
                        {
                        }
                        else if (ruchFigury(7-i, j, 7-k, l, szachownicaKopia)==1)
                        {
                            if (glebokosc == 1)
                            {
                                int ocena = oceniajaca(szachownicaKopia, flaga_pier);
                                if (ocena>=max_ocena)
                                {
                                    max_ocena = ocena;
                                }

                                if (ocena < stara_ocena)
                                {
                                    return (stara_ocena-1);
                                }
                            }
                            else if (glebokosc != glebokosc_pier)
                            {
                                int ocena = ruchAI(szachownicaKopia, flaga_pier, -1*flaga, glebokosc-1, glebokosc_pier, stara_ocena);
                                if (ocena>=max_ocena)
                                {
                                    max_ocena = ocena;
                                }
                            }
                            else
                            {

                                int ocena = ruchAI(szachownicaKopia, flaga_pier, -1*flaga, glebokosc-1, glebokosc_pier, stara_ocena);
                                if (ocena>=max_ocena)
                                {
                                    max_ocena = ocena;
                                    max_i = i;
                                    max_j = j;
                                    max_k = k;
                                    max_l = l;
                                }
                            }

                            szachownicaKopia[k][l] = poleK;
                            szachownicaKopia[i][j] = poleF;
                        }
                    }
                }
            }
        }
    }

    if (glebokosc_pier == glebokosc)
    {
        szachownica[max_k][max_l] = szachownica[max_i][max_j];
        szachownica[max_i][max_j] = N;
    }

    return max_ocena;
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
