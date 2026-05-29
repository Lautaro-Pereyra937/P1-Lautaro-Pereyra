#define A 5
#define valortemp 2
#define sensor 7
#define valorpoten A1
bool movimiento = LOW;
float potenciometro = 0;
float temperatura = 0;

void setup()
{
  pinMode(A,OUTPUT);
  pinMode(movimiento, INPUT);
  pinMode(valortemp, INPUT);
  pinMode(potenciometro, INPUT);
  pinMode(valorpoten, INPUT);
}

void loop()
{
  movimiento = digitalRead(sensor);
  potenciometro = digitalRead(valorpoten);
  temperatura = digitalRead(valortemp);
  if(potenciometro > 50 && temperatura > 20)
  {
    if(movimiento == HIGH)
    {
      analogWrite(A , 200);
      delay(100);
    }
    else
    {
      analogWrite(A, 0);
      delay(100);
    }
  }
}