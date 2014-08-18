boolean vetor[18], lido=0, flag=0;
byte leitura= B00000000, inicio= B00001110, mascara=00001111;
int cont=0;

void setup(){
  attachInterrupt(0, burst, CHANGE);
  Serial.begin(9600);
}

void loop(){
}

void burst(){
   lido = digitalRead(10);
   leitura << lido;
   
   if(flag){
     vetor[cont] = lido;
   }
   
   cont++;
   
   if ((leitura & mascara) == inicio){
     cont = 0;
     flag = 1;
   }
   
  if (cont ==18){
    cont=0;
    flag=0;
    leitura = 0;
    for(int i=0; i<19; i++){
        Serial.print(vetor[i]);
    }
    Serial.println();
  }
   
}
