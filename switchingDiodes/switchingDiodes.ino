#define ledg 12
#define ledr 11
#define button1 10
#define button2 9

int counter = 0;

void setup() {
  pinMode(ledg, OUTPUT);
  pinMode(ledr, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  
  digitalWrite(ledr, LOW);
  digitalWrite(ledg, LOW);
}

void loop() {
  if (digitalRead(button1) == LOW) {
    delay(100);
    
    if (digitalRead(ledg) == HIGH){
      digitalWrite(ledg, LOW);
      digitalWrite(ledr, LOW);
    } else {
      digitalWrite(ledg, HIGH);
      digitalWrite(ledr, LOW);
    }
    
    while (digitalRead(button1) == LOW);
    delay(100);
  } else if (digitalRead(button2) == LOW) {
    delay(100);
    
    if (digitalRead(ledr) == HIGH){
      digitalWrite(ledg, LOW);
      digitalWrite(ledr, LOW);
    } else {
      digitalWrite(ledg, LOW);
      digitalWrite(ledr, HIGH);
    }
    
    while (digitalRead(button2) == LOW);
    delay(100);
  }
}