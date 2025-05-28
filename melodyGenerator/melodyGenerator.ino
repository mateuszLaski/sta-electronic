#define NOTE_C4 262
#define NOTE_SC4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_PAUSE 0

int seq[][2] = {
  {NOTE_C5, 500},
  {NOTE_D5, 500},
  {NOTE_E5, 500},
  {NOTE_F5, 500},
  {NOTE_G5, 500},
  {NOTE_A5, 500},
  {NOTE_B5, 500},
  {NOTE_PAUSE, 1000},
  {NOTE_B5, 500},
  {NOTE_A5, 500},
  {NOTE_G5, 500},
  {NOTE_F5, 500},
  {NOTE_E5, 500},
  {NOTE_D5, 500},
  {NOTE_C5, 500},
};

void setup() {
  int n;

  Serial.begin(9600);

  for (n = 2; n < 9; n++) {
    pinMode(n, INPUT_PULLUP);
  }

  for (n = 0; n < sizeof(seq) / 4; n++) {
    if (seq[n][0])
      tone(9, seq[n][0], seq[n][1]);
    Serial.print(seq[n][0]);
    Serial.print(" ");
    Serial.println(seq[0][1]);
    delay(seq[n][1]);
  }

  noTone(9);
}

void loop() {
  // put your main code here, to run repeatedly:

}
