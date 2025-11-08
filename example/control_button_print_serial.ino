#define BUTTON_PIN 14

int buttonState = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);
  if(buttonState == LOW) {
    Serial.println("Button is pressed");
  } else {
    Serial.println("Button is not pressed");
  }
  delay(100);
}