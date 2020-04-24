int eixo_X= A0; //PINO REFERENTE A LIGAÇÃO DO EIXO X
int eixo_Y = A1; //PINO REFERENTE A LIGAÇÃO DO EIXO Y
int botao = 2; //PINO REFERENTE A LIGAÇÃO NO PINO KEY (EIXO Z)

void setup(){
  pinMode (botao, INPUT_PULLUP); //DEFINE A PORTA COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
  //DO ARDUINO PARA GARANTIR QUE NÃO EXISTA FLUTUAÇÃO ENTRE 0 (LOW) E 1 (HIGH)
  Serial.begin (9600); //INICIALIZA O MONITOR SERIAL
}
void loop(){

    if((analogRead(eixo_X)) == 0){ //SE LEITURA FOR IGUAL A 0, FAZ
        Serial.println("PARA CIMA"); //IMPRIME O TEXTO NO MONITOR SERIAL
    }else{
          if((analogRead(eixo_X)) == 1023){ //SE LEITURA FOR IGUAL A 1023, FAZ
              Serial.println("PARA BAIXO"); //IMPRIME O TEXTO NO MONITOR SERIAL
          }else{
                if((analogRead(eixo_Y)) == 0){ //SE LEITURA FOR IGUAL A 0, FAZ
                  Serial.println("ESQUERDA"); //IMPRIME O TEXTO NO MONITOR SERIAL
                }else{
                      if((analogRead(eixo_Y)) == 1023){ //SE LEITURA FOR IGUAL A 1023, FAZ
                          Serial.println("DIREITA"); //IMPRIME O TEXTO NO MONITOR SERIAL
                      }else{
                            if(digitalRead(botao) == LOW){ //SE LEITURA FOR IGUAL A HIGH, FAZ
                               Serial.println("BOTAO PRESSIONADO"); //IMPRIME O TEXTO NO MONITOR SERIAL
                            }  
                      }
                }
          }
    }
    delay(500); //INTERVALO DE 500 MILISSEGUNDOS
}
