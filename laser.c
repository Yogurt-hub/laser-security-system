
//loading led's and indicator
const int red_led = 6;
const int green_led = 5;
const int blue_led = 7;
const int white_led = 8;
const int yellow_led = 10;  //indicates that there's a huge Light fluctuation
const int buzzer = 3;
const int ldr = 13;
const int pin_input = A0;

int stable_voltage;


void setup() {

  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(pin_input, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ldr, OUTPUT);
  Serial.begin(9600);
  digitalWrite(ldr, OUTPUT);
  //loading();
  stable_voltage = analogRead(pin_input);  //first input
}
void loop() {
  int voltage_read;

  Serial.println(stable_voltage);
  for (int i = 0; i < 5; i++) {
    voltage_read = analogRead(pin_input);
    Serial.println(voltage_read);
    if (voltage_read > stable_voltage + 30) {
      

      do {

        voltage_read = analogRead(pin_input);
        for (int j = 0; j < 1; j++) {
          digitalWrite(red_led, HIGH);
          digitalWrite(buzzer, HIGH);
          digitalWrite(blue_led, HIGH);
          digitalWrite(white_led, HIGH);
          delay(700);
          digitalWrite(buzzer, LOW);
          digitalWrite(red_led, LOW);
          digitalWrite(blue_led, LOW);
          digitalWrite(white_led, LOW);
          delay(700);
        }
      } while (voltage_read > stable_voltage + 30);
      for (int nel = 0; nel < 1; nel++) {
        analogWrite(buzzer, 255);
        delay(500);
        analogWrite(buzzer, 153);
        delay(400);
        analogWrite(buzzer, 102);
        delay(300);
        analogWrite(buzzer, 51);
        delay(200);
        digitalWrite(buzzer, 0);
      }
    } else {

      digitalWrite(green_led, HIGH);
    }
    digitalWrite(red_led, LOW);
    digitalWrite(green_led, LOW);
  }
}
/*void loading() {
  digitalWrite(red_led, HIGH);
  digitalWrite(red_led, LOW);
  delay(500);
  digitalWrite(green_led, HIGH);
  digitalWrite(green_led, LOW);
  delay(500);
  digitalWrite(blue_led, HIGH);
  digitalWrite(blue_led, LOW);
  delay(500);
  digitalWrite(white_led, HIGH);
  digitalWrite(white_led, LOW);
  delay(500);
  digitalWrite(yellow_led, HIGH);
  digitalWrite(yellow_led, LOW);
  delay(500);
}*/
