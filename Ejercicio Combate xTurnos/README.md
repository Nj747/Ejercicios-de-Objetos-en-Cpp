# Combate por Turnos
Se desea hacer un algoritmo que simule un combate por turnos entre 2 guerreros medievales. 
Para ello el usuario podrá elegir entre *3 tipos de guerreros*: ***infantería***, ***caballería*** y ***arquero***. 
Cada una de estas clases tienen una cantidad de vida determinada, un daño y en algunos casos se puede elegir entre más de un arma. 

Esta información se muestra en la siguiente tabla:

Guerrero   | Arma               | Daño del arma | Vida
---|---|---|---
Infantería | Mandoble/Hacha     | 25/10 pts     | 100
Caballería | Espada corta/Lanza |20/30 pts      | 150
Arquero    | Arco y flechas     |5 pts          | 200

En la implementación deberá probar distintos casos, estos serán:
* Infantería con Hacha vs Arquero
* Caballería con Lanza vs Infantería con Mandoble
* Arquero vs Caballería con Espada corta

Hacer una función externa llamada Combate que haga un loop hasta que alguno de los combatientes muera (puede usar un *while* o un *repeat*
). 
Usar dicha función para los 3 combates.

***En el final de cada combate deberá mostrar cuál es la vida restante del jugador y del enemigo, verificar quién ha ganado el combate y si es lo que esperaba de dicha prueba.***
