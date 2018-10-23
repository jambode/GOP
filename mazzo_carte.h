#ifndef MAZZO_CARTE_H
#define MAZZO_CARTE_H
#include <cstring>
#include <iostream>
#include<ctime> // per time()
#include<cstdlib>
#define NUM_RISP 4	// numero possibili risposte per ogni domanda
#define NUM_TOT_DOM 10	// numero totale domande  20  per test  3
#include "carta.h"
#include "effetti.h"
#include "player.h"
using namespace std;



// il mazzo viene implementato come una classe :un array di carte e i vari metodi


struct domanda{
	    string doman;
	    string risposta[NUM_RISP];
	    char risp_esatta;
	  	
	};



class mazzo{
    protected: 
        carta carte[NUMCARTE];
	   

	public:
		carta temp;
		player *p;
		effetti e;
		
		mazzo();  // COSTRUTTORE
		void crea_mazzo();
		void mischia_mazzo();
		void scambia_carta(int i, int J);
		carta estrai_in_cima(); // estrae la carta dalla prima posizione poi la mette all'ultimo
				        //posto facendo slittare tutti i valori di un posto in avanti
								
		
		string msg_carte(int num); 	
		void stampa_mazzo();   
		carta estrai_carta(int i);
		bool gestione_domanda();
		int pesca_carta();
		};

#include "mazzo_carte.cpp"
#endif /* mazzo_carte_h */

