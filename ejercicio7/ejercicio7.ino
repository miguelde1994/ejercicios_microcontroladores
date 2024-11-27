String textoSerial;
char opcion;
bool activo=0;
bool modo=0;
int valor=1;
int numFor=1;
long temporizador=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000); //Espera tras serial begin
  temporizador=millis();

  
}

void loop() {
  
    Serial.print("Introducir opcion: ");
    while(Serial.available()==0){
      textoSerial ="";
      textoSerial = Serial.readString();

      //Si se ha leído algún mensaje, se sale del while
      if(textoSerial != "" || millis()>=temporizador+1000){
        temporizador=millis();
        break;
      }
    }
    Serial.println();
    
    //Se guarda opcion
    if(textoSerial==""){
      opcion = 'z';
    }else{
      opcion = textoSerial.charAt(0);
    }
    
    
    switch(opcion){
      case 'h':
      case 'H':
        Serial.println("H o h (help): muestra este menu de ayuda.");
        Serial.println("START o start: publica cada segundo un valor por el puerto serie");
        Serial.println("STOP o stop: detiene la publicación del valor.");
        Serial.println("T o t (time): El siguiente valor enviado cambiará el periodo de publicación de la señal entre 1 y 10 veces por segundo.");
        Serial.println("M o m (mode): cambia el modo de fijo a alternativo. En modo fijo la señal se emite mantiene siempre el mismo valor siendo el ultimo emitido, por defecto debe ser un 1. Por otra parte, en modo alternativo cada vez que se publica el valor se alterna entre 0 y 1");
        break;
      case 's':
      case 'S':
        //Serial.println(textoSerial);
        //Serial.println(textoSerial.length());
        //if(textoSerial.charAt(4)=='t' || textoSerial.charAt(4)=='T'){
          if(textoSerial.equalsIgnoreCase("start")){ //Enviar los mensajes en consola con < No Line Ending >
          activo=1;
        }else if(textoSerial.equalsIgnoreCase("stop")){
          activo=0;
        }else{
          Serial.println("Opcion no definida");
        }
        break;
      case 't':
      case 'T':
        Serial.print("Introducir veces(1-10) a imprimir: ");
        while(Serial.available()==0){
          textoSerial ="";
          textoSerial = Serial.readString();
          int opcionT = 0;
          if(textoSerial.charAt(0)>=48 && textoSerial.charAt(0) <= 57){
            opcionT = textoSerial.toInt();
          }
          
          //Si se ha leído algún mensaje, se sale del while
          if(textoSerial != "" && opcionT >= 1 && opcionT<=10){
            //Guardar valor
            numFor = opcionT;

            break;
          }else{
            textoSerial ="";
          }
        }
        Serial.println();

        //Mensaje
        Serial.print("Se muestra el valor "),
        Serial.print(numFor);
        Serial.print(" veces");
        Serial.println();
        break;
      case 'm':
      case 'M':
        if(modo==0){ //intermitente
          Serial.println("Modo intermitente");
          modo=1;
          valor=0;  
        }else{ //fijo
          Serial.println("Modo fijo");
          modo=0;
          valor=1;
        }
        break;
      case 'z':
        break;
      default:
        Serial.println("Opcion no definida");
        break;
    }
    
    //Mostrar valor
    if(activo==1){
      
      for(int i=0;i<numFor;i++){
        //Se comprueba el modo
        if(modo==1 && valor==0){
          valor=1;
        }else if(modo==1 && valor==1){
          valor=0;
        }
        Serial.print("Valor: ");
        Serial.println(valor);
      }
    }
  
  //Espera
  //delay(500);

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