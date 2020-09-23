
/* Knight Rider IR Control
   --------------
   @author: Napoleón Devesa
   
*/
#include <IRremote.h>

int pinArray[] = {2, 3, 4, 5, 6};
int count = 0;
int timer = 100;

float tempC; // Variable para almacenar el valor obtenido del sensor (0 a 1023)
int pinLM35 = 1; // Variable del pin de entrada del sensor (A0)


int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // we make all the declarations at once
  Serial.begin(9600);
  irrecv.enableIRIn();
  
  for (count = 0; count < 5; count++) {
    pinMode(pinArray[count], OUTPUT);
  }
}


void loop() {


  // Con analogRead leemos el sensor, recuerda que es un valor de 0 a 1023
  tempC = analogRead(pinLM35); 
   
  // Calculamos la temperatura con la fórmula
  tempC = (5.0 * tempC * 100.0)/1024.0; 
 
  // Envia el dato al puerto serial
  Serial.print(tempC);
  // Salto de línea
  Serial.print("\n");
  
  // Esperamos un tiempo para repetir el loop
  delay(1000);

timer = analogRead(A0);  //El valor leido por analog read es el temporizador
/*
digitalWrite(pinArray[1], HIGH);
delay(timer);
digitalWrite(pinArray[1], LOW);
delay(timer);

digitalWrite(pinArray[4], HIGH);
delay(timer);
digitalWrite(pinArray[4], LOW);
delay(timer);

*/

 for (count = 0; count < 5; count++) {
                                  digitalWrite(pinArray[count], HIGH);
                                  delay(timer);
                                  digitalWrite(pinArray[count], LOW);
                                  delay(timer);
   } 
 for (count = 4; count >= 0; count--) {
                                          timer = analogRead(A0);
                                          digitalWrite(pinArray[count], HIGH);
                                          delay(timer);
                                          digitalWrite(pinArray[count], LOW);
                                          delay(timer);
 }

                              

if (irrecv.decode(&results)) {
          // Dato recibido, conmutamos el LED

           if(results.value == 0xFF6897){  //botón 0//
                              
                              for (count = 0; count < 5; count++) {
                                  digitalWrite(pinArray[count], LOW);
                                  delay(timer);
                                  digitalWrite(pinArray[count], HIGH);
                                  delay(timer);
                                  
                              } 
                               for (count = 4; count >= 0; count--) {
                                          timer = analogRead(A0);
                                          digitalWrite(pinArray[count], LOW);
                                          delay(timer);
                                          digitalWrite(pinArray[count], HIGH);
                                          delay(timer);
                                }
        

          }
                
               irrecv.resume();

          }

            if(results.value == 0xFF30CF){ //boton 1
                   
                                        for (count = 0; count < 5; count++) {
                                          timer = analogRead(A0);
                                          digitalWrite(pinArray[3], LOW);
                                          delay(timer);
                                          digitalWrite(pinArray[3], HIGH);
                                          delay(timer);
                                        }
                                        for (count = 4; count >= 0; count--) {
                                          timer = analogRead(A0);
                                          digitalWrite(pinArray[3], HIGH);
                                          delay(timer);
                                          digitalWrite(pinArray[3], LOW);
                                          delay(timer);
                                        }
        
           }

           irrecv.resume();
          
  
          if (irrecv.decode(&results)){
                  Serial.println(results.value, HEX);
                  irrecv.resume();
            }

  }


      /*
          if (irrecv.decode(&results)) {
          // Dato recibido, conmutamos el LED


           if(results.value == 0xFF6897){  //botón 0//
           
                                digitalWrite(pinArray[2], HIGH);
delay(timer);
digitalWrite(pinArray[2], LOW);
delay(timer);

                }
                
               //irrecv.resume();

                if(results.value == 0xFF30CF){
           
                                for (count = 0; count < 5; count++) {
                                  timer = analogRead(A0);
                                  digitalWrite(pinArray[count], LOW);
                                  delay(timer);
                                  digitalWrite(pinArray[count], HIGH);
                                  delay(timer);
                                }
                                for (count = 4; count >= 0; count--) {
                                  timer = analogRead(A0);
                                  digitalWrite(pinArray[count], HIGH);
                                  delay(timer);
                                  digitalWrite(pinArray[count], LOW);
                                  delay(timer);
                                }

                }

                 if(results.value == 0xFF10EF){
           
                                for (count = 0; count < 5; count++) {
                                  timer = analogRead(A0);
                                  digitalWrite(pinArray[count], HIGH);
                                  digitalWrite(pinArray[count], HIGH);
                                  digitalWrite(pinArray[count], HIGH);
                                  delay(timer);
                                  digitalWrite(pinArray[count], LOW);
                                  delay(timer);
                                 
                                }
                                for (count = 4; count >= 0; count--) {
                                  timer = analogRead(A0);
                                  digitalWrite(pinArray[count], HIGH);
                                  delay(timer);
                                  digitalWrite(pinArray[count], LOW);
                                  delay(timer);
                                }

                }
                
              // irrecv.resume();
                
        }
*/
