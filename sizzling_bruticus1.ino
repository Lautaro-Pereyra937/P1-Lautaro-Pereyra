#define R 11
#define A 10
#define V 6
#define PR A0
#define PA A1
#define PV A2
#define boton 2
int valorrojo;
int valorverde;
int valorazul;
bool valorboton;
void setup()
{
  pinMode(boton, INPUT);
  pinMode(R, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(V, OUTPUT);
  Serial.begin(9800);
}

void loop()
{
  valorrojo = analogRead(PR);
  valorazul = analogRead(PA);
  valorverde = analogRead(PV);
  valorboton = digitalRead(boton);
  valorrojo = map(valorrojo, 0, 1023, 0, 255);
  valorazul = map(valorazul, 0, 1023, 0, 255);
  valorverde= map(valorverde, 0, 1023, 0, 255);
  delay(1000);
  
  valorboton = digitalRead(boton);
  delay(100);
  if(valorboton == HIGH)
  {
    Serial.println("Tenes 10 segundos para cambiar el color");
    delay(10000);
    valorrojo = analogRead(PR);
    valorazul = analogRead(PA);
    valorverde = analogRead(PV);
    valorboton = digitalRead(boton);
    valorrojo = map(valorrojo, 0, 1023, 0, 255);
    valorazul = map(valorazul, 0, 1023, 0, 255);
    valorverde= map(valorverde, 0, 1023, 0, 255);
    Serial.print("Los colores del led son: ");
    Serial.println();
    Serial.println(valorrojo);
    Serial.println(valorazul);
    Serial.println(valorverde);
    
    prenderapagarled();
  }
}

void prenderapagarled()
{
  analogWrite(R, valorrojo);
  analogWrite(V, valorverde);
  analogWrite(A, valorazul);
  delay(10000);
  analogWrite(R, 0);
  analogWrite(V, 0);
  analogWrite(A, 0);
}