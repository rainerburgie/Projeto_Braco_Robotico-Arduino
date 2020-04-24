//Programa : Controle servo motor com joystick
//Autor : FILIPEFLOP
 
#include <VarSpeedServo.h>
 
//Cria objeto para controlar o servo base
VarSpeedServo servo_base;
//Cria objeto para controlar o servo inclinacao
VarSpeedServo servo_inclinacao;
 
int pino_x = A4; //Pino ligado ao X do joystick
int pino_y = A5; //Pino ligado ao Y do joystick
int val_x;   //Armazena o valor do eixo X
int val_y;   //Armazena o valor do eixo Y
 
void setup()
{
  //Define a porta a ser ligada ao servo base
  servo_base.attach(7, 1, 180);
  //Define a porta a ser ligada ao servo inclinacao
  servo_inclinacao.attach(8, 1, 180);
}
 
void loop()
{
  //Recebe o valor do joystick, eixo X
  val_x = analogRead(pino_x);
  //Converte o valor lido para um valor entre 1 e 180 graus
  val_x = map(val_x, 0, 1023, 1, 180);
  //Move o servo base para a posicao definida pelo joystick
  servo_base.slowmove(val_x, 60);
  //Recebe o valor do joystick, eixo Y
  val_y = analogRead(pino_y);
  //Converte o valor lido para um valor entre 1 e 180 graus
  val_y = map(val_y, 0, 1023, 1, 180);
  //Move o servo inclinacao para a posicao definida pelo joystick
  servo_inclinacao.slowmove(val_y, 60);
  //Aguarda a movimentacao do servo e reinicia a leitura
  delay(30);
}
