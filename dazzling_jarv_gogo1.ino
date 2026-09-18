#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define Gb3 208
#define C4 262
#define F3 175
#define A3 220

const int midi1[13][3] = {
 {Gb3, 115, 0},
 {C4, 115, 0},
 {Gb3, 115, 0},
 {F3, 115, 0},
 {A3, 115, 115},
 {Gb3, 115, 0},
 {C4, 115, 0},
 {Gb3, 115, 0},
 {F3, 115, 0},
 {A3, 115, 0},
};

void playMidi(int pin, const int notes[][3], size_t len)
{
 for (int i = 0; i < len; i++) {
    tone(pin, notes[i][0]);
    delay(notes[i][1]);
    noTone(pin);
    delay(notes[i][2]);
  }
}

#include <Servo.h>
#include <Adafruit_LiquidCrystal.h>
#define Rojo 11
#define Verde 10
#define Azul 9
#define boton 3
#define temp A2
#define pote A1
#define pinServo A0
Adafruit_LiquidCrystal lcd1(0);
Servo servo1;
int valorPote;
bool valorboton;
int segundos;
int temperatura;
int RealValorTemperatura;

void setup()
{
  servo1.attach(A0);
  lcd1.begin(16,2);
  pinMode(Rojo, OUTPUT);
  pinMode(Verde, OUTPUT);
  pinMode(Azul, OUTPUT);
  pinMode(boton, INPUT);
  Serial.begin(9800);
}

void loop()
{
  lcd1.setCursor(1,0);
  
  AbrirCerrar();
  prenderLed();
  
  Serial.println("Valor Temperatura: ");
  Serial.println(RealValorTemperatura);
  
  Serial.println("Valor potenciometro: ");
  Serial.println(valorPote);
  
  Serial.println("Valor Boton: ");
  Serial.println(valorboton);
  delay(1000);
}

void prenderLed()
{
   temperatura = analogRead(temp);
   RealValorTemperatura = map(((temperatura - 20) * 3.04), 0, 1058, -40, 125);
   
   if(RealValorTemperatura > 40)
   {
     digitalWrite(Rojo, HIGH);
     digitalWrite(Azul, LOW);
   }
   else
   {
     digitalWrite(Azul, HIGH);
     digitalWrite(Rojo,LOW);
   }
}
    
void AbrirCerrar()
{
  valorboton = digitalRead(boton);
  
  valorPote = analogRead(pote);
  valorPote = map(valorPote,0,1023,0,100);
  
  if(valorboton == LOW)
  {
    if(valorPote < 25)
    {
      segundos = 2;
      for(int i = 0;i <= 10; i++)
      {
        Abrir();
        lcd1.print("Servo moviendose");
        lcd1.print("Melodia");
        digitalWrite(Verde, HIGH);
        delay(segundos);
        Cerrar();
        lcd1.print("Servo moviendose");
        delay(segundos);
      }
    }
    else if(valorPote >= 25 && valorPote < 50)
    {
      segundos = 5;
      for(int i = 0;i <= 10; i++)
      {
        Abrir();
        lcd1.print("Servo moviendose");
        lcd1.print("Melodia");
        digitalWrite(Verde, HIGH);
        delay(segundos);
        Cerrar();
        lcd1.print("Servo moviendose");
        delay(segundos);
      }
    }
    else if(valorPote > 50)
    {
      segundos = 8;
      for(int i = 0;i <= 10; i++)
      {
        Abrir();
        lcd1.print("Servo moviendose");
        lcd1.print("Melodia");
        digitalWrite(Verde, HIGH);
        delay(segundos);
        Cerrar();
        lcd1.print("Servo moviendose");
        delay(segundos);
      }
    }
  }
}

void Abrir()
{
 servo1.write(90); 
}

void Cerrar()
{
 servo1.write(0); 
}