#ifndef CARTA_H
#define CARTA_H
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <cstring>
using namespace std;

#define  NUMCARTE 40

class carta{
   protected:
		int valore;   // i valori  sono cmpresi tra 0 e 5  .....i valori possibili sono 0,1,2,3,4,5
		string msg; // messaggio che indica l'azione da fare  
	public:
		carta(){};	
		// SET
		void set_valore();
		void set_message(string m);
		//GET
		int getvalore();	// restituisce il valore della carta
		string getmsg();  // restituisce il messaggio associato alla carta
         //TEST
		void stampa_carta(); //stampa il messaggio della carta 

};
#include "carta.cpp"
#endif 
