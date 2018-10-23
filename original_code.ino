  #include <Wire.h>

#define SLAVE_ADDRESS 0x04

void setup() 
{
    Serial.begin(9600);         // start serial for output
    Wire.begin(SLAVE_ADDRESS);
    Wire.onReceive(receiveData);
    Wire.onRequest(sendData);
    Serial.println("Ready!");
}
int pin,flag=0;
int val;
int fer = 987;
char chislo;

void loop()
{
  if(flag==1)
  {
    Serial.println(pin);
    val=analogRead(pin);
    sendData();
    flag=0;
  }
}

void receiveData(int byteCount)
{
    while(Wire.available()>0) 
    {
      pin=Wire.read();
      flag=1;
      
    }
}

// callback for sending data
void sendData()
{
  if(fer > 255 && fer < 512) chislo = 1;
  else if( fer > 511 && fer < 768) chislo = 2;
  else if(fer > 767) chislo = 3;
  Wire.write(fer);
  Wire.write(chislo);
  
}
