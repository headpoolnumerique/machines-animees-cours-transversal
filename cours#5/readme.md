
# Cours#5 : Moteurs, librairies, et semi-conducteurs

![Servo Motor circuit Arduino](https://github.com/headpoolnumerique/machines-animees-cours-transversal/blob/main/cours%235/images/servo.png?raw=tru)

### 5.1 Moteur servo et librairie Servo 

Un moteur servo peut se déplacer à l'ordre de position via une impulsion et se place à l’angle demandé.

***Qu’est-ce qu’une librairie ?***

Un ensemble de code réutilisable qu'apporte des fonctionnalités prêtes à l’emploi, testées et documentées.

***Pourquoi utiliser une librairie Servo.h avec un servo ?***

Parce qu’un servo n’a pas besoin d’un PWM “classique”, mais d’impulsions très précises (≈1–2 ms, toutes ~20 ms). Servo.h :
génère ces impulsions au timing beaucoup plus régulier que delay() ou analogWrite()), et simplifie l'usage grâce à une série de fonctions pre-écrites : attach(), write(angle), writeMicroseconds(), detach() 

Comment utiliser : File > examples > Servo > Sweep (puis customiser le code)  

```
#include <Servo.h>

Servo myservo;  // create Servo object to control a servo
// twelve Servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the Servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}
```

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

![DC circuit Arduino](https://github.com/headpoolnumerique/machines-animees-cours-transversal/blob/main/cours%235/images/transistor_motor.png)

***Pourquoi un transistor/MOSFET avec un moteur + pile 9 V + Arduino ?*** 

**— Courant** : un moteur tire bien plus que 40 mA (limite d’une broche Arduino). Le transistor/MOSFET agit comme interrupteur de puissance commandé par l’Arduino.  
**— Tension séparée** : on alimente le moteur par la pile 9 V, pas par l’Arduino.  
**— Protection** : le moteur est inductif → il génère des pics de tension. On met une diode de roue libre (ex. 1N4007) en parallèle du moteur (cathode côté +9 V) pour protéger tout le monde.  
**— Masse commune** : relier GND Arduino et – de la pile. À quoi ça sert concrètement ? — (1) À ce que l’Arduino mesure/commande des tensions cohérentes pour le transistor/MOSFET. (2) À stabiliser le fonctionnement et éviter déclenchements fantômes, resets, surchauffe.

Exemple simple :  
```
const int PWM_PIN = 9;
void setup() { pinMode(PWM_PIN, OUTPUT); }
void loop()  { digitalWrite(PWM_PIN, HIGH); /* ... */ }
```

Exemple avec potentiometre :  
```
const int PWM_PIN = 9;   // broche ~PWM vers la gate
const int POT     = A0;  // potentiomètre

void setup() { pinMode(PWM_PIN, OUTPUT); }

void loop() {
  int v = analogRead(POT);           // 0..1023
  int duty = map(v, 0, 1023, 0, 255);
  analogWrite(PWM_PIN, duty);        // vitesse du moteur
}
```
