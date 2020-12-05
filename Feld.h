#ifndef FELD_H
#define FELD_H

#include <iostream>
#include <string>
#include <cmath>        // f黵 abs()

using namespace std ;

/**
 * Klasse f黵 Schachbrettfelder
 */

class Feld
{
    // Spaltennummer auf dem Schachbrett
    int _spalte ;

    // Zeilennummer auf dem Schachbrett
    int _zeile ;

public:
/***  Konstruktoren  ***/

    // Standardkonstruktor, tut nichts
    Feld ()
    { }

    // Umwandlungskonstruktor von Feldnotation, z.B. "a1" -> (0,0)
    Feld ( char const zug[] )
            : Feld( string( zug ) )
    { }

    // Umwandlungskonstruktor von Feldnotation, z.B. "a1" -> (0,0)
    Feld ( string const& str )
    {
        if ( str.size() <= 1 )
        {
            cerr << "Feld::Feld( string ): habe nicht genug Daten!" << endl ;
            return ;
        }
        _spalte = str[ 0 ] - 'a' ;
        _zeile  = str[ 1 ] - '1' ;
    }

    // Initialisierungskonstruktor von Koordinaten, z.B. (1,4)
    Feld ( int spalte, int zeile )
            : _spalte( spalte ),
              _zeile ( zeile  )
    { }

/***  get-Methoden  ***/

    // gib Spalte des Feldes aus
    int spalte () const
    {
        return _spalte ;
    }

    // gib Zeile des Feldes aus
    int zeile () const
    {
        return _zeile ;
    }

/***  set-Methoden  ***/

    // weise Objekt von Koordinaten zu
    void setze ( int spalte, int zeile )
    {
        _spalte = spalte ;
        _zeile  = zeile ;
    }

/***  Interaktionsmethoden  ***/

    // sind Objekt und feld gleich?
    bool operator == ( Feld const& feld ) const
    {
        return     _spalte == feld._spalte
                   &&  _zeile  == feld._zeile ;
    }

    // sind Objekt und feld verschieden?
    bool operator != ( Feld const& feld ) const
    {
        return ! ( *this == feld ) ;
    }

/***  Rechenmethoden  ***/

    // addiere Objekt und feld zu neuem Objekt
    Feld operator + ( Feld const& feld ) const
    {
        return Feld( _spalte + feld._spalte, _zeile + feld._zeile ) ;
    }

    // subtrahiere Objekt und feld zu neuem Objekt
    Feld operator - ( Feld const& feld ) const
    {
        return Feld( _spalte - feld._spalte, _zeile - feld._zeile ) ;
    }

    // addiere feld zum Objekt hinzu
    void operator += ( Feld const& feld )
    {
        _spalte += feld._spalte ;
        _zeile  += feld._zeile ;
    }

} ;  // class Feld


/***  globale Funktionen  ***/

// Ausgabe auf ostream (nur evtl. f黵 Debugging n鰐ig)
inline
ostream& operator << ( ostream& ostr, Feld const& feld )
{
    return ostr << char( feld.spalte() + 'a' )
                << char( feld.zeile()  + '1' ) ;
}

// Betragsfunktion
inline
Feld abs ( Feld const& feld )
{
    return Feld( abs( feld.spalte() ), abs( feld.zeile() ) ) ;
}


#endif  // FELD_H