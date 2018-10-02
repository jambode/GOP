#ifndef carta_h
#define carta_h
#include <iostream>
#include <string>

using namespace std;

class carta{
   private:
		int valore;  // i valori  sono cmpresi tra 0 e 5  .....i valori possibili sono 0,1,2,3,4,5
		string msg; // frase che indica l'azione da fare  DA VEDERE SE SERVE
	public:
		carta();			// costruttore carta
		carta(int val,string frase);
		// SET
		void setvalore(int i);
		void setstringa (string s);
		//GET
		int getvalore();	// restituisce il valore della carta
		string getmsg();  // restituisce il msg associato alla carta
         //TEST
		void stampa_carta(); // SERVE PER I TEST stampa il valore della carta 

};

#endif /* mazzo_carte_h */

