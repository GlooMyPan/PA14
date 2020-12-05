//
// Created by Xuantong Pan on 2020/11/13.
//

#ifndef PA14_SPRINGER_H
#define PA14_SPRINGER_H

#include "Figur.h"

class Springer
        : public Figur
{
public:
/*** Konstruktoren ***/
    Springer(bool farbe)
            : Figur(farbe, Figur::_NAHFIGUR, farbe == Figur::WEISS ? 'S' : 's') {}

    bool kannZiehen(Feld &von, Feld &nach) const
    {
        if (von != nach && abs(nach.spalte() - von.spalte()) == 2 && abs(nach.zeile() - von.zeile()) == 1
            || abs(nach.spalte() - von.spalte()) == 1 && abs(nach.zeile() - von.zeile()) == 2)
            return true;
        else
            return false;
    }

};


#endif //PA14_SPRINGER_H
