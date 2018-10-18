#ifndef MAZZO_CARTE_H
#define MAZZO_CARTE_H
#include <cstring>
#include <iostream>
#include "carta.h"
#define NUM_RISP 4	// numero possibili risposte per ogni domanda
#define NUM_TOT_DOM 10	// numero totale domande  20  per test  3
#include "effetti.h"
using namespace std;



// il mazzo viene implementato come una classe :un array di cartE E I vari metodi

/*
struct domanda{
	    string doman;
	    string risposta[NUM_RISP];
	    char risp_esatta;
	  	
	};

*/

class mazzo{
    protected: 
        carta carte[NUMCARTE];
	    int  num_cartacorrente;
	   

public:
	carta temp;
	//domanda d;
	mazzo();  // COSTRUTTORE
	void crea_mazzo();
	void mischia_mazzo();
	void scambia_carta(int i, int J);
	carta estrai_in_cima(); // estrae la carta dalla prima posizione poi la mette all'ultimo
							//posto facendo slittare tutti i valori di un posto in avanti
	void inserisci_in_fondo(); // NON IMPLEMENTATA DA TOGLIERE
	string msg_carte(int num);
// servono  per i test sulla classe mazzo	
	void stampa_mazzo();   
	carta estrai_carta(int i);
//	bool gestione_domanda(domanda d);
	};

#include "mazzo_carte.cpp"
#endif /* mazzo_carte_h */

