#define V 2
#define R 13
#define sensor 7
#define buzz 4
bool movimiento = false;

void setup()
{
  pinMode(R,OUTPUT);
  pinMode(V,OUTPUT);
  pinMode(movimiento, INPUT);
}

void loop()
{
  movimiento = digitalRead(sensor);
  if(movimiento == true)
  {
    digitalWrite(R, HIGH);
    digitalWrite(V, LOW);
    delay(10);
    tone(buzz,1000);
  }
  else
  {
    digitalWrite(V, HIGH);
    digitalWrite(R, LOW);
    delay(10);
    noTone(buzz);
  }
}