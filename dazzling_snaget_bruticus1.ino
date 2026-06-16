const int TEMP_PIN   = A0;
const int LED_GREEN  = 8;
const int LED_YELLOW = 9;
const int LED_RED    = 10;

void setup() {
  pinMode(LED_GREEN,  OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED,    OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int raw = analogRead(TEMP_PIN);
  float voltage = (raw / 1023.0) * 5.0;
  float tempC   = (voltage - 0.5) * 100;

  digitalWrite(LED_GREEN,  LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED,    LOW);

  if (tempC < 25) {
    digitalWrite(LED_GREEN, HIGH);
  } else if (tempC <= 35) {
    digitalWrite(LED_YELLOW, HIGH);
  } else {
    digitalWrite(LED_RED, HIGH);
  }

  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.println(" C");

  delay(1000);
}