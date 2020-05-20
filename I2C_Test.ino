#include <Wire.h>

#define Slave_Address  16

String Tx_Data = "AB" ;
int Tx_Size = sizeof(Tx_Data) ;
byte Rx_Data ;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(Slave_Address);                // join i2c bus with address #16
  Wire.onReceive(RX_Event); // register event (Fn. runs when receive data from Master
  Wire.onRequest(Tx_Event);     // register event (Fn. runs To send data to Master after receiving Master request for Data)
  Serial.begin(9600);           // start serial for output  
  Serial.println("Starting I2C Slave Mode");
}

void loop() {
  // put your main code here, to run repeatedly:

}

void RX_Event()
{
  while(0 < Wire.available()) // Read While data received
  {
        Rx_Data = Wire.read();  
  }   
    Serial.print("Received Data from Master: ");         // print the character   
    Serial.print(Rx_Data);         // print the character
    Serial.print('\n');         // New Line
}

void Tx_Event()
{
      
      char Data_Packet[2] ;      // 21

      for (byte i = 0 ; i < 2 ; i++ )
      {
        Data_Packet[i]  = (byte)Tx_Data.charAt(i);  
        Wire.write(Data_Packet[i]) ;  // For array use ---> Wire.write(byte_Array , sizeof(byte_Array)) ;
        Serial.print("Data sent are: ");         // print the character
        Serial.print(Data_Packet[i]);         // print the character  
        Serial.print('\n');         // new Line 
      }
      
      int The_Size = sizeof(Data_Packet) ;
      Serial.print("Data_Packet Size is: ");         // print the character 
      Serial.println(Tx_Size);         // print the character 
}
