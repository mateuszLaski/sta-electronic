// Definizione dei pin dei LED
const int ledPins[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

// Pin di lettura del trimmer
const int trimmerPin = A0;

bool isGoingUp = true;
int position = -1;

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
  int timmerValue = analogRead(trimmerPin);

  int changeSpeed = map(timmerValue, 0, 1023, 50, 5000);
  changeSpeed = constrain(changeSpeed, 50, 500);

  if (isGoingUp) {
    position++;
    if (position == 11) {
      digitalWrite(ledPins[9], LOW);
      //position = 0;
      isGoingUp = false;
    } else {
      digitalWrite(ledPins[position - 1], LOW);
      digitalWrite(ledPins[position], HIGH);
    }
  }

  if (!isGoingUp) {
    position--;
    if (position == -1) {
      digitalWrite(ledPins[0], LOW);
      //position = 0;
      isGoingUp = true;
    } else {
      digitalWrite(ledPins[position + 1], LOW);
      digitalWrite(ledPins[position], HIGH);
    }
  }

  delay(changeSpeed);

  // for (int i = 0; i < 10; i++) {
  //   digitalWrite(ledPins[i], HIGH);
  //   delay(50);
  // }

  // for (int i = 10; i > 0; i--) {
  //   digitalWrite(ledPins[i], LOW);
  //   delay(50);
  // }
}
