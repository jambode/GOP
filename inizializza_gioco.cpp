//inizializza_player.cpp
using namespace std;


inizializza_gioco::inizializza_gioco(){
	num_caselle = return_caselle();
}

int inizializza_gioco::decidi_numero_giocatori(){

	cout << "Per iniziare decidi il numero dei giocatori: ";
            cin >> num_giocatori;                                           //numero giocatori
            if (num_giocatori < 2){
                cout << "i giocatori devono essere almeno 2." << endl;
                num_giocatori = 0;
            }
        return num_giocatori ;
}

int inizializza_gioco::return_num_giocatori(){
    return num_giocatori;
}

void inizializza_gioco::inizializza_player(){
	cout<<"\nSabah al khayr, buongiorno, io sono Anubi, dio dell'oltretomba e sorvegliero' il vostro viaggio nella buona e nella cattiva sorte"<<endl
	    
	    <<"Voi siete?"<<endl<<endl;
	for(int i = 0; i < num_giocatori; i++){
            cout << "(inserire nome giocatore, o iniziale) " << i+1 << ": ";
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

void inizializza_gioco::stampa_giocatori(){
	for(int i = 0; i < num_giocatori; i++){
			cout<<"giocatore "<<i+1<<": ";
			gioc[i]->presenta_giocatore();
            cout << "\niniziale giocatore " << i+1 << ": "<<gioc[i]->name[0];           //iniziale giocatore che verrà stampata sul tabellone
            
            cout << endl
            	 << endl;
        }
}

int inizializza_gioco::set_turno(){
		turno ++;
    	return turno;
}


int inizializza_gioco::return_turn(){
	return turno;
}


void inizializza_gioco::fai_turno(int num){
	dado d;
	    turno = 0;
	 	termina = false;
	 	char stampa;
	 	char play;
        int t = set_turno();
        int j = 0;
        int fw_or_bw[num];
        int i = 0;
        //CREO IL MAZZO
        m.crea_mazzo();
        
        //CICLO CHE PERMETTE DI FARE I TURNI 
        while(gioc[i]->pos != num_caselle || termina == false){
		 	genera_tabellone(num_caselle);
		
	        cout<<"---------------------------------------------------------"<<endl;
	        cout<<"TURNO "<<t++<<endl;
			for(int i=0; i<num; i++){
				cout<<"\n>>Giocatore "<<i+1<<" "<<gioc[i]->name<<endl;
				cout<<"PREMI UNA LETTERA DA TASTIERA PER LANCIARE IL DADO.."<<endl;
				cin>>play;
			    int num_estratto = d.lancia_dado();
				cout<<"\n";
			    cout<<">lancio dado.."<<num_estratto<<endl;
		    	gioc[i]->pos = gioc[i]->vai_avanti_n_caselle(num_estratto);
		    	
		
		    	//CONDIZIONE CHE PERMETTE DI STABILIRE CHE UN GIOCATORE è ARRIVATO AL TRAGUARDO.
	    		if(gioc[i]->pos == num_caselle){
	    			cout<<"posizione giocatore "<<i+1<<"("<<gioc[i]->name<<"): "<<gioc[i]->pos<<endl;
			    	cout<<"CONGRATULAZIONI ";
			    	gioc[i]->presenta_giocatore();
					cout<<" al tesoro sei arrivato ed il gioco hai terminato!"<<endl;
					return;
				}
				
					//CONDIZIONE CHE FA TORNARE INDIETRO IL GIOCATORE QUANDO SUPERA IL NUMERO DI CASELLE
				else if(gioc[i]->pos >= num_caselle){
					gioc[i]->pos = quasi_arrivato(i, num_estratto);
				}
				
				
		    	else if(gioc[i]->pos == 0) 
					cout<<"partenza"<<endl;
		    	
		    	//CONDIZIONE VAI ALLA CASELLA N
		    	else if (gioc[i]->pos%23==0){                
		    		gioc[i]->pos = e.vai_avanti(gioc[i]->pos);
		    		if (gioc[i]->pos >= num_caselle){
		    			gioc[i]->pos = quasi_arrivato(i, num_estratto);
					}
					else
		    			cout<<"posizione giocatore "<<i+1<<"("<<gioc[i]->name<<"): "<<gioc[i]->pos<<endl;
		    		cout<<"\n";
				}
				
				//CONDIZIONE TIRA DI NUOVO
				else if(gioc[i]->pos%19 ==0){
					gioc[i]->pos = e.tira_di_nuovo() + gioc[i]->pos;
					if (gioc[i]->pos >= num_caselle){
		    			gioc[i]->pos = quasi_arrivato(i, num_estratto);
					}
					else
					cout<<"posizione giocatore "<<i+1<<"("<<gioc[i]->name<<"): "<<gioc[i]->pos<<endl;
					cout<<"\n";
				}
				
				//CONDIZIONE PESCA CARTA
		    	else if(gioc[i]->pos%7==0){ 
					cout<<"posizione giocatore "<<i+1<<"("<<gioc[i]->name<<"): "<<gioc[i]->pos<<endl;
					cout<<"PESCA UNA CARTA!"<<endl
						<<" premi una lettera per pescare una carta.."<<endl;
					cin>>play;
					gioc[i]->pos = effetti_carta(i);
					cout<<"posizione giocatore "<<i+1<<"("<<gioc[i]->name<<"): "<<gioc[i]->pos<<endl;
				}
		
				//CONDIZIONE CHE PERMETTE DI ANDARE AVANTI/INDIETRO RANDOM
				else if(gioc[i]->pos%9==0 && t>1){
			
					fw_or_bw[i] = rand()%2;
					int num = e.fortuna(num_giocatori);
					cout<<"posizione giocatore "<<i+1<<"("<<gioc[i]->name<<"): "<<gioc[i]->pos<<endl;
					if(fw_or_bw[i]==1){
				       cout<<"avanti di: "<<num<<endl;
				       gioc[i]->pos = gioc[i]->vai_avanti_n_caselle(num);
				       if (gioc[i]->pos >= num_caselle){
		    			gioc[i]->pos = quasi_arrivato(i, num_estratto);
						}
					}
			        else {
			            cout<<"indietro di: "<<num<<endl;
			            gioc[i]->pos = gioc[i]->indietro_n_caselle(num);
		            }
					cout<<"NUOVA POSIZIONE "<<i+1<<": "<<gioc[i]->pos<<endl;
			    } 
			    
                //CONDIZIONE PER LA QUALE SE SEI IN UNA DELLE DUE CASELLE NON PUOI ANDARE AVANTI DURANTE QUEL TURNO
				else if(gioc[i]->pos==17 || gioc[i]->pos ==37){
					cout<<"LA MUMMIA TI HA INCASTRATO, NELLA CASELLA TI HA BLOCCATO!"<<endl;
					gioc[i]->pos = gioc[i]->pos - num_estratto;
				}
				
				//CASELLA VUOTA
				else cout<<"posizione giocatore "<<i+1<<"("<<gioc[i]->name<<"): "<<gioc[i]->pos<<endl;        
			
				cout<<"\n";
	    
	}
		cout<<"premi T per stampare tabellone.."<<endl;
		stampa = 0;
		while (stampa != 't'){
			cin>>stampa;
			if(stampa=='t')
    			stampa_tabellone();
    		else 
    			cout<<"\npremi t"<<endl;
		}
    }  
		    	
}
    

int inizializza_gioco::quasi_arrivato(int i, int num_estr){
        int posizione;
		cout<<"posizione giocatore "<<i+1<<": "<<gioc[i]->pos<<endl;
		
		if(gioc[i]->pos == num_caselle){
			cout<<"CONGRATULAZIONI ";
			gioc[i]->presenta_giocatore();
			cout<<" al tesoro sei arrivato ed il gioco hai terminato!"<<endl;
			exit(1) ;
		}
		
		gioc[i]->pos = gioc[i]->pos - num_estr;
		int diff_caselle = num_caselle - gioc[i]->pos;
		int difference = num_estr - diff_caselle;
		posizione = num_caselle - difference;
		cout<<"LA FINE HAI SUPERATO INDIETRO SEI TORNATO, NON DISPERARE, AL TESORO STAI QUASI PER ARRIVARE!!...  "<<endl;
		cout<<"posizione giocatore "<<i+1<<"("<<gioc[i]->name<<"): "<<posizione<<endl;
		return (posizione);
}
		
		



void inizializza_gioco::genera_tabellone(int num_cas){
	p = new casella;
    head = p;
    n = p;
    p->prec = NULL;
    int tmp;
    tmp = 0;
    while(num_cas >= 0){
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


bool inizializza_gioco::stampa_tabellone(){
	int j;
	termina = false;
	j = return_num_giocatori();
	int accapo = 0;
    while(head->next != NULL){
              for(int i = 0; i < j; i++){
            if(gioc[i]->pos == head->val){
                cout<<gioc[i]->name[0]<<"->";
            }
        }
            //stampa numeri
        if((head->next->next != NULL) && (head->val != 0)){
            if(head->val < 10) cout << "|" << head->val << "|" << '\t' << '\t' << '\t';
            else cout<<"|" << head->val << "|" << '\t' << '\t' << '\t';    //dispari
        }
            
            //stampa partenza e arrivo
        else if(head->val == 0) 
        	cout << "partenza" << '\t' << '\t';
        else 
			cout << "arrivo" << endl;
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
			else if(x == 'n') {
				termina = true;
				exit(1);
			}
			else{
				cout<<"\nERRORE: INPUT NON VALIDO! Premi y/n.."<<endl;
				cin>>x;
			}
			
				
	return termina;			
}


int inizializza_gioco::return_caselle(){
	  srand(time(0));
        i = (rand() % 20) + 41;
        return i;
}


int inizializza_gioco::effetti_carta(int i){
	carta card;
	cout<<"CARTA ESTRATTA:";
	card = m.estrai_in_cima();
	int posiz; 
	bool result;
	bool fermo=false;
	string msg = card.getmsg();

	if(msg == "ritira il dado"){
		cout<<"Sei stato fortunato, il dado sara' nuovamente tirato.."<<endl;
		cout<<"\n";
		int die = e.tira_di_nuovo();
		gioc[i]->pos = die + gioc[i]->pos; 
		if(gioc[i]->pos >= num_caselle){
			posiz = quasi_arrivato(i, die);
		}
		else
			posiz = gioc[i]->pos;
	}
				
	else if(msg == "rispondi alla domanda"){
		cout<<"La sfinge hai disturbato, un indovinello va azzeccato!"<<endl;
		cout<<"\n";
		result = m.gestione_domanda();
		if(result == true){
			posiz = gioc[i]->avanza_uno();
			if(posiz >= num_caselle){
				posiz = quasi_arrivato(i, 1);
			}
		}
		else
			posiz = gioc[i]->indietro_uno();
		
	}
	
		
	else if(msg == "ritorna alla casella di partenza"){
		cout<<"Un guaio hai combinato alla casella di partenza sei ritornato"<<endl;
		cout<<"\n";
		posiz = gioc[i]->ritorna_pos()-gioc[i]->ritorna_pos();	
	}
		  	    
	else if(msg == "fai 3 passi in avanti"){
		cout<< "Dalla divinita' Bes sei accompagnato, in avanti di 3 caselle ti ha portato"<<endl;    //Bes divinità protettrice del malocchio
		cout<<"\n";
		gioc[i]->pos = gioc[i]->vai_avanti_n_caselle(3);
		if(gioc[i]->pos >= num_caselle){
			posiz = quasi_arrivato(i, 3);
		}
		else 
			posiz = gioc[i]->pos;
	}
		  	    
	else if(msg == "fai 3 passi indietro") {
		cout<<"Shai e' arrabbiato, indietro di 3 caselle ti ha riportato"<<endl;      //dio della sorte
		cout<<"\n";
		posiz = gioc[i]->indietro_n_caselle(3);	
	}
	
		  	
   else if (msg == "scambia posizione con un altro giocatore"){
   		cout<<"In una botola sei incappato con un altro giocatore di posto verrai scambiato"<<endl;
   		cout<<"\n";
   		int pl = rand()%num_giocatori;
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
		    posiz = gioc[i]->pos;
		    cout<<"\nLa pergamena vuota hai pescato dalla tua casella non verrai spostato "<<endl;
						    }  
						}
		
	return (posiz);
	
}
