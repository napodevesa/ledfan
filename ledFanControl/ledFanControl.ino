
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
  irrecv.enableIRIn(); // Empezamos la recepción  por IR
  for (count = 0; count < 5; count++) {
    pinMode(pinArray[count], OUTPUT);
  }
}

boolean on = LOW;


void loop() {

  
  timer = analogRead(A0);  //El valor leido por analog read es el temporizador
      
          if (irrecv.decode(&results)) {
          // Dato recibido, conmutamos el LED

               on =! on;
                
                                for (count = 0; count < 5; count++) {
                                  timer = analogRead(A0);
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
        
                
                

                if (results.value == 0xFF18E7) {
                on == on;
                
                }
                
      }
  }
