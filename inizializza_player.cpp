#include<iostream>
#include "inizializza_player.h"
using namespace std;



int inizializza_giocatori::decidi_numero_giocatori(){

	cout << "decidi il numero dei giocatori: ";
            cin >> num_giocatori;                                           //numero giocatori
            if (num_giocatori < 2){
                cout << "i giocatori devono essere almeno 2." << endl;
                num_giocatori = 0;
            }
        return num_giocatori ;
}

int inizializza_giocatori::return_num_giocatori(){
    return num_giocatori;
}

void inizializza_giocatori::inizializza_player(){
	for(int i = 0; i < num_giocatori; i++){
            cout << "inserisci nome giocatore " << i+1 << ": ";
            cin>>N;
            posizione = 0;
            p[i] = new player(posizione, N);
        }
}

void inizializza_giocatori::stampa_giocatori(){
	for(int i = 0; i < num_giocatori; i++){
            cout << "nome giocatore " << i+1 << ": ";
            p[i]->presenta_giocatore();
            cout << endl;
        }
}

int inizializza_giocatori::set_turno(){
		turno ++;
    	return turno;
}


int inizializza_giocatori::return_turn(){
	return turno;
}


void inizializza_giocatori::posizione_corrente(int num){
	dado d;
	    turno = 0;
        int t = set_turno();
        //int j = 0;
        int fw_or_bw[num];
        //int pos_corr[1000]; 
        int i = 0;
        
        int num_caselle = tab.return_caselle();
        cout<<"numero caselle "<<num_caselle<<endl;
	    
        while(p[i]->pos != num_caselle){
	tab.genera_tabellone(num_caselle);
        cout<<"---------------------------------------------------------"<<endl;
        cout<<"TURNO "<<t++<<endl;
		for(i=0; i<num; i++){
		
		
        int num_estratto= d.lancia_dado();
        cout<<"lancio dado.."<<num_estratto<<endl;
        p[i]->pos = p[i]->vai_avanti_n_caselle(num_estratto);
    	
    	//cout<<"pos_corr[j] giocatore "<<i+1<<": ";
    	//CONDIZIONE CHE PERMETTE DI STABILIRE CHE UN GIOCATORE è ARRIVATO AL TRAGUARDO.
    		if(p[i]->pos == num_caselle){
    			cout<<"posizione giocatore "<<i+1<<": "<<p[i]->pos<<endl;
    	cout<<"giocatore "<<i+1<<" SEI ARRIVATO! "<<endl;
		return;
			}
			//CONDIZIONE CHE FA TORNARE INDIETRO IL GIOCATORE QUANDO SUPERA IL NUMERO DI CASELLE
		else if(p[i]->pos > num_caselle){
			cout<<"posizione giocatore "<<i+1<<": "<<p[i]->pos<<endl;
			int difference = p[i]->pos - num_caselle;
			p[i]->pos = p[i]->pos - difference*2;
			cout<<"DEVI TORNARE INDIETRO DI "<<difference<<", CI SEI QUASI... "<<endl;
			cout<<"posizione giocatore "<<i+1<<": "<<p[i]->pos<<endl;
		}
    	else if(p[i]->pos == 0) cout<<"partenza"<<endl;
    	
    	//CONDIZIONE VAI ALLA CASELLA N
    	else if (p[i]->pos%9==0){                 
    		p[i]->pos = e.vai_avanti(p[i]->pos);
    		cout<<"posizione giocatore "<<i+1<<": "<<p[i]->pos<<endl;
    		cout<<"\n";
		}
		//CONDIZIONE TIRA DI NUOVO
		else if(p[i]->pos%5 ==0){            
		
			p[i]->pos = e.tira_di_nuovo() + p[i]->pos;
			cout<<"posizione giocatore "<<i+1<<": "<<p[i]->pos<<endl;
			cout<<"\n";
		}
    	else if(p[i]->pos==13){      //condizione casella pesca carta
			e.pesca_carta();
			p[i]->pos = p[i]->pos + p[i]->pos;
			cout<<"posizione giocatore: "<<p[i]->pos<<endl;
		}

		
		//CONDIZIONE CHE PERMETTE DI ANDARE AVANTI/INDIETRO RANDOM
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
		
		//CASELLA VUOTA
		else cout<<"posizione giocatore "<<i+1<<": "<<p[i]->pos<<endl;        
	
		cout<<"\n";
} 
    tab.stampa_tabellone();
}
    
}



//          PROVE DI EFFETTI           //

		
/*		//CONDIZIONE SALTA TURNO
		else if(pos%10==0){
			e.salta_turno();
			int turno = return_turno();
			
		}*/
		//CONDIZIONE SCAMBIA POSTO GIOCATORI
	/*	else if(p[i]->pos==13 || p[i]->pos == 23){
			int pl = rand()%num_giocatori+1;
			int temp;
			if(pl!= i){
			temp = p[i]->pos;
			p[i]->pos = p[pl]->pos;
			p[pl]->pos = temp;
			cout<<"SCAMBIA CON "<<pl+1<<endl;
			cout<<"posizione giocatore "<<i+1<<": "<<p[i]->pos<<endl;
			cout<<"posizione giocatore "<<pl+1<<": "<<p[pl]->pos<<endl;
		    }
		    else {
			cout<<"SEI STATO FORTUNATO, RIMANI AL TUO POSTO!! "<<endl;
		    cout<<"posizione giocatore "<<i+1<<": "<<p[i]->pos<<endl;
		    }  
		}*/
