#ifndef GENERATOR_LICZB_H
#define GENERATOR_LICZB_H


//Klasa ma za zadanie stworzyæ plik tekstowy
//wygenerowac liczby typu int o okreslonej ilosci
//w pierwszej linii pliku tekstowego ma sie zanlezc ilosc liczb
//nastepne liczby sa w nowych liniach

class Generator_liczb
{
    public:
        int ilosc;          //okresla ilosc liczb do losowania

        Generator_liczb();
        virtual ~Generator_liczb();

        void Generator();

    protected:

    private:
};

#endif // GENERATOR_LICZB_H
