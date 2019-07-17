// Ejercicio Combate x Turnos
#include <iostream>
#include <string>
#include "Guerreros.h"

using namespace std;

// nCombate representa el n° de combate que se lleva a cabo
void Combate(Guerreros &pj, Guerreros &enemigo, int nCombate);

int main()
{
// Test 1 ------------------------------
	Infanteria pj1("Hacha");
	Arquero enemy1;
	Combate(pj1,enemy1,1);	
// Test 2 ------------------------------    
	Caballeria pj2("Lanza");
	Infanteria enemy2("Mandoble");
	Combate(pj2,enemy2,2);
// Test 3 ------------------------------
	Arquero pj3;
	Caballeria enemy3("Espada corta");
	Combate(pj3,enemy3,3);
// -------------------------------------	
	
	system("pause");
    return 0;
}

void Combate(Guerreros &pj, Guerreros &enemigo, int nCombate){
	cout<<"Combate N: "<<nCombate<<endl;
	
	pj.Estado();
	enemigo.Estado();	
		
	while(true){	
		pj.Atacar(enemigo);
		if (enemigo.getVida()<=0){
			break;
		}
		
		enemigo.Atacar(pj);	
		if(pj.getVida()<=0){
			break;
		}
	}
	
	cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"Estado del Combate: "<<nCombate<<endl;
	cout<<"Jugador tiene "<<pj.getVida()<<" vida"<<endl;
	cout<<"Enemigo tiene "<<enemigo.getVida()<<" vida"<<endl;
	cout<<"/////////////////////////////////////"<<endl;
}
