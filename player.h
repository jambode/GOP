#ifndef player_h
#define player_h
#include <cstring>
#include "mazzo_carte.h"
using namespace std;

class player: public mazzo{
protected:
    int pos;
    string name;
public:
    player(){}
   player(int p){
        this->pos = p;
    }
    player(int p, string n){
        this->pos = p;
        this->name = n;
    }
    void presenta_giocatore(){
        cout << name;
    }
    int ritorna_pos(){
    	return pos;
    }
    int indietro_uno(){
        if (pos > 0) pos -= 1;
        else cout << "impossibile andare indietro." << endl;
        return pos;
    }
    int avanza_uno(){
        pos += 1;
        return pos;
    }
    int vai_a_casella(int i){
        pos = i;
        return pos;
    }
    int vai_avanti_n_caselle(int i){
    	int p = pos;
        return p + i;
    }
    int vuota(){
        cout << "casella vouta." << endl;
        return pos;
    }
    
    
    //fermo, scambia pos.
};

#endif /* player_h */
