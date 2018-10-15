#ifndef mazzo_carte_h
#define mazzo_carte_h
#include <string>
#include <iostream>
#include "carta.h"
using namespace std;

#define  NUMCARTE 40

// il mazzo viene implementato come una classe :un array di cartE E I vari metodi

class mazzo{

private:
	carta mazzo_carte[NUMCARTE];
	 int  num_cartacorrente;
	
public:
	mazzo();  // COSTRUTTORE
	void crea_mazzo();
	void mischia_mazzo();
	void scambia_carta(int i, int J);
	carta estrai_in_cima(); // estrae la carta dalla prima posizione poi la mette all'ultimo
				//posto facendo slittare tutti i valori di un posto in avanti
	string msg_carte(int num);
	
	//void stampa_mazzo();   // serve  per i test sulla classe mazzo
	//carta estrai_carta(int i);
	};

#include "mazzo_carte.cpp"
#endif /* mazzo_carte_h */









