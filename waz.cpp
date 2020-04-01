#include <iostream>
#include <process.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
VOID WINAPI Sleep(DWORD dwMilliseconds);

int kod = 0;
char znacznik;
char wybor = 'n';

int szer = 15;
int wys = 10;
int punkty = 0;

void funkcja(void * Args)
{
    while(true)
    {
        kod = getch();
    if(kbhit())
        kod = getch();
    }
    if(kod == 27)
        _endthread();
}



void gra()
{
    srand(time(NULL));
    int licznikPetli = 0;
    int tabX[60];
    int tabY[60];
    string tablica[wys + 1][szer + 1];
    int y = 1;
    int x = 1;
    int nowyIndeks;

    int yy;
    int xx;
    int poprzedniKod = 0;
    bool znacznikO = false;

    for(int i = 0; i < wys + 1; i++)
    {
        for(int j = 0; j < szer + 1; j++)
        {
            tablica[i][j] = " ";
        }
    }

_beginthread( funkcja, 0, NULL );

    while(kod != 27)
    {
        cout << "Esc - wyjscie" << endl;
        cout << "Punkty: " << punkty << endl;

        if(znacznikO == false)
        {
        do{
        yy = rand() % (wys - 1) + 1;
        xx = rand() % (szer - 1) + 1;
        }while((yy == y) || (xx == x));
        }

        for(int i = 0; i < wys + 1; i++)
        {
            for(int j = 0; j < szer + 1; j++)
            {

                if((i == y) && (j == x))
                {
                    if(tablica[i][j] != "@")
                    {
                        tablica[i][j] = "@";
                    }
                    else
                    {
                        if(licznikPetli != 0)
                        {
                        kod = 27;
                        }

                    }
                }

                if((i == 0) || (i == wys) || (j == 0) || (j == szer))
                {
                    tablica[i][j] = "0";
                }

                if( (i == yy) && (j == xx) )
                {
                    tablica[i][j] = "X";
                    znacznikO = true;
                }

                if((licznikPetli > punkty) && (licznikPetli != 0))
                {
                    tablica[tabY[licznikPetli - punkty-1]][tabX[licznikPetli - punkty-1]] = " ";
                }

                if((licznikPetli <= punkty) && (punkty != 0))
                {
                    tablica[tabY[licznikPetli +(59 - (punkty))]][tabX[licznikPetli + (59 - (punkty))]] = " ";
                }

            }
        }





        for(int i = 0; i < wys + 1; i++)
        {
            for(int j = 0; j < szer + 1; j++)
            {
                cout << tablica[i][j];
            }
            cout << endl;
        }


        if( (kod == 77) && (poprzedniKod != 75) && (znacznik != 'l') || ((znacznik == 'p') && (kod == 75)))
          {

              znacznik = 'p';

            if(x < szer - 1)
            {
                x++;
            }else{
            x = 1;
            }
        }


        if((kod == 80) && (poprzedniKod != 72) && (znacznik != 'g') || ((znacznik == 'd') && (kod == 72)))
        {

           znacznik = 'd';

            if(y < wys - 1)
            {
                y++;
            }else{
            y = 1;
            }
        }

        if(( (kod == 72) && (poprzedniKod != 80) && (znacznik != 'd') ) || ((znacznik == 'g') && (kod == 80)))
        {
            znacznik = 'g';

            if(y > 1)
            {
                y--;
            }else{
            y = wys - 1;
            }
        }


        if( (kod == 75) && (poprzedniKod != 77) && (znacznik != 'p') || ((znacznik == 'l') && (kod == 77)))
        {
            znacznik = 'l';


            if(x > 1)
            {
                x--;
            }else{
            x = szer - 1;
            }
        }

        if((y == yy) && (x == xx))
        {
            tablica[y][x] = " ";
            znacznikO = false;
            punkty++;
        }

        if(licznikPetli < 59)
        {
        if(kod != 0)
        licznikPetli++;
        }
        else
        {
           licznikPetli = 0;
        }

        tabX[licznikPetli] = x;
        tabY[licznikPetli] = y;

        cout << licznikPetli;
        Sleep(1);

        //system("cls");
        //clrscr();
        //system("clear");
        system("cls");
        //fprintf(stdout, "\033[2J"); // Cancella lo schermo
        //fprintf(stdout, "\033[1;1H"); // Posiziona il cursore sulla linea colonna 1
    }
}




int main()
{

    gra();
    cout << endl <<"Przegrana :(" << endl;
    cout << "Zdobyte punkty: " << punkty << endl;
    cout << endl;

    cin.get();

    return 0;
}
