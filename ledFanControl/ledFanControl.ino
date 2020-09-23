
/* Knight Rider IR Control
   --------------
   @author: Napoleón Devesa
   
*/
#include <IRremote.h>

int pinArray[] = {2, 3, 4, 5, 6};
int count = 0;
int timer = 100;


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

timer = analogRead(A0);  //El valor leido por analog read es el temporizador
digitalWrite(pinArray[1], HIGH);
delay(timer);
digitalWrite(pinArray[1], LOW);
delay(timer);

          if (irrecv.decode(&results)) {
          // Dato recibido, conmutamos el LED


                   if(results.value == 0xFF6897){  //botón 0//
                              
                              for (count = 0; count < 5; count++) {
                                  digitalWrite(pinArray[2], HIGH);
                                  delay(timer);
                                  digitalWrite(pinArray[2], LOW);
                                  delay(timer);
                              } 

                }
                
               irrecv.resume();

          }

                  if(results.value == 0xFF30CF){ //boton 1
                   
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
          
  
          if (irrecv.decode(&results)){
                  Serial.println(results.value, HEX);
                  irrecv.resume();
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
  }
