#include <SoftwareSerial.h>

int rx = 2, tx = 3, state = 0;
SoftwareSerial device(rx, tx);

void reconfigDevice()
{
  device.write("AT+NAMEElderDevice");
  delay(1100);
  device.write("AT+PIN1234");
  delay(1100);
}

void setup()
{
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
  Serial.begin(4800);
  device.begin(9600);
  
  //uncoment if you want reconfig name or pin of bluetooth device
  //reconfigDevice();
}

void loop()
{
  Serial.print("waiting command: ");
  
  //do nothing until some thing comes
  while(!device.available());

  //do something if something comes
  Serial.println(dRead());

}

String dRead()
{ 
  char c;
  String out = "";
  while(device.available())
  {
    Serial.print(device.read());
    //if(c == '\n') break;
    //delay(10);
  }
  device.print(state = !state);
  if(out.length() <= 0) return ".";
  else return out;
}

