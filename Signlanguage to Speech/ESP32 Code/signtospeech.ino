#include <BluetoothSerial.h>
BluetoothSerial SerialBT;

const int numSensors = 5;
const int adcPins[numSensors][3] = {
  {34, 39, 36},  // Sensor 1 (X, Y, Z)
  {33, 32, 35},  // Sensor 2
  {27, 26, 25},  // Sensor 3
  {13, 12, 14},  // Sensor 4
  {15, 2, 4}     // Sensor 5
};

int values[numSensors][3]; // To hold X, Y, Z for each sensor

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32_BT_Test");
  Serial.println("Bluetooth initialized");

  for (int i = 0; i < numSensors; i++) {
    for (int j = 0; j < 3; j++) {
      adcAttachPin(adcPins[i][j]);
    }
  }
  analogReadResolution(12); // 0 to 4095
}

void loop() {
  // Read and scale sensor data
  for (int i = 0; i < numSensors; i++) {
    for (int j = 0; j < 3; j++) {
      values[i][j] = analogRead(adcPins[i][j]) / 10; // scale down
    }
  }

  String gesture = detectGesture();
  if (gesture != "") {
    Serial.println(gesture);
    SerialBT.println(gesture);
    delay(1000);
  }
}

String detectGesture() {
  int X[5], Y[5], Z[5];
  for (int i = 0; i < 5; i++) {
    X[i] = values[i][0];
    Y[i] = values[i][1];
    Z[i] = values[i][2];
  }

  if (Z[0] > 165 && Z[0] < 180 && Z[1] > 145 && Z[1] < 165 && Z[2] > 145 && Z[2] < 165 && Z[3] > 150 && Z[3] < 165 && Z[4] > 145 && Z[4] < 160)
    return "Welcome";

  if (X[0] > 180 && X[0] < 210 && Y[0] > 135 && Y[0] < 160 &&
      X[1] > 180 && X[1] < 210 && Y[1] > 140 && Y[1] < 170 &&
      X[2] > 180 && X[2] < 210 && Y[2] > 140 && Y[2] < 170 &&
      X[3] > 180 && X[3] < 210 && Y[3] > 140 && Y[3] < 170 &&
      X[4] > 205 && X[4] < 220 && Y[4] > 140 && Y[4] < 170)
    return "Thank you";

  if (X[0] > 190 && X[0] < 200 && Y[0] < 160 &&
      X[1] > 225 && X[1] < 240 && Y[1] < 170 &&
      X[2] > 220 && X[2] < 240 && Y[2] < 170 &&
      X[3] > 220 && X[3] < 230 && Y[3] < 195 &&
      X[4] > 240 && X[4] < 255 && Y[4] < 170)
    return "Help";

  if (X[0] > 150 && X[0] < 175 && Y[0] > 160 && Y[0] < 190 &&
      X[1] > 175 && X[1] < 200 && Y[1] > 135 && Y[1] < 160)
    return "Water";

  if (X[0] > 165 && X[0] < 180 && Y[0] > 150 && Y[0] < 195 &&
      X[1] > 165 && X[1] < 180 && Y[1] > 145 && Y[1] < 200)
    return "Hello";

  if (X[0] > 140 && X[0] < 170 && Y[0] > 150 && Y[0] < 195 &&
      X[1] > 160 && X[1] < 185 && Y[1] > 150 && Y[1] < 180)
    return "Okay";

  if (X[0] > 190 && X[0] < 210 && Y[0] > 205 && Y[0] < 220 &&
      X[1] > 220 && X[1] < 240 && Y[1] > 190 && Y[1] < 210)
    return "Name";

  if (X[0] > 185 && X[0] < 200 && Y[0] > 220 && Y[0] < 240 &&
      X[1] > 195 && X[1] < 210 && Y[1] > 220 && Y[1] < 240)
    return "Time";

  return "";
}
