//
// Created by Xuantong Pan on 2020/11/13.
//

#ifndef PA14_LAEUFER_H
#define PA14_LAEUFER_H

#include "Figur.h"

class Laeufer
        : public Figur
{
public:
/*** Konstruktoren ***/
    Laeufer(bool farbe)
            :Figur(farbe, Figur::_FERNFIGUR, farbe == Figur::WEISS ? 'L' : 'l'){}

    bool kannZiehen(Feld &von, Feld &nach) const
    {
        if (von == nach || abs(nach.zeile() - von.zeile()) != abs(nach.spalte() - von.spalte()))
            return false;
        else
            return true;
    }

};

#endif //PA14_LAEUFER_H
