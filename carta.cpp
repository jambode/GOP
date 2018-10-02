#include "carta.h"
#include <iostream>
#include <string>
using namespace std;

carta::carta(){
valore=0;
msg="";}

carta::carta(int val,string frase) {
	valore=val;
	msg=frase;
}
void carta::setvalore(int i){
	valore=i;
}
void carta::setstringa(string s ){
	msg=s;
	}


int carta::getvalore(){
	return(valore);
}
string carta :: getmsg(){
	return msg;
}

// SERVE PER I TEST stampa il valore di una carta 
	void carta::stampa_carta (){
		cout<< " num carta =  "   <<valore << "    "<<"messaggio =  "<<msg <<"\n";
		
	}


