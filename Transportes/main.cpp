#include <iostream>
#include <string>
#include "Transporte.h"

using namespace std;

int main() {
	
	Transporte t1("colectivo",20);
	t1.MostrarDatos();
	t1.MostrarRecaudacion();
	
	Transporte t2("subte",70,2);
	t2.MostrarDatos();
	t2.MostrarRecaudacion();
	
	Transporte t3("colectivo",100);
	t3.MostrarDatos();	
	t3.MostrarRecaudacion();
	
	Transporte t4("subte",70,1);
	t4.MostrarDatos();	
	t4.MostrarRecaudacion();
	
	system("pause");
	return 0;
}
