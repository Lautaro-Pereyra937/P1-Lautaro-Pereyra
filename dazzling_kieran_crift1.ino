#define boton 2
#define boton1 4
#include <Servo.h>

Servo servo1;
Servo servo2;
bool movimiento;
bool movimiento2;
int rotacion = 0;

void setup()
{
  pinMode(boton, INPUT);
  pinMode(boton1, INPUT);
  servo1.attach(A1);
  servo1.write(0);
  servo2.attach(A2);
  servo2.write(0);
}

void loop()
{
   movimiento = digitalRead(boton);
   movimiento2 = digitalRead(boton1);
   if(movimiento == LOW)
   {
       avanzar();
   }
   else if(movimiento2 == LOW)
   {
       retroceder();
   }
}

void avanzar()
{
   rotacion = rotacion + 10;
   servo1.write(rotacion);
   servo2.write(rotacion);
   delay(1000);
   if(rotacion > 180)
   {
     rotacion = rotacion - 10; 
   }
}

void retroceder()
{
       rotacion = rotacion - 10;
       servo1.write(rotacion);
       servo2.write(rotacion);
       delay(1000);
       if(rotacion < 0)
       {
         rotacion = rotacion + 10; 
       }
}