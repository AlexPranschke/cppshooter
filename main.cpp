#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <iomanip>
#include <fstream>
#include <ctime>

using namespace std;

void aplydata(int&, int&, int&, int&);
void buildwektor(vector < queue<int> >& vec, int);
void buildkolej(vector < queue<int> >& vec, int, int, int);
void wyskolb(vector < queue<int> > vec, int, int);
void wyswietlanie(vector < queue<int> > vec, int, int, int);
int option(char);
int trudnosc(int, int);
void sprkoniec(vector < queue<int> > vec, int, int);
void koniecgry();
void dodaj_kol(vector < queue<int> >& vec, int, int);
void przesun_lewo_prawo(int, int&, int);
void strzelaj(vector <queue<int> >& vec, int);

void sprzwyciestwo(const std::vector<std::queue<int>>& vec, bool& , int);
int main()
{
    bool zwyciestwo = false;
    srand(time(NULL));
    int k, b, r, n;
    aplydata(k, b, r, n);
    int w = 10;
    int licznik = 0;
    int kolejnywiersz = trudnosc(r, n);
    int gracz = k / 2;
    cout << "nowy wiersz bedzie sie pojawiac co : " << kolejnywiersz;
    vector<queue<int> > vec;
    buildwektor(vec, k);
    buildkolej(vec, k, b, w);
    for (;;)
    {
        int wybor;
        licznik++;
        char znak;
        cout << endl;
        wyswietlanie(vec, k, w, gracz);
        cout << "lewo/prawo/strzal/koniec  [A/S/W/K]: ";
        cin >> znak;
        getchar();
        system("cls");
        wybor = option(znak);
        if (wybor)
            cout << "\nwybrales opcje : " << wybor;
        cout << "\nlicznik wynosi : " << licznik;
        if ((wybor == 1) || (wybor == 2))
            przesun_lewo_prawo(k, gracz, wybor);
        if (wybor == 3)
            strzelaj(vec, gracz);
        if (licznik % kolejnywiersz == 0)
            dodaj_kol(vec, k, w);
        sprkoniec(vec, w, k);
        sprzwyciestwo(vec, zwyciestwo, k);
        if (zwyciestwo == true)
            koniecgry();
    }
    cout << endl;
    system("pause");
    return 0;
}

void sprzwyciestwo(const std::vector<std::queue<int>>& vec, bool& zwyciestwo, int kolumny)
{
    // Tworzymy zmienn¹ bool do œledzenia, czy wszystkie kolejki s¹ puste
    bool apap = true;

    // Sprawdzamy ka¿d¹ kolejkê
    for (int i = 0; i < kolumny; i++) {
        if (!vec[i].empty()) { // Jeœli któraœ kolejka nie jest pusta
            apap = false;
            break; // Mo¿emy przerwaæ, jeœli choæ jedna nie jest pusta
        }
    }

    // Jeœli wszystkie kolejki s¹ puste, ustawiamy zwyciestwo na true
    zwyciestwo = apap;

    // Wywo³ujemy koniecgry(), jeœli apap jest true
    if (apap) {
        koniecgry();
    }
}

void strzelaj(vector <queue<int> >& vec, int gracz)
{
    if (vec[gracz].size() == 0)
        cout << "nie moge strzelic w nic";
    else
        vec[gracz].pop();
}
void przesun_lewo_prawo(int kolumny, int& gracz, int wybor)
{
    if (wybor == 1)        //przesuw w lewo
    {
        if (gracz == 0)
            cout << "nie moge przesunac gracza";
        else
            gracz = gracz - 1;
    }
    if (wybor == 2)        //przesuw w prawo
    {
        if (gracz == (kolumny - 1))
            cout << "nie moge przesunac gracza";
        else
            gracz = gracz + 1;
    }




}
int trudnosc(int minimum, int maximum)
{
    int liczba;
    maximum += 1;
    liczba = (rand() % maximum);
    liczba = liczba + minimum;
    return liczba;
}


void sprkoniec(vector < queue<int> > vec, int wiersze, int kolumny)
{
    cout << "\nrozmiary kolejek : ";
    for (int i = 0; i < kolumny; i++) {
        cout << vec[i].size() << ' ';
        cout << vec[i].size() << ' ';
        if (vec[i].size() == wiersze)
            koniecgry();
    }
    cout << endl;
}

void koniecgry()
{
    system("cls");
    cout << "\n\n\n\n\n!!!!GAME OVER!!!!!!\n\n\n\n\n\n";
    exit(0);
}

int option(char A)
{
    switch (A)
    {
    case 97:
        cout << "\nwybrales skret w lewo";
        return(1);
        break;
    case 115:
        cout << "\nwybrales skret w prawo";
        return(2);
        break;
    case 119:
        cout << "\nwybrales strzal";
        return(3);
        break;
    case 107:
        cout << "\nwybrales koniec programu";
        koniecgry();
        break;
    default:
        cout << "Nie ma takiej opcji w menu!";
        break;
    }
}


void wyswietlanie(vector < queue<int> > vec, int kolumny, int wiersze, int gracz)
{
    for (int i = 0; i < kolumny; i++)
        cout << "-----";
    cout << endl;

    wyskolb(vec, kolumny, wiersze);
    cout << ' ';
    for (int i = 0; i < gracz; i++) //gracz
        cout << "     ";
    cout << "=[]=";
    for (int i = 0; i < kolumny - (gracz + 1); i++)
        cout << "     ";
    cout << endl;

    for (int j = 0; j < kolumny; j++)
        cout << "-----";
    cout << endl;
}

void dodaj_kol(vector < queue<int> >& vec, int kolumny, int wiersze)
{
    for (int i = 0; i < kolumny; i++)
    {
        vec[i].push(1);
    }
}

void buildkolej(vector < queue<int> >& vec, int kolumny, int bloki, int wiersze)
{
    for (int j = 0; j < wiersze; j++) {
        for (int i = 0; i < kolumny; i++)
        {
            if (j < bloki)vec[i].push(1);
        }
    }
}


void buildwektor(vector < queue<int> >& vec, int kolumny)
{
    for (int i = 0; i < kolumny; i++)
        vec.push_back(queue<int>());
}


void aplydata(int& k, int& b, int& r, int& n)
{
    cout << "\npodaj ilosc kolumn : ";
    cin >> k;
    cout << "\npodaj ilosc ilosc bloczkow na poczatku : ";
    cin >> b;
    do
    {
        cout << "\npodaj minimalna ilosc ruchow do dodania klocka : ";
        cin >> r;
        cout << "\npodaj maksymalna ilosc ruchow do dodania klocka : ";
        cin >> n;
        n = n - r;
    } while (n < 0);
}

void wyskolb(vector < queue<int> > vec, int kolumny, int wiersze)
{
    int a;
    for (int j = 0; j < wiersze; j++) {
        for (int i = 0; i < kolumny; i++)
        {

            if (vec[i].size() > j)
            {
                a = 1;
            }
            else
            {
                a = 0;
            }
            if (a == 1)
            {
                cout << setw(5) << "####";
            }
            else { cout << setw(5) << "    "; }
        }
        cout << endl;
    }
}
