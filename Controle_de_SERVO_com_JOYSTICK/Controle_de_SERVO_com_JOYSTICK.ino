//Programa : Controle servo motor com joystick
//Autor : Rainer Burgie
 
#include <VarSpeedServo.h>
 
//Cria objeto para controlar o servo base
VarSpeedServo servo_base;
VarSpeedServo servo_base2;
 
 
int pino_x = A0; //Pino ligado ao X do joystick
int pino_y = A1; //Pino ligado ao Y do joystick
int val_x;   //Armazena o valor do eixo X
int val_y;   //Armazena o valor do eixo Y
int botao = 2; //Botão do joystick
int joystick = 0;
int pos = 90;
 
void setup()
{
  //Define a porta a ser ligada ao servo base
  servo_base.attach(7, 1, 180);

  Serial.begin(9600);
  pinMode (botao, INPUT_PULLUP);
  
  servo_base.write(pos);
}
void loop()
{
  //Recebe o valor do joystick, eixo X
  val_x = analogRead(pino_x);
  
  //Converte o valor lido para um valor entre 1 e 180 graus
  val_x = map(val_x, 0, 1023, 1, 180);
  
  //Move o servo base para a posicao definida pelo joystick
  servo_base.slowmove(val_x, 60);
  
///////////////////////////////////

///Recebe o valor do joystick, eixo y
  val_y = analogRead(pino_y);
  
  //Converte o valor lido para um valor entre 1 e 180 graus
  val_y = map(val_y, 0, 1023, 1, 1180);
  
  //Move o servo base para a posicao definida pelo joystick
  servo_base2.slowmove(val_y, 70);
  

  joystick = digitalRead(botao);

  Serial.print("   x=");
  Serial.print(val_x);

  Serial.print("   y=");
  Serial.print(val_y);

  Serial.print("   Z=");
  Serial.println(joystick);
  
  delay(30);

}
