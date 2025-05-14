#define ledg 12
#define ledr 11
#define button 9

int counter = 0;

void setup() {
  pinMode(ledg, OUTPUT);
  pinMode(ledr, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  
  digitalWrite(ledr, LOW);
  digitalWrite(ledg, LOW);
}

void loop() {
  if (digitalRead(button) == LOW) {
    delay(100);
    counter = counter + 1;
    
    if (counter == 4) {
      counter = 0;
    }
    
    if (counter == 3) {
      digitalWrite(ledr, LOW);
      digitalWrite(ledg, LOW);
    }
    
    if (counter == 2) {
      digitalWrite(ledr, LOW);
      digitalWrite(ledg, HIGH);
    } 
    
    if (counter == 1) {
      digitalWrite(ledr, HIGH);
      digitalWrite(ledg, HIGH);
    } 
    
    if (counter == 0) {
      digitalWrite(ledr, HIGH);
      digitalWrite(ledg, LOW);
    }
    
    while (digitalRead(button) == LOW);
    delay(100);
  }
}