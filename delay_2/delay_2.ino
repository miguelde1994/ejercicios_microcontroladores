int ctr1=0;
int ctr2=0;
int aux_ctr=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}
void loop() {
  if(aux_ctr%2==0 && aux_ctr>0){
    //Aumentar ctr2 cada dos segundos
    ctr2++;
    ctr1-=ctr2;
    //Se muestra mensaje tras aumentar contador
    mostrarMensaje();
  }
  
    for(int i=0;i<10;i++){
      ctr1++;
      //Se muestra mensaje tras aumentar contador
      mostrarMensaje();
    }
  
  //delay de 1 segundo
  delay(1000);
  //Se aumenta contador auxiliar tras pasar un segundo
  aux_ctr++;
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
e. Usar la función delay.
*/