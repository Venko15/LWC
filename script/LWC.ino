#include <SoftwareSerial.h> // TX RX software library for bluetooth

#include <Servo.h> // servo library 
Servo myservo; // servo name

int bluetoothTx = 0; // bluetooth tx to 10 pin
int bluetoothRx = 1; // bluetooth rx to 11 pin
int servop = -1;
int IN1 = 7;
int IN2 = 6;
int IN3 = 5;
int IN4 = 4;
int ENA = 9;
int ENB = 3;

SoftwareSerial bluetooth(0, 1);
void setup()
{

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
 pinMode(ENB, OUTPUT);
  //myservo.attach(9); // attach servo signal wire to pin 9
  //Setup usb serial connection to computer
  Serial.begin(9600);
  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
  myservo.write(90);
}

void loop()
{
  //Read from bluetooth and write to usb serial
  if (bluetooth.available() > 0 ) // receive number from bluetooth
  {
    int Move;
    Move = bluetooth.read();
    Serial.print(Move);
    Serial.print(" ");
    if(Move  == 5){
       analogWrite(ENA, 0);
       analogWrite(ENB, 0);
       digitalWrite(IN1,LOW);
       digitalWrite(IN2,LOW);
       digitalWrite(IN3,LOW);
       digitalWrite(IN4,LOW);    
    }
    else if (Move == 1) {
        //myservo.write(130);
       analogWrite(ENA, 130);
       analogWrite(ENB, 130);
       digitalWrite(IN1,HIGH);
       digitalWrite(IN2,LOW);
       digitalWrite(IN3,LOW);
       digitalWrite(IN4,HIGH);    
    }
    else if (Move == 2) {
      Serial.print(" tuka suuuum  ");
       analogWrite(ENA, 130);
       analogWrite(ENB, 80);
       digitalWrite(IN1,HIGH);
       digitalWrite(IN2,LOW);
       digitalWrite(IN3,LOW);
       digitalWrite(IN4,HIGH);    

    }else if(Move == 3){
       analogWrite(ENA, 80);
       analogWrite(ENB, 130);
       digitalWrite(IN1,HIGH);
       digitalWrite(IN2,LOW);
       digitalWrite(IN3,LOW);
       digitalWrite(IN4,HIGH);    
      
      
      }
      else if(Move == 4){
       analogWrite(ENA, 100);
       analogWrite(ENB, 100);
       digitalWrite(IN1,LOW);
       digitalWrite(IN2,HIGH);
       digitalWrite(IN3,HIGH);
       digitalWrite(IN4,LOW);    
      }
      

  }
  //Serial.println(servopos);
  // serial print servopos current number received from bluetooth
  // roate the servo the angle received from the android app
}
