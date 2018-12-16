#include "Kopiec.h"
#include <iostream>
#include<fstream>
#include <iostream>

using namespace std;

Kopiec::Kopiec()
{
    rozmiar = 0;
    tablica = NULL;
    //ctor
}

Kopiec::~Kopiec()
{
    if(rozmiar>0)
        delete [] tablica;
    //dtor
}

//Metoda pozwala na wczytanie danych z pliku do struktury
bool Kopiec::ZbudujZPliku()
{
    fstream plik;
    plik.open("liczby.txt");            //Otwieranie pliku liczby.txt
    int wartosc;

    if(plik.good())                     //Jesli plik otworzy sie dobrze
    {
        while(plik.good())
        {
        plik>>wartosc;
        DodajElement(wartosc);
        }
        return true;
    }
    else                                //Jesli plik nie otworzy sie
    {
        cout<<"Nie udalo sie otworzyc pliku"<<endl;
        return false;
    }
}

//Metoda wypisuje kopiec w charakterystyce tablicy
void Kopiec::WyswietlKopiec(string sp, string sn, int x)
{
    cout << "Elementy kopca:" << endl;
    if (tablica != NULL) {
        for (int i = 0; i < rozmiar; i++) {
            cout << "    [" << i << "] " << tablica[i] << endl;
        }
    } else {
        cout << "    Tablica nie ma ¿adnych elementów" << endl;
    }
}

//Metoda dodaje wartosc do kopca
void Kopiec::DodajElement(int x)
{
    if(Szukaj(x)==false)                     //Sprawdzenie czy w kopcu nie ma juz podanej wartosci
    {
        int *nowaTab = new int [rozmiar + 1];  //Utworzenie tablicy o 1 wiekszej

        for (int i = 0; i < rozmiar; i++)   //Przepisanie danych ze starej tablicy do nowej
        {
            nowaTab[i] = tablica[i];
        }
        nowaTab[rozmiar] = x;   //Dodanie wybranej wartosci do kopca

        delete[]tablica;      //Usun stara tablice

        tablica = nowaTab;   //Zastap stara tablice nowa
        rozmiar++;          //Zwieksz rozmiar kopca
        Popraw();           //Popraw kolejnosc elementów w kopcu
    }
    else
    {
        cout<<"Wartosc nie zostala dodana - juz sie tam znajduje"<<endl;
    }
}

//Metoda usuwa wartosc x z kopca
void Kopiec::UsunElement(int x)
{
    if(Szukaj(x))
    {
        for(int i=0; i<rozmiar; i++)                    //Rozpoczecie przeszukiwania kopca
        {
            if(tablica[i] == x)                         //Moment znalezienia wartosci szukanej
            {
                int *nowaTab = new int [rozmiar - 1];   //Deklaracja nowego kopca pomocniczego

                for(int j=0; j<i; j++)
                {
                    nowaTab[j] = tablica[j];            //Przekopiowanie elementow do wartosci szukanej
                }
                for(int j=i+1; j<rozmiar; j++)
                {
                    nowaTab[j-1] = tablica[j];          //Przekopiowanie elementow po wartosci szukanej
                }
                delete[] tablica;                       //Usuniecie zawartosci tablicy starego kopca
                tablica = nowaTab;                      //Przypisanie wskaznika na nowy kopiec
                rozmiar--;                              //Zmniejszenie rozmiaru o jeden
                Popraw();                               //Przywrocenie wlasciwosci kopca
                return;
            }
        }
    }
    else
    {
        cout<<"Brak elementu do usuniecia"<<endl;
    }
}

//Metoda przywraca wlasciwosci kopca
void Kopiec::Popraw()
{
    int j = 0;                                  //Zmienna pomocnicza
    for(int i=rozmiar; i>0; i--)
    {
        if(tablica[i-1]<tablica[i])
        {
            j = tablica[i-1];
            tablica[i-1] = tablica[i];
            tablica[i] = j;
        }
    }
}

//Metoda wyszukuje wartosc w kopcu
bool Kopiec::Szukaj(int x)
{
    for(int i=0; i<rozmiar; i++)        //Przeszukiwanie kopca
    {
        if(tablica[i] == x)             //Jesli wartosc x jest rowna elementowi kopca
            return true;                //Zwroc true
    }
    return false;                       //Jesli nie zwroc false
}

