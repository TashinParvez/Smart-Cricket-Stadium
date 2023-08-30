#include<Servo.h>
#include<Stepper.h>


int ser = 7; // arduino pin for servo

Servo serat;
int ang = 96; // our = zero degree  || motor 96
int a = A0; // left pin sensor input  [ sensor er higgest 33 deegree ] 66 degree left moving
int b = A1;  // right pin sensor input [ sensor er higgest 153 deegree  ] 57 degree right moving

// sensor inputs
int sout2;
int sout1;

int solarFlag2 = 0;
int solarFlag1 = 0;

// pitch
int steps = 2048;
Stepper stepper(steps, 10, 12, 11, 13);

int pitchFlag = 0;
int pitchFlag1 = 0;

void setup()
{
  // put your setup code here, to run once:
  //pinMode(a, INPUT);
  Serial.begin(9600);  // ask
  serat.attach(ser); // where to start from // ser =96

  // pitch
  Serial.begin(9600);
  stepper.setSpeed(2);

}

void loop() {
  while(Serial.available())
  {
    int scan = Serial.read();
    if (scan == 1){
    solarMechanism();
    }
    else if (scan == 2) {
    pitchMechanism();
    }
  }
}
int solarMechanism() {

  Serial.print("1. Exicute solar mechanism\n 2. Exit"); // consol print
  if (Serial.available())
  {
    int s = Serial.read();
    if (s == 1) {
      // put your main code here, to run repeatedly
      sout1 = analogRead(a);
      sout2 = analogRead(b);

      Serial.print("A1: "); // consol print
      Serial.print(sout1);
      Serial.print("         A2: ");
      Serial.println(sout2);




      if (sout1 > 800 && sout2 < 200)
      {

        for (; !((sout1 + sout2) <= 400) && ang <= 115 && !((sout1 + sout2) >= 1600); ang++)
          //
        {
          // Serial.println("NOOOOOPPPPEEEE!!!!");
          serat.write(ang); // REWRITE THE ANGLE

          // sensor input
          sout1 = analogRead(a);
          sout2 = analogRead(b);

          Serial.print("A1: ");
          Serial.print(sout1);
          Serial.print("         A2: ");
          Serial.println(sout2);

          solarFlag1 = 1; // for DETECT rotate right done
          delay(1);
        }
      }


      if (sout2 > 800 && sout1 < 200)
      {
        //    int flag=0;

        for (; !((sout1 + sout2) <= 400) && ang >= 66 && !((sout1 + sout2) >= 1600); ang--)
        {
          Serial.println("Yeeeeeeeeeeeeeeeeeeeeeeepppppp!!!!!!");
          serat.write(ang);
          // sensor input
          sout1 = analogRead(a);
          sout2 = analogRead(b);

          Serial.print("A1: ");
          Serial.print(sout1);
          Serial.print("         A2: ");
          Serial.println(sout2);

          delay(1);
          solarFlag1 = 0;
        }
      }



      if ((sout1 + sout2) >= 1600)
      {
        //delay(2000);
        for (; !((sout1 + sout2) <= 1600); )
        {

          sout1 = analogRead(a);
          sout2 = analogRead(b);
          Serial.print("A1: ");
          Serial.print(sout1);
          Serial.print("         A2: ");
          Serial.println(sout2);
          Serial.println(ang);

          if (solarFlag1 == 0 && ang >= 66)
          {

            ang--;
            serat.write(ang);
            if (ang < 66) solarFlag1 = 1;
          }
          else if (solarFlag1 == 1 && ang <= 115)
          {
            ang++;
            serat.write(ang);
            if (ang > 115) solarFlag1 = 0;
          }
        }

      }
    }
    else {
      return 0;
    }
  }


  }
int  pitchMechanism() {
    if (Serial.available())
  {
    int s = Serial.read();

    if (s == 1) {
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
    else {
      return 0;
    }
  }
}
