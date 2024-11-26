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
echo 
a. Recibir datos por la conexión serial.
b. Reenviar por dicha conexión los datos recibidos cambiando las 
mayúsculas por minúsculas y las minúsculas por mayúsculas.
*/