#include <Servo.h>

Servo myservoFL1; //Front left down
Servo myservoFL2; //Front left up
Servo myservoFR1; //Front right down
Servo myservoFR2; //Front right up
Servo myservoRL1; //Rear left down
Servo myservoRL2; //Rear left up
Servo myservoRR1; //Rear right down
Servo myservoRR2; //Rear right up

int pos = 0;
int state=0;

void setup() {
  myservoFL1.attach(2);
  myservoFL2.attach(3);
  myservoFR1.attach(4);
  myservoFR2.attach(5);
  myservoRL1.attach(6);
  myservoRL2.attach(7);
  myservoRR1.attach(8);
  myservoRR2.attach(9);

  myservoFL1.write(90);
  myservoFL2.write(45);
  myservoFR1.write(180);
  myservoFR2.write(135);
  myservoRL1.write(120);
  myservoRL2.write(135);
  myservoRR1.write(150);
  myservoRR2.write(0);

  Serial.begin(9600);
}

void FL()
{
  for (pos = 60; pos <= 120; pos += 4) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservoFL2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  
  for (pos = 90; pos >= 45; pos -= 4) { // goes from 180 degrees to 0 degrees
    myservoFL1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }

  for (pos = 120; pos >= 60; pos -= 4) { // goes from 180 degrees to 0 degrees
    myservoFL2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }

  for (pos = 45; pos <= 90; pos += 4) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservoFL1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}

void RR()
{

  for (pos = 60; pos >= 0; pos -= 4) { // goes from 180 degrees to 0 degrees
      myservoRR2.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
  }

  for (pos = 90; pos >= 45; pos -= 4) { // goes from 180 degrees to 0 degrees
    myservoRR1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  
  for (pos = 0; pos <= 60; pos += 4) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservoRR2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  
  for (pos = 45; pos <= 90; pos += 4) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservoRR1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}
  
void FR(){
  for (pos = 130; pos >= 90; pos -= 4) { // goes from 180 degrees to 0 degrees
    myservoFR2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }

  for (pos = 90; pos >= 45; pos -= 4) { // goes from 180 degrees to 0 degrees
    myservoFR1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }

  for (pos = 90; pos <= 130; pos += 4) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservoFR2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }

  for (pos = 45; pos <= 90; pos += 4) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservoFR1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}

void RL(){
  for (pos = 90; pos <= 160; pos += 4) { // goes from 180 degrees to 0 degrees
      myservoRL2.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15 ms for the servo to reach the position
  }

  for (pos = 90; pos >= 45; pos -= 4) { // goes from 180 degrees to 0 degrees
    myservoRL1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  
  for (pos = 160; pos >= 90; pos -= 4) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservoRL2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  
  for (pos = 45; pos <= 90; pos += 4) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservoRL1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}

void loop() {

  if (Serial.available()>0)
  state=Serial.read();
  if (state=='F')
  {
  // Forward
  FL();// Front Left
  RR();// Rear Right
  FR();// Front Right
  RL();// Rear Left
  }
  else if(state=='B')
  {

  // Backward

  }
  else if(state=='L')
  {

  // Left

  }
  else if(state=='R')
  {

  // Right

  }
  else if(state=='S')
  {

  // Stop

  }

}

