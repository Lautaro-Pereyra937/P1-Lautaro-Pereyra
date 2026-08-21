#define sensor1 2
#define sensor2 4
#define bombilla 6
#define luz A2
#include <Servo.h>
#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define Fb5 740
#define G5 784
#define Gb5 831
#define A5 880
#define Ab5 932

Servo servo1;
Servo servo2;
bool movimiento1;
bool movimiento2;
int rotacion = 0;
int valorluz;
int realvalorluz;

const int midi1[5][3] = {
 {Fb5, 273, 0},
 {G5, 273, 0},
 {Gb5, 273, 0},
 {A5, 273, 0},
 {Ab5, 273, 0},
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


void setup()
{
  pinMode(luz, INPUT);
  playMidi(13, midi1, ARRAY_LEN(midi1));
  servo1.attach(A0);
  servo1.write(0);
  servo2.attach(A1);
  servo2.write(0);
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
}

void loop()
{
  movimiento1 = digitalRead(sensor1);
  movimiento2 = digitalRead(sensor2);
  
  valorluz = analogRead(luz);
  realvalorluz = map(valorluz ,0,1023,0,100);
  
  Serial.println("Valor luz:");
  Serial.println(realvalorluz);
  
  delay(200);
  
  prender_foquito();
  abrir_cerrar();
  delay(1000);
}

void abrir_cerrar()
{
  if(movimiento1 == HIGH || movimiento2 == HIGH)
  {
     retroceder(); 
     playMidi(13, midi1, ARRAY_LEN(midi1));
  }
  else
  {
    avanzar();
  }
}

void prender_foquito()
{
  if(realvalorluz < 30)
  {
    analogWrite(bombilla, 255);
  }
  else
  {
    analogWrite(bombilla, 0);
  }
}

void avanzar()
{
  rotacion = 80;
  rotacion = rotacion + 10;
  servo1.write(rotacion);
  servo2.write(rotacion);
  if(rotacion > 80)
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
