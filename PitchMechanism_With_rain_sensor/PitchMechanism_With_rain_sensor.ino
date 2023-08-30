#include<Stepper.h>


//int sensor=900;
int steps = 2048;
Stepper stepper(steps, 10, 12, 11, 13);

int pitchFlag = 0;
int pitchFlag1 = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stepper.setSpeed(2);


}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A2);
      Serial.println(value);

      if (value < 450) {
        Serial.println("Rain Detected");
        pitchFlag = 1;
      }
      else if (value > 450)
      {
        pitchFlag = 0;
        Serial.println("No Rain");
      }
      if (value < 450 && pitchFlag == 1 && pitchFlag1 == 0) {
        pitchFlag1 = 1;
        //Serial.println("cover is coming out");
        Serial.println("cover is coming out In 5 sec");
        Serial.println("5");
        delay(1000);
        Serial.println("4");
        delay(1000);
        Serial.println("3");
        delay(1000);
        Serial.println("2");
        delay(1000);
        Serial.println("1");
        delay(1000);
        Serial.println("0");


        stepper.step(820);
        Serial.println("Pitch is covered");
        delay(1000);



      }
      else if (value > 450 && pitchFlag1 == 1 ) {

        Serial.println("Rain Over");
        Serial.println("please enter input");


        while (Serial.available() == 0) {
        }
        int n = Serial.parseInt();
        switch (n) {
          case 1:
            Serial.println("Umpare will oveserve the pitch");
            stepper.step(-500);
            Serial.println("case 1 done");
            break;

          case 2:
            //flag1 = 0;
            Serial.println("Umpare decision");
            Serial.println("pitch is not good to play");
            stepper.step(500);
            break;

          case 3:
            pitchFlag1 = 0;
            Serial.println("pitch is good to play");
            stepper.step(-320);
            break;

  
}
      }
}
