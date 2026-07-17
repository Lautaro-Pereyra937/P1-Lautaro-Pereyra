#define sensor 7
#define poten A0
#define temp A1
#define luz A2
#define R 8
#define V 4
#define A 2

int potenciometro;
bool movimiento;
int temperatura;
int valorpote;
int valortemp;
int valorluz;
int realvalorluz;

void setup()
{
  pinMode(potenciometro, INPUT);
  pinMode(movimiento, INPUT);
  pinMode(temperatura, INPUT);
  pinMode(luz, INPUT);
  pinMode(R, OUTPUT);
  pinMode(V, OUTPUT);
  pinMode(A, OUTPUT);
  Serial.begin(9800);
}

void loop()
{
  movimiento = digitalRead(sensor);
  
  potenciometro = analogRead(poten);
  valorpote = map(potenciometro,0,1023,0,100);
  
  temperatura = analogRead(temp);
  valortemp = map(((temperatura - 20) * 3.04), 0, 1023, -40, 125);
  
  valorluz = analogRead(luz);
  realvalorluz = map(valorluz ,0,674,0,100);
  
  Serial.println("Valor potenciometro:");
  Serial.println(valorpote);  
  Serial.println("Valor temperatura:");
  Serial.println(valortemp);
  Serial.println("Valor sensor movimiento:");
  Serial.println(movimiento);
  Serial.println("Valor luz:");
  Serial.println(realvalorluz);
  
  delay(1200);
  
  
  if(valorpote > 50 && valorpote < 75)
  {
    if(valortemp < 15)
    {
      if(movimiento == HIGH)
      {
        digitalWrite(R, HIGH);
        digitalWrite(V, LOW);
        digitalWrite(A, LOW);
        delay(1000);
        
        digitalWrite(R, LOW);
        digitalWrite(V, HIGH);
        digitalWrite(A, LOW);
        delay(1000);
        
        digitalWrite(R, LOW);
        digitalWrite(V, LOW);
        digitalWrite(A, HIGH);
        delay(1000);
      }
    }
  }
  if(realvalorluz == 100)
  {
    digitalWrite(R, HIGH);
    digitalWrite(V, HIGH);
    digitalWrite(A, HIGH);
    delay(1000);
    
    digitalWrite(R, LOW);
    digitalWrite(V, LOW);
    digitalWrite(A, LOW);
    delay(1000);
  }
}