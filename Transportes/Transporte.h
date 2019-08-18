#include <iostream>
#include <string>

using namespace std;

class Transporte{
	private:
		string tipo;
		int cantPasajeros;
		float precioBoleto;
		int maxCap;
		int personasFuera;
		
		float CalcularRecaudacion();
		void Disponibilidad(int cant);
	public:
		Transporte(string t, int cant);
		Transporte(string t, int cant, int v);
		void MostrarRecaudacion();
		void MostrarDatos();
		~Transporte(){}
};


float Transporte::CalcularRecaudacion(){
	return precioBoleto * cantPasajeros;
}

void Transporte::Disponibilidad(int cant){
	if ((maxCap - cant) >= 0){
		cantPasajeros = cant;
		personasFuera = 0;
	}	
	else{
		personasFuera = cant - maxCap;
		cantPasajeros = maxCap;
	}
}

Transporte::Transporte(string t, int cant){
	maxCap = 50;
	tipo = t;
	precioBoleto = 20;
	Disponibilidad(cant);
}

Transporte::Transporte(string t, int cant, int v){
	
// como es un subte su capacidad depende de la cantidad de vagones
	maxCap = 50*v; 
	tipo = t;
	precioBoleto = 15;
	Disponibilidad(cant);	
}

void Transporte::MostrarRecaudacion(){
	cout<<"La recaudacion total del "<<tipo<<" es de "<<CalcularRecaudacion()<<" pesos"<<endl;
}

void Transporte::MostrarDatos(){
	cout<<"-------------------------------------------------"<<endl;
	cout<<"Transporte: "<<tipo<<endl;
	cout<<"Cantidad de Pasajeros dentro del transporte: "<<cantPasajeros<<endl;
	cout<<"Maxima Capacidad: "<<maxCap<<endl;
	cout<<"Personas que quedaron fuera del transporte son: "<<personasFuera<<endl;
}
