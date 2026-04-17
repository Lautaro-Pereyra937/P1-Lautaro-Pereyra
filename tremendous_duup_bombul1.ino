void setup()
{ 
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop()
{ 
  analogWrite(11,255); 
  delay(1000); 
  
  analogWrite(11,0); 
  delay(1000); 
  //rojo
  
   for(int x = 0;x <=3;x++)  
   {
    analogWrite(11,255); 
    analogWrite(10,50);
    digitalWrite(13, HIGH); 
    analogWrite(3, 50); 
    analogWrite(9, 255); 
    analogWrite(6, 50); 
    delay(100); 
  
    analogWrite(11,0); 
    analogWrite(10,0);
    digitalWrite(13, LOW); 
    analogWrite(3, 0); 
    analogWrite(9, 0); 
    analogWrite(6, 0); 
    delay(100);
    }  
 
  digitalWrite(13, HIGH); 
  digitalWrite(2, HIGH); 
  delay(1000); 
  
  digitalWrite(13,LOW); 
  digitalWrite(2,LOW); 
  delay(1000); 
  //magenta
  
  for(int x = 0;x <=3;x++)  
   {
    analogWrite(11,255); 
    analogWrite(10,50);
    digitalWrite(13, HIGH); 
    analogWrite(3, 50); 
    analogWrite(9, 255); 
    analogWrite(6, 50); 
    delay(100); 
  
    analogWrite(11,0); 
    analogWrite(10,0);
    digitalWrite(13, LOW); 
    analogWrite(3, 0); 
    analogWrite(9, 0); 
    analogWrite(6, 0); 
    delay(100);
    }  
  
  analogWrite(6, 255); 
  analogWrite(5, 255); 
  delay(1000); 
  
  digitalWrite(6, 0); 
  digitalWrite(5, 0); 
  delay(1000); 
  //cian
   for(int x = 0;x <=3;x++)  
   {
    analogWrite(11,255); 
    analogWrite(10,50);
    digitalWrite(13, HIGH); 
    analogWrite(3, 50); 
    analogWrite(9, 255); 
    analogWrite(6, 50); 
    delay(100); 
  
    analogWrite(11,0); 
    analogWrite(10,0);
    digitalWrite(13, LOW); 
    analogWrite(3, 0); 
    analogWrite(9, 0); 
    analogWrite(6, 0); 
    delay(100);
    }    
}