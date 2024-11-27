int contador=0;
unsigned long temporizador=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  temporizador=millis();
  
}
void loop() {

  if(millis()>=temporizador+1000){
    temporizador=millis();
    contador++;
    Serial.println(contador);
  }
}


/*int ctr1=0;
int ctr2=0;
unsigned long temporizador=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  temporizador=millis();
  
}
void loop() {
  if(millis()>=temporizador+2000){
    //Aumentar ctr2 cada dos segundos
    ctr2++;
    ctr1-=ctr2;
    //se obtiene nuevo valor del temporizador
    temporizador=millis();
    //Se muestra mensaje tras aumentar contador
    mostrarMensaje();
  }
  
  if((millis()-temporizador)%1000==0){
  //Se aumenta 10 veces por segundo
    for(int i=0;i<10;i++){
      ctr1++;
      //Se muestra mensaje tras aumentar contador
      mostrarMensaje();
    }
  }
}
void mostrarMensaje(){
  Serial.print("C1: ");
  Serial.print(ctr1);
  Serial.print(" C2: ");
  Serial.print(ctr2);
  Serial.println();
}*/
/*
 millis
a. Incrementar un contador e imprimirlo por el monitor serie cada segundo.
b. Usar millis()
*/