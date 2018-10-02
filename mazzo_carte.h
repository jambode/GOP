#ifndef mazzo_carte_h
#define mazzo_carte_h
#include <iostream>
using namespace std;

struct lista{
    int val;        //azione da far eseguire per le carte
    lista *next;
};

typedef lista* ptr_lista;

class mazzo{
public:
    ptr_lista head, p;
    void Lista(){
        p = new lista;
        head = p;
        for (int i = 0; i <= 40; i++){
            p->val = 0;
            p->next = new lista;
            p = p->next;
            p->next = head;
        }
    }
    int pesca_carta(){            //rimozione in testa, inserimento in coda
        ptr_lista tmp = head;
        head = head->next;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = new lista;
        p = p->next;
        p->val = tmp->val;
        p->next = NULL;
        delete tmp;
        return p->val;         //sbagliato: non puntatore, ma valore
    }
};


#endif /* mazzo_carte_h */
