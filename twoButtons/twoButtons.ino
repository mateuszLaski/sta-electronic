#define ledr 12
#define ledg 11
#define button_a 10
#define button_b 9

void setup()
{
  pinMode(ledr, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(button_a, INPUT_PULLUP);
  pinMode(button_b, INPUT_PULLUP);
}

void loop()
{
  if(digitalRead(button_a) && digitalRead(button_b)) {
    digitalWrite(ledg, LOW);
    digitalWrite(ledr, LOW);
  } else if (digitalRead(button_a)) {
    digitalWrite(ledg, HIGH);
    digitalWrite(ledr, LOW);
  } else if (digitalRead(button_b)) {
    digitalWrite(ledg, LOW);
    digitalWrite(ledr, HIGH);
  }
  else {
    digitalWrite(ledg, LOW);
    digitalWrite(ledr, HIGH);
    delay(250);
    digitalWrite(ledg, HIGH);
    digitalWrite(ledr, LOW);
    delay(250);
  }
}


// #define ledr 12
// #define ledg 11
// #define button_a 10
// #define button_b 9

// void setup()
// {
//   pinMode(ledr, OUTPUT);
//   pinMode(ledg, OUTPUT);
//   pinMode(button_a, INPUT_PULLUP);
//   pinMode(button_b, INPUT_PULLUP);
// }

// void loop()
// {
//   bool button_a_state = digitalRead(button_a);
//   button_a_state = !button_a_state;
//   bool button_b_state = digitalRead(button_b);
//   button_b_state = !button_b_state;

//   if(button_a_state && button_b_state) {
//     digitalWrite(ledg, LOW);
//     digitalWrite(ledr, HIGH);
//     delay(250);
//     digitalWrite(ledg, HIGH);
//     digitalWrite(ledr, LOW);
//     delay(250);
//   } else if (button_a_state) {
//     digitalWrite(ledg, LOW);
//     digitalWrite(ledr, HIGH);
//   } else if (button_b_state) {
//     digitalWrite(ledg, HIGH);
//     digitalWrite(ledr, LOW);
//   }
//   else {
//     digitalWrite(ledg, LOW);
//     digitalWrite(ledr, LOW);
//   }
// }