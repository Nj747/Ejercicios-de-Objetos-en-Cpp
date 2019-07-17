#include <iostream>
#include <string>

using namespace std;

class Guerreros{
    protected:
        string tipoArma;
        string tipoGuerrero;
        int vida;
    public:
        Guerreros(){}
        ~Guerreros(){}
        
        void Atacar(Guerreros &guerrero){
        	if (tipoGuerrero=="Infanteria"){
        
        		if (tipoArma == "Mandoble"){
        			// resto 25
        			guerrero.vida = guerrero.vida - 25;
				}
				else if(tipoArma == "Hacha"){
					//resto 10
					guerrero.vida = guerrero.vida - 10;
				}
			}	
			else if (tipoGuerrero == "Caballeria"){
				
				if (tipoArma == "Espada corta"){
					// resto 20
					guerrero.vida = guerrero.vida - 20;
					
				}
				else if (tipoArma == "Lanza"){
					// resto 30
					guerrero.vida = guerrero.vida - 30;
				}
			}
			else if(tipoGuerrero=="Arquero"){

				guerrero.vida = guerrero.vida - 5;
			}
		}
		
		int getVida(){return vida;}
		
		// devuelve el tipoGuerrero, vida y tipoArma todos juntos.
		void Estado(){
			cout<<"--------------------------------"<<endl;
			cout<<"Tipo de guerrero: "<<tipoGuerrero<<endl;
			cout<<"Vida: "<<vida<<endl;
			cout<<"Tipo de arma: "<<tipoArma<<endl;
			cout<<"--------------------------------"<<endl;
		}
};

class Infanteria : public Guerreros{
    public:
        Infanteria(string arma){
			Guerreros::tipoArma = arma;
			Guerreros::vida = 100;
			Guerreros::tipoGuerrero = "Infanteria"; 
		}
        ~Infanteria(){}
};

class Caballeria : public Guerreros{
    public:
        // Constructor que acepta por parámetro el tipo de arma
		Caballeria(string arma){
			Guerreros::tipoArma = arma;
			Guerreros::vida = 150;
			Guerreros::tipoGuerrero = "Caballeria";
		}
		~Caballeria(){}
};

class Arquero : public Guerreros{
    public:
        Arquero(){
			Guerreros::vida = 200;
			Guerreros::tipoGuerrero = "Arquero";
			Guerreros::tipoArma = "Arco";
		}
        ~Arquero(){}
};
