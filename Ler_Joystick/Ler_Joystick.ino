#define joystick1X A0
#define joystick1Y A1

void setup() {
    pinMode(joystick1X, INPUT);
    pinMode(joystick1Y, INPUT);
    Serial.begin(9600);

}

void loop() {
    int x, y;
    x = analogRead(joystick1X);
    y = analogRead(joystick1Y);
    Serial.print("Eixo X: ");
    Serial.print(x);
    Serial.print("   |   ");
    Serial.print("Eixo Y: ");
    Serial.print(y);
    Serial.println("");
    delay(1);
}
