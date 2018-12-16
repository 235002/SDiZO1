#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <fstream>

#include "Lista.h"

using namespace std;

Lista::Lista() {

    Lista::pierwszyElement = NULL;
    Lista::aktualnyElement = NULL;
    Lista::ostatniElement = NULL;
    Lista::rozmiar = 0;

}

Lista::~Lista() {


    for (int i = 0; i < Lista::rozmiar; i++) {

        //Przypisz kolejny element jako aktualny
        aktualnyElement = pierwszyElement->nastepny;
        //Usun pierwszy element
        delete pierwszyElement;

        pierwszyElement = aktualnyElement;
    }

}

void Lista::wczytajZPliku()
{
    fstream plik;
    int wartosc;
    int rozmiar;

    plik.open("liczby.txt");
    if(plik.good())
    {
        plik>>rozmiar;
        while(plik.good())
        {
            plik>>wartosc;
            dodajNaPoczatek(wartosc);
        }

    }

}

void Lista::dodajNaPoczatek(int wartosc) {

    //Sprawdz, czy istnieje element poczatkowy
    if (pierwszyElement == NULL) {
        //Utwórz nowy element i ustaw go jako element poczatkowy i koncowy
        pierwszyElement = new ElementListy(wartosc, NULL, NULL);
        ostatniElement = pierwszyElement;

    } else {
        //Ustaw element ktory byl pierwszym jako aktualny
        aktualnyElement = pierwszyElement;
        //Zastap pierwszy element nowym
        //Ustaw jego wartosc oraz element kolejny na element aktualny (byly pierwszy)
        pierwszyElement = new ElementListy(wartosc, aktualnyElement, NULL);
        aktualnyElement->poprzedni = pierwszyElement;

    }

    //Zwieksz rozmiar listy
    rozmiar = rozmiar + 1;

}

void Lista::dodajNaKoniec(int wartosc) {
    //Sprawdz, czy istnieje element poczatkowy
    if (pierwszyElement == NULL) {
        //Utwórz nowy element i ustaw go jako element poczatkowy i koncowy
        ostatniElement = new ElementListy(wartosc, NULL, NULL);
        pierwszyElement = ostatniElement;

    } else {
        //Ustaw element który byl ostatnim jako aktualny
        aktualnyElement = ostatniElement;
        //Zastap ostatni element nowym
        //Ustaw jego wartosc oraz element poprzedni na element aktualny (byly ostatni)
        ostatniElement = new ElementListy(wartosc, NULL, aktualnyElement);
        aktualnyElement->nastepny = ostatniElement;
    }
    //Zwieksz rozmiar listy o 1
    rozmiar++;
}

void Lista::DodajNaPozycje(int wartosc, int pozycja) {

    //Sprawdz czy w liscie istnieje pozycja podana przez uzytkownika
    if (pozycja < 0 || pozycja > rozmiar) {
        cout << "W liscie nie istnieje pozycja [" << pozycja << "]" << endl;
        return;
    }
    //Sprawdz czy wybrana pozycja jest pierwsza
    if (pozycja == 0) {
        Lista::dodajNaPoczatek(wartosc);
        return;
    }

    //Sprawdz czy wybrana pozycja jest ostatnia
    if (pozycja == rozmiar - 1) {
        dodajNaKoniec(wartosc);
        return;
    }

    //Sprawdz w której polowie listy znajduje sie wybrany element
    if (pozycja < rozmiar / 2) { //liczone od indeksu zerowego

        //Przypisz za aktualny element pierwszy
        aktualnyElement = pierwszyElement;

        //Przesun wszyskie elementy o jeden dalej
        for (int i = 1; i < pozycja - 1; ++i) {
            aktualnyElement = aktualnyElement->nastepny;
        }

    } else {

        //Przypisz za aktualny element ostatni
        aktualnyElement = ostatniElement;

        //Przesun wszystkie elementy o jedna pozycje wstecz
        for (int i = 0; i < Lista::rozmiar - pozycja - 1; ++i) {
            aktualnyElement = aktualnyElement->poprzedni;
        }
    }

    //Stwórz nowy element listy z podanymi parametrami
    ElementListy *nowyElementListy = new ElementListy(wartosc, aktualnyElement,
                                                      aktualnyElement->nastepny);

    //przypisz nowy element w odpowiednim miejscu listy
    aktualnyElement->nastepny->poprzedni = nowyElementListy;
    aktualnyElement->nastepny = nowyElementListy;

    //Zwieksz rozmiar listy
    rozmiar = rozmiar + 1;
}

void Lista::dodajElementLosowo(int wartosc)
{
    int k = (rand()%rozmiar);
    DodajNaPozycje(wartosc, k);
}

void Lista::usunPierwszy() {

    //przypisz drugi element jako aktualny
    aktualnyElement = pierwszyElement->nastepny;

    //Usun pierwszy element
    delete pierwszyElement;

    //Sprawdz, czy w liscie sa jeszcze jakies elementy
    //Jezeli tak, ustaw aktualny element jako pierwszy
    //Jezeli nie, wyzeruj elementy listy
    if (rozmiar > 1) {
        aktualnyElement->poprzedni = NULL;
        pierwszyElement = aktualnyElement;
    } else {
        aktualnyElement = NULL;
        pierwszyElement = NULL;
        ostatniElement = NULL;
    }

    //Zmniejsz rozmiar listy
    rozmiar--;
}

void Lista::usunOstatni() {

    //Przypisz przedostani element jako aktualny
    aktualnyElement = ostatniElement->poprzedni;
    //Usun ostatni element
    delete ostatniElement;

    //Sprawdz, czy w liscie sa jeszcze jakies elementy
    //Jezeli tak, ustaw aktualny element jako ostatni
    //Jezeli nie, wyzeruj elementy listy
    if (rozmiar > 1) {
        aktualnyElement->nastepny = NULL;
        ostatniElement = aktualnyElement;
    } else {
        aktualnyElement = NULL;
        pierwszyElement = NULL;
        ostatniElement = NULL;
    }

    //Zmniejsz rozmiar listy
    rozmiar--;

}

void Lista::Usun(int pozycja) {

//Sprawdz czy w liscie istnieje pozycja podana przez uzytkownika
    if (pozycja < 0 || pozycja > rozmiar) {
        cout << "W liscie nie istnieje pozycja [" << pozycja << "]" << endl;
        return;
    }
                                    //Sprawdz czy wybrana pozycja jest pierwsza
    if (pozycja == 0) {
        usunPierwszy();
        return;
    }
                                    //Sprawdz czy wybrana pozycja jest ostatnia
    if (pozycja == rozmiar - 1) {
        usunOstatni();
        return;
    }
                                    //Sprawdz w której polowie listy znajduje sie wybrany element
    if (pozycja < rozmiar / 2)
    {
                                    //Przypisz za aktualny element pierwszy
        aktualnyElement = pierwszyElement;

                                    //Przesun wszyskie elementy o jeden dalej
        for (int i = 1; i < pozycja - 1; ++i) {
            aktualnyElement = aktualnyElement->nastepny;
        }

    } else {
                                        //Przypisz za aktualny element ostatni
        aktualnyElement = ostatniElement;

                                        //Przesun wszystkie elementy o jedna pozycje wstecz
        for (int i = 0; i < rozmiar - pozycja - 1; ++i) {
            aktualnyElement = aktualnyElement->poprzedni;
        }

    }
                                                                //Stwórz nowy element listy z podanymi parametrami
    ElementListy *nowyElementListy = aktualnyElement->nastepny;
                                                                //przypisz nowy element w odpowiednim miejscu tablicy
    aktualnyElement->nastepny = nowyElementListy->nastepny;
    aktualnyElement->nastepny->poprzedni = nowyElementListy;

    delete[]nowyElementListy;

    //Zmniejsz rozmiar listy
    rozmiar--;

}

bool Lista::Wyszukaj(int wartosc) {

    //Jezeli lista jest pusta, zwróc false z automatu
    if (rozmiar == 0) {
        return false;

    }

    //Przypisa pierwszy element jako aktualny
    aktualnyElement = pierwszyElement;

    //Przeszukaj liste pod katem wartosci
    for (int i = 0; i < rozmiar; i++) {
        if (aktualnyElement->wartosc == wartosc) {
            cout << "Szukana wartosc zajmuje w liscie pozycje [" << i << "]" << endl;
            return true;
        }

        aktualnyElement = aktualnyElement->nastepny;
    }

    //Jezeli wartosc nie wystapila w zadnej iteracji listy zwróc false
    cout << "Szukana wartosc nie wystepuje w liscie" << endl;
    return false;
}

void Lista::Wypisz() {
    //Ustaw jako akutualny element pierwszy element listy
    aktualnyElement = pierwszyElement;

    for (int i = 0; i < rozmiar; i++)
    {
        cout << "[" << i << "] " << aktualnyElement->wartosc << endl;
        //Przypisz kolejny element listy jako aktualny
        aktualnyElement = aktualnyElement->nastepny;
    }
}
