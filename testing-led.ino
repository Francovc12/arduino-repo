//testeo de placa arduino uno con led y usando monitor serial
void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
}

void loop() {
  
  if (Serial.available()>=0){
    char num = Serial.read();
    Serial.println(num);
    if (num=='1'){
      digitalWrite(5, HIGH);
      delay(1000);
    }
    else{
      digitalWrite(5, LOW);
    }
  }
}
