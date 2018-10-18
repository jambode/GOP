#include <iostream>
#include "tabellone.h"
#include "player.cpp"
#include "inizializza_player.cpp"
using namespace std;

void tabellone::genera_tabellone(int num_caselle){
	p = new casella;
    cout << "numero caselle: " << num_caselle << endl;
    head = p;
    n = p;
    p->prec = NULL;
    int tmp;
    tmp = 1;
    while(num_caselle > 0){
        n = p;
        p->val = tmp;
        tmp += 1;
        p->next = new casella;
        n = p->next;
        n->prec = p;
        p = n;
        p->next = NULL;
        num_caselle--;
        }
}

void tabellone::stampa_tabellone(){
    int j;
    return_num_giocatori() = j;
	int accapo = 0;
    while(head->next != NULL){
        
           //stampa numeri (se < 10 con una spaziatura un più, si può fare diversamente)
        if((head->next->next != NULL) && (head->val != 1)){
            if(head->val < 10) cout << "|" << head->val << "|" << '\t' << '\t' << '\t' << '\t';
            else cout << "|" << head->val << "|" << '\t' << '\t' << '\t';
        }
            
            //stampa partenza e arrivo
        else if(head->val == 1) 
        	cout << "partenza" << '\t' << '\t';
        else cout << "arrivo" << endl;
        
        head = head->next;
        
        accapo += 1;
    
            //dovrebbe stampare il nome dei giocatori. Fa un ciclo for ogni casella del tabellone. Si può implementare anche con i simboli
        for(int i = 0; i <= j; i++){
            if(p[i]->pos == head->val){
                cout << p[i]->presenta_giocatore();
            }
        }
            //spaziatura a capo
        if (accapo == 10){
            cout << endl << endl << endl;
            accapo = 0;
        }
    }
}


int tabellone::return_caselle(){  //funzione che torna il numero di caselle, utile per essere richiamata in altre parti del programma
        srand(time(0));
        i = (rand() % 20) + 41;
        return i;	
}
