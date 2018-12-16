#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <string.h>

using namespace std;

class ElementListy {

public:
    ElementListy *nastepny;
    ElementListy *poprzedni;
    int wartosc;

    ElementListy(int wartosc, ElementListy *nastepny, ElementListy *poprzedni)
    {
    ElementListy::wartosc = wartosc;
    ElementListy::nastepny = nastepny;
    ElementListy::poprzedni = poprzedni;
    }
};



class Lista {

public:

    int rozmiar;

    Lista();
    ~Lista();

    ElementListy *pierwszyElement;
    ElementListy *ostatniElement;
    ElementListy *aktualnyElement;

    void dodajNaPoczatek(int wartosc);
    void DodajNaPozycje(int wartosc, int pozycja);
    void dodajNaKoniec(int wartosc);
    void dodajElementLosowo(int wartosc);
    void Wypisz();
    void wczytajZPliku();

    void usunPierwszy();
    void usunOstatni();
    void Usun(int);
    bool Wyszukaj(int wartosc);
};


#endif // LISTA_H
