boolean  lido=0, flag=0;
String leitura= "", inicio= "1110", palavra="";
int cont=0;

void setup(){
  attachInterrupt(0, burst, CHANGE);
  Serial.begin(9600);
  pinMode(10,INPUT);
}

void loop(){
}

void burst(){
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 200ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 200)  {
    delayMicroseconds(500);// pegar no meio do bit que foi recebido
    lido = digitalRead(10);
    Serial.println(lido);
    if(lido) leitura += "1";
    else leitura += "0";
    if (leitura.length() > 4){
      leitura = leitura.substring(leitura.length()-4);
    }
    Serial.print("Leitura:");
    Serial.println(leitura);
    if(flag){
      if(lido) palavra += "1";
      else palavra += "0";
    }
   
    cont++;
    if (leitura == inicio){
      cont = 0;
      flag = 1;
      Serial.println("Achou!");
    }
    
    if (cont ==18){
      cont=0;
      flag=0;
      leitura = 0;
      Serial.println();
      Serial.print("Recebido:");
      Serial.print(palavra);
      Serial.println();
    }
  }
  last_interrupt_time = interrupt_time; 
}
