#include <iostream>
#include <ctime>
#include <cstdlib>
#include "inizializza_player.h"



using namespace std;

int main(){
    inizializza_giocatori init;
    init.decidi_numero_giocatori();
    init.inizializza_player();
    init.stampa_giocatori();
     int num_player = init.return_num_giocatori();
    // int num_turno = 0;
    // domanda d;
     //d.gestione_domanda();
   

    
/*   tabellone t;
   cout<<t.return_caselle();
//    t.genera_tabellone(40);
  //  t.stampa_tabellone();
    cout << endl;

 */ 
    srand(time(0));       //permette di generare vari numeri, in un loop non funziona.
    
    
/*    mazzo m;
    m.crea_mazzo();
    m.estrai_in_cima();
    m.mischia_mazzo();
    cout<<"MISCHIO MAZZO "<<"\n";
    m.stampa_mazzo();
    cout<<"SCAMBIO CARTEEEE"<<"\n"<<"\n";
    m.scambia_carta(2, 4);
    m.stampa_mazzo();
    cout<<"\n"<<"\n";
    cout<<"estraggo carta 2: ";
    m.estrai_carta(2);
*/	
   
    
    //turno turn;
    //turn.inizio_turno(num_player);
    /*num_turno = init.return_turn();
    while(num_turno<8){
    init.posizione_corrente(num_player);
    num_turno ++;
}*/
    init.posizione_corrente(num_player);
     
   /* domanda d;
    gestione_domanda(d);
  */  
    return 0;
}
