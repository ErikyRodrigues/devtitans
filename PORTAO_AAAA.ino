#include <RCSwitch.h>
#include <Servo.h>
int servopin = 23; //D23
int statusLed = 0; //VARIÁVEL DO TIPO INT (CONTROLA O ESTADO ATUAL DO LED)

Servo servomotor;

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(22);

  //led config
  servomotor.attach(servopin);
  servomotor.write(0);
}

//Atualização do led (atualmente)
void atualizarPortao(int newState){
  if(newState < statusLed){ //Caso o portão esteja aberto
    while(statusLed > newState){
      statusLed -= 1;
      servomotor.write(statusLed);
      Serial.println(statusLed);
      delay(10);
    }
  }
  else{  //Portão fechado
    while(statusLed < newState){
      statusLed += 1;
      servomotor.write(statusLed);
      Serial.println(statusLed);
      delay(10);
    }
  }
}

void abrirPortao() {
  atualizarPortao(170);
  Serial.println( mySwitch.getReceivedValue() );
}

void fecharPortao() {
  atualizarPortao(0);
  Serial.println( mySwitch.getReceivedValue() );
}

/*
void interromperPortao(){
  
}
*/

void loop() {
  Serial.println( mySwitch.getReceivedValue() );
  if (mySwitch.available()) {
    int value = mySwitch.getReceivedValue();
    
    if (value == 10){
      abrirPortao();
    }
    else {
      if (value == 9 ){
        fecharPortao();
      }
    }
    mySwitch.resetAvailable();
  }
  delay(2000);
}
