#include <Wire.h>

#define SLAVE 4

volatile char stm1 = 1;
volatile char stm2 = 2;
volatile char stm3 = 4;
volatile char stm4 = 8;

volatile int rfm1 = 0;
volatile int rfm2 = 0;
volatile int rfm3 = 0;
volatile int rfm4 = 0;

void setup()
{
  Wire.begin(4);
  Serial.begin(115200);


 Wire.onRequest(requestEvent);
 Wire.onReceive(receiveEvent);
}


void loop ()
{
  //Wire.write(stm);
}



void requestEvent()
{
  Wire.write(stm1);
  Wire.write(stm2);
  Wire.write(stm3);
  Wire.write(stm4);
}


void receiveEvent()
{
   rfm1 = Wire.read();
   rfm2 = Wire.read();
   rfm3 = Wire.read();
   rfm4 = Wire.read();
    Serial.println(rfm1); // 마스터로부터 수신된 데이터 출력
    Serial.println(rfm2); // 마스터로부터 수신된 데이터 출력
}
