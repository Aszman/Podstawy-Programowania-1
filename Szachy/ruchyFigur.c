int ruchFigury(int n_F,int m_F,int n_K,int m_K, bierka szachownica[8][8])
{
    bierka *PoleF = &szachownica[7-n_F][m_F];
    bierka *PoleK = &szachownica[7-n_K][m_K];
    int dn = abs(n_F-n_K);
    int dm = abs(m_F-m_K);

    int poprawne;
    if (PoleF->druzyna != PoleK->druzyna)
    {
        switch (PoleF->ID)
        {
            case 0:  //pionek
                poprawne = ruchPionek(n_F, m_F, n_K, m_K, PoleF, PoleK, szachownica);
                break;
            case 1:  //skoczek
                poprawne = ruchSkoczek(dn, dm, PoleF, PoleK);
                break;
            case 2:  //goniec
                poprawne = ruchGoniec(n_F, m_F, n_K, m_K, PoleF, PoleK, szachownica);
                break;
            case 3:  //wieza
                poprawne = ruchWieza(n_F, m_F, n_K, m_K, PoleF, PoleK, szachownica);
                break;
            case 4:  //hetman
                poprawne = ruchHetman(n_F, m_F, n_K, m_K, PoleF, PoleK, szachownica);
                break;
            case 5:  //krol
                poprawne = ruchKrol(dn, dm, PoleF, PoleK);
                break;
            default:
                poprawne  = 0;
                break;
        }
    }
    else
    {
        poprawne = 0;
    }

    return poprawne;
}

int ruchPionek(int n_F, int m_F, int n_K, int m_K, bierka *PoleF, bierka *PoleK, bierka szachownica[8][8])
{
    if (n_F + 2*PoleF->druzyna == n_K && m_K == m_F && PoleK->druzyna==0 && PoleF->specjalne==1 && szachownica[7-n_F-PoleF->druzyna][m_F].ID==-1)
    {
        PoleF->specjalne = 0;
        *PoleK = *PoleF;
        *PoleF = N;
        return 1;
    }
    else if (n_F + PoleF->druzyna == n_K && PoleK->druzyna==0 && m_K == m_F )
    {
        PoleF->specjalne = 0;
        *PoleK = *PoleF;
        *PoleF = N;
        return 1;
    }
    else if (n_F + PoleF->druzyna == n_K && PoleK->druzyna == -1*PoleF->druzyna && abs(m_K-m_F)==1)
    {
        PoleF->specjalne = 0;
        *PoleK = *PoleF;
        *PoleF = N;
        return 1;
    }

    return 0;

}

int ruchSkoczek(int dn, int dm, bierka *PoleF, bierka *PoleK)
{
    if ((dn == 1 && dm == 2) || (dn == 2 && dm == 1))
    {
        *PoleK = *PoleF;
        *PoleF = N;
        return 1;
    }

    return 0;
}

int ruchGoniec(int n_F, int m_F, int n_K, int m_K, bierka *PoleF, bierka *PoleK, bierka szachownica[8][8])
{
    if (abs(n_K-n_F) != abs(m_K-m_F))
    {
        return 0;
    }
    else if (n_K-n_F == m_K-m_F && m_K-m_F>0)
    {
        for (int i = 1; i < abs(m_K-m_F); ++i)
        {
            if (szachownica[7-n_F-i][m_F+i].druzyna != 0)
            {
                return 0;
            }
        }
    }
    else if (n_K-n_F == m_K-m_F && m_K-m_F<0 )
    {
        for (int i = 1; i < abs(m_K-m_F); ++i)
        {
            if (szachownica[7-n_F+i][m_F-i].druzyna != 0)
            {
                return 0;
            }
        }
    }
    else if (-1*(n_K-n_F) == m_K-m_F && m_K-m_F>0)
    {
        for (int i = 1; i < abs(m_K-m_F); ++i)
        {
            if (szachownica[7-n_F+i][m_F+i].druzyna != 0)
            {
                return 0;
            }
        }
    }
    else if(-1*(n_K-n_F) == m_K-m_F && m_K-m_F<0)
    {
        for (int i = 1; i < abs(m_K-m_F); ++i)
        {
            if (szachownica[7-n_F-i][m_F-i].druzyna != 0)
            {
                return 0;
            }
        }
    }
    *PoleK = *PoleF;
    *PoleF = N;
    return 1;
}

int ruchWieza(int n_F, int m_F, int n_K, int m_K, bierka *PoleF, bierka *PoleK, bierka szachownica[8][8])
{
    if (n_F-n_K !=0 && m_F-m_K != 0)
    {
        return 0;
    }
    else if (n_K-n_F == 0 && m_K-m_F>0)
    {
        for (int i=1; i < abs(m_K-m_F); ++i)
        {
            if (szachownica[7-n_F][m_F+i].druzyna != 0)
            {
                return 0;
            }
        }
    }
    else if (n_K-n_F < 0 && m_K-m_F == 0)
    {
        for (int i=1; i < abs(n_K-n_F); ++i)
        {
            if (szachownica[7-n_F+i][m_F].druzyna != 0)
            {
                return 0;
            }
        }
    }
    else if (n_K-n_F == 0 && m_K-m_F < 0)
    {
        for (int i=1; i < abs(m_K-m_F); ++i)
        {
            if (szachownica[7-n_F][m_F-i].druzyna != 0)
            {
                return 0;
            }
        }
    }
    else if (n_K-n_F > 0 && m_K-m_F == 0)
    {
        for (int i=1; i < abs(n_K-n_F); ++i)
        {
            if (szachownica[7-n_F-i][m_F].druzyna != 0)
            {
                return 0;
            }
        }
    }
    *PoleK = *PoleF;
    *PoleF = N;
    return 1;
}

int ruchHetman(int n_F, int m_F, int n_K, int m_K, bierka *PoleF, bierka *PoleK, bierka szachownica[8][8])
{
    if((n_F-n_K !=0 && m_F-m_K != 0) && (abs(n_K-n_F) != abs(m_K-m_F)))
    {
        return 0;
    }
    else if (n_K-n_F == m_K-m_F && m_K-m_F>0)
    {
        for (int i = 1; i < abs(m_K-m_F); ++i)
        {
            if (szachownica[7-n_F-i][m_F+i].druzyna != 0)
            {
                return 0;
            }
        }
    }
    else if (n_K-n_F == m_K-m_F && m_K-m_F<0 )
    {
        for (int i = 1; i < abs(m_K-m_F); ++i)
        {
            if (szachownica[7-n_F+i][m_F-i].druzyna != 0)
            {
                return 0;
            }
        }
    }
    else if (-1*(n_K-n_F) == m_K-m_F && m_K-m_F>0)
    {
        for (int i = 1; i < abs(m_K-m_F); ++i)
        {
            if (szachownica[7-n_F+i][m_F+i].druzyna != 0)
            {
                return 0;
            }
        }
    }
    else if(-1*(n_K-n_F) == m_K-m_F && m_K-m_F<0)
    {
        for (int i = 1; i < abs(m_K-m_F); ++i)
        {
            if (szachownica[7-n_F-i][m_F-i].druzyna != 0)
            {
                return 0;
            }
        }
    }
    else if (n_K-n_F == 0 && m_K-m_F>0)
    {
        for (int i=1; i < abs(m_K-m_F); ++i)
        {
            if (szachownica[7-n_F][m_F+i].druzyna != 0)
            {
                return 0;
            }
        }
    }
    else if (n_K-n_F < 0 && m_K-m_F == 0)
    {
        for (int i=1; i < abs(n_K-n_F); ++i)
        {
            if (szachownica[7-n_F+i][m_F].druzyna != 0)
            {
                return 0;
            }
        }
    }
    else if (n_K-n_F == 0 && m_K-m_F < 0)
    {
        for (int i=1; i < abs(m_K-m_F); ++i)
        {
            if (szachownica[7-n_F][m_F-i].druzyna != 0)
            {
                return 0;
            }
        }
    }
    else if (n_K-n_F > 0 && m_K-m_F == 0)
    {
        for (int i=1; i < abs(n_K-n_F); ++i)
        {
            if (szachownica[7-n_F-i][m_F].druzyna != 0)
            {
                return 0;
            }
        }
    }

    *PoleK = *PoleF;
    *PoleF = N;
    return 1;
}

int ruchKrol(int dn, int dm, bierka *PoleF, bierka *PoleK)
{
    if (dn + dm == 1 || (dn == 1 && dm == 1))
    {
        *PoleK = *PoleF;
        *PoleF = N;
        return 1;
    }

    return 0;
}
