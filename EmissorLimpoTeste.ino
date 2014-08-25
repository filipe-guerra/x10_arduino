boolean Vetor[22] = {1,1,1,0,0,1, 1,0, 1,0, 0,1, 1,0,1,0,1,0,0,1,0,1};
int cont=0;

void setup(){
  pinMode(13,OUTPUT);
  attachInterrupt(0, burst, FALLING);  
}

void loop(){}

void burst(){
sinal(Vetor[cont]);
cont =  cont+1;
if (cont == 22){cont = 0;}
}

void sinal(boolean n){
  if (n==1){
    //for(int i=0;i<3;i++){
      digitalWrite(13, HIGH);   // Joga valor 1 na rede
      delayMicroseconds(1000); 
      digitalWrite(13, LOW);    // set the LED off
      delayMicroseconds(1777);
    //}
  } else {
    //for(int i=0;i<3;i++){
      digitalWrite(13, LOW);   // Joga valor 0 na rede
      delayMicroseconds(2777); 
    //}
  }
}
