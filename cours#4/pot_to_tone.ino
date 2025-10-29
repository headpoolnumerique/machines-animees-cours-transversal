// déclaration d'une variable
int potentiometre;

void setup() {
  // décliner pin 9 en output
  pinMode(9, OUTPUT);

  // initialiser le port série pour vérifier les données
  Serial.begin(9600);
}

void loop() {

  potentiometre = analogRead(A0);
  // put your main code here, to run repeatedly:
  
  Serial.print("Potentiometre: ");
  Serial.println(potentiometre);

  // convertir/mapper la valeur du potentiometre
  // a la valeur du TONE
  // map = (1)valeur d'entree, son minimum, son maximum)
  //        (2) minimum de valeur sortie, et maximum

  Serial.print("Mapping Hertz: ");
  Serial.println(potToTone);

  // Mapper les valeurs de l'entrée du potentiomètre aux valeurs du buzzer Piezo. 
  int potToTone = map(potentiometre, 0, 1024, 0, 400);
  
  // faire sonner le buzzer
  tone(9, potToTone);
  
  // petit délai entre les boucles
  delay(200);
}
