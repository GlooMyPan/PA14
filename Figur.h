//
// Created by Xuantong Pan on 2020/11/13.
//

#ifndef PA14_FIGUR_H
#define PA14_FIGUR_H

#include "Feld.h"

class Figur
{

/*** private Attribute ***/
    bool _istFern;
    char _symbol;

protected:
/*** Konstruktoren ***/
    Figur(){}

    Figur(bool farbe, bool istFern, char symbol)
            : _farbe(farbe),
              _istFern(istFern),
              _symbol(symbol){}

public:

/*** public Attribute ***/
    bool _farbe;

/*** public Konstanten ***/
    static bool const _NAHFIGUR = false;
    static bool const _FERNFIGUR = true;
    static bool const WEISS = true;
    static bool const SCHWARZ = false;

/*** get-Methode ***/
    bool farbe() const
    {
        return _farbe;
    }

    bool istFernfigur() const
    {
        return _istFern;
    }

    virtual bool kannZiehen(Feld &von, Feld &nach) const = 0;

    friend
    ostream& operator << (ostream& ostr, Figur const* fig)
    {
        if (fig->_symbol)
            return ostr << fig->_symbol;
        else
            return ostr << ' ';
    }

};


#endif //PA14_FIGUR_H
