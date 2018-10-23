//carta.cpp
using namespace std;


void carta::set_valore(){
	valore = rand()%40+1;
}

void carta::set_message(string m){
 	msg = m;
	}


int carta::getvalore(){
	return valore;
}

string carta::getmsg(){
	return msg;
}


void carta::stampa_carta (){
	cout<<"messaggio =  "<<msg <<"\n";		
}
