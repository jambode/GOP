#include <cstring>
#include <iostream> 
#include<ctime> // per time()
#include<cstdlib>
#include "mazzo_carte.h"

using namespace std;


string  mazzo::msg_carte(int num){
	string	str;
	switch (num){
		case 0:	str ="ritira il dado";
				break;
		case 1:  str= "salta il turno";	
		  	    break;
		case 2:  str= "ritorna alla casell 0";	
		  	    break;
		case 3:  str= "fai 3 passi in avanti";	
		  	    break;
		case 4:  str= "fai 3 passi indietro";	
		  	    break;
		case 5:  str= "scambia il posto con il giocatore precedente";	
		  	    break;
		default: str="errore" 	;
		
		 	    
	}
	return str;
}

mazzo::mazzo(){
}

// TESTATO OK
void  mazzo::crea_mazzo(){ // costruttore : le 40 carte saranno inizializzate ciclicamente da 0......5              //FUNZIONA
        for(int i = 0; i<NUMCARTE; i++){
        	carte[i].set_valore();
        	carte[i].set_message(msg_carte(i));
        	carte[i].stampa_carta();
		}  
	  	};
	
		

	
	
// TESTATO OK	
void mazzo::mischia_mazzo(){           //FUNZIONA
		int t=0;
		int j=0;
		srand(time(NULL));
		for(int i=0;i<40; i++){
			t=rand()%NUMCARTE;
			j=rand()%NUMCARTE;
			scambia_carta( t, j );
		}
		
	};
	
	void mazzo::scambia_carta(int i, int j ){     //FUNZIONA
		carta temp;
		temp = carte[i];
		carte[i]=carte[j];
		carte[j]=temp;
	}
	
	
// estrae la prima carta e la rimette in fondo al mazzo = ultima  posizione	del mazzo
// facendo slittare in avanti di una posizione tutti gli altri

	carta mazzo::estrai_in_cima(){               //FUNZIONA
		
	
	    temp=carte[0];  // estraggo la prima ( poi la rimetto  in fondo)
	  //TEST
	    temp.stampa_carta();
	    
		int j=1;
	    for(int i=0;i<NUMCARTE-1; i++) // faccio slittare di uno a sinistra tutto l'array
	   	  carte[i]=carte[j++];
	   	 // TEST
	   	 cout<<"\n"<<"\n";
	   	carte[j-1] =temp; //copio l'elemento selezionato nell'ultima posizione
	   	carte[j-1].stampa_carta();
		return(temp);
	};
	
	
	
	void mazzo::inserisci_in_fondo(){
		
	};

// serve per i test
#define CARTE_DA_STAMPARE 40
void mazzo::stampa_mazzo(){             //FUNZIONA
	for(int i =0; i<NUMCARTE; i++){
		carte[i].stampa_carta();
	}
}
/*
int temp;  non serve  ...serviva nell'altra implementazione 
string temp_string;

for(int i=0;i< CARTE_DA_STAMPARE; i++){
	
 altra implementazione, ok anche questa
temp = carte[i].getvalore();
  cout<< temp  <<"  ";

  cout<< carte[i].getvalore()<<"   ";
  
  cout <<carte[i].getmsg() <<"\n";
  
}

};
*/

carta mazzo::estrai_carta(int i){      //FUNZIONA
	carta estr = carte[i-1];
    estr.stampa_carta();
    
};






// il mazzo viene implementato come una classe :un array di cartE E I vari metodi





