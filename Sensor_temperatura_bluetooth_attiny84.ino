#include "SoftwareSerial.h"
#define RxD 5
#define TxD 4

int temp=1;
String readString;

SoftwareSerial blueToothSerial(RxD,TxD);


void setup() {
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  setupBlueToothConnection();
  pinMode(4,OUTPUT);
 
}

void loop() {
  temp = ((5.0 * analogRead(A7) * 100.0)/1024);
  blueToothSerial.print(temp);
  blueToothSerial.println("ºC");
  if(temp>=80)
  {
    digitalWrite(4,HIGH);
  }
    if(temp<80)
  {
    digitalWrite(4,LOW);
  }
  delay(1000);   
}

void setupBlueToothConnection()
{
  blueToothSerial.begin(9600); //Set BluetoothBee BaudRate to default baud rate 38400
  blueToothSerial.print("\r\n+STWMOD=0\r\n"); //set the bluetooth work in slave mode
  blueToothSerial.print("\r\n+STNA=HC-05\r\n"); //set the bluetooth name as "HC-05"
  blueToothSerial.print("\r\n+STOAUT=1\r\n"); // Permit Paired device to connect me
  blueToothSerial.print("\r\n+STAUTO=0\r\n"); // Auto-connection should be forbidden here
    blueToothSerial.println("ºC");
  
  delay(2000); // This delay is required.
  //blueToothSerial.print("\r\n+INQ=1\r\n"); //make the slave bluetooth inquirable 
  blueToothSerial.print("bluetooth connected!\n");
  
  delay(2000); // This delay is required.
  blueToothSerial.flush();
}
