#include <iostream>
#include<ctime>
#include "inizializza_player.h"
#include "tabellone.h"
#include "turno.h"
using namespace std;

int main() {
    inizializza_giocatori init;
    init.decidi_numero_giocatori();
    init.inizializza_player();
    init.stampa_giocatori();
     int num_player = init.return_num_giocatori();
   

    
    tabellone t;
    t.genera_tabellone();
    t.stampa_tabellone();
    cout << endl;
    
    srand(time(0));       //permette di generare vari numeri, in un loop non funziona.
    
    // turno turn;
   // turn.inizio_turno(num_player);
    init.turni(num_player);
    return 0;
}
