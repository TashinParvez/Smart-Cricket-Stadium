int inp1;
int inp2;
int flag1 = 0;
int flag2 = 0;
int count = 8;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  
  // put your main code here, to run repeatedly:

  inp1 = analogRead(A4);
  inp2 = analogRead(A5);


  Serial.print(inp1);
  Serial.print(" ");
  Serial.println(inp2);

  if(flag1==0 && flag2==0) 
  {
    Serial.print("NO of PLAYERS: ");
    Serial.println(count);
    if(count<11){
    Serial.println("No Ball");
  }
  }
  if(flag1==1 && flag2==0) 
  {
    Serial.print("Player Entered...NO of Players: ");
    Serial.println(count);
    if(count<11){
    Serial.println("No Ball");
  }
  }
  if(flag1==0 && flag2==1) 
  {
    Serial.print("Player OUUUUUTTTT...NO of Players: ");
    Serial.println(count);
    if(count<11){
    Serial.println("No Ball");
  }
  }
  if(inp1>600 && inp2<600)
  {
    inn();
  }
  else if(inp1<600 && inp2>600)
  {
    out();
  }

 delay(1);
}

void inn()
{
  while(inp2<600)
  {
    inp1 = analogRead(A4);
    inp2 = analogRead(A5);

    Serial.print(inp1);
    Serial.print(" ");
    Serial.println(inp2);
    
    Serial.println("Waiting For Player to ENTER..... ");
  }
  count++;
  Serial.print("Player Entered...NO of Players: ");
  Serial.println(count);
  if(count<11){
    Serial.println("No Ball");
  }
  flag1 = 1;
  flag2 = 0;
  while(inp2>600)
  {
    
    Serial.print("Player Entered...NO of Players: ");
    Serial.println(count);
    if(count<11){
    Serial.println("No Ball");
  }

    inp1 = analogRead(A4);
    inp2 = analogRead(A5);

    Serial.print(inp1);
    Serial.print(" ");
    Serial.println(inp2);
  }
}

void out()
{
  while(inp1<600)
  {
    inp1 = analogRead(A4);
    inp2 = analogRead(A5);

    Serial.print(inp1);
    Serial.print(" ");
    Serial.println(inp2);
    
    Serial.println("Waiting For Player to OUUUTTT..... ");
  }
  count--;
  if(count<11){
    Serial.println("No Ball");
  }
  
  Serial.print("Player OUUUUUTTTT...NO of Players: ");
  Serial.println(count);
  flag1 = 0;
  flag2 = 1;
  while(inp1>600)
  {
    Serial.print("Player OUUTTT...NO of Players: ");
    Serial.println(count);
    if(count<11){
    Serial.println("No Ball");
  }

    inp1 = analogRead(A4);
    inp2 = analogRead(A5);

    Serial.print(inp1);
    Serial.print(" ");
    Serial.println(inp2);
  }
}
