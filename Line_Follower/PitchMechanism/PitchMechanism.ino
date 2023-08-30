#include <Stepper.h>
//int sensor=900;
int steps = 2048;
Stepper stepper(steps, 10, 12, 11, 13);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stepper.setSpeed(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A3);
  Serial.println(value);


    stepper.step(-820);
    Serial.println("Pitch is covered");
    delay(1000);
     stepper.step(820);




  

}
