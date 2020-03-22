# Funciones para datos string
Las funciones que se van a enumerar a continuación pertenecen a la librería string, lo que implica que para que dichas funciones compilen se deberá agregar la librería `string.h`, en caso contrario el compilador no ejecutará la instrucción deseada. 
Empecemos:
1. `cadena.size()` - devuelve el tamaño de la cadena
1. `cadena.empty()` - devuelve 0 ***(Falso)***, es decir que no está vacía, ó 1 ***(True)*** en caso de que sí esté vacía. 
1. `cadena1.compare(cadena2)` - devuelve 0 si la cadena1 tiene la misma cantidad de caracteres que la cadena2, sino devuelve 1 cuando la cadena1 tiene más caracteres que la cadena2 o -1 en viceversa.
4. `cadena1.erase(inicio, cant)` - borra caracteres desde ***inicio*** que representa la posición desde la cual se quiere comenzar a borrar y ***cant*** representa la cantidad de caracteres que queremos borrar. Dichas variables son numéricas. 
5. `cadena1.assign(cadena2)` - copia toda la cadena2 en la cadena1.
6. `cadena1.assign(cadena2, inicio, cant)` - copia de la ***cadena2*** los caracteres indicados desde ***inicio*** y la cantidad (cant)*** que deseamos copiar en la cadena1.

Las funciones que no tengan referencias hacia algún ejemplo dentro de este apunte, quedará para que los realicen ustedes mismos en el entorno que quieran (DevC++, CodeBlocks o Visual Studio) y corroborar dichas funcionalidades.

Por otra parte, se pueden convertir tipos de datos alfanuméricos, como son los de tipo string, en tipos de datos numéricos, a saber como: double, float e int. Las funciones para convertir cadenas en números son:
* `stod(cadena)` - convierte una cadena en `double`.
* `stoi(cadena)` - convierte una cadena en `int`.
* `stof(cadena)` - convierte una cadena en `float`.

## Ejemplos
### Conversión de tipos de datos
A continuación, piense cuál sería la salida por consola del siguiente algoritmo y luego inténtelo ud. mismo para corroborar el resultado.
```cpp
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string cad3 = "24";
    cout << stoi(cad3) + 1 << endl;
    cout << stod(cad3) + 10 << endl;
    cout << stof(cad3) + 4 << endl;
    
    system("pause");
    return 0;
}
```
> **Para pensar**: ¿Puedo convertir tipos de datos numéricos en tipos de datos alfanuméricos?

### Funciones *size* - *empty*
Nuevamente reflexione cuál sería la salida del siguiente algoritmo.
```cpp
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string cadena1 = "Marcus";
    cout << "La cadena posee: "<< cadena1.size() << " caracteres" << endl;
    
    cout << "La cadena esta vacía?" << endl;
    if (cadena1.empty()==0){ cout << "No, no lo está" << endl;}
    else { cout << "Está vacía" << endl;}
    
    system("pause");
    return 0;    
}
```
En este caso la consola mostraría lo siguiente:
> La cadena posee: 6 caracteres
La cadena está vacía?
No, no lo está

### Función *erase*
```cpp
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string cadena1 = "Marcus";
    string cadena2 = "Reed";
    cout << "Caracteres que quedan" << endl;
    cout << cadena1.erase(0,2) << endl;
    
    system("pause");
    return 0;   
}
```
En la consola obtenemos la siguiente salida:
> Caracteres que quedan
rcus

Ahora bien, qué sucedería si quisiera sacar vocales o consonantes de una palabra dada. 
Analice el siguiente código:
```cpp
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string cad = "aabretu";
    int largo;
    largo = cad.size();
    for(int i = 0; i<largo; i++)
    {
        if (cad[i] == 'a'){ cout << cad[i]; }
    }
    system("pause");
    return 0;   
}
```
*¿Qué devuelve la por consola el algoritmo anteriormente presentado? ¿Funciona?*

Reflexione y haga un algoritmo para contar vocales de una palabra cualquiera ingresada por teclado tomando como base el algoritmo anterior. Trate de usar if para las vocales, ya que las consonantes son unas cuantas y tener una sentencia if de 2 km no es bueno para el compilador.

Por un momento, pensemos que tenemos muchas tareas para hacer con la cadena que nos ingresaron, como copiarlas en un lado, usar la mitad de la cadena en otro, sacar las consonantes, o bien encontrar un patrón en un texto (porque las cadenas pueden guardar oraciones enteras), ahí tendríamos un `main` bastante extenso y quizás hasta tedioso de leer para todo aquel que quisiera entender el código. Para ordenar un poco este chiquero se utilizan las funciones, dichas funciones pueden ser procedimientos, de tipo `void`, o pueden realizar una tarea y devolver un resultado en cualquier tipo de dato, por ejemplo podría hacer una suma de números de tipo `float` y devolver su resultado que también va a ser de tipo `float`, pero... Cómo agrego al algoritmo que acabamos de hacer una función? 

Pues es sencillo, lo agregamos de la siguiente manera:

```cpp
#include <iostream>
#include <string.h>
using namespace std;

void Devolucion(string cad)
{
    int largo;
    largo = cad.size();
    for(int i = 0; i<largo; i++)
    {
    if (cad[i] == 'a'){ cout << cad[i]; }
    }
}
int main()
{
    string cad = "aabretu";
    Devolucion(cad); //LLamado a funcion
    
    system("pause");
    return 0;
}    
```
Como se puede observar, la palabra `void` cambia de color porque es una palabra reservada para las funciones que son mas específicamente, procedimientos, es decir, que realizan múltiples tareas y devuelven múltiples resultados.

> ¿Y si quiero usar una función que me devuelva un tipo de dato? 

Para ello, tomemos una función que devuelve un saludo.
```cpp
#include <iostream>
#include <string.h>
using namespace std;

string Saludar(){
    return "Hola! Cómo estás?";
}
string Responder(){
    return "Todo bien y vos?";
}

int main()
{
    cout << Saludar() << endl;
    cout << Responder() << endl;
    
    system("pause");
    return 0;
}    
```
Tanto la función `Saludar` como la función `Responder`, muestran por pantalla una cadena de caracteres con sus espacios y sus signos de interrogación.

### Cuidados
Al trabajar con cadenas de caracteres del tipo string se suscitan errores muy extraños como por ejemplo `“unsigned const *char to const char”`, entre otros de la misma índole. Esto se debe a que los datos de tipo string son en realidad punteros que “apuntan” (valga la redundancia) a la memoria donde está ubicada una clase llamada `string` y con cada creación de esas variables estaríamos implementando un objeto... No se me pongan nerviosos, tomense un mate y relajen (pero no tanto), ya entenderemos más adelante qué hacer con esta wea de las clases, los objetos y los punteros.