#ifndef KOPIEC_H
#define KOPIEC_H
#include <iostream>
#include <conio.h>

class Kopiec
{
    public:
        int rozmiar;            //rozmiar kopca - liczba elementów
        int *tablica;           //wskaznik na tablice

        Kopiec();
        ~Kopiec();

        bool ZbudujZPliku();                                              //Metoda ładuje dane z pliku do struktury
        void WyswietlKopiec(std::string sp, std::string sn, int x);   //Metoda wyswietla kopiec
        void DodajElement(int x);                                         //Metoda dodaje element do struktury
        void UsunElement(int x);                                          //Metoda usuwa element z kopca
        bool Szukaj(int x);                                               //Metoda szuka elementu po wartosci
        void Popraw();                                                  //Metoda do porzadkowania kopca

    protected:

    private:
};

#endif // KOPIEC_H
