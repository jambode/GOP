#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <cstring>
#include <iostream>


using namespace std;

class player{
protected:
   
    
    int turno ;
public: 
    int pos;
    char name[50];
    player(int p, char n[]);
    void presenta_giocatore();
    int ritorna_pos();
    int indietro_uno();
    int avanza_uno();
    int vai_a_casella(int i);
    int vai_avanti_n_caselle(int i);
    int indietro_n_caselle(int i);
   
};
#include "player.cpp"
#endif /* player_h */
