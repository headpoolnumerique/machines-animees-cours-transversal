
# Cours#3 : Inputs (Digital/Analogique) / Outputs (Digital/Digital PWM)

### 3.1 Différents inputs et outputs arduino

![circuit analogique vs numérique](https://github.com/headpoolnumerique/machines-animees-cours-transversal/blob/main/cours%232/images/difference%20analysis.jpg)

**Digital IN (entrée numérique)**
Lit un état 0/1 (LOW/HIGH). Utilise pinMode(pin, INPUT/INPUT_PULLUP) + digitalRead(pin).
⚠️ Nécessite souvent une résistance de pull-up/pull-down pour éviter un état flottant.

**Digital OUT (sortie numérique)**
Force un état 0/1 sur la broche: digitalWrite(pin, LOW/HIGH) après pinMode(pin, OUTPUT).
⚠️ Tension = celle de la carte (5 V ou 3,3 V). Courant limité par broche (ordre de ~20 mA max ⇒ piloter des relais/LED puissantes via transistor).

**Analogique (entrée analogique / ADC)**
Mesure une tension continue entre 0 V et Vref (souvent 5 V ou 3,3 V) et la convertit en valeur numérique (typ. 10 bits → 0–1023): analogRead(Ax).
Permet de lire capteurs de tension, potentiomètres, etc.

**PWM OUT (sortie PWM, pseudo-analogique)**
Sortie numérique commutée très vite avec un rapport cyclique variable: analogWrite(pin, 0–255) sur pins PWM (~490/980 Hz selon carte).
Donne une moyenne équivalente à une tension analogique (utile pour LED, vitesse moteur). Ce n’est pas une vraie sortie DAC; pour une tension lisse, ajouter un filtre RC.

—  

### 2.2 Arduino

![Arduino Uno](https://github.com/headpoolnumerique/machines-animees-cours-transversal/blob/main/cours%232/images/caracteristique_arduino.png)
  
**Qu’est que c’est que un microcontrôleur?**

Les microcontrôleurs sont des composants intégrés qui combinent un processeur, de la mémoire et des interfaces d'entrée/sortie. Ils sont utilisés pour contrôler des systèmes électroniques, des dispositifs embarqués, et des objets connectés.

**Qu’est que c’est que un Arduino?**

Un Arduino est un outil de prototypage électronique qui permet de créer des projets interactifs en programmant un microcontrôleur à l'aide de l'IDE Arduino. La combinaison de l'interface de programmation, des broches d'entrée/sortie et des bibliothèques facilite la création de projets électroniques variés. Composition d’un environment Arduino : 

1. **Microcontrôleur Arduino** : Au cœur d'une carte Arduino se trouve un microcontrôleur, le cerveau du système qu’exécute le programme que vous téléchargez sur la carte.
2. **Environnement de développement** : Pour programmer l'Arduino, vous utilisez l'IDE (environnement de développement intégré) Arduino, qui est un logiciel open-source que vous pouvez installer sur votre ordinateur. L'IDE Arduino vous permet de rédiger, de compiler et de télécharger votre code sur la carte Arduino.
3. **Langage de programmation** : Les programmes Arduino sont écrits en utilisant une variante simplifiée du langage C/C++. Vous écrivez des instructions pour le microcontrôleur, telles que "allumer une LED" ou "lire une valeur de capteur".
4. **Téléchargement du code** : Une fois que vous avez écrit votre programme dans l'IDE Arduino, vous le compilez (pour le convertir en langage machine) et le téléchargez sur la carte Arduino via un câble USB. Le microcontrôleur exécute ensuite le programme.
5. **Broches d'entrée/sortie** : Les cartes Arduino ont un certain nombre de broches d'entrée/sortie numériques et analogiques que vous pouvez utiliser pour connecter des composants électroniques. Vous pouvez configurer ces broches pour lire des signaux provenant de capteurs ou pour contrôler des actionneurs tels que des moteurs ou des LEDs.
6. **Alimentation** : Les cartes Arduino sont alimentées soit par le port USB de l'ordinateur lors de la programmation, soit par une source d'alimentation externe.

–  

### 2.3 La loi d'Ohm

![Electricite](https://github.com/headpoolnumerique/machines-animees-cours-transversal/blob/main/cours%232/images/schema-electronique3.png?raw=true)

La loi d'Ohm énonce que la tension (V) à travers un composant d'un circuit est directement proportionnelle au courant (I) qui le traverse, et cette relation est inversement proportionnelle à la résistance (R) de ce composant. Mathématiquement, cela peut être exprimé de la manière suivante :

![Loi d'Ohm](https://github.com/headpoolnumerique/machines-animees-cours-transversal/blob/main/cours%232/images/Loi_d'Ohm.png?raw=true)

### V = I * R

- **V** représente la tension en volts (V).
- **I** représente le courant en ampères (A).
- **R** représente la résistance en ohms (Ω).

En d'autres termes, plus la tension est élevée, plus le courant sera élevé, à condition que la résistance reste constante. De même, si la résistance augmente, le courant diminuera pour une tension donnée.

#### Comment lire un circuit de base et calculer la resistance pour un LED

![LED circuit](https://github.com/headpoolnumerique/machines-animees-cours-transversal/blob/main/cours%232/images/basic_circuit.jpg)
![Arduino Fritzing LED](https://github.com/headpoolnumerique/machines-animees-cours-transversal/blob/main/cours%232/images/arduino_led_circuit_pwm_pin.png?raw=true)
