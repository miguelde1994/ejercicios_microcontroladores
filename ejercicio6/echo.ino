String textoSerial;
String salidaSerial;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  delay(1000);
}

void loop() {
  
    Serial.print("Introducir mensaje: ");
    while(Serial.available()==0){
      textoSerial ="";
      textoSerial = Serial.readString();

      //Si se ha leído algún mensaje, se sale del while
      if(textoSerial != ""){
        break;
      }
    }
    Serial.println();
    
    //Se recorre String y se van cambiando los caracteres
    salidaSerial = "";
    for(int i=0;i<textoSerial.length();i++){
      char c = textoSerial.charAt(i);

      if(c >=65 && c <= 90){
        c+=32;
      }else if(c >=97 && c <= 122){
        c-=32;
      }
      salidaSerial.concat(c);
    }
    Serial.print("Mensaje original: ");
    Serial.println(textoSerial);
    Serial.print("Mensaje con caracteres invertidos: ");
    Serial.println(salidaSerial);
  
  //mensajes y espera
  delay(500);

}




/*
Hacer una aplicación de línea de comandos mediante el puerto serie del 
microcontrolador.
a. Al iniciar o enviar una h se debe mostrar el menu de ayuda con la 
siguiente información:
H o h (help): muestra este menu de ayuda.
START o start: publica cada segundo un valor por el puerto serie
STOP o stop: detiene la publicación del valor.
T o t (time): El siguiente valor enviado cambiará el periodo de
publicación de la señal entre 1 y 10 veces por segundo.
M o m (mode): cambia el modo de fijo a alternativo. En modo fijo la 
señal se emite mantiene siempre el mismo valor siendo el ultimo 
emitido, por defecto debe ser un 1. Por otra parte, en modo 
alternativo cada vez que se publica el valor se alterna entre 0 y 1
*/