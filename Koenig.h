//
// Created by Xuantong Pan on 2020/11/13.
//

#ifndef PA14_KOENIG_H
#define PA14_KOENIG_H

#include "Figur.h"

class Koenig
        : public Figur
{
public:
/*** Konstruktoren ***/
    Koenig(bool farbe)
    :Figur(farbe, Figur::_NAHFIGUR, farbe == Figur::WEISS ? 'K' : 'k'){}

    bool kannZiehen(Feld &von, Feld &nach) const
    {
        if (von == nach || abs(nach.spalte() - von.spalte()) > 1 || abs(nach.zeile() - von.zeile() > 1))
            return false;
        else
            return true;
    }

};

#endif //PA14_KOENIG_H
