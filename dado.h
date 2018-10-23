#ifndef _DADO_H
#define _DADO_H
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


class dado{
public:
	dado();
	int dice;
    int lancia_dado();
 
};

 #include "dado.cpp"

#endif /* dado_h */
