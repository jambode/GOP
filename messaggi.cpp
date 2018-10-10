// TESTATO OK   messaggi relativi alle carte o alle caselle tabellone

#include <iostream>
#include <string>

using namespace std;

string  msg_carte(int num){
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
		case 5:  str= "rispondi alla domanda";	
		  	    break;
		default: str="errore" 	;
		
		 	    
	}
	return str;
}
