int ctr1=0;
int ctr2=0;

unsigned long temporizador=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  temporizador=micros()/1000;
  
}

void loop() {
  if(micros()/1000>=temporizador+2000){
    //Aumentar ctr2 cada dos segundos
    ctr2++;
    ctr1-=ctr2;

    //se obtiene nuevo valor del temporizador
    temporizador=micros()/1000;

    //Se muestra mensaje tras aumentar contador
    mostrarMensaje();
  }
  
  if((micros()/1000-temporizador)%1000==0){
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
}


/*
 delay_2
a. El contador ctr1 se incrementará 10 veces por segundo
b. El contador ctr2 se incrementará 1 vez cada 2 segundos.
c. Cuando se incremente ctr2 se descontará el valor de dicho contador de
ctr1.
d. Cada vez que uno de los dos contadores se incremente se imprimirá con 
el formato C1: {valor del contador 1} C2: {valor del contador 2}.
e. Usar micros()
*/