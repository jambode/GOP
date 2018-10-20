#ifndef _INIZIALIZZA_PLAYER_H
#define _INIZIALIZZA_PLAYER_H
#include <iostream>
#include <cstring>
#include <ctime>
#include"player.h"
#include "effetti.cpp"
#include "dado.cpp"
#include "mazzo_carte.h"
using namespace std;



struct casella{
    int val;
    casella *next;
    casella *prec;
};
typedef casella* ptr_casella;



class inizializza_giocatori{
    ptr_casella head, p, n;
    effetti e;
    player *gioc[100];
    mazzo m;
public: 

	int i;          // numero caselle random
	int num_cas;
	char x;
	//FUNZIONI PER IL TABELLONE
    void genera_tabellone(int num_cas);
    bool stampa_tabellone();
    int return_caselle();
    bool termina;
    //FUNZIONI PER I GIOCATORI
    int posizione; 
	char N[50];
    int num_giocatori ;
    int turno ;
    int decidi_numero_giocatori();
	int return_num_giocatori();
    
    
    void inizializza_player();
    void stampa_giocatori();
  
    int set_turno();
	int return_turn();
	
    void posizione_corrente(int num);
    //FUNZIONE PER GLI EFFETTI DELLE CARTE
    int effetti_carta(int valore);


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
#include "inizializza_player.cpp"
#endif /* inizializza_player_h */
