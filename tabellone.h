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
	int i;          // numero caselle random
    void genera_tabellone();
    void stampa_tabellone();
    int return_caselle();

    
};


#endif /* tabellone_h */
