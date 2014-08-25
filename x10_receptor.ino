boolean vetor[18], inicio[4] = {1,1,1,0},lido=0, flag=0, a=0, b=0, c=0, d=0;

int cont=0;

void setup(){
  attachInterrupt(0, burst, FALLING);
  pinMode(10,INPUT);
  Serial.begin(9600);
}

void loop(){
}

void burst(){
//  static unsigned long last_interrupt_time = 0;
//  unsigned long interrupt_time = millis();
  // If interrupts come faster than 200ms, assume it's a bounce and ignore
//  if (interrupt_time - last_interrupt_time > 200){
    delayMicroseconds(200);
   lido = digitalRead(10);
//   Serial.print(lido);
   a=b;
   b=c;
   c=d;
   d=lido;
   
   if(flag){
     vetor[cont] = lido;
   }
   
   cont++;
   
   if (((inicio[0] == a) and (inicio[1] == b)) and ((inicio[2] == c) and (inicio[3] == d))){
     cont = 0;
     flag = 1;
   }
   
   if ((cont ==18) && flag){
    cont=0;
    flag=0;
    detachInterrupt(0);
    Serial.println(); 
    Serial.println("House:");
    for(int i=0; i<8; i++){
        Serial.print(vetor[i]);
    }
    Serial.println();
    Serial.println("Codigo:");
    for(int i=0; i<10; i++){
        Serial.print(vetor[i+8]);
    }
    Serial.println();
    attachInterrupt(0, burst, FALLING);
   }
//  }
//  last_interrupt_time = interrupt_time; 
   
}

