#define R 11
#define A 10
#define V 9

void setup()
{
  pinMode(R, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(V, OUTPUT); 
}

void loop()
{
  for(int x = 1;x <= 255;x ++)
  {
    analogWrite(R, x);
    for(int x = 1;x <= 255;x ++)
    {
      analogWrite(A, x);
      for(int x = 1;x <= 255;x ++)
      {
        analogWrite(V, x);
      }
    }
  }
}