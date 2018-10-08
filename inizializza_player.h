#ifndef inizializza_player_h
#define inizializza_player_h
#include <iostream>
#include <cstring>
#include <ctime>
#include "player.h"
#include "dado.h"
#include "effetti.h"
#include "effetti.cpp"
#include "tabellone.h"
using namespace std;

class inizializza_giocatori{
public:
    player *p[100];
    int posizione; 
	string N;
    int num_giocatori ;
    effetti e;
    int turno = 0;
    tabellone tab;
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
        posizione[i] += n;
        return posizione[i];
    }*/
       int set_turno(){     //tiene il conto dei turni
    	turno ++;
    	return turno;
	}
	int return_turn(){
		return turno;
	}
	
    void posizione_corrente(int num){                  //stampa la posizione[i] corrente
        dado d;
        int t = set_turno();
        int j = 0;
        int fw_or_bw[num];
        //int pos_corr[1000]; 
        int i = 0;
        
        int num_caselle = tab.return_caselle();
        cout<<"numero caselle "<<num_caselle<<endl;
	
	    
        while(p[i]->pos < num_caselle){
        cout<<"---------------------------------------------------------"<<endl;
        cout<<"TURNO "<<t++<<endl;
		for(int i=0; i<num; i++){
		
		
        int num_estratto= d.lancia_dado();
        cout<<"lancio dado.."<<num_estratto<<endl;
        p[i]->pos = p[i]->vai_avanti_n_caselle(num_estratto);
    	
    	//cout<<"pos_corr[j] giocatore "<<i+1<<": ";
    		if(p[i]->pos >= num_caselle){
    			cout<<"posizione giocatore "<<i+1<<": "<<p[i]->pos<<endl;
    	cout<<"giocatore "<<i+1<<" SEI ARRIVATO! "<<endl;
		return;
			}
    	else if(p[i]->pos == 0) cout<<"partenza"<<endl;
    	
    	else if (p[i]->pos%9==0){                 //condizione casella vai avanti
    		p[i]->pos = e.vai_avanti(p[i]->pos);
    		cout<<"posizione giocatore "<<i+1<<": "<<p[i]->pos<<endl;
    		cout<<"\n";
		}
		else if(p[i]->pos%5 ==0){            //condizione casella tira di nuovo
		
			p[i]->pos = e.tira_di_nuovo() + p[i]->pos;
			cout<<"posizione giocatore "<<i+1<<": "<<p[i]->pos<<endl;
			cout<<"\n";
		}
   /*  	else if(pos%4==0){      //condizione casella pesca carta
			e.pesca_carta();
			pos = pos + pos;
			cout<<"posizione giocatore: "<<pos<<endl;
		}*/
	/*	else if(pos%10==0){
			e.salta_turno();
			int turno = return_turno();
			p[i]
		}*/
		else if(p[i]->pos%4==0 && t>1){
	
			fw_or_bw[i] = rand()%2;
			int num = e.fortuna(num_giocatori);
			cout<<"posizione giocatore "<<i+1<<": "<<p[i]->pos<<endl;
			if(fw_or_bw[i]==1){
		cout<<"avanti di: "<<num<<endl;
		p[i]->pos = p[i]->vai_avanti_n_caselle(num);
	}
	else {
	cout<<"indietro di: "<<num<<endl;
	p[i]->pos = p[i]->indietro_n_caselle(num);

}
			cout<<"NUOVA POSIZIONE "<<i+1<<": "<<p[i]->pos<<endl;
	} 
		
		else cout<<"posizione giocatore "<<i+1<<": "<<p[i]->pos<<endl;        //casella vuota
	
		cout<<"\n";
} 

}
}



    
  /*  void turns(){
    	int num_caselle = tab.return_caselle();
    	cout<<"caselle "<<num_caselle;
    	for(int i=0; i<num_giocatori; i++){
    	while(p[i]->pos < num_caselle)
    	posizione_corrente(num_giocatori);
    
    		
}
}
   */

};


#endif /* inizializza_player_h */
