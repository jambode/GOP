#ifndef CARTA_H
#define CARTA_H
#include <iostream>
#include <cstring>

using namespace std;

#define  NUMCARTE 40

class carta{
   protected:
		int valore;   // i valori  sono cmpresi tra 0 e 5  .....i valori possibili sono 0,1,2,3,4,5
		string msg; // frase che indica l'azione da fare  DA VEDERE SE SERVE
	public:
		carta(){};			// costruttore carta
		//carta(int val,string frase);
		// SET
		void set_valore();
		void set_message(string m);
		//GET
		int getvalore();	// restituisce il valore della carta
		char getmsg();  // restituisce il msg associato alla carta
         //TEST
		void stampa_carta(); // SERVE PER I TEST stampa il valore della carta 

};
#include"carta.cpp"
#endif 


