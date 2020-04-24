#include <Servo.h>

// --- Projeto para configurar servo em posição inicial de 90 graus.

Servo myservo; 

int pos =56;

void setup() {
  myservo.attach(2);
  myservo.write(pos);

}

void loop() {

}
