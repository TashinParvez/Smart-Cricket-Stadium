
int inp1;
int inp2;
int flag0 = -1;
int flag1 = -1;
int count = 4;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);



}

void loop()
{
  delay(400);
  // put your main code here, to run repeatedly:

  inp1 = analogRead(A5);
  inp2 = analogRead(A4);


  Serial.print(inp1);
  Serial.print(" ");
  Serial.print(inp2);

  Serial.print("\n\n");

  
  inp1 = analogRead(A5);
  inp2 = analogRead(A4);


  Serial.print(inp1);
  Serial.print(" ");
  Serial.print(inp2);

  Serial.print("\n\n");
  if (inp2 > 600 ) {
    flag0 = 1;
  }
  if (flag0 == 1 && inp1 > 600) {
    flag0 = -1;
    Serial.print("Player is out from 30 Yards");
    count--;
    if (count < 10) {
      Serial.print("No Ball ");
      Serial.println(count);
    }
  }
  if (inp1 > 600) {
    flag1 = 1;
  }
  if (flag1 == 1 && inp2 > 600) {
    flag1 = -1;
    Serial.print("Player is in 30 Yards ");
    count ++;
    Serial.println(count);
    delay(1000);
    inp1 = analogRead(A5);
    inp2 = analogRead(A4);
  }



  //
  //
  //  if (inp2 > 800 && inp1 < 200)
  //  {
  //    Serial.print("Player is out from 30 Yards");
  //    count--;
  //    if (count < 6) {
  //      Serial.print("No Ball");
  //      Serial.print("count");
  //    }
  //
  //  }
  //  else if (inp1 > 800 && inp2 < 200) {
  //    Serial.print("Player is in 30 Yards");
  //    count ++;
  //    Serial.print("count");
  //
  //  
  }
