#include <SoftwareSerial.h>

int in1=8;
int in2=9;
int in3=10;
int in4=11;
int rx=3;
int tx=4;
char comando;
SoftwareSerial miBT(4,3);

void setup() {
  Serial.begin(9600);
  miBT.begin(38400);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  if (miBT.available()){
    //Serial.write(miBT.read());
    comando=miBT.read();
    Serial.println(comando);
    if (comando == 'w'){
      Serial.println(comando);
      avanzar();
      delay(2000);
    }
    if (comando == 's'){
      Serial.println(comando);
      retroceder();
      delay(2000);
    }
    if (comando == 'a'){
      Serial.println(comando);
      izquierda();
      delay(2000);
    }
    if (comando == 'd'){
      Serial.println(comando);
      derecha();
      delay(2000);
    }
    if (comando == 'q'){
      Serial.println(comando);
      parar();
      delay(2000);
    }
  }

}
void avanzar(){
  //motor1-2 avanza
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //motor4-3 avanza
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
void izquierda(){
  //motor1-2 avanza
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //motor4-3 avanza
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void derecha(){
  //motor1-2 avanza
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  //motor4-3 avanza
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void retroceder(){
  //motor1-2 retrocede
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  //motor4-3 retrocede
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void parar(){
  //motor1-2 para
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  //motor4-3 para
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
