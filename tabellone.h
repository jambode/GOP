#ifndef tabellone_h
#define tabellone_h
#include <ctime>
#include <cstdlib>
#include "player.h"
#include "effetti.h"
#include "effetti.cpp"
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
    void genera_tabellone(){
        p = new casella;
        int num_caselle = return_caselle();
        cout << "numero caselle: " << num_caselle << endl;
        head = p;
        n = p;
        p->prec = NULL;
        int tmp;
        tmp = 1;
        while(i > 0){
            n = p;
            p->val = tmp;
            tmp += 1;
            p->next = new casella;
            n = p->next;
            n->prec = p;
            p = n;
            p->next = NULL;
            i--;
        }
    }
    void stampa_tabellone(){   //prende il numero di giocatori
     	//player *gioc[100];
     	//int posit = gioc[num]->ritorna_pos();
        int accapo = 0;
        while(head->next != NULL){
            
            //stampa numeri
            if((head->next->next != NULL) && (head->val != 1)){
                if(head->val < 10) cout << "|" << head->val << "|" << '\t' << '\t' << '\t' << '\t';
                else cout << "|" << head->val << "|" << '\t' << '\t' << '\t';    //dispari
            }
            
            //stampa partenza e arrivo
            else if(head->val == 1) 
        		cout << "partenza" << '\t' << '\t';
            else cout << "arrivo" << endl;
            head = head->next;
            accapo += 1;
            
            //spaziatura a capo
            if (accapo == 10){
                cout << endl << endl << endl;
                accapo = 0;
            }
        }
    }
        int return_caselle(){   //funzione che torna il numero di caselle, utile per essere richiamata in altre parti del programma
        	srand(time(0));
            i = (rand() % 20) + 41;
        	return i;
		}
		

    
};


#endif /* tabellone_h */
