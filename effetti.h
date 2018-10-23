#ifndef _EFFETTI_H
#define _EFFETTI_H
#include<iostream>
#include "dado.h"
#include "player.h"
using namespace std;

class effetti{

	player *p[100];
	
	public:
		
		dado d;
	    int num_estratto; 
		effetti(){
		};
		int tira_di_nuovo();
		int vai_avanti(int pos);
	    int fortuna(int num);
	};

#include "effetti.cpp"
#endif /*EFFETTI_H*/
