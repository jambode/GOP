File inutile al momento, ho implementato questo in un'altra funzione.



/*#ifndef turno_h
#define turno_h
#include "player.h"
#include "inizializza_player.h"
#include "dado.h"
#include "mazzo_carte.h"
#include<ctime>



class turno{   
public:
    int inizio_turno(int num){
       dado d;
	   if (num==0)
		return 0;
		 cout<<"giocatore "<<num<<" lancia dado.."<<d.lancia_dado();            //mettere prossimo giocatore e fare una funzione del tipo nextplayer()
		cout << endl;
		
		inizio_turno(num-1);
        /*p[i]->vai_avanti_n_caselle(d.dado);
        cout << p[i]->ritorna_pos(d.dado);*/
    }
    
 /*   void move(int current){
    	int casella;
    	casella = d.return_dado();
    	p[current]->vai_a_casella(casella);
	}*/
};

#endif /* turno_h */
*/
