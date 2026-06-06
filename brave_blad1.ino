#define A 5
#define R 6
#define V 3
#define valortemp 2
#define sensor 7
#define valorpoten A1
bool movimiento = LOW;
int potenciometro = 0;
int temperatura = 0;

void setup()
{
  pinMode(A,OUTPUT);
  pinMode(movimiento, INPUT);
  pinMode(valortemp, INPUT);
  pinMode(potenciometro, INPUT);
}

void loop()
{
  movimiento = digitalRead(sensor);
  potenciometro = analogRead(valorpoten);
  potenciometro = map(potenciometro,0, 1023, 0, 100);

  temperatura = analogRead(valortemp);
  temperatura = map(((temperatura - 20) * 3.04), 0, 1023, -40, 125);
  
  if(potenciometro > 50 && temperatura > 20)
  {
    if(movimiento == HIGH)
    {
      analogWrite(R , 64);
      analogWrite(V, 224);
      analogWrite(A, 208);
      delay(100);
    }
    else
    {
      analogWrite(A, 0);
      delay(100);
    }
  }
}
