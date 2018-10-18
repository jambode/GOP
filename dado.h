#ifndef _DADO_H
#define _DADO_H
#include <iostream>
#include <ctime>
#include <cstdlib>

//using namespace std;

/*
   idea per dado: ogni volta che esce numero 6, si pesca carta da mazzo
 */

class dado{
public:
	dado();
	int dice;
    int lancia_dado();
 
};

#endif /* dado_h */

