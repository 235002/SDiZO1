#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"
#include "Generator_liczb.h"
using namespace std;

LARGE_INTEGER startTimer()
{
LARGE_INTEGER start;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&start);
 SetThreadAffinityMask(GetCurrentThread(), oldmask);
 return start;
}
LARGE_INTEGER endTimer()
{
LARGE_INTEGER stop;
DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
QueryPerformanceCounter(&stop);
SetThreadAffinityMask(GetCurrentThread(), oldmask);
return stop;
}

void spisTablica()
{
    Tablica tab;
    int wybor;
    bool koniec = false;
    int wartosc;
    int pozycja;

    LARGE_INTEGER performanceCountStart,performanceCountEnd;
    double tm;
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);

    while(!koniec)
    {
        cout<<"Tablica"<<endl;
        cout<<"1. Zbuduj tablice z pliku" <<endl;
        cout<<"2. Wypisz tablice" <<endl;
        cout<<"3. Wstaw element na poczatek" <<endl;
        cout<<"4. Wstaw element na koniec" <<endl;
        cout<<"5. Wstaw element na wskazanej pozycji" <<endl;
        cout<<"6. Wstaw element na losowej pozycji" <<endl;
        cout<<"7. Usun element na poczatku" <<endl;
        cout<<"8. Usun element na koncu" <<endl;
        cout<<"9. Usun element na pozycji"<<endl;
        cout<<"10. Usun element na losowej pozycji"<<endl;
        cout<<"11. Wyszukaj element w tablicy"<<endl;
        cout<<"12. Powrot"<<endl;


        cout<<"Wybor: ";
        cin>>wybor;
        switch(wybor)
        {
        case 1:
            system("CLS");
            performanceCountStart = startTimer();
            tab.ZbudujZPliku();
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;

        case 2:
            system("CLS");

            performanceCountStart = startTimer();
            tab.WypiszTablice();
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;

        case 3:
            system("CLS");
            cout<<"Podaj wartosc: ";
            cin>>wartosc;

            performanceCountStart = startTimer();
            tab.WstawElementPoczatkowy(wartosc);
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;

        case 4:
            system("CLS");
            cout<<"Podaj wartosc: ";
            cin>>wartosc;

            performanceCountStart = startTimer();
            tab.WstawElementKoncowy(wartosc);
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;;
            break;

        case 5:
            system("CLS");
            cout<<"Podaj wartosc: ";
            cin>>wartosc;
            cout<<"Podaj pozycje: ";
            cin>>pozycja;

            performanceCountStart = startTimer();
            tab.WstawElementNaPozycji(wartosc, pozycja);
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;

        case 6:
            system("CLS");
            cout<<"Podaj wartosc: ";
            cin>>wartosc;
            cout<<"Wstawiam "<<wartosc<<" w losowe miejsce"<<endl;

            performanceCountStart = startTimer();
            tab.WstawElementLosowo(wartosc);
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;            break;

        case 7:
            system("CLS");
            cout<<"Usuwam element z poczatku tablicy ";

            performanceCountStart = startTimer();
            tab.UsunElementPoczatek();
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;

        case 8:
            system("CLS");
            cout<<"Usuwam element z konca tablicy ";

            performanceCountStart = startTimer();
            tab.UsunElementKoniec();
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;

        case 9:
            system("CLS");
            cout<<"Podaj pozycje do usuniecia: ";
            cin>>pozycja;
            cout<<endl<<"Usuwam element na pozycji: "<<pozycja<<endl;

            performanceCountStart = startTimer();
            tab.UsunElementNaPozycji(pozycja);
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;

        case 10:
            system("CLS");
            cout<<"Usuwam losowy element";

            performanceCountStart = startTimer();
            tab.UsunElementLosowo();
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;

        case 11:
            system("CLS");
            cout<<"Podaj wartosc do wyszukania: ";
            cin>>wartosc;

            performanceCountStart = startTimer();
            if(tab.Wyszukaj(wartosc)==true)
                cout<<"Podana wartosc znajduje sie w tablicy"<<endl;
            else
                cout<<"Podana wartosc nie znajduje sie w tablicy"<<endl;
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;

        case 12:
            system("CLS");
            koniec = true;
            break;

        default:
            break;
        }
        cout<<endl;
    }
}

void spisLista()
{
    Lista lis;
    int wybor;
    bool koniec = false;

    int wartosc, wartosc2;

    LARGE_INTEGER performanceCountStart,performanceCountEnd;
    double tm;
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);

    while(!koniec)
    {
        cout<<"Lista"<<endl;
        cout<<"1. Wczytaj z pliku"<<endl;
        cout<<"2. Usun element po wartosci"<<endl;
        cout<<"3. Usun element z poczatku listy"<<endl;
        cout<<"4. Usun element z konca listy"<<endl;
        cout<<"5. Dodaj element za inny element"<<endl;
        cout<<"6. Dodaj element na poczatek listy"<<endl;
        cout<<"7. Dodaj element na koniec listy"<<endl;
        cout<<"8. Dodaj element na losowe miejsce listy"<<endl;
        cout<<"9. Znajdz"<<endl;
        cout<<"10. Wyswietl"<<endl;
        cout<<"11. Powrot"<<endl;
        cout<<endl<<"Twoj wybor:";
        cin>>wybor;

        switch(wybor)
        {
        case 1:
            system("CLS");
            lis.wczytajZPliku();
            break;
        case 2:
            system("CLS");
            cout<<"Podaj wartosc do usuniecia: ";
            cin>>wartosc;
            performanceCountStart = startTimer();
            lis.Usun(wartosc);
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;
        case 3:
            system("CLS");
            cout<<"Usuwam element poczatkowy";
            performanceCountStart = startTimer();
            lis.usunPierwszy();
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;
        case 4:
            system("CLS");
            cout<<"Usuwam element koncowy";
            performanceCountStart = startTimer();
            lis.usunOstatni();
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;
        case 5:
            system("CLS");
            cout<<"Podaj wartosc: ";
            cin>>wartosc;
            cout<<"Podaj pozycje: ";
            cin>>wartosc2;
            performanceCountStart = startTimer();
            lis.DodajNaPozycje(wartosc, wartosc2);
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;
        case 6:
            system("CLS");
            cout<<"Podaj wartosc: ";
            cin>>wartosc;
            performanceCountStart = startTimer();
            lis.dodajNaPoczatek(wartosc);
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;
        case 7:
            system("CLS");
            cout<<"Podaj wartosc: ";
            cin>>wartosc;
            performanceCountStart = startTimer();
            lis.dodajNaKoniec(wartosc);
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;
        case 8:
            system("CLS");
            cout<<"Podaj wartosc do wyszukania: ";
            cin>>wartosc;
            performanceCountStart = startTimer();
            lis.dodajElementLosowo(wartosc);
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;
        case 9:
            system("CLS");
            cout<<"Podaj wartosc do wyszukania: ";
            cin>>wartosc;
            performanceCountStart = startTimer();
            lis.Wyszukaj(wartosc);
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;
        case 10:
            system("CLS");
            lis.Wypisz();
            break;
        case 11:
            system("CLS");
            koniec = true;
            break;

        default:
            break;
        }

    }
}

void spisKopiec()
{
    Kopiec kop;
    int wybor;
    bool koniec = false;
    int wartosc;

    LARGE_INTEGER performanceCountStart,performanceCountEnd;
    double tm;
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);

    while(!koniec)
    {
        cout<<"Kopiec"<<endl;
        cout<<"1. Zbuduj kopiec z pliku"<<endl;
        cout<<"2. Wyswietl kopiec"<<endl;
        cout<<"3. Dodaj element"<<endl;
        cout<<"4. Usun element"<<endl;
        cout<<"5. Szukaj element"<<endl;
        cout<<"6. Powrot"<<endl;
        cin>>wybor;

        switch(wybor)
        {
        case 1:
            system("CLS");
            if(kop.ZbudujZPliku())
                cout<<"Poprawnie zaladowano z pliku"<<endl;
            else
                cout<<"Nie udalo sie zbudowac kopca"<<endl;
            break;
        case 2:
            system("CLS");
            cout<<"Kopiec binarny"<<endl<<"Plik - liczby.txt"<<endl<<endl;
            kop.WyswietlKopiec("","",0);
            break;
        case 3:
            system("CLS");
            cout<<"Podaj wartosc: ";
            cin>>wartosc;
            performanceCountStart = startTimer();
            kop.DodajElement(wartosc);
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;
        case 4:
            system("CLS");
            cout<<"Podaj wartosc: ";
            cin>>wartosc;
            performanceCountStart = startTimer();
            kop.UsunElement(wartosc);
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;
            break;
        case 5:
            system("CLS");
            cout<<"Podaj wartosc: ";
            cin>>wartosc;
            performanceCountStart = startTimer();
            if(kop.Szukaj(wartosc))
                cout<<"Szukany element znajduje sie w kopcu"<<endl;
            else
                cout<<"Szukany element nie znajduje sie w kopcu"<<endl;
            performanceCountEnd = endTimer();

            tm = performanceCountEnd.QuadPart - performanceCountStart.QuadPart;
            cout.setf(ios::fixed);
            cout << endl << "Czas:" << setprecision(6) << tm / freq.QuadPart * 1000 <<" [ms]"<<endl;

            break;
        case 6:
            system("CLS");
            koniec = true;
            break;
        default:
            break;
        }


    }

}

void MENU()
{
    int wybor;
    bool koniec = false;

    while(!koniec)
    {
        cout<<"1. Tablica"<<endl;
        cout<<"2. Lista"<<endl;
        cout<<"3. Kopiec binarny"<<endl;

        cout<<"0. Koniec"<<endl;
        cin>>wybor;
    switch(wybor)
    {
    case 1:
        system("CLS");
        spisTablica();
        break;
    case 2:
        system("CLS");
        spisLista();
        break;
    case 3:
        system("CLS");
        spisKopiec();
        break;
    case 4:

        break;
    case 0:
        koniec = true;
        break;
    }

    }
}


int main()
{
    Generator_liczb G1;
    G1.ilosc = 10;
    G1.Generator();

    MENU();

    return 0;
}
