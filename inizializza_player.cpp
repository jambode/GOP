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
            gioc[i] = new player(posizione, N);
        }
}

void inizializza_giocatori::stampa_giocatori(){
	for(int i = 0; i < num_giocatori; i++){
            cout << "nome giocatore " << i+1 << ": ";
            gioc[i]->presenta_giocatore();
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
        int j = 0;
        int fw_or_bw[num];
        //int pos_corr[1000]; 
        int i = 0;
        
        int num_caselle = return_caselle();
        cout<<"numero caselle "<<num_caselle<<endl;
	    
	   // tab.stampa_tabellone();
        while(gioc[i]->pos != num_caselle && termina == false){
		 	genera_tabellone(num_caselle);
		
		        cout<<"---------------------------------------------------------"<<endl;
		        cout<<"TURNO "<<t++<<endl;
				for(int i=0; i<num; i++){
					
			        int num_estratto = d.lancia_dado();
			        cout<<"lancio dado.."<<num_estratto<<endl;
			        gioc[i]->pos = gioc[i]->vai_avanti_n_caselle(num_estratto);
			    	
			    	//cout<<"pos_corr[j] giocatore "<<i+1<<": ";
			    	//CONDIZIONE CHE PERMETTE DI STABILIRE CHE UN GIOCATORE è ARRIVATO AL TRAGUARDO.
		    		if(gioc[i]->pos == num_caselle){
		    			cout<<"posizione giocatore "<<i+1<<"("<<gioc[i]->name<<"): "<<gioc[i]->pos<<endl;
				    	cout<<"giocatore "<<i+1<<" SEI ARRIVATO! "<<endl;
						return;
					}
						//CONDIZIONE CHE FA TORNARE INDIETRO IL GIOCATORE QUANDO SUPERA IL NUMERO DI CASELLE
					else if(gioc[i]->pos > num_caselle){
						cout<<"posizione giocatore "<<i+1<<": "<<gioc[i]->pos<<endl;
						int difference = gioc[i]->pos - num_caselle;
						gioc[i]->pos = gioc[i]->pos - difference*2;
						cout<<"DEVI TORNARE INDIETRO DI "<<difference<<", CI SEI QUASI... "<<endl;
						cout<<"posizione giocatore "<<i+1<<"("<<gioc[i]->name<<"): "<<gioc[i]->pos<<endl;
					}
			    	else if(gioc[i]->pos == 0) 
						cout<<"partenza"<<endl;
			    	
			    	//CONDIZIONE VAI ALLA CASELLA N
			    	else if (gioc[i]->pos%9==0){                 
			    		gioc[i]->pos = e.vai_avanti(gioc[i]->pos);
			    		cout<<"posizione giocatore "<<i+1<<"("<<gioc[i]->name<<"): "<<gioc[i]->pos<<endl;
			    		cout<<"\n";
					}
					//CONDIZIONE TIRA DI NUOVO
					else if(gioc[i]->pos%5 ==0){            
					
						gioc[i]->pos = e.tira_di_nuovo() + gioc[i]->pos;
						cout<<"posizione giocatore "<<i+1<<"("<<gioc[i]->name<<"): "<<gioc[i]->pos<<endl;
						cout<<"\n";
					}
					
			    	else if(gioc[i]->pos%10==0){      //condizione casella pesca carta
						e.pesca_carta();
						gioc[i]->pos = gioc[i]->pos + gioc[i]->pos;
						cout<<"posizione giocatore: "<<gioc[i]->pos<<endl;
					}
			
					
					//CONDIZIONE CHE PERMETTE DI ANDARE AVANTI/INDIETRO RANDOM
					else if(gioc[i]->pos%4==0 && t>1){
				
						fw_or_bw[i] = rand()%2;
						int num = e.fortuna(num_giocatori);
						cout<<"posizione giocatore "<<i+1<<"("<<gioc[i]->name<<"): "<<gioc[i]->pos<<endl;
						if(fw_or_bw[i]==1){
					       cout<<"avanti di: "<<num<<endl;
					       gioc[i]->pos = gioc[i]->vai_avanti_n_caselle(num);
				           }
				        else {
				            cout<<"indietro di: "<<num<<endl;
				            gioc[i]->pos = gioc[i]->indietro_n_caselle(num);
			            }
						cout<<"NUOVA POSIZIONE "<<i+1<<": "<<gioc[i]->pos<<endl;
				    } 
					
					//CASELLA VUOTA
					else cout<<"posizione giocatore "<<i+1<<"("<<gioc[i]->name<<"): "<<gioc[i]->pos<<endl;        
				
					cout<<"\n";
					} 
		    stampa_tabellone();
		}  

	}
    




//          PROVE DI EFFETTI           //

		
/*		//CONDIZIONE SALTA TURNO
		else if(pos%10==0){
			e.salta_turno();
			int turno = return_turno();
			
		}*/
		//CONDIZIONE SCAMBIA POSTO GIOCATORI
	/*	else if(gioc[i]->pos==13 || gioc[i]->pos == 23){
			int pl = rand()%num_giocatori+1;
			int temp;
			if(pl!= i){
			temp = gioc[i]->pos;
			gioc[i]->pos = p[pl]->pos;
			p[pl]->pos = temp;
			cout<<"SCAMBIA CON "<<pl+1<<endl;
			cout<<"posizione giocatore "<<i+1<<": "<<gioc[i]->pos<<endl;
			cout<<"posizione giocatore "<<pl+1<<": "<<p[pl]->pos<<endl;
		    }
		    else {
			cout<<"SEI STATO FORTUNATO, RIMANI AL TUO POSTO!! "<<endl;
		    cout<<"posizione giocatore "<<i+1<<": "<<gioc[i]->pos<<endl;
		    }  
		}*/
		
		



void inizializza_giocatori::genera_tabellone(int num_cas){
	p = new casella;
    //cout << "numero caselle: " << num_cas << endl;
    head = p;
    n = p;
    p->prec = NULL;
    int tmp;
    tmp = 1;
    while(num_cas > 0){
        n = p;
        p->val = tmp;
        tmp += 1;
        p->next = new casella;
        n = p->next;
        n->prec = p;
        p = n;
        p->next = NULL;
        num_cas--;
        }
}


bool inizializza_giocatori::stampa_tabellone(){
	int j;
	j = return_num_giocatori();
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
            
       for(int i = 0; i < j; i++){
            if(gioc[i]->pos == head->val){
                gioc[i]->presenta_giocatore();
                cout<<"->";
            }
        }
        
            //spaziatura a capo
        if (accapo == 10){
            cout << endl << endl << endl;
            accapo = 0;
            }
        }
        	cout<<"Vuoi continuare? Premi y/n.. "<<endl;
			cin>>x;
			if(x=='y')
				termina = false;
			else 
				termina = true;
				
	return termina;			
}


int inizializza_giocatori::return_caselle(){
	  srand(time(0));
        i = (rand() % 20) + 41;
        return i;
}
