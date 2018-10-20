#include<iostream>
#include "inizializza_player.h"
using namespace std;



int inizializza_giocatori::decidi_numero_giocatori(){

    //cout<<"State per addentrarvi nei mea";
	cout << "Per iniziare decidi il numero dei giocatori: ";
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
	cout<<"\nSabah al khayr, buongiorno, io sono Anubi, dio dell'oltretomba e sorvegliero' il vostro viaggio nella buona e nella cattiva sorte"<<endl
	    
	    <<"Voi siete?"<<endl<<endl;
	for(int i = 0; i < num_giocatori; i++){
            cout << "(inserire nome giocatore) " << i+1 << ": ";
            cin>>N;
            posizione = 0;
            gioc[i] = new player(posizione, N);
        }
        cout<<endl;
    stampa_giocatori();
    cout<<"\nBenvenuti nella Valle dei Re!"<<endl
        <<"molti hanno cercato di arrivare al tesoro di Tutankamon, "
		<<"ma nessuno fin ora e' riuscito nell'impresa, "
		<<"chissa' che uno di voi non riesca a raggiungerlo. "
		<<"Non indugiamo, prego..cominciamo "<<endl<<endl
		<<"ma ricordate: "<<endl<<endl
		<<"'La tempesta si alzera'. Il cielo si aprira'. Il potere si scatenera'' contro chi un passo falso commetera'"<<"\n"<<"\n";
	cout<<"Haz saeed, buona fortuna!"<<"\n"<<"\n";
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
	 	termina = false;
	 	char stampa;
        int t = set_turno();
        int j = 0;
        int fw_or_bw[num];
        //int pos_corr[1000]; 
        int i = 0;
        //CREO IL MAZZO
        m.crea_mazzo();
        int num_caselle = return_caselle();
        //cout<<"numero caselle "<<num_caselle<<endl;
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
			    	else if (gioc[i]->pos%10==0){                 
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
					
					//CONDIZIONE PESCA CARTA
			    	else if(gioc[i]->pos%4==0){ 
						
						gioc[i]->pos = effetti_carta(i);
						cout<<"posizione giocatore: "<<gioc[i]->pos<<endl;
					}
			
					
					//CONDIZIONE CHE PERMETTE DI ANDARE AVANTI/INDIETRO RANDOM
					else if(gioc[i]->pos%9==0 && t>1){
				
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
				    
				        //CONDIZIONE SCAMBIA GIOCATORI
				    /*	else if(gioc[i]->pos==13 || gioc[i]->pos == 23){
							int pl = rand()%num_giocatori+1;
							int temp;
							if(pl!= i){
								temp = gioc[i]->pos;
								gioc[i]->pos = gioc[pl]->pos;
								gioc[pl]->pos = temp;
								cout<<"SCAMBIA CON "<<pl+1<<endl;
								cout<<"posizione giocatore "<<i+1<<": "<<gioc[i]->pos<<endl;
								cout<<"posizione giocatore "<<pl+1<<": "<<gioc[pl]->pos<<endl;
						    }
						    else {
								cout<<"SEI STATO FORTUNATO, RIMANI AL TUO POSTO!! "<<endl;
							    cout<<"posizione giocatore "<<i+1<<": "<<gioc[i]->pos<<endl;
						    }  
						}*/
					else if(gioc[i]->pos==13 || gioc[i]->pos == 23){
						cout<<"SEI IN PRIGIONE! STAI FERMO UN TURNO!"<<endl;
						gioc[i]->pos = gioc[i]->pos - num_estratto;
					}
					//CASELLA VUOTA
					else cout<<"posizione giocatore "<<i+1<<"("<<gioc[i]->name<<"): "<<gioc[i]->pos<<endl;        
				
					cout<<"\n";
					} 
			cout<<"premi T per stampare tabellone.."<<endl;
			cin>>stampa;
			if(stampa=='t')
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
	termina = false;
	j = return_num_giocatori();
	int accapo = 0;
    while(head->next != NULL){
              for(int i = 0; i < j; i++){
            if(gioc[i]->pos == head->val){
                gioc[i]->presenta_giocatore();
                cout<<"->";
            }
        }
            //stampa numeri
        if((head->next->next != NULL) && (head->val != 1)){
            if(head->val < 10) cout << "|" << head->val << "|" << '\t' << '\t' << '\t';
            else cout<<"|" << head->val << "|" << '\t' << '\t' << '\t';    //dispari
        }
            
            //stampa partenza e arrivo
        else if(head->val == 1) 
        	cout << "partenza" << '\t' << '\t';
        else cout << "arrivo" << endl;
        head = head->next;
        accapo += 1;
            
     
        
            //spaziatura a capo
        if (accapo == 5){
            cout << endl <<endl<<endl;
            cout<<"\t";
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


int inizializza_giocatori::effetti_carta(int i){
	//m.stampa_mazzo();
	//cout<<"\n"<<"\n";
	carta card;
	
	cout<<"CARTA ESTRATTA:"<<endl;
	card = m.estrai_in_cima();
	card.stampa_carta();
	cout<<"\n";
	int posiz; 
	bool result;
	bool fermo=false;
	string msg = card.getmsg();

	if(msg == "ritira il dado")
		posiz = e.tira_di_nuovo() + gioc[i]->pos; 
				
	else if(msg == "rispondi alla domanda"){
		cout<<"La sfinge si è svegliata, rispondi a sta cagataaaaaa yeee!!!!  "<<endl;
		result = m.gestione_domanda();
		if(result == true)
			posiz = gioc[i]->avanza_uno();
		else
			posiz = gioc[i]->indietro_uno();
	}	
	else if(msg == "ritorna alla casella 0")
		posiz = gioc[i]->ritorna_pos()-gioc[i]->ritorna_pos();	
		  	    
	else if(msg == "fai 3 passi in avanti")
		posiz = gioc[i]->vai_avanti_n_caselle(3);  
		  	    
	else if(msg == "fai 3 passi indietro") 
		posiz = gioc[i]->indietro_n_caselle(3);	
		  	
   else if (msg == "scambia posizione con un altro giocatore"){
   		int pl = rand()%num_giocatori+1;
		int temp;
		if(pl!= i){
			temp = gioc[i]->pos;
			posiz = gioc[pl]->pos;
			gioc[pl]->pos = temp;
			cout<<"SCAMBIA CON "<<pl+1<<endl;
			cout<<"posizione giocatore "<<i+1<<": "<<posiz<<endl;
			cout<<"posizione giocatore "<<pl+1<<": "<<gioc[pl]->pos<<endl;
	    }
	    else {
			cout<<"SEI STATO FORTUNATO, RIMANI AL TUO POSTO!! "<<endl;
		    cout<<"posizione giocatore "<<i+1<<": "<<gioc[i]->pos<<endl;
						    }  
						}
		
	return (posiz);
	
}
