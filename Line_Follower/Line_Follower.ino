
int inp1;
int inp2;
int inp3;
int inp4;
int inp5;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);



}

void loop() {
  // put your main code here, to run repeatedly:

  inp1 = analogRead(A0);
  inp2 = analogRead(A1);
  inp3 = analogRead(A2);
  inp4 = analogRead(A3);
  inp5 = analogRead(A4);

  Serial.print(inp1);
  Serial.print(" ");
  Serial.print(inp2);
  Serial.print(" ");
  Serial.print(inp3);
  Serial.print(" ");
  Serial.print(inp4);
  Serial.print(" ");
  Serial.print(inp5);
  Serial.print("\n\n");


}
