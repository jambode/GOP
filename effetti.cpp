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
	cout<<"CASELLA FORTUNATA!! "<<"avanza di "<<dice<<endl;       //se si capita su una casella del genere si va avanti di un numero                                                             
	pos =	pos+dice;                                             //casuale (decidere se vogliamo farlo con il lancio del dado o usando
	return pos;                                                   //un rand su numeri da 1..10)
}
/*                                    ANCORA DA IMPLEMENTARE
void effetti::salta_turno(){
	
}

void effetti::pesca_carta(){
	
}*/

#endif 
