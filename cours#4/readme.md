
# Cours#4 : Buzzer (output PWM, ~) et potentiomètre (input analogique); Variables

### 4.1 Potentiomètre : Input analogique

Mesure une tension continue entre 0 V et Vref (dans le cas d'Ardruino 5 V) et la convertit en valeur numérique (typ. 10 bits → 0–1023): analogRead(Ax).  
Permet de lire capteurs de tension, potentiomètres, etc.  

Un potentiomètre fournit une tension variable (ex. 0 à 5 V) selon sa position. Entrée analogique sait mesurer une valeur continue de tension (0…1023 sur Arduino Uno). On récupère donc la position précise du potentiometre.

### 4.2 Buzzer : Output PWM

Sortie numérique commutée très vite avec un rapport cyclique variable: analogWrite(pin, 0–255) sur pins PWM (~) (~490/980 Hz selon carte).  
Donne une moyenne équivalente à une tension analogique (utile pour LED, vitesse moteur, buzzer piezo).

Un buzzer passif (piezo) a besoin d’un signal carré à une fréquence précise pour produire une note. Les broches notées “~” sont prévues pour des signaux qui commutent rapidement, donc on les utilise par habitude pour générer des tons.

### 4.3 Variables. 

Une variable est un espace nommé en mémoire qui stocke une valeur qu’on peut lire et (souvent) modifier pendant l’exécution du programme.  
Elle a un type (ex. int, float, bool) qui détermine la forme des données et l’espace mémoire utilisé.  

***Déclaration vs initialisation vs mise à jour*** 

Déclaration : on introduit la variable et son type. Aucune valeur n’est fixée (elle peut contenir n’importe quoi tant qu’on ne l’a pas définie).  

```int compteur;        // déclaration```  

Initialisation : on donne la première valeur au moment de la déclaration.  

```int compteur = 0;    // déclaration + initialisation```

Mise à jour (affectation) : on change la valeur plus tard, sans redéclarer.  

```
compteur = compteur + 1;  // mise à jour
compteur += 1;            // équivalent
```

On ne redéclare pas une variable dans la même portée :  

```
int compteur = 0;
int compteur = 5;   // ❌ erreur dans la même portée
compteur = 5;       // ✅ mise à jour correcte
```
