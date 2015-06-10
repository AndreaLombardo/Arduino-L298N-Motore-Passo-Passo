/*
 * L298N pilotare un motore passo passo con Arduino
 * In questo esempio vediamo come sfruttare la libreria Stepper
 * al fine di controllare un motore passo passo
 * Obbietivo : muovere ripetutamente il motore da 0 a 180 gradi e ritorno
 * Nel post correlato viene mostrato come interfacciare Arduino
 * ed il motore passo passo tramite il modulo L298N
 *
 * Autore  : Andrea Lombardo
 * Web     : http://www.lombardoandrea.com
 * Post    : http://bit.ly/L298N-ARDUINO-MOTOREPASSOPASSO
 * Git     : https://github.com/AndreaLombardo/Arduino-L298N-Motore-Passo-Passo
 */

//includo l'apposita libreria per gestire i motori passo passo
#include <Stepper.h>

/*
* Informo il programma su quanti sono gli step impiegati
* dal mio motore per compiere un giro completo.
* In alcuni datasheet (come nel mio caso) non e' specificato il numero di step del motore
* viene tuttavia specificato il numerdo di gradi effettuato ad ogni step (Step angle).
* Avendo queste informazioni, basta dividere 360 per lo Step angle
* per ottenere il numero di step del motore.
* E' evidente che piu' alto e' il numero degli step, piu' accurato sara' il movimento del motore
*/
int static stepMotore = 96; //modificare il valore in base agli step del motore in possesso

//un giro completo e' composto da 360 gradi, ne deriva che per compiere 180 gradi il motore dovra' percorrere
//un numero di step pari ai suoi "stepMotore diviso 2"
int stepDaPercorrere = stepMotore/2;

//definisco i pin che controlleranno il motore, per convenzione ho usato i nomi dei connettori presenti sul modulo L298N
int static IN1 = 11;
int static IN2 = 10;
int static IN3 = 9;
int static IN4 = 8;

//Istanzio un oggetto Stepper che rappresentera' il mio motore
Stepper mioMotore(stepMotore, IN1, IN2, IN3, IN4);

void setup() {
  //imposto la velocita' del motore
  //prova a giocare con questo valore per vedere le reazioni del motore
  //ma fallo gradualmente per non fare incazzare il motore...
  mioMotore.setSpeed(40);
}

void loop() {

  //effettuo il movimento di andata
  mioMotore.step(stepDaPercorrere);

  //attendo 50 millisecondi
  delay(50);

  //il metodo step accetta valori negativi
  //effettuo il movimento di ritorno
  mioMotore.step(-stepDaPercorrere);
  
  //attendo altri 50 millisecondi
  delay(50);
}
