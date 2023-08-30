#include <Servo.h>

Servo myservo1;
Servo myservo2;

int inp1 = 12;
int inp2 = 7;
int en1 = 6;

int pwm = 32;
int flag = 0;
int d = 3600;
char c;

int ang1 = 90;
int ang2 = 160;
int s1 = 3;
int s2 = 4;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(inp1, OUTPUT);
  pinMode(inp2, OUTPUT);
  
  pinMode(en1, OUTPUT);
   myservo1.attach(s1);
  myservo2.attach(s2);

  myservo2.write(ang2);
  myservo1.write(ang1);



}

void loop() {



  if (Serial.available()) {
    c = Serial.read();
    if (c == 'w') {

      flag = 0;
      if (flag == 0) {
        srp();
        l();
        r();
        sip();
        flag++;
      } else if (flag == 1) {
        analogWrite(en1, 0);
      }
    }
  } else {
    analogWrite(en1, 0);
  }
}


void r() {
  Serial.println("Inn RIGHT");
  digitalWrite(inp1, 0);
  digitalWrite(inp2, 1);

  analogWrite(en1, pwm);

  delay(d);
  Serial.println("OUT From RIGHT");
}

void l() {
  Serial.println("Inn LEFT");
  digitalWrite(inp1, 1);
  digitalWrite(inp2, 0);

  analogWrite(en1, pwm);

  delay(d);

  Serial.println("OUT From LEFT");
}

void srp() {
  while (ang1 > 0) {
    ang1--;
    myservo1.write(ang1);
    Serial.print("Ang1: ");
    Serial.println(ang1);
    delay(10);
  }
  while (ang2 > 130) {
    ang2--;
    myservo2.write(ang2);
    Serial.print("    Ang2: ");
    Serial.println(ang2);
    delay(10);
  }
  
}

void sip() {
  while (ang2 < 160) {
    ang2++;
    myservo2.write(ang2);
    Serial.print("    Ang2: ");
    Serial.println(ang2);
    delay(10);
  }
  while (ang1 < 90) {
    ang1++;
    myservo1.write(ang1);
    Serial.print("Ang1: ");
    Serial.println(ang1);
    delay(10);
  }
}
