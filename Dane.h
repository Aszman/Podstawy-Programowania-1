#ifndef DANE_H_INCLUDED
#define DANE_H_INCLUDED

#define GLEBOKOSC 7

typedef struct bierka
{
    short druzyna;  // 1 - biala   -1 - czarna  0 - puste
    char nazwa[8];
    char symbol[8];
    short ID;       // 0 - pionek   1 - skoczek   2 - goniec   3 - wieza   4 - hetman   5 - krol  -1 - puste

    int wartosc;
    int specjalne;  //roszada (krol/wieza) lub skok(pionek)   1 - moze    0 - nie moze
}bierka;

// Król
bierka K_b = {1, "Król", "\u2654", 5, 1000, 1};
bierka K_c = {-1, "Król", "\u265A", 5, -1000, 1};

// Hetman
const bierka H_b = {1, "Hetman", "\u2655", 4, 9, 0};
const bierka H_c = {-1, "Hetman", "\u265B", 4, -9, 0};

// Wieża
bierka W_b = {1, "Wieża", "\u2656", 3, 5, 1};
bierka W_c = {-1, "Wieża", "\u265C", 3, -5, 1};

// Goniec
const bierka G_b = {1, "Goniec", "\u2657", 2, 3, 0};
const bierka G_c = {-1, "Goniec", "\u265D", 2, -3, 0};

// Skoczek
const bierka S_b = {1, "Skoczek", "\u2658", 1, 3, 0};
const bierka S_c = {-1, "Skoczek", "\u265E", 1, -3, 0};

//Pionek
bierka P_b = {1, "Pionek", "\u2659", 0, 1, 1};
bierka P_c = {-1, "Pionek", "\u265F", 0, -1, 1};

// Puste pole
const bierka N = {0, "Puste", "-", -1, 0, 0};


//Prototypy funkcji

//main.c
void wyswietlanie(bierka[8][8]);
int sprawdzenie(bierka[8][8], int);
void ruchGracza(bierka[8][8], int);
int oceniajaca(bierka[8][8], int);
void vsAI();
void vsPlayer();

//ruchyFigur.c
int ruchFigury(int, int, int, int, bierka[8][8]);
int ruchPionek(int, int, int, int, bierka*, bierka*, bierka[8][8]);
int ruchSkoczek(int, int, bierka*, bierka*);
int ruchGoniec(int, int, int, int, bierka*, bierka*, bierka[8][8]);
int ruchWieza(int, int, int, int, bierka*, bierka*, bierka[8][8]);
int ruchHetman(int, int, int, int, bierka*, bierka*, bierka[8][8]);
int ruchKrol(int, int, bierka*, bierka*);

//ruchyGraczy.c
int ruchAI(bierka[8][8],int, int, int, int, int, int);
void ruchGracza(bierka[8][8], int);


#endif // DANE_H_INCLUDED
