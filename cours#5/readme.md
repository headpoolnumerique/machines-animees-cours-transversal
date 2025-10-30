
# Cours#5 : Moteurs, librairies, et semi-conducteurs

![Buzzer circuit Arduino](https://github.com/headpoolnumerique/machines-animees-cours-transversal/blob/main/cours%234/images/buzzer-circuit.png?raw=true)

### 5.1 Moteur servo et librairie Servo 

Un moteur servo peut se déplacer à l'ordre de position via une impulsion et se place à l’angle demandé.

***Qu’est-ce qu’une librairie ?***

Un ensemble de code réutilisable qu'apporte des fonctionnalités prêtes à l’emploi, testées et documentées.

***Pourquoi utiliser Servo.h avec un servo ?***

Parce qu’un servo n’a pas besoin d’un PWM “classique”, mais d’impulsions très précises (≈1–2 ms, toutes ~20 ms). Servo.h :
génère ces impulsions au timing beaucoup plus régulier que delay() ou analogWrite()), et simplifie l'usage grâce à une série de fonctions pre-écrites : attach(), write(angle), writeMicroseconds(), detach(),


![Servo motor circuit Arduino]()

