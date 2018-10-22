#ifndef _INIZIALIZZA_GIOCO_H
#define _INIZIALIZZA_GIOCO_H
#include <iostream>
#include <cstring>
#include <ctime>
#include"player.h"
#include "effetti.h"
#include "dado.h"
#include "mazzo_carte.h"
using namespace std;



struct casella{
    int val;
    casella *next;
    casella *prec;
};
typedef casella* ptr_casella;



class inizializza_gioco{
    ptr_casella head, p, n;
    effetti e;
    player *gioc[100];
    mazzo m;
public: 
	inizializza_gioco();
	int i;          
	int num_cas;
	char x;
	int num_caselle;
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
    int decidi_numero_giocatori();   //permette di decidere il numero di giocatori all'inzio del gioco
	int return_num_giocatori();		//ritorna il numero di giocatori
    int quasi_arrivato(int i, int num_estr);	//funzione che permette di tornare indietro se si va oltre il numero di arrivo
    void inizializza_player(); 		//inizializza i giocatori con il proprio nome
    void stampa_giocatori();		
    int set_turno();				//contatore per i turni
	int return_turn();
    void fai_turno(int num);
    //FUNZIONE PER GLI EFFETTI DELLE CARTE
    int effetti_carta(int valore);
 

};
#include "inizializza_gioco.cpp"
#endif /* inizializza_gioco_h */
