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
     void posizione_corrente(int num){                  //stampa la posizione[i] corrente
        dado d;
        int t = set_turno();
        int j = 0;
        int pos_corr[100]; 
        	cout<<"---------------------------------------------------------"<<endl;
        cout<<"TURNO "<<t<<endl;
        
		while(j<num){
		for(int i=0; i<num; i++){
        int num_estratto = d.lancia_dado();
        cout<<"lancio dado.."<<num_estratto<<endl;
        
    	pos_corr[j] = p[i]->vai_a_casella(num_estratto) + p[i]->vai_a_casella(pos_corr[j]);
    	
    	//cout<<"pos_corr[j] giocatore "<<i+1<<": ";
    
    	if(pos_corr[j] == 0) cout<<"partenza"<<endl;
    	
    	else if (pos_corr[j]%3==0){                 //condizione casella vai avanti
    		pos_corr[j] = e.vai_avanti(pos_corr[j]);
    		cout<<"posizione giocatore "<<i+1<<": "<<pos_corr[j]<<endl;
    		cout<<"\n";
		}
		else if(pos_corr[j]%5==0){            //condizione casella tira di nuovo
		
			pos_corr[j] = e.tira_di_nuovo() + pos_corr[j];
			cout<<"posizione giocatore "<<i+1<<": "<<pos_corr[j]<<endl;
			cout<<"\n";
		}
     /*	else if(pos_corr[j]%4==0){      //condizione casella pesca carta
			e.pesca_carta();
			pos_corr[j] = pos_corr[j] + pos_corr[j];
			cout<<"pos_corr giocatore: "<<pos_corr[j]<<endl;
		}*/
		else if(pos_corr[j]%10==0){
			e.salta_turno();
			
		}
	
		else
		cout<<"posizione giocatore "<<i+1<<": "<<pos_corr[j]<<endl;
	
		cout<<"\n";
		j++;
}
}
};


#endif /* inizializza_player_h */
