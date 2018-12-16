#include "Tablica.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <fstream>
using namespace std;

Tablica::Tablica()
{
    tablica = NULL;
    rozmiar = 0;
    //ctor
}

Tablica::~Tablica()
{
    rozmiar = 0;
    delete [] tablica;
    //dtor
}

void Tablica::StworzTablice(int k)
{
    rozmiar = k;
    tablica = new int[rozmiar];
    for(int i=0; i < k; i++)
    {
        tablica[i] = i;//rand();
    }
}

bool Tablica::ZbudujZPliku()
{
    fstream plik;
    plik.open("liczby.txt");

    if(plik.good() == true)
    {
        plik>>rozmiar;
        tablica = new int [rozmiar];

        for(int i=0; i<rozmiar; i++)
        {
            plik>>tablica[i];
        }
        plik.close();
        return true;
    }
    else
    {
        cout<<"Pliku nie udalo sie otworzyc"<<endl;
        return false;
    }

}

void Tablica::UsunElementPoczatek()
{
    int *nowaTab = new int[rozmiar--];
    for(int i = 0; i < rozmiar; i ++)
    {
        nowaTab[i] = tablica[i+1];
    }
    delete [] tablica;
    tablica = nowaTab;
    rozmiar--;
}

void Tablica::UsunElementKoniec()
{
    int *nowaTab = new int[rozmiar--];
    for(int i = 0; i < rozmiar; i ++)
    {
        nowaTab[i] = tablica[i];
    }
    delete [] tablica;
    tablica = nowaTab;
    rozmiar--;
}

void Tablica::UsunElementNaPozycji(int k)
{
    int *nowaTab = new int[rozmiar--];

    if((k<0)||(k>rozmiar))
    {
        cout<<"Wprowadzono nie poprawny indeks"<<endl;
    }
    else
    {

    for(int i=0; i<=rozmiar-1; i++)
    {
        if(i<k)
        {
            nowaTab[i] = tablica[i];
        }
        else if(i>=k)
        {
            nowaTab[i] = tablica[i+1];
        }

    }
        tablica = NULL;
        tablica = nowaTab;

    }
        //delete [] nowaTab;
        //nowaTab=NULL;
}

void Tablica::UsunElementLosowo()
{
    int k = (rand()%rozmiar);
    UsunElementNaPozycji(k);
}

void Tablica::WstawElementPoczatkowy(int x)
{
    int *nowaTab = new int[rozmiar+1];
    nowaTab[0] = x;
    for(int i=0; i<rozmiar; i++)
    {
        nowaTab[i+1] = tablica[i];
    }
    delete[] tablica;
    tablica = nowaTab;
    nowaTab = NULL;
    rozmiar++;
}

void Tablica::WstawElementKoncowy(int x)
{
    int *nowaTab = new int[rozmiar + 1];
    nowaTab[rozmiar] = x;

    for(int i = 0; i < rozmiar; i ++)
    {
        nowaTab[i] = tablica[i];
    }

    delete[] tablica;
    tablica = nowaTab;
    nowaTab = NULL;
    rozmiar++;
}

void Tablica::WstawElementNaPozycji(int x, int k)
{
    int *nowaTab = new int[rozmiar + 1];
    if((x<0)||(k<0)||(k>rozmiar))
    {
        cout<<"Podane wartosci sa niepoprawne"<<endl;
    }
    else
    {
    for(int i=0; i<=rozmiar; i++)
    {
        if(i<k)
        {
            nowaTab[i] = tablica[i];
        }
        else if(i==k)
        {
            nowaTab[i] = x;
        }
        else if(i>k)
        {
            nowaTab[i] = tablica[i-1];
        }
    }
        delete[] tablica;
        tablica = nowaTab;
        nowaTab = NULL;
        rozmiar++;
    }
}

void Tablica::WstawElementLosowo(int x)
{
    int k = (rand()%rozmiar);
    WstawElementNaPozycji(x,k);
}

void Tablica::WypiszTablice()
{
    cout<<endl<<"Liczba elementow w tablicy to: "<<rozmiar<<endl;
    for(int i=0; i<rozmiar; i++)
    {
        //cout<<"Element tablicy nr "<<i + 1<<" : "<<tablica[i]<<endl;
        cout << tablica[i] << " ";
    }
    cout<<endl;
}

bool Tablica::Wyszukaj(int x)
{
    for(int i=0; i<rozmiar; i++)
    {
        if(tablica[i] == x)
            return true;
    }
    return false;
}



