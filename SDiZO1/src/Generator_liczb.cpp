#include "Generator_liczb.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Generator_liczb::Generator_liczb()
{
    ilosc = 0;
    //ctor
}

Generator_liczb::~Generator_liczb()
{
    //dtor
}

void Generator_liczb::Generator()
{
    fstream plik;
    srand(time(NULL));
    plik.open("liczby.txt", ios::in | ios::out);
    if(plik.good() == true)
    {
        plik<<ilosc<<endl;
        for(int i = 0; i < ilosc; i++)
        {
            plik<<rand()<<endl;
        }
        plik.close();
    }
}
