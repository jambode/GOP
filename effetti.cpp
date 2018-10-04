#ifndef EFFETTI_CPP
#define EFFETTI_CPP
#include<iostream>
#include "dado.h"
#include "effetti.h"
#include "player.h"
#include "inizializza_player.h"
using namespace std;



int effetti::tira_di_nuovo(){
		int dado = d.lancia_dado();
		cout<<"lancio dado seconda volta.."<<dado<<endl;
		return dado;
}

int effetti::vai_avanti(int pos){
	int dice = d.lancia_dado();
	cout<<"CASELLA FORTUNATA!! "<<"avanza di "<<dice<<endl;
	pos =	pos+dice;
	return pos;
}
/*
void effetti::salta_turno(){
	
}

void effetti::pesca_carta(){
	
}*/

#endif 
