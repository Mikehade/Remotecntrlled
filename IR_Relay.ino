
#include <IRremote.h>
void off();
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;
#define rly1 2
#define rly2 3
#define rly3 4

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(rly1,OUTPUT);
  pinMode(rly2,OUTPUT);
  pinMode(rly3,OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) 
  {
                  
      switch(results.value)
      {
        case 0xFF30CF:  digitalWrite(rly1, !digitalRead(rly1)); break; // Button 1
        case 0xFF18E7:  digitalWrite(rly2, !digitalRead(rly2)); break; // Button 2
        case 0xFF7A85:  digitalWrite(rly3, !digitalRead(rly3)); break; // Button 3     
      }  
    irrecv.resume(); // Re
  }
}
