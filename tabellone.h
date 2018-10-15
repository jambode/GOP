#ifndef tabellone_h
#define tabellone_h
#include <ctime>
#include <cstdlib>
#include "player.h"
#include "effetti.h"

using namespace std;

struct casella{
    int val;
    casella *next;
    casella *prec;
};

typedef casella* ptr_casella;

class tabellone{
    ptr_casella head, p, n;
    effetti e;
    
public: 
    player *gioc[100];
	int i;        
	
    void genera_tabellone(int num_caselle);
    void stampa_tabellone();
    int return_caselle();
    int num_caselle = return_caselle();   // numero caselle random (vengono definite prima che venga generato il tabellone,
                                          // in modo che all'interno del gioco il numero di caselle non cambi ogni turno.)
    
};


#endif /* tabellone_h */
