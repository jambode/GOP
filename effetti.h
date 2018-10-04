#ifndef EFFETTI_H
#define EFFETTI_H
#include<iostream>
#include "dado.h"
#include "mazzo_carte.h"
#include "player.h"
using namespace std;

class effetti{
	dado d;
	player *p[100];
	public:
		effetti(){
		};
		int tira_di_nuovo();
		int vai_avanti(int pos);
		void salta_turno();   //inserire un contatore di turni??
		void pesca_carta();
	};
		

#endif 
