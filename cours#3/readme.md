
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
  
#### 3.2.1 Bouton (entrée digitale ON/OFF)

⚠️ Pour un boutton, il faut une resistance pull-up (ou pull-down) parce qu’une entrée Arduino, si elle n’est reliée à rien, elle “flotte”. Elle capte du bruit (EMI), des fuites, des charges parasites et oscille aléatoirement entre HIGH et LOW.  

***OPTION #1***  
Câblage “pull-up” interne (le plus simple) : bouton entre pin et GND, activer la résistance interne.  
→ pinMode(pin, INPUT_PULLUP);  

![Bouton Int-Pull-Up](https://github.com/headpoolnumerique/machines-animees-cours-transversal/blob/main/cours%233/images/button_int_pullup.png?raw=true)

```
void setup(){ pinMode(2, INPUT_PULLUP); }
void loop(){
  if(digitalRead(2)==LOW){ /* appuyé */ }
}
```


***OPTION #2***
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

Installation (pont diviseur), en image mentale :  
Une échelle entre + (Vcc) et – (GND). Au milieu de l’échelle, on prend la mesure (pin A0). Les deux “barreaux” de l’échelle sont :  

— le capteur (qui change avec la lumière)  
— une deuxième résistance fixe (par ex. 10 kΩ)  

Tu peux mettre la LDR en haut et la résistance en bas, ou l’inverse :

Comment choisir la résistance fixe ?
Prendre 10 kΩ pour commencer. Si le capteur se situe surtout dans une ambiance donnée (studio, scène, dehors), choisir une valeur proche du capteur dans cette ambiance pour avoir une sensibilité correcte. (Pas besoin de maths : tester 4.7 kΩ, 10 kΩ, 47 kΩ et garder celle qui te donne une bonne variation.)

Lecture côté Arduino :

```
int v = analogRead(A0); // 0 (sombre) à 1023 (clair)
```
![capteur lumiere](https://github.com/headpoolnumerique/machines-animees-cours-transversal/blob/main/cours%233/images/light_sensor.png?raw=true)


