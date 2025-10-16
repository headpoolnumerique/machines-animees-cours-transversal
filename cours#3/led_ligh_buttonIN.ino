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


