/* 
Projeto Arduino - Leitura de um joystick para
         controle de servo no Arduino
----------------------------------------
--=<| Rainer Burgie |>=--
----------------------------------------
*/
 
//Variável que armazena a posição lida 
//nos eixos do joystick
int joystick = 0;
 
//Atribuindo o pino analógico A0 a variável eixoX
int eixoX = A0;
 
//Atribuindo o pino analógico A1 a variável eixoY
int eixoY = A1;
 
//Atribuindo o pino digital 2 a variável eixoZ
int botao = 2;
 
void setup() {
  //Definindo eixoZ como um pino de entrada
  pinMode (botao, INPUT_PULLUP);
 
  //Ativando o Serial Monitor que exibirá os
  //valores lidos no Joystick
  Serial.begin(9600);
}
 
void loop() {
  //Lê o valor do eixoX
  joystick = analogRead(eixoX);
 
  //imprime o valor do eixoX
  Serial.print("  X=");
  Serial.print(joystick);
 
  //Lê o valor do eixoY
  joystick = analogRead(eixoY);
 
  //imprime o valor do eixoY 
  Serial.print("   Y=");
  Serial.print(joystick);
 
  //Lê o valor do eixoZ
  joystick = digitalRead(botao);
 
  //imprime o valor do eixoZ
  Serial.print("   Z=");
  Serial.println(joystick);
 
  //espera 200 milisegundos. 
  //Se vc quiser aumentar a velocidade 
  //de leitura dos valores do joystick 
  //diminua o tempo de espera. Ex: delay(100);
  delay(200); 
}
