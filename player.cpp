#include<iostream>
#include "player.h"
using namespace std;



player::player(int p, char n[]){
	pos = p;
	strcpy(name, n);
}


void player::presenta_giocatore(){
	cout<<name;
}

int player::ritorna_pos(){
	return pos;
}

int player::indietro_uno(){
	if(pos>0) pos-= 1;
	else cout<<"impossibile andare indietro."<<endl;
	return pos;
}

int player::avanza_uno(){
	pos += 1;
    return pos;
}

int player::vai_a_casella(int i){
	pos = i;
    return pos;
}


int player::vai_avanti_n_caselle(int i){
	return pos + i;
}

int player::vuota(){
    cout << "casella vouta." << endl;
    return pos;	
}


int player::somma_pos(int n){
	pos = n + pos;
    return pos;
}


int player::indietro_n_caselle(int i){
	return pos-i;
}
