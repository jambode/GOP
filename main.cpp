#include <iostream>
#include <ctime>
#include <cstdlib>
#include "inizializza_gioco.h"



using namespace std;

int main(){
	char start;
    inizializza_gioco init;
    init.decidi_numero_giocatori();
    init.inizializza_player();
    int num_player = init.return_num_giocatori();
   
   
    srand(time(0));       //permette di generare numeri random
    
    
    while(start != 'a'){
		cout<<"premi a per iniziare "<<endl;
		cin>>start;
		if(start=='a')
			init.fai_turno(num_player);
		else 
			cout<<"INPUT NON VALIDO"<<"\n";
   	}
     
    return 0;
}
