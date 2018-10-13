#include <iostream>
#include <cstring>
#include <ctime>
#include "carta.h"

using namespace std;


void carta::set_valore(){
	valore = rand()%40+1;        //permette di generare 40 carte random
}

void carta::set_message(string m){
	msg = m;
	}


int carta::getvalore(){
	return valore;
}
/*
char carta::getmsg(){
	return msg;
}*/

// SERVE PER I TEST stampa il valore di una carta 
	void carta::stampa_carta (){
		cout<< " num carta =  "   <<valore << "    "<<"messaggio =  "<<msg <<"\n";
		
	}
