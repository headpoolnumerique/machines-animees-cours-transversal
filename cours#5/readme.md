
# Cours#5 : Moteurs, librairies, et semi-conducteurs

![Buzzer circuit Arduino](https://github.com/headpoolnumerique/machines-animees-cours-transversal/blob/main/cours%234/images/buzzer-circuit.png?raw=true)

### 5.1 Moteur servo et librairie Servo 

Un moteur servo peut se déplacer à l'ordre de position via une impulsion et se place à l’angle demandé.

***Qu’est-ce qu’une librairie ?***

Un ensemble de code réutilisable qu'apporte des fonctionnalités prêtes à l’emploi, testées et documentées.

***Pourquoi utiliser une librairie Servo.h avec un servo ?***

Parce qu’un servo n’a pas besoin d’un PWM “classique”, mais d’impulsions très précises (≈1–2 ms, toutes ~20 ms). Servo.h :
génère ces impulsions au timing beaucoup plus régulier que delay() ou analogWrite()), et simplifie l'usage grâce à une série de fonctions pre-écrites : attach(), write(angle), writeMicroseconds(), detach() 

Comment utiliser : File > examples > Servo > Sweep (puis customiser le code)  

***Comment inlcure une librairie ?***
1) Reprendre depuis un code exemple : File > examples > [nom de la librairie] > [example souhaité]
2) Inclure juste la librairie : Sketch > Include library > [nom de la librairie]  

***Comment installer une librairie ?***

1) Par le Library Manager (recommandé) :  
Sketch ▸ Include Library ▸ Manage Libraries  
Dans le code : #include <NomDeLaLibrairie.h>  

2) Depuis un fichier .zip (i.e. téléchargé depuis GitHub, etc.)
Sketch ▸ Include Library ▸ Add .ZIP Library  
Sélectionne le .zip téléchargé.  
Dans le code : #include <NomDeLaLibrairie.h>  

3) Installation manuelle
Décompresse la librairie dans Documents/Arduino/libraries/[librairie]/
Redémarre l’IDE si besoin, puis #include <NomDeLaLibrairie.h>.

### 5.2 Moteur DC et transistor (semi-conducteur)

![DC circuit Arduino](https://github.com/headpoolnumerique/machines-animees-cours-transversal/blob/main/cours%235/images/servo.png?raw=true)

