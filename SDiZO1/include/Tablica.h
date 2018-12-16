#ifndef TABLICA_H
#define TABLICA_H


class Tablica
{
    public:
        int rozmiar;
        int *tablica;

        Tablica();
        ~Tablica();

        void StworzTablice(int k);
        bool ZbudujZPliku();

        void UsunElementPoczatek();
        void UsunElementKoniec();
        void UsunElementNaPozycji(int k);
        void UsunElementLosowo();

        void WstawElementPoczatkowy(int x);
        void WstawElementKoncowy(int x);
        void WstawElementNaPozycji(int x, int k);
        void WstawElementLosowo(int x);

        void WypiszTablice();
        bool Wyszukaj(int x);
};

#endif // TABLICA_H
