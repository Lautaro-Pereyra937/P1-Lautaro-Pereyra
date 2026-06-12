#define valortemp A0
#define movi 5
#define boton 4
#include <Servo.h>

Servo servo1;
Servo servo2;
bool movimiento = LOW;
bool moviboton = HIGH;
int temperatura = 0;
int rotacion = 0;

void setup()
{
  pinMode(boton, INPUT);
  pinMode(movi, INPUT);
  pinMode(valortemp, INPUT);
  
  servo1.attach(10);
  servo1.write(0);
  servo2.attach(9);
  servo2.write(0);
}

void loop()
{
  movimiento = digitalRead(movi);
  moviboton = digitalRead(boton);
  
  temperatura = analogRead(valortemp);
  temperatura = map(((temperatura - 20) * 3.04), 0, 1023, -40, 125);
  
  if(moviboton == LOW)
  {
    servo_intervalo();
    if(movimiento == HIGH)
    {
       servo0();
       if(temperatura > 35)
       {
         servo_quieto();
       }
    }
  }
  else if(moviboton == HIGH)
  {
    servoquietocuarentaycinco();
  }
}

void servo_intervalo()
{
  rotacion += 90;

  if (rotacion > 180) 
  {
    rotacion = 90;
  }

  servo1.write(rotacion);
  servo2.write(rotacion);
  delay(3000);
}

void servo_quieto()
{
  servo1.write(rotacion);
  servo2.write(rotacion);
  delay(6000);
}

void servo0()
{
  rotacion = 0;
  servo1.write(rotacion);
  servo2.write(rotacion);
  delay(6000);
}

void servoquietocuarentaycinco()
{
  rotacion = 45;
  servo1.write(rotacion);
  servo2.write(rotacion);
  delay(100);
}