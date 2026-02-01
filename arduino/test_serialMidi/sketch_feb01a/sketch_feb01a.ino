
// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;  // the number of the pushbutton pin
const int ledPin = 13;    // the number of the LED pin
//#include <SoftwareSerial.h>
// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
int buttonPState = 1; //

void setup() {
  // initialize the LED pin as an output:
  Serial.begin(115200);
  noNotes();
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.println(buttonState);
}

/*

   Midi message:
    0x90 = 144 -> Note on
    Note numer (0-127)
    Note velocity

*/



void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // noteOn(random(50, 70), 100,500);

  // buttonPState = buttonState;

  if (buttonState != buttonPState) {
    digitalWrite(ledPin, !buttonState);
    //Serial.println(!buttonState);
    buttonPState = buttonState;
    if (buttonState == LOW){
        noteOn(60, 60, 1);    
    }

  }
  if(buttonState == HIGH) {
    noteOff(60);
 }
}



void noteOn(int note, int velocity, int duration) {
  Serial.write(144);
  Serial.write(note);
  Serial.write(velocity);
  delay(duration);
  //Serial.write(144);
  //Serial.write(note);
  //Serial.write(0);

}
void noteOnButton(int note, int velocity) {
  Serial.write(144);
  Serial.write(note);
  Serial.write(velocity);
  Serial.write(144);
  Serial.write(note);
  Serial.write(0);

}




void noNote(int duration) {
  Serial.write(144);
  Serial.write(0);
  Serial.write(0);
  delay(duration);
  Serial.write(144);
  Serial.write(90);
  Serial.write(0);

}
void noteOff(int note) {
  Serial.write(144);
  Serial.write(note);
  Serial.write(0);
}


void noNotes() {
  for (int i = 0; i < 0x7F; i++) {
    Serial.write(0x90);
    Serial.write(i);
    Serial.write(0x00);
  }
}
