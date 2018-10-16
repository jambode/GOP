#ifndef _INIZIALIZZA_PLAYER_H
#define _INIZIALIZZA_PLAYER_H
#include <iostream>
#include <cstring>
#include <ctime>
#include "dado.cpp"
#include "player.cpp"
#include "effetti.cpp"
#include "tabellone.cpp"
using namespace std;

class inizializza_giocatori{

public:
    player *p[100];
    int posizione; 
	char N[50];
    int num_giocatori ;
    effetti e;
    int turno = 0;
    tabellone tab;
    int decidi_numero_giocatori();
	int return_num_giocatori();
    
    
    void inizializza_player();
    void stampa_giocatori();
  
    int set_turno();
	int return_turn();
	
    void turni(int num);



/*    
    void turns(){
    	int num_caselle = tab.return_caselle();
    	cout<<"caselle "<<num_caselle;
    	for(int i=0; i<num_giocatori; i++){
    	while(p[i]->pos < num_caselle)
    	posizione_corrente(num_giocatori);
    
    		
}
}
 */  

};

#endif /* inizializza_player_h */
