#include <max6675.h>
int sensorPin = A0;
int sensorValue =A0;
float vol;
int buzzerPin = 13;
int ktcSO = 8;
int ktcCS = 9;
int ktcCLK = 10;

MAX6675 ktc(ktcCLK, ktcCS, ktcSO);

  
void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  delay(500);
  pinMode(13,OUTPUT);
}

void loop() {
  
  
   Serial.print("Deg C = "); 
   Serial.print(ktc.readCelsius());
   Serial.print("\t Deg F = ");
   Serial.println(ktc.readFahrenheit());
   sensorValue = analogRead(sensorPin);
   vol=(float)sensorValue/12; //scale işlemi(ortama göre değer sınırlandırması)
   Serial.print("PPM=");
   Serial.println(vol,1);
   Serial.println(sensorValue);
  {
    if (vol>38){ 
    Serial.print("GAZ KAÇAĞI  ");
    digitalWrite(13,HIGH);
    } else {Serial.print("Gaz kaçağı yok  ");
    digitalWrite(13,LOW);
    
  
    }
  }
  
       delay(1000);
}
