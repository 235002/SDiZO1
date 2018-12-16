#ifndef ELEMENT_H
#define ELEMENT_H


class Element
{
    public:
        Element(int wartosc);
        virtual ~Element();

        int ZwrocWartosc();
        Element ZwrocNastepny();
        void UstawNastepny(int wartosc);
        void UsunNastepny();

    protected:

    private:
        int wartosc;
        Element *nastepny;
};

#endif // ELEMENT_H
