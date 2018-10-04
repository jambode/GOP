#ifndef inizializza_player_h
#define inizializza_player_h
#include <iostream>
#include <cstring>
#include "player.h"
#include "dado.h"
using namespace std;

class inizializza_giocatori{
public:
    player *p[100];
    int posizione; 
	string N;
    int num_giocatori ;

    int decidi_numero_giocatori(){

        
            cout << "decidi il numero dei giocatori: ";
            cin >> num_giocatori;                                           //numero giocatori
            if (num_giocatori < 2){
                cout << "i giocatori devono essere almeno 2." << endl;
                num_giocatori = 0;
            }
        return num_giocatori ;
    }
    
	int return_num_giocatori(){
     return num_giocatori;
    }
    
    
    void inizializza_player(){
        for(int i = 0; i < num_giocatori; i++){
            cout << "inserisci nome giocatore " << i+1 << ": ";
            cin >> N;
            posizione = 0;
            p[i] = new player(posizione, N);
        }
    }
    void stampa_giocatori(){
        for(int i = 0; i < num_giocatori; i++){
            cout << "nome giocatore " << i+1 << ": ";
            p[i]->presenta_giocatore();
            cout << endl;
        }
    }
  /*  void muoviGiocatore(int passi){
    	for(int i=0; i<num_giocatori; i++){
    	int nuova_pos = p[i]->ritorna_pos()+passi;
    	if (nuova_pos<0)
    	nuova_pos = 0;
    	p[i]->player(nuova_pos);
    	cout<<"casella "<<p[i]->ritorna_pos()<< ": ";
	}
    /* int vai_avanti_a(int n){
        posizione += n;
        return posizione;
    }*/
    void posizione_corrente(int num){                  //stampa la posizione corrente
        dado d;
        for(int i=0; i<num; i++){
        int num_estratto = d.lancia_dado();
        cout<<"lancio dado.."<<num_estratto<<endl;
    	
    	int posizione = p[i]->vai_a_casella(num_estratto);
    	//cout<<"posizione giocatore "<<i+1<<": ";
    	if(posizione == 0) cout<<"partenza"<<endl;
    	else if (posizione%3==0){                  //permette di andare avanti se si capita su una casella %3==0
    		posizione = e.vai_avanti(posizione);
    		cout<<"posizione giocatore "<<i+1<<": "<<posizione<<endl;
    		cout<<"\n";
		}
		else if(posizione%5==0){            //si rilancia il dado se si capita su una casella %5==0
			posizione = e.tira_di_nuovo() + posizione;
			cout<<"posizione giocatore "<<i+1<<": "<<posizione<<endl;
			cout<<"\n";
		}
		else cout<<"posizione giocatore "<<i+1<<": "<<posizione<<endl;
		cout<<"\n";
}
}
};


#endif /* inizializza_player_h */
