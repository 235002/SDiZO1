#include "Element.h"
#include <iostream>
Element::Element(int wartosc)
{
    wartosc=0;
    nastepny=NULL;
    //ctor
}

Element::~Element()
{
    //dtor
}

int Element::ZwrocWartosc()
{
    return wartosc;
}

Element Element::ZwrocNastepny()
{
    return *nastepny;
}
