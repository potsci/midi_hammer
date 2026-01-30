
const int HallSensorPin = A0;
int HallSensorSignal = 0;

void setup() {
  Serial.begin(115200);
}
void loop() {
  HallSensorSignal = analogRead(HallSensorPin);
  Serial.println(HallSensorSignal);
  // Testing output values (with no B field: 513-514
  // One direction of Magenesis Neody magenet MGNT02-50 ->  856-859
  // Other direction:                                       178-179

  
  //initial guesstimate of b ~ d (mm)
  //mm      reading
  //35      506
  //30      503
  //25      501
  //20      479
  //15      435
  //10      340

  //Note to self: if too close to arduino: B field from arduino is sensed.
  delay(5);
}
