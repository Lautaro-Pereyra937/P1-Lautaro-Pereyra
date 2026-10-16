#include <Servo.h>
#define led 4
#define boton 2
#define luz A1

Servo Servo1;
bool valorboton;
int valorluz;
int valorservo;

void setup()
{
  Servo1.attach(A0);
  pinMode(led, OUTPUT);
  pinMode(boton, INPUT);
  Serial.begin(9600);
}

void loop()
{
  valorboton = digitalRead(boton);
  valorluz = analogRead(luz);
  int realvalorluz = map(valorluz, 0, 1023, 0, 100);
  
  Serial.println("Valor boton");
  Serial.println(valorboton);
  
  Serial.println("-------");
  
  Serial.println("Valor luz:");
  Serial.println(valorluz);
  delay(1500);
  
  
  if (valorluz < 20  && valorboton == LOW)
  {
    digitalWrite(led, HIGH);
  }
  
  if (valorboton == LOW)
  {
    abrir();
    delay(1000);
    cerrar();
    delay(1000);
  }
}

void abrir()
{
  Servo1.write(80);
}

void cerrar()
{
  Servo1.write(0);
}