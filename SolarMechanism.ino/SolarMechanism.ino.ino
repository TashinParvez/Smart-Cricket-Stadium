#include<Servo.h>

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

void setup() 
{
  // put your setup code here, to run once:
  //pinMode(a, INPUT);
  Serial.begin(9600);  // ask
  serat.attach(ser); // where to start from // ser =96
}

void loop() {
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
