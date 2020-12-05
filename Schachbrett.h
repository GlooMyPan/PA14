//
// Created by Xuantong Pan on 2020/11/14.
//

#ifndef PA14_SCHACHBRETT_H
#define PA14_SCHACHBRETT_H

#include "Springer.h"
#include "Koenig.h"
#include "Laeufer.h"
#include "Turm.h"

class Schachbrett
{

/*** private Attribute ***/

    static size_t const _DIM = 6;
    bool _spieler;
    Figur const* _brett[_DIM][_DIM];

/*** set-Methode ***/
    Figur const* _figurAuf(Feld const& feld)
    {
        return _brett[feld.zeile()][feld.spalte()];
    }

    void move(Feld const & von, Feld const & nach)
    {
        int v0 = von.zeile();
        int v1 = von.spalte();
        int n0 = nach.zeile();
        int n1 = nach.spalte() ;

        _brett[n0][n1] = _brett[v0][v1];
        _brett[v0][v1] = nullptr;

        _spieler = !_spieler;
    }

    bool _figurAufZugspur(Feld const & von, Feld const & nach) const
    {
        int v0 = von.zeile();
        int v1 = von.spalte();
        int n0 = nach.zeile();
        int n1 = nach.spalte() ;

        int minZ = min(v0, n0);
        int maxZ = max(v0, n0);
        int minS = min(v1, n1);
        int maxS = max(v1, n1);
        if (v0 == n0)
        { // Turm
            for (int i = minS + 1; i < maxS; ++i)
                if (_brett[v0][i])
                    return true;
        }
        else if (v1 == n1)
        { // Turm
            for (int i = minZ + 1; i < maxZ; ++i)
                if (_brett[i][v1])
                    return true;
        }
        else
        {
            for (int i = minZ + 1, j = minS + 1; i < maxZ, j < maxS; ++i, ++j) // Lauefer
                if (_brett[i][j])
                    return true;
        }
        return false;
    }
public:
/*** Konstruktoren ***/

    Schachbrett()
    {
        _spieler = Figur::WEISS;
        for (int i = 0; i < _DIM; ++i)
            for (int j = 0; j < _DIM; ++j)
                _brett[i][j] = nullptr;
        _brett[0][2] = new Springer(Figur::WEISS);
        _brett[2][0] = new Springer(Figur::WEISS);
        _brett[0][1] = new Turm(Figur::WEISS);
        _brett[1][0] = new Turm(Figur::WEISS);
        _brett[0][0] = new Laeufer(Figur::WEISS);
        _brett[1][1] = new Koenig(Figur::WEISS);

        _brett[5][3] = new Springer(Figur::SCHWARZ);
        _brett[3][5] = new Springer(Figur::SCHWARZ);
        _brett[5][4] = new Turm(Figur::SCHWARZ);
        _brett[4][5] = new Turm(Figur::SCHWARZ);
        _brett[5][5] = new Laeufer(Figur::SCHWARZ);
        _brett[4][4] = new Koenig(Figur::SCHWARZ);

    }

/*** get-Methode ***/

    string spieler() const
    {
        return _spieler == Figur::WEISS ? "WEISS" : "SCHWARZ";
    }

/*** set-Methode ***/

    bool ziehe(string const& zug)
    {
        // das zug-Argument enth¨alt zwei Schachfelder, die beide auf dem Schachbrett liegen
        if (zug.size() == 4 && zug[0] >= 'a' && zug[0] <= 'f' && zug[2] >= 'a' && zug[2] <= 'f'
        &&  zug[1] >= '1' && zug[1] <= '6' && zug[3] >= '1' && zug[3] <= '6')
        {
            Feld von = zug.substr(0, 2);
            Feld nach = zug.substr(2, 2);
            // auf dem Startfeld steht eine Figur des ziehenden Spielers
            if (_figurAuf(von) && _figurAuf(von)->_farbe == _spieler)
            {
                // auf dem Endfeld steht keine Figur desselben Spielers
                if (!_figurAuf(nach) || _figurAuf(nach)->_farbe != _spieler)
                {
                    // die gefuhrte Figur kann diese Zugbewegung ausfuehren
                    if (_figurAuf(von)->kannZiehen(von, nach))
                    {
                        // bei Fernfiguren steht keine andere Figur auf der Zugspur
                        if (_figurAuf(von)->istFernfigur())
                        {
                            if (!_figurAufZugspur(von, nach))
                            {
                                move(von, nach);
                                return true;
                            }
                        }
                        else
                        {
                            move(von, nach);
                            return true;
                        }
                    }
                }
            }
        }

        return false;

    }

    friend
    ostream& operator << (ostream& ostr, Schachbrett const& brett)
    {

        ostr << "+-------------+" << endl;
        for (int i = _DIM - 1; ~i; --i)
        {
            ostr << "| ";
            for (int j = 0; j < _DIM; ++j)
            {
                if (brett._brett[i][j])
                    ostr << brett._brett[i][j] << ' ';
                else
                    ostr << "  ";
            }
            ostr << "| " << i+1 << endl;
        }

        ostr << "+-------------+" << endl;
        return ostr << "  a b c d e f" << endl;
    }

    ~Schachbrett()
    {

        for (int i = 0; i < _DIM; ++i)
            for (int j = 0; j < _DIM; ++j) {
                delete _brett[i][j];
                _brett[i][j] = nullptr;
            }
    }
};


#endif //PA14_SCHACHBRETT_H
