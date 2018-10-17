#include<iostream>
#include "effetti.h"

using namespace std;



int effetti::tira_di_nuovo(){
		int dice = d.lancia_dado();
		cout<<"lancio dado seconda volta.."<<dice<<endl;
		return dice;
}

int effetti::vai_avanti(int pos){
	int dice = d.lancia_dado();
	cout<<"CASELLA FORTUNATA!! "<<"avanza di "<<dice<<endl;
	pos =	pos+dice;
	return pos;
}
/*
void effetti::salta_turno(){
	
}
*/
void effetti::pesca_carta(){
    m.crea_mazzo();
    cout<<"CARTA ESTRATTA: "<<endl;
	card = m.estrai_in_cima();
	//card.stampa_carta();
}

/*
void effetti::salta_turno(){
	cout<<"STOP per un turno :( "<<endl;
}
*/

//RITORNA UN NUMERO E IL GIOCATORE VA AVANTI/INDIETRO IN BASE A QUEL NUMERO
int effetti::fortuna(int num){
	//cout<<"FORTUNA O SFORTUNA? ";   messo nella funzione a parte

	
	int player_pos = rand()%num+1;
	
	return player_pos;
}

void gestisci_carta(){
	mazzo m;
	effetti e;
	player p;
	inizializza_giocatori iniz;
	carta carta_corrente;
	m.estrai_in_cima();
	int k=3; 
	bool result;
	int n=carta_corrente.getvalore();

	switch (n){
		case 0:e.tira_di_nuovo();// ritira dado
			break;
		case 1://vai avanti   
			cout<<"vai avanti di 3 caselle"<<endl;                                                                   
			if ((pos+k)>=p[i]->pos /* ultima casella*/){
				pos= (2*(p[i]->pos)-(pos+k));//se il n del dado è troppo per arrivare alla fine del tabellone
			}
			else 
				pos=pos+k; 
			return pos;                                                  
			}
			break;
		case 2: 
			p.pos=0; //torna alla casella di partenza
			break;
		case 3://stai fermo un turno
				bool fermo=flase;
				counter=0;
				if (n!=3){ //se la carta non ha il messaggio "salta turno"
					fermo==false;
					for (counter<=num_giocatori){			 
					 iniz.turni();//fai turno normale 
					counter ++;
			 			}
				}
			 	else if (c.valore==3){ //la carta ha il messaggio "salta turno"
			 		fermo==true;
			 		while (counter!= iniz.num_giocatori){
			 				for(counter!= /*numero giocatore che becca il salto)*/, couter++){
							iniz.turni();//esegui il turno
			 				}
			 			counter ++;
					}}
			break;
		case 4:
			cout<<"vai indietro di 3 caselle"<<endl;                                                                   
			if ((pos-k)<= 0 /*prima casella*/){
				pos=0; //se il numero viene negativo prende 0
			}
			else 
				pos=pos-k; 
			return pos;                                                  
			}
			break;
		case 5://rispondi alla domanda
				result= gestione_domanda();
	        	if (result==true){
	            	e.vai_avanti();
	             	} 
			 	else {
				   e.vai_indietro();
				 } 
		  	    break;
	

			break; 
} 
	return ;
}
#endif 
