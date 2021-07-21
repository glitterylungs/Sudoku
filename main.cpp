#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>


using namespace std;

//ZMIENNE GLOBALNE
const int n = 9;     //zmienna const okreslajaca rozmiar tablicy
int plansza[n][n] = {};     //tablica dwuwymiarowa do ktorej zostana przekazane liczby z pliku tekstowego
int plansza_do_solvera[n][n] = {};     //tablica dwuwymiarowa, ktora zostanie przekazana do funkcji
                                       // solvera sudoku i bedzie zawierac liczby prawidlowego rozwiazania sudoku



//DEKLARACJA FUNKCJI PETLA_GRY
bool petla_gry();




//FUNKCJA USTALAJĄCA WIELKOSC OKNA KONSOLI
void okno_konsoli(){
  char c = 0;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT sr;
    sr.Left = 0;
    sr.Top = 0;
    sr.Right = 85;
    sr.Bottom = 45;
    SetConsoleWindowInfo(handle,true,&sr);
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo(handle, &sbi);
}




//FUNKCJA ODPOWIADAJACA ZA ZMIANE KOLORU TEKSTU
void koloryTekstu(int numer_koloru){
    HANDLE hWyj;
    hWyj = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hWyj, numer_koloru);
}




//FUNKCJA ODPOWIADAJACA ZA WYPISANIE GLOWNEGO TYTULU GRY "SUDOKU"
void tytulGry(){
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    koloryTekstu(3);
    cout << "                                       __         __" << endl;
    koloryTekstu(4);
    cout << "                                      |  |       |  |" << endl;
    koloryTekstu(5);
    cout << "                    _____ __    _  ___|  |  ___  |  | ____   __ " << endl;
    koloryTekstu(6);
    cout << "                   /   __|  |  | |/  _   |/  _  \\|  |/ /  | |  |" << endl;
    koloryTekstu(11);
    cout << "                   \\ __  \\  |__| |  (_|  |  (_)  |    <|  |_|  |" << endl;
    koloryTekstu(12);
    cout << "                   |_____/\\____,_|\\___,__|\\ ___ /|__|\__\\\\___,__|" << endl;
    //Sleep(60);
    koloryTekstu(15);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    koloryTekstu(7);
    cout << "                                   Press ENTER..." << endl;
    koloryTekstu(15);
    getchar();          //czekanie na wcisnieje entera
    system("cls");     //wyczyszczenie ekranu
    petla_gry();     //wypisanie menu glownego
}




//FUNKCJA ODPOWIADAJACA ZA WYPISANIE MIGAJACEGO NAPISU "GREAT JOB"
void napis_na_zakonczenie(){
    int i = 0;    //zmienna wykorzystywana w petli

//petla, ktorej wynikiem jest wrazenie migania tekstu
    while(i < 7){
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;


        koloryTekstu(3);
        cout << "                                                     __" << endl;
        koloryTekstu(4);
        cout << "                                                 ___|   |___" << endl;
        koloryTekstu(5);
        cout << "                                                |___     ___|" << endl;
        koloryTekstu(6);
        cout << "                  ______   ____  ______     _____   |   |" << endl;
        koloryTekstu(11);
        cout << "                /  __   \\/   __|/   _   \\ /  __  \\  |   |" << endl;
        koloryTekstu(12);
        cout << "               |  (__)   |   |  |  (_)  /|  (__)  | |   |" << endl;
        koloryTekstu(13);
        cout << "                \\____    |   |  |   ___/_|        |_|   |" << endl;
        koloryTekstu(14);
        cout << "                     |   |___|   \\_______|\\_________| __|    " << endl;
        koloryTekstu(3);
        cout << "                     |   |                                    __" << endl;
        koloryTekstu(4);
        cout << "                  __/   /                         _          |  |" << endl;
        koloryTekstu(5);
        cout << "                 |_____/                         |_|   ____  |  |___   " << endl;
        koloryTekstu(6);
        cout << "                                                |   |/  _   \\|   __  \\" << endl;
        koloryTekstu(11);
        cout << "                                                |   |  (__)  |  (__)  |" << endl;
        koloryTekstu(12);
        cout << "                                                |   |\\ ____ /\\_______/" << endl;
        koloryTekstu(13);
        cout << "                                                |   |" << endl;
        koloryTekstu(14);
        cout << "                                             __/   /" << endl;
        koloryTekstu(3);
        cout << "                                            |_____/" << endl;
        koloryTekstu(15);
        i++;
        Sleep(100);
        system("cls");
        Sleep(50);
}}




//FUNKCJA ODPOWIADAJACA ZA WYPISANIE NAPISU "SUDOKU" W RAMCE, W GŁÓWNYM MENU
void napis_sudoku_maly(){

    char lg = 0xC9;   //lewy gorny rog ramki
    char ld = 0xC8;   //lewy dolny rog ramki
    char pg = 0xBB;   //prawy gorny rog ramki
    char pd = 0xBC;   //prawy dolny rog ramki
    char h = 0xBA;   //pion ramki
    char v = 0xCD;   //poziom ramki


    koloryTekstu(12);
    cout << "                                " << lg << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << pg << endl;
    cout << "                                " << h;

    koloryTekstu(6);
    cout << "  " << lg << v << v << v << v << v << v << v << v << v << v << v << v << pg << "  ";

    koloryTekstu(12);
    cout << h << endl;
    cout << "                                " << h;

    koloryTekstu(6);
    cout << "  " << h << "  ";

    koloryTekstu(11);
    cout << " SUDOKU ";

    koloryTekstu(6);
    cout << "  " << h << "  ";

    koloryTekstu(12);
    cout << h << endl;
    cout << "                                " << h;

    koloryTekstu(6);
    cout << "  " << ld << v << v << v << v << v << v << v << v << v << v << v << v << pd << "  ";

    koloryTekstu(12);
    cout << h << endl;
    cout << "                                " << ld << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << pd << endl;

    koloryTekstu(15);
}




//FUNKCJA ODPOWIADAJACA ZA WYPISANIE NAPISU "DIFFICULTY" W RAMCE, W MENU WYBORU TRUDNOSCI
void napis_difficulty(){
    char lg = 0xC9;   //lewy gorny rog ramki
    char ld = 0xC8;   //lewy dolny rog ramki
    char pg = 0xBB;   //prawy gorny rog ramki
    char pd = 0xBC;   //prawy dolny rog ramki
    char h = 0xBA;   //pion ramki
    char v = 0xCD;   //poziom ramki

    koloryTekstu(12);
    cout << "                              " << lg << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << pg << endl;
    cout << "                              " << h;

    koloryTekstu(11);
    cout << "  " << lg << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << pg << "  ";

    koloryTekstu(12);
    cout << h << endl;
    cout << "                              " << h;

    koloryTekstu(11);
    cout << "  " << h << "  ";

    koloryTekstu(6);
    cout << " DIFFICULTY ";

    koloryTekstu(11);
    cout << "  " << h << "  ";

    koloryTekstu(12);
    cout << h << endl;
    cout << "                              " << h;

    koloryTekstu(11);
    cout << "  " << ld << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << pd << "  ";

    koloryTekstu(12);
    cout << h << endl;
    cout << "                              " << ld << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << pd << endl;

    koloryTekstu(15);
}




//FUNKCJA ODPOWIADAJACA ZA WYPISANIE NAPISU "HOW TO PLAY" W RAMCE, W MIEJSCU INSTRUKCJI GRY
void napis_how_to_play(){
    char lg = 0xC9;   //lewy gorny rog ramki
    char ld = 0xC8;   //lewy dolny rog ramki
    char pg = 0xBB;   //prawy gorny rog ramki
    char pd = 0xBC;   //prawy dolny rog ramki
    char h = 0xBA;   //pion ramki
    char v = 0xCD;   //poziom ramki

    koloryTekstu(12);
    cout << "                              " << lg << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << pg << endl;
    cout << "                              " << h;

    koloryTekstu(11);
    cout << "  " << lg << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << pg << "  ";

    koloryTekstu(12);
    cout << h << endl;
    cout << "                              " << h;

    koloryTekstu(11);
    cout << "  " << h << "  ";

    koloryTekstu(6);
    cout << " HOW TO PLAY ";

    koloryTekstu(11);
    cout << "  " << h << "  ";

    koloryTekstu(12);
    cout << h << endl;
    cout << "                              " << h;

    koloryTekstu(11);
    cout << "  " << ld << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << pd << "  ";

    koloryTekstu(12);
    cout << h << endl;
    cout << "                              " << ld << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << pd << endl;

    koloryTekstu(15);
}




//FUNKCJA ODPOWIADAJACA ZA WYPISANIE NAPIS "AUTHOR" W RAMCE, W MIJSCU OPISANIA AUTORA
void napis_author(){
    char lg = 0xC9;   //lewy gorny rog ramki
    char ld = 0xC8;   //lewy dolny rog ramki
    char pg = 0xBB;   //prawy gorny rog ramki
    char pd = 0xBC;   //prawy dolny rog ramki
    char h = 0xBA;   //pion ramki
    char v = 0xCD;   //poziom ramki

    koloryTekstu(12);
    cout << "                                " << lg << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << pg << endl;
    cout << "                                " << h;

    koloryTekstu(11);
    cout << "  " << lg << v << v << v << v << v << v << v << v << v << v << v << v << pg << "  ";

    koloryTekstu(12);
    cout << h << endl;
    cout << "                                " << h;

    koloryTekstu(11);
    cout << "  " << h << "  ";

    koloryTekstu(6);
    cout << " AUTHOR ";

    koloryTekstu(11);
    cout << "  " << h << "  ";

    koloryTekstu(12);
    cout << h << endl;
    cout << "                                " << h;

    koloryTekstu(11);
    cout << "  " << ld << v << v << v << v << v << v << v << v << v << v << v << v << pd << "  ";

    koloryTekstu(12);
    cout << h << endl;
    cout << "                                " << ld << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << v << pd << endl;

    koloryTekstu(15);
}




//FUNKCJA ODPOWIADAJACA ZA WYPISANIE PLANSZY, WYKORZYSTYWANA JEST PO WYBRANIU OPCJI SOLVE,
// KTORA JEST DOSTEPNA PO WPISANIEU ODPOWIEDNIEJ WARTOSCI
// KONIEC - 1195 LINIJKA
void wypisz_plansze(){

    char lg = 0xC9;   //lewy gorny rog
    char ld = 0xC8;   //lewy dolny rog
    char pg = 0xBB;   //prawy gorny rog
    char pd = 0xBC;   //prawy dolny rog
    char v2 = 0xBA;   //pionowy podwojny
    char h2 = 0xCD;   //poziomy podwojny
    char v1 = 0xB3;   //pionowy pojedynczy
    char h1 = 0xC4;   //poziomy pojedynczy
    char lb2 = 0xCC;   //lewy bok podwojny
    char pb2 = 0xB9;   //prawy bok podwojny
    char s2 = 0xCE;   //srodkowy podwojny
    char g2 = 0xCB;   //gorny podwojny
    char d2 = 0xCA;   //dolny podwojny
    char s1 = 0xC5;   //srodkowy pojedynczy



    koloryTekstu(12);
    cout << "                       ";
    cout << lg << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << g2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << g2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << pg << endl;


    cout << "                       ";
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza[0][0] ==0){
        cout << " ";
    }
    else{cout << plansza[0][0];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[0][1] == 0){
        cout << " ";
    }
    else{cout << plansza[0][1];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[0][2] == 0){
        cout << " ";
    }
    else{cout << plansza[0][2];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[0][3] == 0){
        cout << " ";
    }
    else{cout << plansza[0][3];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[0][4] == 0){
        cout << " ";
    }
    else{cout << plansza[0][4];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[0][5] == 0){
        cout << " ";
    }
    else{cout << plansza[0][5];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[0][6] == 0){
        cout << " ";
    }
    else{cout << plansza[0][6];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[0][7] == 0){
        cout << " ";
    }
    else{cout << plansza[0][7];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[0][8] == 0){
        cout << " ";
    }
    else{cout << plansza[0][8];}

    koloryTekstu(12);
    cout << " " << v2 << endl;


    cout << "                       ";
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                       ";
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza[1][0] == 0){
        cout << " ";
    }
    else{cout << plansza[1][0];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[1][1] == 0){
        cout << " ";
    }
    else{cout << plansza[1][1];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[1][2] == 0){
        cout << " ";
    }
    else{cout << plansza[1][2];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[1][3] == 0){
        cout << " ";
    }
    else{cout << plansza[1][3];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[1][4] == 0){
        cout << " ";
    }
    else{cout << plansza[1][4];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[1][5] == 0){
        cout << " ";
    }
    else{cout << plansza[1][5];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[1][6] == 0){
        cout << " ";
    }
    else{cout << plansza[1][6];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[1][7] == 0){
        cout << " ";
    }
    else{cout << plansza[1][7];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[1][8] == 0){
        cout << " ";
    }
    else{cout << plansza[1][8];}

    koloryTekstu(12);
    cout << " " << v2 << endl;


    cout << "                       ";
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                       ";
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza[2][0] == 0){
        cout << " ";
    }
    else{cout << plansza[2][0];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[2][1] == 0){
        cout << " ";
    }
    else{cout << plansza[2][1];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[2][2] == 0){
        cout << " ";
    }
    else{cout << plansza[2][2];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[2][3] == 0){
        cout << " ";
    }
    else{cout << plansza[2][3];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[2][4] == 0){
        cout << " ";
    }
    else{cout << plansza[2][4];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[2][5] == 0){
        cout << " ";
    }
    else{cout << plansza[2][5];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[2][6] == 0){
        cout << " ";
    }
    else{cout << plansza[2][6];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[2][7] == 0){
        cout << " ";
    }
    else{cout << plansza[2][7];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[2][8] == 0){
        cout << " ";
    }
    else{cout << plansza[2][8];}

    koloryTekstu(12);
    cout << " " << v2 << endl;


    cout << "                       ";
    cout << lb2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << s2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << s2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << pb2 << endl;


    cout << "                       ";
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza[3][0] == 0){
        cout << " ";
    }
    else{cout << plansza[3][0];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[3][1] == 0){
        cout << " ";
    }
    else{cout << plansza[3][1];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[3][2] == 0){
        cout << " ";
    }
    else{cout << plansza[3][2];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[3][3] == 0){
        cout << " ";
    }
    else{cout << plansza[3][3];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[3][4] == 0){
        cout << " ";
    }
    else{cout << plansza[3][4];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[3][5] == 0){
        cout << " ";
    }
    else{cout << plansza[3][5];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[3][6] == 0){
        cout << " ";
    }
    else{cout << plansza[3][6];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[3][7] == 0){
        cout << " ";
    }
    else{cout << plansza[3][7];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[3][8] == 0){
        cout << " ";
    }
    else{cout << plansza[3][8];}

    koloryTekstu(12);
    cout << " " << v2 << endl;


    cout << "                       ";
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                       ";
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza[4][0] == 0){
        cout << " ";
    }
    else{cout << plansza[4][0];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[4][1] == 0){
        cout << " ";
    }
    else{cout << plansza[4][1];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[4][2] == 0){
        cout << " ";
    }
    else{cout << plansza[4][2];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[4][3] == 0){
        cout << " ";
    }
    else{cout << plansza[4][3];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[4][4] == 0){
        cout << " ";
    }
    else{cout << plansza[4][4];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[4][5] == 0){
        cout << " ";
    }
    else{cout << plansza[4][5];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[4][6] == 0){
        cout << " ";
    }
    else{cout << plansza[4][6];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[4][7] == 0){
        cout << " ";
    }
    else{cout << plansza[4][7];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[4][8] == 0){
        cout << " ";
    }
    else{cout << plansza[4][8];}

    koloryTekstu(12);
    cout << " " << v2 << endl;


    cout << "                       ";
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                       ";
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza[5][0] == 0){
        cout << " ";
    }
    else{cout << plansza[5][0];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[5][1] == 0){
        cout << " ";
    }
    else{cout << plansza[5][1];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[5][2] == 0){
        cout << " ";
    }
    else{cout << plansza[5][2];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[5][3] == 0){
        cout << " ";
    }
    else{cout << plansza[5][3];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[5][4] == 0){
        cout << " ";
    }
    else{cout << plansza[5][4];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[5][5] == 0){
        cout << " ";
    }
    else{cout << plansza[5][5];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[5][6] == 0){
        cout << " ";
    }
    else{cout << plansza[5][6];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[5][7] == 0){
        cout << " ";
    }
    else{cout << plansza[5][7];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[5][8] == 0){
        cout << " ";
    }
    else{cout << plansza[5][8];}

    koloryTekstu(12);
    cout << " " << v2 << endl;


    cout << "                       ";
    cout << lb2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << s2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << s2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << pb2 << endl;


    cout << "                       ";
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza[6][0] == 0){
        cout << " ";
    }
    else{cout << plansza[6][0];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[6][1] == 0){
        cout << " ";
    }
    else{cout << plansza[6][1];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[6][2] == 0){
        cout << " ";
    }
    else{cout << plansza[6][2];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[6][3] == 0){
        cout << " ";
    }
    else{cout << plansza[6][3];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[6][4] == 0){
        cout << " ";
    }
    else{cout << plansza[6][4];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[6][5] == 0){
        cout << " ";
    }
    else{cout << plansza[6][5];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[6][6] == 0){
        cout << " ";
    }
    else{cout << plansza[6][6];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[6][7] == 0){
        cout << " ";
    }
    else{cout << plansza[6][7];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[6][8] == 0){
        cout << " ";
    }
    else{cout << plansza[6][8];}

    koloryTekstu(12);
    cout << " " << v2 << endl;


    cout << "                       ";
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                       ";
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza[7][0] == 0){
        cout << " ";
    }
    else{cout << plansza[7][0];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[7][1] == 0){
        cout << " ";
    }
    else{cout << plansza[7][1];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[7][2] == 0){
        cout << " ";
    }
    else{cout << plansza[7][2];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[7][3] == 0){
        cout << " ";
    }
    else{cout << plansza[7][3];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[7][4] == 0){
        cout << " ";
    }
    else{cout << plansza[7][4];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[7][5] == 0){
        cout << " ";
    }
    else{cout << plansza[7][5];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[7][6] == 0){
        cout << " ";
    }
    else{cout << plansza[7][6];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[7][7] == 0){
        cout << " ";
    }
    else{cout << plansza[7][7];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[7][8] == 0){
        cout << " ";
    }
    else{cout << plansza[7][8];}

    koloryTekstu(12);
    cout << " " << v2 << endl;


    cout << "                       ";
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                       ";
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza[8][0] == 0){
        cout << " ";
    }
    else{cout << plansza[8][0];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[8][1] == 0){
        cout << " ";
    }
    else{cout << plansza[8][1];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[8][2] == 0){
        cout << " ";
    }
    else{cout << plansza[8][2];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[8][3] == 0){
        cout << " ";
    }
    else{cout << plansza[8][3];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[8][4] == 0){
        cout << " ";
    }
    else{cout << plansza[8][4];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[8][5] == 0){
        cout << " ";
    }
    else{cout << plansza[8][5];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[8][6] == 0){
        cout << " ";
    }
    else{cout << plansza[8][6];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[8][7] == 0){
        cout << " ";
    }
    else{cout << plansza[8][7];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[8][8] == 0){
        cout << " ";
    }
    else{cout << plansza[8][8];}

    koloryTekstu(12);
    cout << " " << v2 << endl;


    cout << "                       ";
    cout << ld << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << d2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << d2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << pd << endl;

    koloryTekstu(15);
}




//FUNKCJA ODPOWIADAJACA ZA WYPISANIE PLANSZY ORAZ MOZLIWIOSCI JAKIE POSIADA GRACZ PODCZAS WYPELNIANIA PLANSZY
//WYKORZYSTYWANA JEST W GLOWNEJ GRZE
//KONIEC - 2090 LINIJKA
void wypisz_plansze_z_klawiszami(){

    char lg = 0xC9;   //lewy gorny rog
    char ld = 0xC8;   //lewy dolny rog
    char pg = 0xBB;   //prawy gorny rog
    char pd = 0xBC;   //prawy dolny rog
    char v2 = 0xBA;   //pionowy podwojny
    char h2 = 0xCD;   //poziomy podwojny
    char v1 = 0xB3;   //pionowy pojedynczy
    char h1 = 0xC4;   //poziomy pojedynczy
    char lb2 = 0xCC;   //lewy bok podwojny
    char pb2 = 0xB9;   //prawy bok podwojny
    char s2 = 0xCE;   //srodkowy podwojny
    char g2 = 0xCB;   //gorny podwojny
    char d2 = 0xCA;   //dolny podwojny
    char s1 = 0xC5;   //srodkowy pojedynczy



    koloryTekstu(7);
    cout << "                        " << 1 << "   " << 2 << "   " << 3 << "   " << 4 << "   " << 5 << "   " << 6 << "   " << 7 << "   " << 8 << "   " << 9 << endl;
    koloryTekstu(12);
    cout << "                      ";
    cout << lg << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << g2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << g2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << pg << endl;


    cout << "                    ";
    koloryTekstu(7);
    cout << 1 << " ";
    koloryTekstu(12);
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza[0][0] ==0){
        cout << " ";
    }
    else{cout << plansza[0][0];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[0][1] == 0){
        cout << " ";
    }
    else{cout << plansza[0][1];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[0][2] == 0){
        cout << " ";
    }
    else{cout << plansza[0][2];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[0][3] == 0){
        cout << " ";
    }
    else{cout << plansza[0][3];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[0][4] == 0){
        cout << " ";
    }
    else{cout << plansza[0][4];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[0][5] == 0){
        cout << " ";
    }
    else{cout << plansza[0][5];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[0][6] == 0){
        cout << " ";
    }
    else{cout << plansza[0][6];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[0][7] == 0){
        cout << " ";
    }
    else{cout << plansza[0][7];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[0][8] == 0){
        cout << " ";
    }
    else{cout << plansza[0][8];}

    koloryTekstu(12);
    cout << " " << v2 << endl;


    cout << "                      ";
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                    ";
    koloryTekstu(7);
    cout << 2 << " ";
    koloryTekstu(12);
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza[1][0] == 0){
        cout << " ";
    }
    else{cout << plansza[1][0];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[1][1] == 0){
        cout << " ";
    }
    else{cout << plansza[1][1];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[1][2] == 0){
        cout << " ";
    }
    else{cout << plansza[1][2];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[1][3] == 0){
        cout << " ";
    }
    else{cout << plansza[1][3];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[1][4] == 0){
        cout << " ";
    }
    else{cout << plansza[1][4];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[1][5] == 0){
        cout << " ";
    }
    else{cout << plansza[1][5];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[1][6] == 0){
        cout << " ";
    }
    else{cout << plansza[1][6];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[1][7] == 0){
        cout << " ";
    }
    else{cout << plansza[1][7];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[1][8] == 0){
        cout << " ";
    }
    else{cout << plansza[1][8];}

    koloryTekstu(12);
    cout << " " << v2 << endl;


    cout << "                      ";
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                    ";
    koloryTekstu(7);
    cout << 3 << " ";
    koloryTekstu(12);
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza[2][0] == 0){
        cout << " ";
    }
    else{cout << plansza[2][0];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[2][1] == 0){
        cout << " ";
    }
    else{cout << plansza[2][1];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[2][2] == 0){
        cout << " ";
    }
    else{cout << plansza[2][2];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[2][3] == 0){
        cout << " ";
    }
    else{cout << plansza[2][3];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[2][4] == 0){
        cout << " ";
    }
    else{cout << plansza[2][4];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[2][5] == 0){
        cout << " ";
    }
    else{cout << plansza[2][5];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[2][6] == 0){
        cout << " ";
    }
    else{cout << plansza[2][6];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[2][7] == 0){
        cout << " ";
    }
    else{cout << plansza[2][7];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[2][8] == 0){
        cout << " ";
    }
    else{cout << plansza[2][8];}

    koloryTekstu(12);
    cout << " " << v2 << endl;


    cout << "                      ";
    cout << lb2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << s2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << s2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << pb2 << endl;


    cout << "                    ";
    koloryTekstu(7);
    cout << 4 << " ";
    koloryTekstu(12);
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza[3][0] == 0){
        cout << " ";
    }
    else{cout << plansza[3][0];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[3][1] == 0){
        cout << " ";
    }
    else{cout << plansza[3][1];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[3][2] == 0){
        cout << " ";
    }
    else{cout << plansza[3][2];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[3][3] == 0){
        cout << " ";
    }
    else{cout << plansza[3][3];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[3][4] == 0){
        cout << " ";
    }
    else{cout << plansza[3][4];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[3][5] == 0){
        cout << " ";
    }
    else{cout << plansza[3][5];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[3][6] == 0){
        cout << " ";
    }
    else{cout << plansza[3][6];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[3][7] == 0){
        cout << " ";
    }
    else{cout << plansza[3][7];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[3][8] == 0){
        cout << " ";
    }
    else{cout << plansza[3][8];}

    koloryTekstu(12);
    cout << " " << v2 << endl;


    cout << "                      ";
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                    ";
    koloryTekstu(7);
    cout << 5 << " ";
    koloryTekstu(12);
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza[4][0] == 0){
        cout << " ";
    }
    else{cout << plansza[4][0];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[4][1] == 0){
        cout << " ";
    }
    else{cout << plansza[4][1];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[4][2] == 0){
        cout << " ";
    }
    else{cout << plansza[4][2];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[4][3] == 0){
        cout << " ";
    }
    else{cout << plansza[4][3];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[4][4] == 0){
        cout << " ";
    }
    else{cout << plansza[4][4];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[4][5] == 0){
        cout << " ";
    }
    else{cout << plansza[4][5];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[4][6] == 0){
        cout << " ";
    }
    else{cout << plansza[4][6];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[4][7] == 0){
        cout << " ";
    }
    else{cout << plansza[4][7];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[4][8] == 0){
        cout << " ";
    }
    else{cout << plansza[4][8];}

    koloryTekstu(12);
    cout << " " << v2 << endl;


    cout << "                      ";
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2;

    koloryTekstu(12);
    cout << "      Enter a value:" << endl;


    koloryTekstu(12);
    cout << "                    ";
    koloryTekstu(7);
    cout << 6 << " ";
    koloryTekstu(12);
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza[5][0] == 0){
        cout << " ";
    }
    else{cout << plansza[5][0];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[5][1] == 0){
        cout << " ";
    }
    else{cout << plansza[5][1];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[5][2] == 0){
        cout << " ";
    }
    else{cout << plansza[5][2];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[5][3] == 0){
        cout << " ";
    }
    else{cout << plansza[5][3];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[5][4] == 0){
        cout << " ";
    }
    else{cout << plansza[5][4];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[5][5] == 0){
        cout << " ";
    }
    else{cout << plansza[5][5];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[5][6] == 0){
        cout << " ";
    }
    else{cout << plansza[5][6];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[5][7] == 0){
        cout << " ";
    }
    else{cout << plansza[5][7];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[5][8] == 0){
        cout << " ";
    }
    else{cout << plansza[5][8];}

    koloryTekstu(12);
    cout << " " << v2;
    koloryTekstu(6);
    cout << "       [10] - menu" << endl;


    koloryTekstu(12);
    cout << "                      ";
    cout << lb2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << s2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << s2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << pb2;



    koloryTekstu(6);
    cout << "       [11] - solve" << endl;


    koloryTekstu(12);
    cout << "                    ";
    koloryTekstu(7);
    cout << 7 << " ";
    koloryTekstu(12);
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza[6][0] == 0){
        cout << " ";
    }
    else{cout << plansza[6][0];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[6][1] == 0){
        cout << " ";
    }
    else{cout << plansza[6][1];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[6][2] == 0){
        cout << " ";
    }
    else{cout << plansza[6][2];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[6][3] == 0){
        cout << " ";
    }
    else{cout << plansza[6][3];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[6][4] == 0){
        cout << " ";
    }
    else{cout << plansza[6][4];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[6][5] == 0){
        cout << " ";
    }
    else{cout << plansza[6][5];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[6][6] == 0){
        cout << " ";
    }
    else{cout << plansza[6][6];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[6][7] == 0){
        cout << " ";
    }
    else{cout << plansza[6][7];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[6][8] == 0){
        cout << " ";
    }
    else{cout << plansza[6][8];}

    koloryTekstu(12);
    cout << " " << v2 << endl;


    cout << "                      ";
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                    ";
    koloryTekstu(7);
    cout << 8 << " ";
    koloryTekstu(12);
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza[7][0] == 0){
        cout << " ";
    }
    else{cout << plansza[7][0];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[7][1] == 0){
        cout << " ";
    }
    else{cout << plansza[7][1];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[7][2] == 0){
        cout << " ";
    }
    else{cout << plansza[7][2];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[7][3] == 0){
        cout << " ";
    }
    else{cout << plansza[7][3];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[7][4] == 0){
        cout << " ";
    }
    else{cout << plansza[7][4];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[7][5] == 0){
        cout << " ";
    }
    else{cout << plansza[7][5];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[7][6] == 0){
        cout << " ";
    }
    else{cout << plansza[7][6];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[7][7] == 0){
        cout << " ";
    }
    else{cout << plansza[7][7];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[7][8] == 0){
        cout << " ";
    }
    else{cout << plansza[7][8];}

    koloryTekstu(12);
    cout << " " << v2 << endl;


    cout << "                      ";
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                    ";
    koloryTekstu(7);
    cout << 9 << " ";
    koloryTekstu(12);
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza[8][0] == 0){
        cout << " ";
    }
    else{cout << plansza[8][0];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[8][1] == 0){
        cout << " ";
    }
    else{cout << plansza[8][1];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[8][2] == 0){
        cout << " ";
    }
    else{cout << plansza[8][2];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[8][3] == 0){
        cout << " ";
    }
    else{cout << plansza[8][3];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[8][4] == 0){
        cout << " ";
    }
    else{cout << plansza[8][4];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[8][5] == 0){
        cout << " ";
    }
    else{cout << plansza[8][5];}

    koloryTekstu(12);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza[8][6] == 0){
        cout << " ";
    }
    else{cout << plansza[8][6];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[8][7] == 0){
        cout << " ";
    }
    else{cout << plansza[8][7];}

    koloryTekstu(12);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza[8][8] == 0){
        cout << " ";
    }
    else{cout << plansza[8][8];}

    koloryTekstu(12);
    cout << " " << v2 << endl;


    cout << "                      ";
    cout << ld << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << d2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << d2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << pd << endl;

    koloryTekstu(15);
}





//FUNKCJA ODPOWIADAJACA ZA WYPISANIE ROZWIAZANEJ PRZEZ PROGRAM PLANSZY, WYKORZYSTYWANA JEST
// PO WYBRANIU PRZEZ GRACZA OPCJI SOLVE
// KONIEC - 2948 LINIJKA
void wypisz_plansze_do_solvera(){

    char lg = 0xC9;   //lewy gorny rog
    char ld = 0xC8;   //lewy dolny rog
    char pg = 0xBB;   //prawy gorny rog
    char pd = 0xBC;   //prawy dolny rog
    char v2 = 0xBA;   //pionowy podwojny
    char h2 = 0xCD;   //poziomy podwojny
    char v1 = 0xB3;   //pionowy pojedynczy
    char h1 = 0xC4;   //poziomy pojedynczy
    char lb2 = 0xCC;   //lewy bok podwojny
    char pb2 = 0xB9;   //prawy bok podwojny
    char s2 = 0xCE;   //srodkowy podwojny
    char g2 = 0xCB;   //gorny podwojny
    char d2 = 0xCA;   //dolny podwojny
    char s1 = 0xC5;   //srodkowy pojedynczy



   koloryTekstu(6);
    cout << "                       ";
    cout << lg << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << g2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << g2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << pg << endl;


    cout << "                       ";
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[0][0] ==0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[0][0];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[0][1] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[0][1];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[0][2] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[0][2];}

    koloryTekstu(6);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[0][3] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[0][3];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[0][4] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[0][4];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[0][5] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[0][5];}

    koloryTekstu(6);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[0][6] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[0][6];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[0][7] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[0][7];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[0][8] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[0][8];}

    koloryTekstu(6);
    cout << " " << v2 << endl;


    cout << "                       ";
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                       ";
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[1][0] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[1][0];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[1][1] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[1][1];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[1][2] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[1][2];}

    koloryTekstu(6);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[1][3] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[1][3];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[1][4] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[1][4];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[1][5] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[1][5];}

    koloryTekstu(6);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[1][6] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[1][6];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[1][7] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[1][7];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[1][8] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[1][8];}

    koloryTekstu(6);
    cout << " " << v2 << endl;


    cout << "                       ";
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                       ";
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[2][0] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[2][0];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[2][1] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[2][1];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[2][2] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[2][2];}

    koloryTekstu(6);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[2][3] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[2][3];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[2][4] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[2][4];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[2][5] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[2][5];}

    koloryTekstu(6);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[2][6] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[2][6];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[2][7] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[2][7];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[2][8] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[2][8];}

    koloryTekstu(6);
    cout << " " << v2 << endl;


    cout << "                       ";
    cout << lb2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << s2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << s2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << pb2 << endl;


    cout << "                       ";
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[3][0] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[3][0];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[3][1] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[3][1];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[3][2] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[3][2];}

    koloryTekstu(6);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[3][3] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[3][3];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[3][4] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[3][4];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[3][5] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[3][5];}

    koloryTekstu(6);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[3][6] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[3][6];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[3][7] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[3][7];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[3][8] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[3][8];}

    koloryTekstu(6);
    cout << " " << v2 << endl;


    cout << "                       ";
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                       ";
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[4][0] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[4][0];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[4][1] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[4][1];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[4][2] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[4][2];}

    koloryTekstu(6);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[4][3] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[4][3];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[4][4] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[4][4];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[4][5] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[4][5];}

    koloryTekstu(6);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[4][6] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[4][6];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[4][7] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[4][7];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[4][8] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[4][8];}

    koloryTekstu(6);
    cout << " " << v2 << endl;


    cout << "                       ";
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                       ";
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[5][0] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[5][0];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[5][1] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[5][1];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[5][2] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[5][2];}

    koloryTekstu(6);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[5][3] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[5][3];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[5][4] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[5][4];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[5][5] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[5][5];}

    koloryTekstu(6);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[5][6] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[5][6];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[5][7] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[5][7];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[5][8] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[5][8];}

    koloryTekstu(6);
    cout << " " << v2 << endl;


    cout << "                       ";
    cout << lb2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << s2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << s2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << pb2 << endl;


    cout << "                       ";
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[6][0] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[6][0];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[6][1] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[6][1];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[6][2] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[6][2];}

    koloryTekstu(6);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[6][3] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[6][3];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[6][4] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[6][4];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[6][5] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[6][5];}

    koloryTekstu(6);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[6][6] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[6][6];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[6][7] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[6][7];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[6][8] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[6][8];}

    koloryTekstu(6);
    cout << " " << v2 << endl;


    cout << "                       ";
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                       ";
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[7][0] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[7][0];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[7][1] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[7][1];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[7][2] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[7][2];}

    koloryTekstu(6);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[7][3] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[7][3];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[7][4] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[7][4];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[7][5] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[7][5];}

    koloryTekstu(6);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[7][6] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[7][6];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[7][7] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[7][7];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[7][8] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[7][8];}

    koloryTekstu(6);
    cout << " " << v2 << endl;


    cout << "                       ";
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                       ";
    cout << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[8][0] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[8][0];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[8][1] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[8][1];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[8][2] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[8][2];}

    koloryTekstu(6);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[8][3] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[8][3];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[8][4] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[8][4];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[8][5] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[8][5];}

    koloryTekstu(6);
    cout << " " << v2 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[8][6] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[8][6];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[8][7] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[8][7];}

    koloryTekstu(6);
    cout << " " << v1 << " ";

    koloryTekstu(11);
    if(plansza_do_solvera[8][8] == 0){
        cout << " ";
    }
    else{cout << plansza_do_solvera[8][8];}

    koloryTekstu(6);
    cout << " " << v2 << endl;


    cout << "                       ";
    cout << ld << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << d2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << d2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << pd << endl;

    koloryTekstu(15);


}




//FUNKCJA ODPOWIADAJACA ZA WYPISANIE PLANSZY W KOLORZE CZERWONYM, WYKORZYSTYWANA JEST PO WPISANIU,
// PRZEZ GRACZA ZLEJ WARTOSCI DO PLANSZY
//KONIEC - 3620 LINIJKA
void wypisz_plansze_na_czerwono(){
    char lg = 0xC9;   //lewy gorny rog
    char ld = 0xC8;   //lewy dolny rog
    char pg = 0xBB;   //prawy gorny rog
    char pd = 0xBC;   //prawy dolny rog
    char v2 = 0xBA;   //pionowy podwojny
    char h2 = 0xCD;   //poziomy podwojny
    char v1 = 0xB3;   //pionowy pojedynczy
    char h1 = 0xC4;   //poziomy pojedynczy
    char lb2 = 0xCC;   //lewy bok podwojny
    char pb2 = 0xB9;   //prawy bok podwojny
    char s2 = 0xCE;   //srodkowy podwojny
    char g2 = 0xCB;   //gorny podwojny
    char d2 = 0xCA;   //dolny podwojny
    char s1 = 0xC5;   //srodkowy pojedynczy



    koloryTekstu(4);
    cout << "                        " << 1 << "   " << 2 << "   " << 3 << "   " << 4 << "   " << 5 << "   " << 6 << "   " << 7 << "   " << 8 << "   " << 9 << endl;
    cout << "                      " << lg << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << g2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << g2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << pg << endl;


    cout << "                    1 " << v2 << " ";

    if(plansza[0][0] ==0){
        cout << " ";
    }
    else{cout << plansza[0][0];}

    cout << " " << v1 << " ";

    if(plansza[0][1] == 0){
        cout << " ";
    }
    else{cout << plansza[0][1];}

    cout << " " << v1 << " ";

    if(plansza[0][2] == 0){
        cout << " ";
    }
    else{cout << plansza[0][2];}

    cout << " " << v2 << " ";

    if(plansza[0][3] == 0){
        cout << " ";
    }
    else{cout << plansza[0][3];}

    cout << " " << v1 << " ";

    if(plansza[0][4] == 0){
        cout << " ";
    }
    else{cout << plansza[0][4];}

    cout << " " << v1 << " ";

    if(plansza[0][5] == 0){
        cout << " ";
    }
    else{cout << plansza[0][5];}

    cout << " " << v2 << " ";

    if(plansza[0][6] == 0){
        cout << " ";
    }
    else{cout << plansza[0][6];}

    cout << " " << v1 << " ";

    if(plansza[0][7] == 0){
        cout << " ";
    }
    else{cout << plansza[0][7];}

    cout << " " << v1 << " ";

    if(plansza[0][8] == 0){
        cout << " ";
    }
    else{cout << plansza[0][8];}

    cout << " " << v2 << endl;


    cout << "                      " << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                    2 " << v2 << " ";

    if(plansza[1][0] == 0){
        cout << " ";
    }
    else{cout << plansza[1][0];}

    cout << " " << v1 << " ";

    if(plansza[1][1] == 0){
        cout << " ";
    }
    else{cout << plansza[1][1];}

    cout << " " << v1 << " ";

    if(plansza[1][2] == 0){
        cout << " ";
    }
    else{cout << plansza[1][2];}

    cout << " " << v2 << " ";

    if(plansza[1][3] == 0){
        cout << " ";
    }
    else{cout << plansza[1][3];}

    cout << " " << v1 << " ";

    if(plansza[1][4] == 0){
        cout << " ";
    }
    else{cout << plansza[1][4];}

    cout << " " << v1 << " ";

    if(plansza[1][5] == 0){
        cout << " ";
    }
    else{cout << plansza[1][5];}

    cout << " " << v2 << " ";

    if(plansza[1][6] == 0){
        cout << " ";
    }
    else{cout << plansza[1][6];}

    cout << " " << v1 << " ";

    if(plansza[1][7] == 0){
        cout << " ";
    }
    else{cout << plansza[1][7];}

    cout << " " << v1 << " ";

    if(plansza[1][8] == 0){
        cout << " ";
    }
    else{cout << plansza[1][8];}

    cout << " " << v2 << endl;


    cout << "                      " << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                    3 " << v2 << " ";

    if(plansza[2][0] == 0){
        cout << " ";
    }
    else{cout << plansza[2][0];}

    cout << " " << v1 << " ";

    if(plansza[2][1] == 0){
        cout << " ";
    }
    else{cout << plansza[2][1];}

    cout << " " << v1 << " ";

    if(plansza[2][2] == 0){
        cout << " ";
    }
    else{cout << plansza[2][2];}

    cout << " " << v2 << " ";

    if(plansza[2][3] == 0){
        cout << " ";
    }
    else{cout << plansza[2][3];}

    cout << " " << v1 << " ";

    if(plansza[2][4] == 0){
        cout << " ";
    }
    else{cout << plansza[2][4];}

    cout << " " << v1 << " ";

    if(plansza[2][5] == 0){
        cout << " ";
    }
    else{cout << plansza[2][5];}

    cout << " " << v2 << " ";

    if(plansza[2][6] == 0){
        cout << " ";
    }
    else{cout << plansza[2][6];}

    cout << " " << v1 << " ";

    if(plansza[2][7] == 0){
        cout << " ";
    }
    else{cout << plansza[2][7];}

    cout << " " << v1 << " ";

    if(plansza[2][8] == 0){
        cout << " ";
    }
    else{cout << plansza[2][8];}

    cout << " " << v2 << endl;


    cout << "                      " << lb2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << s2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << s2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << pb2 << endl;


    cout << "                    4 " << v2 << " ";

    if(plansza[3][0] == 0){
        cout << " ";
    }
    else{cout << plansza[3][0];}

    cout << " " << v1 << " ";

    if(plansza[3][1] == 0){
        cout << " ";
    }
    else{cout << plansza[3][1];}

    cout << " " << v1 << " ";

    if(plansza[3][2] == 0){
        cout << " ";
    }
    else{cout << plansza[3][2];}

    cout << " " << v2 << " ";

    if(plansza[3][3] == 0){
        cout << " ";
    }
    else{cout << plansza[3][3];}

    cout << " " << v1 << " ";

    if(plansza[3][4] == 0){
        cout << " ";
    }
    else{cout << plansza[3][4];}

    cout << " " << v1 << " ";

    if(plansza[3][5] == 0){
        cout << " ";
    }
    else{cout << plansza[3][5];}

    cout << " " << v2 << " ";

    if(plansza[3][6] == 0){
        cout << " ";
    }
    else{cout << plansza[3][6];}

    cout << " " << v1 << " ";

    if(plansza[3][7] == 0){
        cout << " ";
    }
    else{cout << plansza[3][7];}

    cout << " " << v1 << " ";

    if(plansza[3][8] == 0){
        cout << " ";
    }
    else{cout << plansza[3][8];}

    cout << " " << v2 << endl;


    cout << "                      " << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                    5 " << v2 << " ";

    if(plansza[4][0] == 0){
        cout << " ";
    }
    else{cout << plansza[4][0];}

    cout << " " << v1 << " ";

    if(plansza[4][1] == 0){
        cout << " ";
    }
    else{cout << plansza[4][1];}

    cout << " " << v1 << " ";

    if(plansza[4][2] == 0){
        cout << " ";
    }
    else{cout << plansza[4][2];}

    cout << " " << v2 << " ";

    if(plansza[4][3] == 0){
        cout << " ";
    }
    else{cout << plansza[4][3];}

    cout << " " << v1 << " ";

    if(plansza[4][4] == 0){
        cout << " ";
    }
    else{cout << plansza[4][4];}

    cout << " " << v1 << " ";

    if(plansza[4][5] == 0){
        cout << " ";
    }
    else{cout << plansza[4][5];}

    cout << " " << v2 << " ";

    if(plansza[4][6] == 0){
        cout << " ";
    }
    else{cout << plansza[4][6];}

    cout << " " << v1 << " ";

    if(plansza[4][7] == 0){
        cout << " ";
    }
    else{cout << plansza[4][7];}

    cout << " " << v1 << " ";

    if(plansza[4][8] == 0){
        cout << " ";
    }
    else{cout << plansza[4][8];}

    cout << " " << v2 << endl;


    cout << "                      " << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << "      Enter a value:" << endl;


    cout << "                    6 " << v2 << " ";

    if(plansza[5][0] == 0){
        cout << " ";
    }
    else{cout << plansza[5][0];}

    cout << " " << v1 << " ";

    if(plansza[5][1] == 0){
        cout << " ";
    }
    else{cout << plansza[5][1];}

    cout << " " << v1 << " ";

    if(plansza[5][2] == 0){
        cout << " ";
    }
    else{cout << plansza[5][2];}

    cout << " " << v2 << " ";

    if(plansza[5][3] == 0){
        cout << " ";
    }
    else{cout << plansza[5][3];}

    cout << " " << v1 << " ";

    if(plansza[5][4] == 0){
        cout << " ";
    }
    else{cout << plansza[5][4];}

    cout << " " << v1 << " ";

    if(plansza[5][5] == 0){
        cout << " ";
    }
    else{cout << plansza[5][5];}

    cout << " " << v2 << " ";

    if(plansza[5][6] == 0){
        cout << " ";
    }
    else{cout << plansza[5][6];}

    cout << " " << v1 << " ";

    if(plansza[5][7] == 0){
        cout << " ";
    }
    else{cout << plansza[5][7];}

    cout << " " << v1 << " ";

    if(plansza[5][8] == 0){
        cout << " ";
    }
    else{cout << plansza[5][8];}

    cout << " " << v2 << "       [10] - menu" << endl;


    cout << "                      " << lb2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << s2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << s2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << pb2 << "       [11] - solve" << endl;


    cout << "                    7 " << v2 << " ";

    if(plansza[6][0] == 0){
        cout << " ";
    }
    else{cout << plansza[6][0];}

    cout << " " << v1 << " ";

    if(plansza[6][1] == 0){
        cout << " ";
    }
    else{cout << plansza[6][1];}

    cout << " " << v1 << " ";

    if(plansza[6][2] == 0){
        cout << " ";
    }
    else{cout << plansza[6][2];}

    cout << " " << v2 << " ";

    if(plansza[6][3] == 0){
        cout << " ";
    }
    else{cout << plansza[6][3];}

    cout << " " << v1 << " ";

    if(plansza[6][4] == 0){
        cout << " ";
    }
    else{cout << plansza[6][4];}

    cout << " " << v1 << " ";

    if(plansza[6][5] == 0){
        cout << " ";
    }
    else{cout << plansza[6][5];}

    cout << " " << v2 << " ";

    if(plansza[6][6] == 0){
        cout << " ";
    }
    else{cout << plansza[6][6];}

    cout << " " << v1 << " ";

    if(plansza[6][7] == 0){
        cout << " ";
    }
    else{cout << plansza[6][7];}

    cout << " " << v1 << " ";

    if(plansza[6][8] == 0){
        cout << " ";
    }
    else{cout << plansza[6][8];}

    cout << " " << v2 << endl;


    cout << "                      " << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                    8 " << v2 << " ";

    if(plansza[7][0] == 0){
        cout << " ";
    }
    else{cout << plansza[7][0];}

    cout << " " << v1 << " ";

    if(plansza[7][1] == 0){
        cout << " ";
    }
    else{cout << plansza[7][1];}

    cout << " " << v1 << " ";

    if(plansza[7][2] == 0){
        cout << " ";
    }
    else{cout << plansza[7][2];}

    cout << " " << v2 << " ";

    if(plansza[7][3] == 0){
        cout << " ";
    }
    else{cout << plansza[7][3];}

    cout << " " << v1 << " ";

    if(plansza[7][4] == 0){
        cout << " ";
    }
    else{cout << plansza[7][4];}

    cout << " " << v1 << " ";

    if(plansza[7][5] == 0){
        cout << " ";
    }
    else{cout << plansza[7][5];}

    cout << " " << v2 << " ";

    if(plansza[7][6] == 0){
        cout << " ";
    }
    else{cout << plansza[7][6];}

    cout << " " << v1 << " ";

    if(plansza[7][7] == 0){
        cout << " ";
    }
    else{cout << plansza[7][7];}

    cout << " " << v1 << " ";

    if(plansza[7][8] == 0){
        cout << " ";
    }
    else{cout << plansza[7][8];}

    cout << " " << v2 << endl;


    cout << "                      " << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1;
    cout << v2 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << s1 << h1 << h1 << h1 << v2 << endl;


    cout << "                    9 " << v2 << " ";

    if(plansza[8][0] == 0){
        cout << " ";
    }
    else{cout << plansza[8][0];}

    cout << " " << v1 << " ";

    if(plansza[8][1] == 0){
        cout << " ";
    }
    else{cout << plansza[8][1];}

    cout << " " << v1 << " ";

    if(plansza[8][2] == 0){
        cout << " ";
    }
    else{cout << plansza[8][2];}

    cout << " " << v2 << " ";

    if(plansza[8][3] == 0){
        cout << " ";
    }
    else{cout << plansza[8][3];}

    cout << " " << v1 << " ";

    if(plansza[8][4] == 0){
        cout << " ";
    }
    else{cout << plansza[8][4];}

    cout << " " << v1 << " ";

    if(plansza[8][5] == 0){
        cout << " ";
    }
    else{cout << plansza[8][5];}

    cout << " " << v2 << " ";

    if(plansza[8][6] == 0){
        cout << " ";
    }
    else{cout << plansza[8][6];}

    cout << " " << v1 << " ";

    if(plansza[8][7] == 0){
        cout << " ";
    }
    else{cout << plansza[8][7];}

    cout << " " << v1 << " ";

    if(plansza[8][8] == 0){
        cout << " ";
    }
    else{cout << plansza[8][8];}

    cout << " " << v2 << endl;


    cout << "                      " << ld << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << d2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2;
    cout << d2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << h2 << pd << endl;

    koloryTekstu(15);
}




//FUNKCJA WYKORZYSTYWANA PO WYBRANIU PRZEZ GRACZA OPCJI SOLVE
void wypisz_porownanie(){
    cout << endl;
    wypisz_plansze();
    cout << endl;
    koloryTekstu(7);
    cout << "                      Solution: " << endl;
    koloryTekstu(15);
    cout << endl;
    wypisz_plansze_do_solvera();
}






//FUNKCJE ODPOWAIDAJACE ZA ROZWIAZANIE PLANSZY SUDOKU TZW. SUDOKU SOLVER
//WYKORZYSTANIE BACKTRACKINGU
//POCZATEK SOLVERA

//funkcja odpowiadajaca za szukanie niewypelnionego(0) miejsca w planszy
bool znajdzPustePole(int plansza[n][n], int &wiersz, int &kolumna){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(plansza[i][j] == 0){
                wiersz = i;
                kolumna = j;
                return true;
            }
        }
    }
    return false;
}

//funkcja sprawdzajaca czy dana liczba znajduje sie w wierszu
bool sprawdzWiersz(int plansza[n][n], int wiersz, int m){
    for(int i=0; i<n; i++){
        if(plansza[wiersz][i] == m){
            return false;
        }
    }
    return true;
}

//funkcja sprawdzajaca czy dana liczba znajduje sie w kolumnie
bool sprawdzKolumne(int plansza[n][n], int kolumna, int m){
    for(int i=0; i<n; i++){
        if(plansza[i][kolumna] == m){
            return false;
        }
    }
    return true;
}

//funkcja sprawdzajaca czy dana liczba znajduje sie w mniejszym kwadracie (boxie)
bool sprawdzBox(int plansza[n][n], int wiersz, int kolumna, int m){
    int gorneLewePoleOdWiersza = wiersz - (wiersz % 3);
    int gorneLewePoleOdKolumny = kolumna - (kolumna % 3);

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(plansza[i + gorneLewePoleOdWiersza][j + gorneLewePoleOdKolumny] == m){
                return false;
            }
        }
    }
    return true;
}


//funkcja sprawdzajaca czy dana liczba moze zostac wpisana w dane pole
bool sprawdzWierszKolumneBox(int plansza[n][n], int wiersz, int kolumna, int m){
    if(sprawdzWiersz(plansza_do_solvera, wiersz, m) && sprawdzKolumne(plansza_do_solvera, kolumna, m) && sprawdzBox(plansza_do_solvera, wiersz, kolumna, m)){
        return true;
    }
    return false;
}

//glowna funkcja odpowiadacjaca za wpisywanie liczb w dane pola i sprawdzanie wszystkich mozliwosci
//funkcja ta wybiera plansze, ktora jest prawidlowym rozwiazaniem
bool sudokuSolver(int plansza[n][n]){
    int wiersz{}, kolumna{};

    if(!znajdzPustePole(plansza_do_solvera, wiersz, kolumna)){
        return true;
    }

    for(int i=1; i<=n; i++){
        if(sprawdzWierszKolumneBox(plansza_do_solvera ,wiersz,kolumna,i)){
            plansza[wiersz][kolumna] = i;

            if(sudokuSolver(plansza)){
                return true;
            }

        plansza[wiersz][kolumna] = 0;
        }
    }
    return false;
}
//KONIEC SOLVERA




//FUNKCJA ODPOWIADAJACA ZA CALY PRZEBIEG GRY PO DOKONANIU WYBORU TRUDNOSCI PLANSZY
//KONIEC - 4044 LINIJKA
bool gra(string nazwaPliku){

    int k = 0;  //zmianna opisujaca miejsce w stringu
    string linia;   //zmienna do ktorej przekazywana jest wylosowana linia z pliku .txt
    int wiersz{};   //zmienna oprzechowujaca nr wiersza
    int kolumna{};   //zmienna przechowujaca za nr kolumny
    int nowa_liczba{};   //zmienna przechowujaca wybrana przez gracza wartosc do wpisania do planszy
    unsigned int end1 = 0;   //zmianna odpowiadajaca za przerwanie srodkowej petli (po wpisaniu w miejsce wiersza wartosci "12")
    unsigned int end2 = 0;   //zmienna odpowiadajaca za przerwanie zewnetrznej petli (po wpisaniu w miejsce wiersza wartosci "12")
    char wybor;   //zmienna odpowiadajaca za przechwytywanie klawiszu esc, gdy chcemy zakonczyc ogladanie prawidlowego rozwiazania planszy
    int blad{};   //zmienna przechowujaca ilosc bledow
    double zero{};   //sprawdzenie ile jest zer w tablicy
    double a{};   //dodanie odpowiedniej wartosci do zmiennej progress
    double progress{};   //pokazanie precentowego stanu rozwiazania tablicy




    //losowanie linii Z pliku .txt
    srand( time( NULL ) );
    int los = ( std::rand() % 20 ) + 1;



    //zapis danej linii z pliku .txt
    fstream plik(nazwaPliku, ios::in);

    if(plik.is_open()){
        for(int i =0; i<los; i++){
                getline(plik,linia);
        }
        }
    else {
        cout << "Nie można otworzyc pliku" << endl;
    }



    //zapis do tablicy plansza oraz plansza_do_solvera odpowiednich liczb z wylosowanej linii pliku .txt
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char z = linia[k];
            k++;
            plansza[i][j] = stoi(&z);
            plansza_do_solvera[i][j] = stoi(&z);
        }
    }



    //wywolanie funkcji rozwiazujacej sudoku, od teraz plansza_do_solvera posiada wszystkie prawidlowe liczby
    sudokuSolver(plansza_do_solvera);


    //sprawdznie ilosci zer wystepujacych w tablicy
    for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(plansza[i][j] == 0){
                       zero++ ;
                    }}}



    a = 100/zero;


   //petle odpowiadajace za glowny przebieg gry
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    while(plansza[i][j] == 0){  //sprawdzenie czy w planszy sa jakies niezapelnione miejsca

                        system("cls");
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        cout << endl;
                        koloryTekstu(6);
                        cout << "                Mistakes: ";
                        koloryTekstu(7);
                        cout << blad << endl;
                        koloryTekstu(6);
                        cout << "                Progress: ";
                        koloryTekstu(7);
                        cout << fixed << setprecision(1) << progress << "%" << endl;
                        cout << endl;
                        cout << endl;
                        wypisz_plansze_z_klawiszami();    //wypisanie planszy
                        cout << endl;
                        cout << endl;


                        //wprowadzenie wartosci nr wiersza
                        koloryTekstu(6);
                        cout << "                   Enter a row number: ";
                        koloryTekstu(7);
                        cin >> wiersz;
                        koloryTekstu(15);

                        //sprawdzenie czy wpisana wartosc jest liczba
                        if(!(wiersz)){
                                cout << endl;
                                koloryTekstu(3);
                                cout << "                   Enter a value from 1 to 11.";
                                koloryTekstu(15);
                                cin.clear();
                                cin.sync();
                                j--;
                                Sleep(3000);
                                continue;
                        }

                        //jesli wpisano "10" to powrot do menu
                        if(wiersz == 10){
                            system("cls");
                            petla_gry();
                        }

                        //jesli wpisano "12" to przerwanie wszystkich petli i wypisanie napisu "great job"
                        //(warunek powstal tylko na potrzeby prezentacji projektu)
                        if(wiersz == 12){
                            system("cls");
                            end1 = 1;
                            end2 = 1;
                            break;
                        }

                        //jesli wpisano "11" to wypisanie rozwiazania planszy
                        if(wiersz == 11){
                            while(true){    //nieskonczona petla przerywana przyciskiem Esc
                            system("cls");
                            wypisz_porownanie();
                            cout << endl;
                            cout << "                      Press Esc to go back to menu of difficulty." << endl;
                            if((wybor = getch()) == 27){
                                system("cls");
                                return false;}
                            else{
                                koloryTekstu(3);
                                cout << endl;
                                cout << "                      There is no such option!";
                                koloryTekstu(15);
                                Sleep(1700);
                                system("cls");
                                continue;
                                }}
                        }


                        //sprawdzenie czy wpisane wartosci mieszcza sie w przedziale od 1 do 11(w tym przypadku 12 --> przycisk do prezentacji)
                        if(!(wiersz < 12) && wiersz != 0){
                                cout << endl;
                                koloryTekstu(3);
                            cout << "                   Enter a value from 1 to 11.";
                            koloryTekstu(15);
                            j--;
                            Sleep(3000);
                            continue;
                        }


                        //wprowadzenie wartosci nr kolumny
                        koloryTekstu(6);
                        cout << "                   Enter a column number: ";
                        koloryTekstu(7);
                        cin >> kolumna;
                        koloryTekstu(15);


                        if(!(kolumna)){
                            cout << endl;
                            koloryTekstu(3);
                            cout << "                   Enter a value from 1 to 11.";
                            koloryTekstu(15);
                            cin.clear();
                            cin.sync();
                            j--;
                            Sleep(3000);
                            continue;
                        }


                        if(kolumna == 10){
                            system("cls");
                            petla_gry();
                        }


                         if(kolumna == 11){
                            while(true){
                            system("cls");
                            wypisz_porownanie();
                            cout << endl;
                            cout << "                      Press Esc to go back to menu of difficulty." << endl;
                            if((wybor = getch()) == 27){
                                system("cls");
                                return false;}
                            else{
                                koloryTekstu(3);
                                cout << endl;

                                cout << "                         There is no such option!";
                                koloryTekstu(15);
                                Sleep(1700);
                                system("cls");
                                continue;}}
                        }


                        if(!(kolumna < 11) && kolumna != 0){
                                cout << endl;
                                koloryTekstu(3);
                            cout << "                   Enter a value from 1 to 11.";
                            koloryTekstu(15);
                            j--;
                            Sleep(3000);
                            continue;
                        }

                        //sprawdzenie czy miejsce wybrane przez gracza jest już wypełnione
                        if(plansza[wiersz-1][kolumna-1] != 0){
                            cout << endl;
                            koloryTekstu(3);
                            cout << "                   That space is already filled.";
                            koloryTekstu(15);
                            j--;
                            Sleep(3000);
                            continue;
                        }



                        //wprowadzenie wybranej przez gracza liczby
                        cout << endl;
                        koloryTekstu(6);
                        cout << "                   Enter selected number: ";
                        koloryTekstu(11);
                        cin >> nowa_liczba;
                        koloryTekstu(15);


                        if(!(nowa_liczba)){
                            cout << endl;
                            koloryTekstu(3);
                            cout << "                   Enter a value from 1 to 11.";
                            koloryTekstu(15);
                            cin.clear();
                            cin.sync();
                            j--;
                            Sleep(3000);
                            continue;
                        }


                        if(nowa_liczba == 10){
                            system("cls");
                            petla_gry();
                        }


                         if(nowa_liczba == 11){
                              while(true){
                            system("cls");
                            wypisz_porownanie();
                            cout << endl;
                            cout << "                      Press Esc to go back to menu of difficulty." << endl;
                            if((wybor = getch()) == 27){
                                system("cls");
                                return false;}
                            else{
                                koloryTekstu(3);
                                cout << endl;

                                cout << "                         There is no such option!";
                                koloryTekstu(15);
                                Sleep(1700);
                                system("cls");
                                continue;
                                }}
                        }


                        if(!(nowa_liczba < 11) && nowa_liczba!= 0){
                                cout << endl;
                                koloryTekstu(3);
                            cout << "                   Enter a value from 1 to 11.";
                            koloryTekstu(15);
                            j--;
                            Sleep(3000);
                            continue;
                        }


                        //przypisanie wybranej przez gracza liczby do odpowiedniego miejsca w tablicy
                        plansza[wiersz-1][kolumna-1] = nowa_liczba;


                        //sprawdzenie czy wybrana liczba jest prawidlowa, jesli nie --> wypisanie czerwonej planszy
                        if(!(plansza[wiersz-1][kolumna-1] == plansza_do_solvera[wiersz-1][kolumna-1])){
                            system("cls");
                            cout << endl;
                            cout << endl;
                            cout << endl;
                            cout << endl;
                            cout << endl;
                            cout << endl;
                            cout << endl;
                            cout << endl;
                            blad++;
                            wypisz_plansze_na_czerwono();
                            plansza[wiersz-1][kolumna-1] = 0;
                            j--;
                            Sleep(600);
                        }
                        else{progress = progress + a;}


                        system("cls");
                        cout << endl;
                        koloryTekstu(15);
                    }

                    if(end1){
                        break;
                    }
                }
                if(end2){
                    break;
                }
            }


            //gdy nie znaleziono pustych miejsc w planszy, wyslwietlany jest napisa "great job"
            system("cls");
            napis_na_zakonczenie();
            return true;
}





//FUNKCJA ZAWIERAJACA ROZNE TYPY MENU I ODPOWIADAJACA ZA WYPISANIE DANEGO MENU
void wypisz(int typ_strony){
    switch(typ_strony){

    case 1:
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        napis_sudoku_maly();
        cout << endl;
        cout << endl;
        koloryTekstu(7);
        cout << "                         1. How to play" << endl;
        koloryTekstu(6);
        cout << "                         2. NEW GAME" << endl;
        koloryTekstu(7);
        cout << "                         3. Author" << endl;
        cout << "                         4. Exit" << endl;
        koloryTekstu(15);
        break;

    case 2:
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        napis_how_to_play();
        cout << endl;
        cout << endl;
        koloryTekstu(6);
        cout << "               Sudoku is played on a grid of 9 x 9 spaces. Within the" << endl;
        cout << "           rows and columns are 9 ""squares"" (made up of 3 x 3 spaces)." << endl;
        cout << "           Each row, column and square (9 spaces each) needs to be filled" << endl;
        cout << "           out with the numbers 1-9, without repeating any numbers within" << endl;
        cout << "           the row, column or square." << endl;
        cout << endl;
        koloryTekstu(11);
        cout <<  "              At the beginning select the row, column and number you" << endl;
        cout << "           want to put into the selected space. If this number will be" << endl;
        cout << "           incorrect, the board will turn red for a moment." << endl;
        cout << "           Remember. While entering values into the board, you must" <<endl;
        cout << "           confirm them with an enter key." << endl;
        cout << endl;
        koloryTekstu(12);
        cout << "               If you would like to see the board solution or go to the menu," << endl;
        cout << "           you can do so by entering the appropriate values anywhere" << endl;
        cout << "           (in place of row, column or number)." << endl;
        cout << endl;
        cout << endl;
        koloryTekstu(7);
        cout << "               Press Esc to go back to menu." << endl;
        koloryTekstu(15);
        break;

    case 3:
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        napis_author();
        cout << endl;
        cout << endl;
        koloryTekstu(6);
        cout << "                         Full name: ";
        koloryTekstu(7);
        cout << "Alicja Gruca" << endl;
        koloryTekstu(11);
        cout << "                         Faculty: ";
        koloryTekstu(7);
        cout << "Applied Mathematics" << endl;
        koloryTekstu(12);
        cout << "                         Subject: ";
        koloryTekstu(7);
        cout << "Computer science" << endl;
        koloryTekstu(6);
        cout << "                         Year of study: ";
        koloryTekstu(7);
        cout << "I" << endl;
        koloryTekstu(11);
        cout << "                         Group: ";
        koloryTekstu(7);
        cout << "3E" << endl;
        koloryTekstu(12);
        cout << "                         E-mail: ";
        koloryTekstu(7);
        cout << "alicgru026@student.polsl.pl" << endl;
        cout << endl;
        koloryTekstu(7);
        cout << "                         Press Esc to go back to menu." << endl;
        koloryTekstu(15);
        break;

    case 4:
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        napis_difficulty();
        cout << endl;
        cout << endl;
        koloryTekstu(7);
        cout << "                         1. ";
        koloryTekstu(11);
        cout << "EASY" << endl;
        koloryTekstu(7);
        cout << "                         2. ";
        koloryTekstu(12);
        cout << "MEDIUM" << endl;
        koloryTekstu(7);
        cout << "                         3. ";
        koloryTekstu(6);
        cout << "HARD" << endl;
        cout << endl;
        koloryTekstu(7);
        cout << "                           Press Esc to go back to menu." << endl;
        koloryTekstu(15);
        break;
    }
}





//FUNKCJA OBSLUGUJACA MENU POSREDNIE ZAWIERAJACE MOZLIWOSC WYBORU TRUDNOSCI PLANSZY
bool petla_trudnosci(){
    char wybor;
    for(;;){

        wypisz(4);

        wybor = getch();


        switch(wybor){

    case '1':
        system("cls");
        gra("latwa.txt");
        break;

    case '2':
        system("cls");
        gra("srednia.txt");
        break;

    case '3':
        system("cls");
        gra("trudna.txt");
        break;

    case 27:
        system("cls");
        petla_gry();
        break;

    default:
        cout << endl;
        koloryTekstu(3);
        cout << "                           There is no such option!";
        koloryTekstu(15);
        Sleep(1700);
        system("cls");
        petla_trudnosci();
    }

    getchar();

    system("cls");
        }

    return 0;
}






int main()
{

    okno_konsoli();

    tytulGry();

    petla_gry();

    system("pause");
    return 0;
}




//FUNKCJA OBSLUGUJACA GLOWNE MENU
bool petla_gry(){
    int menu = 1;
    char wybor;
    char wybor2;


    for(;;){

    wypisz(menu);

    wybor = getch();


    switch(wybor){

    case '1':

        while(true){
            system("cls");
            wypisz(2);
            if((wybor2 = getch()) == 27){
                system("cls");
                petla_gry();}
            else{
                koloryTekstu(3);
                cout << endl;
                cout << "               There is no such option!";
                koloryTekstu(15);
                Sleep(1700);
                system("cls");
                continue;
                }}
        break;


    case '2':

        system("cls");
        petla_trudnosci();
        //gra();
        break;


    case '3':

        while(true){
            system("cls");
            wypisz(3);
            if((wybor2 = getch()) == 27){
                system("cls");
                petla_gry();}
            else{
                koloryTekstu(3);
                cout << endl;
                cout << "                         There is no such option!";
                koloryTekstu(15);
                Sleep(1700);
                system("cls");
                continue;
                }}
        break;


    case '4':
        exit(0);
        break;


    default:
        cout << endl;
        koloryTekstu(3);
        cout << "                            There is no such option!";
        koloryTekstu(15);
        Sleep(1700);
        system("cls");
        petla_gry();
    }

    getchar();
    system("cls");

    }

    return 0;
}

