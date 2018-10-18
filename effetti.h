#ifndef _EFFETTI_H
#define _EFFETTI_H
#include<iostream>
#include "dado.h"
#include "mazzo_carte.h"
#include "player.h"
#include "carta.h"
using namespace std;

class effetti{

	player *p[100];
	mazzo m;
    carta card;

	public:
		//mazzo	
		dado d;
	    int num_estratto; 
		effetti(){
		};
		int tira_di_nuovo();
		int vai_avanti(int pos);
		void salta_turno();   //inserire un contatore di turni??  forse non lo implemento
		void pesca_carta();
	    int fortuna(int num);
	};


#endif /*EFFETTI_H*/

