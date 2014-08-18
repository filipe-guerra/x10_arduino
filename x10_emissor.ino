boolean Header[4] = {1, 1, 1, 0};
boolean     HouseCode[8] = {0,1, 1,0, 1,0, 0,1};
boolean FunctionCode[10] = {0,0, 0,0, 0,0, 0,0, 0,0};  
boolean FunctionCode2[10] = {0,0, 0,0, 0,0, 0,0, 0,0};  
boolean     Vetor[22] = {0};
boolean flag=0, x=0;
int escolha = 0, escolha2 = 0, cont = 0;
 
  

void setup(){
  Serial.begin(9600);
  void mudarHouseCode(boolean a, boolean b, boolean c, boolean d);
  void mudarFunctionCode(boolean a, boolean b, boolean c, boolean d, boolean e);
  void mudarFunctionCode2(boolean a, boolean b, boolean c, boolean d, boolean e);
  void mudarVetor();
  void mudarVetor2();
  void sinal(boolean n);
  attachInterrupt(0, burst, CHANGE);
   
}

void loop(){
       
    if(x==0){
      
        Serial.println("Digite a funcao:1, 2, 17(ALL OFF), 18(ALL ON)");
        escolha = 2;
        Serial.println(escolha);
        
        switch (escolha){
          case 1:
            mudarFunctionCode(0,1,1,0,0);
          //  flag = 1;        //flag eh necessario para mandar o comando para o receptor
          break;
         
          case 2:
            mudarFunctionCode(1,1,1,0,0);
         //  flag = 1;
          break;     
          
          case 17:
            mudarFunctionCode(0,0,0,0,1);
          break;
          
          case 18:
            mudarFunctionCode(0,0,0,1,1);
          break;
          
       }
      mudarVetor();
      escolha = 0;
      x=1;
    }
    
   /* if (flag==1){
      
      Serial.println("Digite a funcao:19(ON), 20(OFF)");
      escolha = 20;
      Serial.println(escolha);
        
      switch (escolha){
        case 19:
          mudarFunctionCode2(0,1,1,0,0);
        break;
       
        case 20:
          mudarFunctionCode2(1,1,1,0,0);
        break;     
        
        flag=0;
      }
      if(x == 0){
        mudarVetor2();
        escolha2 = 0;
      }
    }*/
}

void burst(){
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  // If interrupts come faster than 200ms, assume it's a bounce and ignore
  if (interrupt_time - last_interrupt_time > 200)
  {
   sinal(Vetor[cont]);
   Serial.println(Vetor[cont]);
   cont = cont+1;
     if (cont == 22){
        if(x==1){
          mudarFunctionCode(0,0,0,0,0);
          x=0;
        }
        if(flag==0){
          mudarFunctionCode2(0,0,0,0,0);
        }
       cont = 0;
       Serial.println("FIM");
     }
  }
  last_interrupt_time = interrupt_time;  
}

void mudarHouseCode(boolean a, boolean b, boolean c, boolean d){
  HouseCode[0] = a;
  HouseCode[1] = !a;
  HouseCode[2] = b;
  HouseCode[3] = !b;
  HouseCode[4] = c;
  HouseCode[5] = !c;
  HouseCode[6] = d;
  HouseCode[7] = !d;
  }
  
  void mudarFunctionCode(boolean a, boolean b, boolean c, boolean d, boolean e){
  FunctionCode[0] = a;
  FunctionCode[1] = !a;
  FunctionCode[2] = b;
  FunctionCode[3] = !b;
  FunctionCode[4] = c;
  FunctionCode[5] = !c;
  FunctionCode[6] = d;
  FunctionCode[7] = !d;
  FunctionCode[8] = e;
  FunctionCode[9] = !e;
  }
  
  void mudarFunctionCode2(boolean a, boolean b, boolean c, boolean d, boolean e){
  FunctionCode2[0] = a;
  FunctionCode2[1] = !a;
  FunctionCode2[2] = b;
  FunctionCode2[3] = !b;
  FunctionCode2[4] = c;
  FunctionCode2[5] = !c;
  FunctionCode2[6] = d;
  FunctionCode2[7] = !d;
  FunctionCode2[8] = e;
  FunctionCode2[9] = !e;
  }
  
  void mudarVetor(){
    int i=0;
    do{
      Vetor[i] = Header[i];
            Serial.print(Vetor[i]);
      i = i+1;
    } while (i<4);
            Serial.println();
    i = 0;
    
    do{
      Vetor[i+4] = HouseCode[i];
            Serial.print(Vetor[i+4]);
      i = i+1;
    } while (i<8);
            Serial.println();
    i = 0;
    
    do{
      Vetor[i+12] = FunctionCode[i];
            Serial.print(Vetor[i+12]);      
      i = i+1;
    } while (i<10);
            Serial.println();
  }
  
  void mudarVetor2(){
    int i=0;
    
    do{
      Vetor[i+12] = FunctionCode2[i];
            Serial.print(Vetor[i+12]);      
      i = i+1;
    } while (i<10);
            Serial.println();
  }

void sinal(boolean n){
  if (n==1){
    for(int i=0;i<3;i++){
      digitalWrite(13, HIGH);   // Joga valor 1 na rede
      delayMicroseconds(1000); 
      digitalWrite(13, LOW);    // set the LED off
      delayMicroseconds(1777); //teste
    }
  }
  
  if (n==0){
    for(int i=0;i<3;i++){
      digitalWrite(13, LOW);   // Joga valor 0 na rede
      delayMicroseconds(2777); // tempo de 1/3 de 1/2 ciclo: 2777 micro segundos
    }
  }
}
