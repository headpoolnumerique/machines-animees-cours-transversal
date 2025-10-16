
# Cours#3 : Inputs (Digital/Analogique) / Outputs (Digital/Digital PWM)

### 3.1 Différents inputs et outputs arduino

**En résumé:**  
  
— ***Digital IN*** lit 0/1 (LOW/HIGH)  
— ***Digital OUT*** écrit 0/1 (LOW/HIGH)  
— ***Analogique*** lit une tension (Valeur 0-1024)  
— ***PWM OUT*** écrit une moyenne de tension via commutation rapide (Valeur 0-1024)  

**~**  

**Digital IN (entrée numérique)**  
Lit un état 0/1 (LOW/HIGH). Utilise pinMode(pin, INPUT/INPUT_PULLUP) + digitalRead(pin).  
⚠️ Nécessite souvent une résistance de pull-up/pull-down pour éviter un état flottant.  

**Digital OUT (sortie numérique)**  
Force un état 0/1 sur la broche: digitalWrite(pin, LOW/HIGH) après pinMode(pin, OUTPUT).  

**Analogique (entrée analogique / ADC)**  
Mesure une tension continue entre 0 V et Vref (souvent 5 V ou 3,3 V) et la convertit en valeur numérique (typ. 10 bits → 0–1023): analogRead(Ax).  
Permet de lire capteurs de tension, potentiomètres, etc.  

**PWM OUT (sortie PWM, pseudo-analogique)**  
Sortie numérique commutée très vite avec un rapport cyclique variable: analogWrite(pin, 0–255) sur pins PWM (~490/980 Hz selon carte).  
Donne une moyenne équivalente à une tension analogique (utile pour LED, vitesse moteur). Ce n’est pas une vraie sortie DAC; pour une tension lisse, ajouter un filtre RC.  

—  

### 3.2 Exemples
  
#### 3.2.1 Bouton (entrée numérique ON/OFF –> digitalRead)

⚠️ Pour un boutton, il faut une resistance pull-up (ou pull-down) parce qu’une entrée Arduino, si elle n’est reliée à rien, elle “flotte”. Elle capte du bruit (EMI), des fuites, des charges parasites et oscille aléatoirement entre HIGH et LOW.  

***Montage OPTION #1***  
Câblage “pull-up” interne (le plus simple) : bouton entre pin et GND, activer la résistance interne.  
→ pinMode(pin, INPUT_PULLUP);  

![Bouton Int-Pull-Up](https://github.com/headpoolnumerique/machines-animees-cours-transversal/blob/main/cours%233/images/button_int_pullup.png?raw=true)

```
void setup(){ pinMode(2, INPUT_PULLUP); }
void loop(){
  if(digitalRead(2)==LOW){ /* appuyé */ }
}
```


***Montage OPTION #2***  
Câblage “pull-down” externe : bouton entre Vcc et pin, résistance ~10 kΩ entre pin et GND.
→ pinMode(pin, INPUT); puis digitalRead(pin) vaut HIGH quand on appuie.

![Bouton Int-Pull-Up](https://github.com/headpoolnumerique/machines-animees-cours-transversal/blob/main/cours%233/images/button_ext_pullup.png?raw=true)

```
void setup(){ pinMode(2, INPUT); }
void loop(){
  if(digitalRead(2)==HIGH){ /* appuyé */ }
}
```

#### 3.2.2 Capteur de lumière - LDR (entrée analogique 0-1024)

Un capteur de lumière consiste en une petite “résistance qui change avec la lumière”. Plus il y a de lumière, plus elle laisse passer le courant (sa résistance baisse).

Installation (pont diviseur) en image mentale :  
Une échelle entre + (Vcc) et – (GND). Au milieu de l’échelle, on prend la mesure (pin A0). Les deux “barreaux” de l’échelle sont :  

— le capteur (qui change avec la lumière)  
— une deuxième résistance fixe (par ex. 10 kΩ)  

Comment choisir la résistance fixe ?
Prendre 10 kΩ pour commencer. Si le capteur se situe surtout dans une ambiance donnée (studio, scène, dehors), choisir une valeur proche du capteur dans cette ambiance pour avoir une sensibilité correcte. (Pas besoin de maths : tester 4.7 kΩ, 10 kΩ, 47 kΩ et garder celle qui te donne une bonne variation.)

![capteur lumiere](https://github.com/headpoolnumerique/machines-animees-cours-transversal/blob/main/cours%233/images/light_sensor.png?raw=true)

```
analogRead(A0); // 0 (sombre) à 1023 (clair)
```
⚠️ Pour analogRead (au contraire de digitalRead) pas besoin de définir le comme input dans void Setup car les entrées analogiques servent que comme des input.   

#### 3.2.3 LED ON/OFF + PWM

Digital OUT (ON/OFF) : 
```pinMode(9, OUTPUT); digitalWrite(LED,HIGH/LOW);```  
—> Allume ou éteigne la LED  
  
PWM OUT (pins avec un ~ —> luminosité variable) :  
```analogWrite(9, 0–255);```  
⚠️ Pour une LED spécifiquement, la valeur est entre 0 et 255, pour les autres composants ça varie mais 0-1024 de manière générale. 

![circuit complet](https://github.com/headpoolnumerique/machines-animees-cours-transversal/blob/main/cours%233/images/button_light_led.png?raw=true)

```
void setup() {
  // put your setup code here, to run once:
  
  // déclaration du pin bouton (2) comme input pullup (pour éviter que la valeur d'entrée fluctue)
  pinMode(2, INPUT_PULLUP);

  // déclaration du pin led (~9) comme output
  pinMode(9, OUTPUT);

}

void loop() {

  // si le bouton est appuyé, allumer la LED
  if (digitalRead(2) == LOW) {
    digitalWrite(2, HIGH);
  }

  // autrement (si le bouton n'est pas appuyé)
  else {
    digitalWrite(2, LOW);
  }

  // Également, lire la valeur du capteur lumière (A0),
  // et faire la LED pulser (analogWrite) en fonction de cette lumière 
  // Utilisant la fonction map() qui permet de lier des valeurs entre deux plages
  // Dans ce cas, la valeur du capteur de lumière 
  // (entre 0 et 200, selon conditions réeles) et la valeur de la LED (0, 255)

  analogWrite(2, map(analogRead(A0), 0, 200, 0, 255)); 

}
```
### 3.3 Conditions – Port Serial – Fonction MAP

#### 3.3.1 Conditions IF - ELSE

Structure :  
```
if (condition1) {
  // A
} else if (condition2) {
  // B
} else {
  // C (cas par défaut)
}
```

#### 3.3.2 Le port série (Serial) 

**À quoi ça sert ?**
À parler entre l’Arduino et l'ordinateur : afficher des messages, lire des commandes, régler des erreurs

Initialisation :  
```  
void setup() {
  Serial.begin(9600);   // 9600, 115200, etc. Doit correspondre au Moniteur Série
}
```

Envoyer des messages vers l’ordinateur :  
```
Serial.print("Hello");
Serial.println(valeur);   // println ajoute un retour à la ligne
```

#### 3.3.3 Fonction Map() 

**À quoi ça sert ?**
Transformer une valeur qui vit dans une plage A vers une plage B.  
Ex : convertir 0–1023 (capteur analogique) en 0–255 (PWM LED).  

Syntaxe (Arduino) :  
```long map(long x, long in_min, long in_max, long out_min, long out_max);```



