//
// Created by Xuantong Pan on 2020/11/13.
//

#ifndef PA14_TURM_H
#define PA14_TURM_H

#include "Figur.h"

class Turm
        : public Figur
{
public:

/*** Konstruktoren ***/
    Turm(bool farbe)
            : Figur(farbe, Figur::_FERNFIGUR, farbe == Figur::WEISS ? 'T' : 't') {}

    bool kannZiehen(Feld &von, Feld &nach) const
    {
        if (von.spalte() != nach.spalte() && von.zeile() == nach.zeile() ||
            von.spalte() == nach.spalte() && von.zeile() != nach.zeile())
            return true;
        else
            return false;
    }

};

#endif //PA14_TURM_H
