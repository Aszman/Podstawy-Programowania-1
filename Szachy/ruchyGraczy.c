int ruchAI(bierka szachownica[8][8], int flaga_pier, int flaga, int glebokosc, int glebokosc_pier, int min_ocena, int max_ocena)
{
    if(glebokosc == 0)
    {
        return (oceniajaca(szachownica, flaga_pier));
    }
    else
    {
        bierka szachownicaKopia[8][8];
        for (int i = 0; i <= 7; ++i)
        {
            for (int j = 0; j<=7; ++j)
            {
                szachownicaKopia[i][j] = szachownica[i][j];
            }
        }

        if(glebokosc != glebokosc_pier && flaga != flaga_pier)
        {
            for (int i = 0; i<=7; ++i)
            {
                for (int j = 0; j<=7; ++j)
                {
                    bierka poleF = szachownicaKopia[i][j];

                    if (poleF.druzyna==flaga)
                    {
                        for (int k = 0; k<=7; ++k)
                        {
                            for (int l = 0; l<=7; ++l)
                            {
                                bierka poleK = szachownica[k][l];
                                if (k == i && l == j)
                                {
                                }
                                else if (ruchFigury(7-i, j, 7-k, l, szachownicaKopia)==1)
                                {
                                    int ocena = ruchAI(szachownicaKopia, flaga_pier, -1*flaga, glebokosc-1, glebokosc_pier, min_ocena, max_ocena);

                                    szachownicaKopia[k][l] = poleK;
                                    szachownicaKopia[i][j] = poleF;

                                    if (ocena < max_ocena)
                                    {
                                        max_ocena = ocena;
                                    }

                                    if (min_ocena >= max_ocena)
                                    {
                                        return max_ocena;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            return max_ocena;
        }
        else if (glebokosc != glebokosc_pier && flaga == flaga_pier)
        {
            for (int i = 0; i<=7; ++i)
            {
                for (int j = 0; j<=7; ++j)
                {
                    bierka poleF = szachownicaKopia[i][j];

                    if (poleF.druzyna==flaga)
                    {
                        for (int k = 0; k<=7; ++k)
                        {
                            for (int l = 0; l<=7; ++l)
                            {
                                bierka poleK = szachownica[k][l];
                                if (k == i && l == j)
                                {
                                }
                                else if (ruchFigury(7-i, j, 7-k, l, szachownicaKopia)==1)
                                {
                                    int ocena = ruchAI(szachownicaKopia, flaga_pier, -1*flaga, glebokosc-1, glebokosc_pier, min_ocena, max_ocena);

                                    szachownicaKopia[k][l] = poleK;
                                    szachownicaKopia[i][j] = poleF;

                                    if (ocena > min_ocena)
                                    {
                                        min_ocena = ocena;
                                    }

                                    if (min_ocena >= max_ocena)
                                    {
                                        return min_ocena;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            return min_ocena;
        }
        else
        {
            int max_i, max_j, max_k, max_l;

            for (int i = 0; i<=7; ++i)
            {
                for (int j = 0; j<=7; ++j)
                {
                    bierka poleF = szachownicaKopia[i][j];

                    if (poleF.druzyna==flaga)
                    {
                        for (int k = 0; k<=7; ++k)
                        {
                            for (int l = 0; l<=7; ++l)
                            {
                                bierka poleK = szachownica[k][l];
                                if (k == i && l == j)
                                {
                                }
                                else if (ruchFigury(7-i, j, 7-k, l, szachownicaKopia)==1)
                                {
                                    int ocena = ruchAI(szachownicaKopia, flaga_pier, -1*flaga, glebokosc-1, glebokosc_pier, min_ocena, max_ocena);

                                    szachownicaKopia[k][l] = poleK;
                                    szachownicaKopia[i][j] = poleF;

                                    if (ocena > min_ocena)
                                    {
                                        min_ocena = ocena;
                                        max_i = i;
                                        max_j = j;
                                        max_k = k;
                                        max_l = l;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            szachownica[max_k][max_l] = szachownica[max_i][max_j];
            szachownica[max_i][max_j] = N;
            return 0;
        }
    }
}

void ruchGracza(bierka szachownica[8][8], int flaga)
{
    char litera,liczba;

    while (1)
    {
        printf("Podaj wspołrzędne figury, którą chcesz przemieścić [litera|liczba]: ");

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
                    printf("Wybrałeś to samo pole, spróbuj ponownie\n ");
                }
                else if (0<=n_K && n_K<=7 && 0<=m_K && m_K<=7)
                {

                    if (ruchFigury(n_F, m_F, n_K, m_K, szachownica)==1)
                    {
                        break;
                    }
                    else
                    {
                        printf("Ruch nie jest możliwy, spróbuj ponownie.\n");
                    }
                }
                else
                {
                    printf("Niepoprawny format wspołrzędnych, spróbuj ponownie\n");
                }
            }
            else if (poleF.druzyna==-flaga)
            {
                printf("Wybrałeś figurę przeciwnika, podaj wspołrzędne jeszcze raz\n");
            }
            else
            {
                printf("Wybrałes puste pole, podaj wspołrzędne jeszcze raz\n");
            }
        }
        else
        {
            printf("Niepoprawny format wspołrzędnych, podaj je jeszcze raz\n");
        }
    }
}
