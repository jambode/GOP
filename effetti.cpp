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
	cout<<"FORTUNA O SFORTUNA? ";
	//cout<<"FORTUNA O SFORTUNA? ";   messo nella funzione a parte
 	
	int player_pos = rand()%num+1;
 	
 	return player_pos;
 }
