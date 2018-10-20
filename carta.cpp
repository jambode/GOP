#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "carta.h"

using namespace std;


void carta::set_valore(){
	valore = rand()%40+1;
}

void carta::set_message(string m){
 	msg = m;
	}


int carta::getvalore(){
	return valore;
}

string carta::getmsg(){
	return msg;
}

// SERVE PER I TEST stampa il valore di una carta 
	void carta::stampa_carta (){
		cout<<"messaggio =  "<<msg <<"\n";
		
	}
