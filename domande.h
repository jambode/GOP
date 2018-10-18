#ifndef domande_h
#define domande_h
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#define NUM_RISP 4	// numero possibili risposte per ogni domanda
#define NUM_TOT_DOM 10	// numero totale domande  20  per test  3
#include "effetti.h"
#include "carta.h"
using namespace std;

	struct domanda{
	    string doman;
	    string risposta[NUM_RISP];
	    char risp_esatta;
	  	
	};
  bool gestione_domanda(domanda d);
#include "domande.cpp"
#endif

