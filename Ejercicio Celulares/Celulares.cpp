// Ejercicio Celulares
#include <iostream>
#include <string>
using namespace std;

class Celulares{
    private:
        float bateria;
        string marca;
    public:
        Celulares(string m){
            marca = m;
            bateria = 5; //arranca cargado
        }
        string getMarca(){return marca;}
        void recargarBateria(){bateria = 5;} // suponemos que lo recarga a su máxima capacidad
        float getBateria(){return bateria;}
        
        void descargarBateria(){
            if (marca == "Motorola"){
                bateria = bateria - 0.25;
            }
            else if (marca == "Iphone"){
                bateria = bateria - 0.10;
            }
        }
};

class Personas{
    private:
        //string tipocel;
        string nombre;
        Celulares *cel; //puntero que va a almacenar la dirección de memoria del objeto celular
        float factura;
        string empresa;
    public:
        Personas(string n, Celulares &celular, string emp){
            cel = &celular; // asigno un puntero de tipo celulares a la dire de memoria
            //celular.setBateria(5);
            //tipocel = celular.getMarca();
            nombre = n;
            empresa = emp;
            factura = 0; 
        }
        
        string getNombre(){
            return nombre;    
        }
        
        string getTipoCel(){
            return cel->getMarca();    
        }
        
        void Llamar(Personas &persona, float duracion){
            cout<<getNombre()<<" esta llamando a "<<persona.getNombre()<<endl;
            cel->descargarBateria();
            if (empresa == "Movistar"){factura = factura + 0.50 * duracion;}
            else if (empresa == "Claro"){factura = factura + 0.60*duracion;}
        }
        
        void cuantoPagar(){
            cout<<getNombre()<<" debe pagar $"<<factura<<endl;        
        }
};

int main()
{
// PRUEBO INSTANCIAS PARTICULARES ---- Test 1 ---------------------------------------------------------------------
    // instancio los objetos
    Celulares celM("Motorola");
    Celulares celI("Iphone");
    
    // le doy el celular que corresponde a la persona indicada por el enunciado
    Personas juli("Juliana",celM, "Movistar"); 
    Personas cata("Catalina",celI,"Claro"); 
    
    cout<<juli.getNombre()<<" tiene un "<<juli.getTipoCel()<<" con "<<celM.getBateria()<<" puntos de bateria"<<endl;
    juli.Llamar(cata,2);
    juli.Llamar(cata,2);
    juli.Llamar(cata,2);
    juli.Llamar(cata,4);
    cout<<"la bateria del celu de "<<juli.getNombre()<<" tiene "<<celM.getBateria()<<endl;
    cata.Llamar(juli,5);
    cata.Llamar(juli,4);
    cata.Llamar(juli,6);
    cata.Llamar(juli,10);
    cout<<"la bateria del celu de "<<cata.getNombre()<<" tiene "<<celI.getBateria()<<endl;
    
    juli.cuantoPagar();
    cata.cuantoPagar();
//------------------------------------------------------------------------------------------------------------------
    system("pause");
    return 0;
}
