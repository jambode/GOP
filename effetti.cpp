//effetti.cpp
 
using namespace std;
 
 
 //lancia il dado una seconda volta
 int effetti::tira_di_nuovo(){
 		int dice = d.lancia_dado();
 		cout<<"lancio dado seconda volta.."<<dice<<endl;
 		return dice;
 }
 
 //il giocatore viene spostato in una casella in modo random
 int effetti::vai_avanti(int num){
 	int num_cas = rand()%num+1;
 	cout<<"SABBIE MOBILI, ATTENZIONE! Vai alla casella "<<num_cas<<endl;
 	return num_cas;
 }


 //RITORNA UN NUMERO E IL GIOCATORE VA AVANTI/INDIETRO IN BASE A QUEL NUMERO
int effetti::fortuna(int num){
	cout<<"FORTUNA O SFORTUNA? ";
	int player_pos = rand()%num+1;
 	return player_pos;
 }
