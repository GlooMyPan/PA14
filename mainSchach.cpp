#include <iostream>
#include <string>
#include "Schachbrett.h"

using namespace std ;


int main ()
{
    // Konstruiere das Brett mit der Figurenaufstellung
    Schachbrett brett ;
    cout << brett << endl ;

    // Hauptschleife: die Spieler ziehen abwechselnd
    while ( true )
    {
        // fordere aktuellen Spieler zum Zug auf
        string zug ;
        cout << "naechster Zug (" << brett.spieler() << "): " ;
        cin >> zug ;
        cout << zug << endl ;

        // abbrechen?
        if ( zug == "0" )
            break ;

        // f�hre Zug ggf. aus
        if ( brett.ziehe( zug ) )
        {
            cout << endl ;
            cout << brett << endl ;
        }
        else
        {
            cout << "Dieser Zug ist nicht zulaessig!" << endl ;
            cout << endl ;
        }
    }  // while ( true )

    return 0 ;

}  // main()