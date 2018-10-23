//mazzo_carte.cpp
using namespace std;


string  mazzo::msg_carte(int num){
	string	str;
	bool result;
	switch (num){
		case 0:	str = "ritira il dado";
				break;
				
		case 1:  str = "rispondi alla domanda";
		  	    break;
		  	    
		case 2: str = "ritorna alla casella di partenza";
		  	    break;
		  	    
		case 3: str = "fai 3 passi in avanti";	
		  	    break;
		  	    
		case 4: str = "fai 3 passi indietro";
				break;
				
		case 5: str = "scambia posizione con un altro giocatore";	
		  	    break;	    
		  	    
		default: cout<<"errore" 	;
		
		 	    
	}
	return str;
}

mazzo::mazzo(){
}


void  mazzo::crea_mazzo(){ // costruttore : le 40 carte saranno inizializzate ciclicamente da 0......5              
           int i=0;
		for(int t=0; t<NUMCARTE;t++){
		    if(i<6){
			carte[t].set_valore() ;
			carte[t].set_message(msg_carte(i));//associa alla carta il msg associato al suo numeri funzione che sta in messaggi.cpp
			i++;
		}
		else {
			i = 0;
			carte[t].set_valore();
			carte[t].set_message(msg_carte(i));
			i++;
		}
	}
}
	
	
		

	
	
void mazzo::mischia_mazzo(){           
		int t=0;
		int j=0;
		srand(time(NULL));
		for(int i=0;i<40; i++){
			t=rand()%NUMCARTE;
			j=rand()%NUMCARTE;
			scambia_carta( t, j );
		}
		
	};
	
	void mazzo::scambia_carta(int i, int j ){
		carta temp;
		temp = carte[i];
		carte[i]=carte[j];
		carte[j]=temp;
	}
	
	
// estrae la prima carta e la rimette in fondo al mazzo = ultima  posizione	del mazzo
// facendo slittare in avanti di una posizione tutti gli altri

	carta mazzo::estrai_in_cima(){               
		
	    temp=carte[0];  // estraggo la prima ( poi la rimetto  in fondo)
	  //TEST
	    //temp.stampa_carta();
	    
		int j=1;
	    for(int i=0;i<NUMCARTE-1; i++) // faccio slittare di uno a sinistra tutto l'array
	   	  carte[i]=carte[j++];
	   	 // TEST
	   	 cout<<"\n";
	   	carte[j-1] =temp; //copio l'elemento selezionato nell'ultima posizione
	   	//carte[j-1].stampa_carta();
		return(temp);
	};
	
	


void mazzo::stampa_mazzo(){             
	for(int i =0; i<NUMCARTE; i++){
		carte[i].stampa_carta();
	}
}

carta mazzo::estrai_carta(int i){
	carta estr = carte[i-1];
    estr.stampa_carta();
    
}


int mazzo::pesca_carta(){
    int val;
    carta card;
    mischia_mazzo();
    cout<<"\n"<<"\n";
    stampa_mazzo();
    cout<<"CARTA ESTRATTA: "<<endl;
 	card = estrai_in_cima();
 	val = card.getvalore();

	return (val);
	}




domanda vect_dom[NUM_TOT_DOM]={
	/*1° domanda*/{"Se lo alimenti vive, se gli dai da bere muore ",/* lista risposte*/{
						" a - Gas ",
						" b - Fuoco ",
						" c - Caldo",
						" d - Fumo"	}, /* fine lista risposte 1° domanda*/ 
		/*risposta esatta*/ 'b'},/*fine 1° domanda
						
	/*2° domanda*/{"Piange senza voce, Fluttua senza ali, Morde senza denti, Mormora senza bocca. ", /* lista risposte*/{
						" a - La Frana",
						" b - Il tornado",
						" c - Il vento",
						" d - La valanga"	}, /* fine lista risposte 2° domanda*/ 
		/*risposta esatta*/ 'c'},/*fine 2° domanda
		
	/*3° domanda*/{"Mi muovo in cerchi, Ma vado sempre avanti. Non mi lamento mai, Non importa dove sono condotta. ", /* lista risposte*/{
						" a - La ruota",
						" b - La girandola",
						" c - L'aquilone",
						" d - Il ventilatore"	}, /* fine lista risposte 2° domanda*/ 
		/*risposta esatta*/ 'a'},/*fine 3° domanda
		
	/*4° domanda*/{"Ha radici che nessuno vede. Supera ogni albero. Sale verso l'alto ma non cresce mai. ", /* lista risposte*/{
						" a - La roccia",
						" b - La collina",
						" c - La quercia",
						" d - La montagna"	}, /* fine lista risposte 2° domanda*/ 
		/*risposta esatta*/ 'd'},/*fine 4° domanda	
 	/*5° domanda*/{"Vado avanti vado indietro corro e mi fermo ma non cambio mai di posto. Chi sono? ", /* lista risposte*/{
						" a - La lancetta",
						" b - La freccia",
						" c - Il pendolo",
						" d - Il treno"	}, /* fine lista risposte 2° domanda*/ 
		/*risposta esatta*/ 'c'},/*fine 5° domanda
	
	/*6° domanda*/{"Nel calendario alcuni mesi hanno 30 giorni, altri 31. Quanti mesi hanno 28 giorni? ", /* lista risposte*/{
						" a - Nessuno",
						" b - Uno",
						" c - Tutti",
						" d - Quattro"	}, /* fine lista risposte 2° domanda*/ 
		/*risposta esatta*/ 'b'},/*fine 6° domanda	
 	/*7° domanda*/{"Tutti mi sanno saprire, nessuno mi sa richiudere, non sto in piedi dritto e se mi rompi, a volte, sono fritto, chi sono?", /* lista risposte*/{
						" a - L'uovo",
						" b - La busta",
						" c - La bottiglia",
						" d - Il cocco"	}, /* fine lista risposte 2° domanda*/ 
		/*risposta esatta*/ 'a'},/*fine 7° domanda	
		
	/*8° domanda*/{"Quando sono in piedi loro sono sdraiati, quando sono sdraiato loro sono in piedi. Chi sono? ", /* lista risposte*/{
						" a - I capelli",
						" b - I vestiti",
						" c - I gomiti",
						" d - I piedi"	}, /* fine lista risposte 2° domanda*/ 
		/*risposta esatta*/ 'd'},/*fine 8° domanda	
 	/*9° domanda*/{"Lo puoi piantare, ma non crescera'; ha una testa ma mai ragionera', chi e'?", /* lista risposte*/{
						" a - Il moscerino",
						" b - Il chiodo",
						" c - Il seme",
						" d - L'asso"	}, /* fine lista risposte 2° domanda*/ 
		/*risposta esatta*/ 'b'},/*fine 9° domanda	
						
	/*ULTIMA domanda*/{"Esisto fino a quando hai vita Ma se mi perdi non c'e' più vita! ", /* lista risposte*/{
						" a - La speranza ",
						" b - La gioia ",
						" c - La tristezza",
						" d - L'angoscia"},   /* fine lista risposte ULTIMA domanda X*/ 
		/*risposta esatta*/ 'a'}/*fine ULTIMA domandaV*/
	};// Fine array domande
	
/* 
   Funzione che gestisce le domande :
	1) sceglie una domanda A CASO  tra le NUM_DOM
	2) viualizza il testo della domanda e delle possibili risposte 
	3) gestisce la risposta :  legge la risposta
			controlla se è esatta 
			ritorna TRUE se è OK FALSE se è errata
                NOTA :    (SI POTREBBE PENSARE DI FARE GESTIRE LE AZIONI CORRISPONDENTI: 
		 N PASSI AVANTI   o N PASSI INDIETRO  direttamente QUI)
	*/
	
	
	
bool mazzo::gestione_domanda(){
    int num_dom;   //indicherà il numero della domanda da fare  sarà  0<  num_dom  <NUM_TOT_DOM
    char risp=' ';
	
 	num_dom = (rand() % NUM_TOT_DOM) ;
	cout<<" domanda num:  "   << num_dom<<endl;
 	cout<< vect_dom[num_dom].doman<< endl <<endl;
    for(int i=0;i<NUM_RISP;i++){
     	cout<< vect_dom[num_dom].risposta[i]<< endl ;
	}
        cout<<endl;
 	// GESTIONE RISPOSTA 
 	cout<< "INSERIRE LA RISPOSTA ESATTA (inserire  la lettera corrispondente : a,b,c,d  )  :   ";
	cin>> risp;
	while(cin.fail()|| risp<'a'||risp>'d'){
		cout<< " Imput non valido"<<endl<<endl;
		cout<<"  Inserire una delle seguenti lettere minuscole : a,b,c,d  :  ";
		cin>>risp;
	} /* End while controllo risposta valida*/
 	if(risp==vect_dom[num_dom].risp_esatta){ 
	// RISPOSTA ESATTA
		cout<<" Risposta esatta !!! "<<endl<<endl;
		cin.ignore();  
		// viene eventualmente invocata la funzione che gestisce la risposta esatta  oppure return true
		return true;
	}
	else{
		// RISPOSTA ERRATA
		cout<<" Risposta e' errata  !!! "<<endl<<endl;
		cin.ignore();  
		// viene eventualmente invocata la funzione che gestisce la risposta esatta  oppure return true
		return false;
	}
 }



// il mazzo viene implementato come una classe :un array di carte e i vari metodi
