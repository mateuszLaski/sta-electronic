#define led 12
#define button 2

const double multiplier = 1;
long ledInterval = 500;
unsigned long previousMillis = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(button) == LOW){
    unsigned long startTime = millis();
    delay(100);
    while(digitalRead(button) == LOW);
    unsigned long endTime = millis();
    delay(100);
    ledInterval = (endTime - startTime) * multiplier;
  }
  
  checkBlinking(previousMillis, ledInterval, led);
}

void checkBlinking(unsigned long& previousMillis, long interval, int ledPin){
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    digitalWrite(ledPin, !digitalRead(ledPin));
  }
}