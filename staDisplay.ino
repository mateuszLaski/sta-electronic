// Definizione dei pin dei LED
const int ledPins[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

// Pin di lettura del trimmer
const int trimmerPin = A0;

void setup() {
  // Inizializzazione dei pin dei LED come OUTPUT
  for (int i = 0; i < 10; i++) {
    pinMode(ledPins[i], OUTPUT); // Assicurati che i LED siano spenti all"inizio
    digitalWrite(ledPins[i], LOW); // Assicurati che I LED siano spenti all"inizio
  }
  // Inizializzazione dle pin del timmer come INPUT
  pinMode(trimmerPin, INPUT);
}

void loop() {
  // Legge il valore analogico(0, 1023)
  int timmerValue = analogRead(trimmerPin);
  
  // Mappa il valore letto (0, 1023) al numero di LED (0-10)
  int numLeds = map(timmerValue, 0, 1023, 0, 11);

  // Assicurati che numLeeds non superi i limiti
  numLeds = constrain(numLeds, 0, 10);

  // Accende i LED in baase al numero calcolato
  for(int i = 0; i < 10; i++) {
    if (i < numLeds) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
  
  // Piccola pausa per styabilizzare la lattura
  delay(10);
}
