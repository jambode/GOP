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
void  mazzo::crea_mazzo(){ // costruttore : le 40 carte saranno inizializzate ciclicamente da 0......5
		int i=0;
		for(int t=0; t<NUMCARTE;t++){
		
		if (i<6){
			mazzo_carte[t]->setvalore(i) ;
	     	mazzo_carte[t]->setstringa(msg_carte(i)); //associa alla carta il msg associato al suo numeri funzione che sta in messaggi.cpp
		
			i++;
		} else{
				i=0;
				mazzo_carte[t]->setvalore(i) ;
				mazzo_carte[t]->setstringa(msg_carte( i));//associa alla carta il msg associato al suo numeroi
				i++;
		}
	}
	};
	
		

	
	
// TESTATO OK	
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
		carta *temp;
		temp = mazzo_carte[i];
		mazzo_carte[i]=mazzo_carte[j];
		mazzo_carte[j]=temp;
	}
	
	
// estrae la prima carta e la rimette in fondo al mazzo = ultima  posizione	del mazzo
// facendo slittare in avanti di una posizione tutti gli altri

	carta mazzo::estrai_in_cima(){
		carta *temp;
	
	    temp=mazzo_carte[0];  // estraggo la prima ( poi la rimetto  in fondo)
	  //TEST
	    temp->stampa_carta();
	    
		int j=1;
	    for(int i=0;i<NUMCARTE-1; i++) // faccio slittare di uno a sinistra tutto l'array
	   	  mazzo_carte[i]=mazzo_carte[j++];
	   	 // TEST
			 cout<< "\n DOPO FOR  \n"; 
			 cout<< "   j= " << j ;
	   	  
	   	mazzo_carte[j-1] =temp; //copio l'elemento selezionato nell'ultima posizione
	   	mazzo_carte[j-1]->stampa_carta();
		return(*temp);
	};
	
	void mazzo::inserisci_in_fondo(){
	};

// serve per i test
#define CARTE_DA_STAMPARE 40
void mazzo::stampa_mazzo()
{
//int temp;  non serve  ...serviva nell'altra implementazione 
string temp_string;


for(int i=0;i< CARTE_DA_STAMPARE; i++){
	
/* altra implementazione, ok anche questa
temp = mazzo_carte[i].getvalore();
  cout<< temp  <<"  ";
*/
  cout<< mazzo_carte[i]->getvalore()<<"   ";
  
  cout <<mazzo_carte[i]->getmsg() <<"\n";
  
}

};

/*
carta mazzo::estrai_carta(int i ){
return  mazzo_carte[i];
};

*/




// il mazzo viene implementato come una classe :un array di cartE E I vari metodi





