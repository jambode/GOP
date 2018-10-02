#ifndef dado_h
#define dado_h
//#include <iostream>
#include <ctime>
#include <cstdlib>
#include "mazzo_carte.h"
#include "player.h"
//using namespace std;

/*
   idea per dado: ogni volta che esce numero 6, si pesca carta da mazzo
 */

class dado{
public:
	int dado;
    int lancia_dado(){
        //srand(time(0));
        dado = (rand() % 6) + 1;
        
        return dado;
       // muoviGiocatore(dado);
}};

#endif /* dado_h */
