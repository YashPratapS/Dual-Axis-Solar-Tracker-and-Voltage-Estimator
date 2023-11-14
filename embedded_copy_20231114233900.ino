#include <Servo.h>

Servo myservohori; //horizontal servo(BOTTOM SERVO)
int servoh = 0; //assign servo at 0 degree
int servohLimitHigh = 180; //maximum range of servo is 180 degree(it is variable you can also change)
int servohLimitLow = 10;   //minimum range of servo is 10 degree(it is variable you can also change)

Servo myservoverti; //vertical servo(TOP SERVO) 
int servov = 0; 
int servovLimitHigh = 180;
int servovLimitLow = 10;

int ldrtopr = A1; //top right LDR A1 pin
int ldrtopl = A2; //top left LDR A2 pin

int ldrbotr = A0; // bottom right LDR A0 pin
int ldrbotl = A3; // bottom left LDR A3 pin
int topl = 0;
int topr = 0;
int botl = 0;
int botr = 0;

 void setup () 
 {
  Serial.begin(9600);
  myservohori.attach(2); //horizontal servo connected to arduino pin 10
  myservohori.write(0);
  
  myservoverti.attach(3); //vertical servo connected to arduino pin 9
  myservoverti.write(0);
  delay(500); //delay
 }

void loop()
{
  servoh = myservohori.read();
  servov = myservoverti.read();
  
  
  int topl = analogRead(ldrtopl); //read analog values from top left LDR
  int topr = analogRead(ldrtopr); //read analog values from top right LDR
  int botl = analogRead(ldrbotl); //read analog values from bottom left LDR
  int botr = analogRead(ldrbotr); //read analog values from bottom right LDR
  
  
  int avgtop = (topl + topr) / 2; //average of top LDRs
  int avgbot = (botl + botr) / 2; //average of bottom LDRs
  int avgleft = (topl + botl) / 2; //average of left LDRs
  int avgright = (topr + botr) / 2; //average of right LDRs
  Serial.print(avgtop);
  Serial.print(" ");
  Serial.print(avgbot);
  Serial.print(" ");
  Serial.print(avgleft);
  Serial.print(" ");
  Serial.print(avgright);
  Serial.println(" ");

  if (avgtop > avgbot)
  {
    myservoverti.write(servov -3);
    if (servov > servovLimitHigh) 
     { 
      servov = servovLimitHigh;
     }
    delay(8);
  }
  else if (avgbot > avgtop)
  {
    myservoverti.write(servov +3);
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
    delay(8);
  }
  else 
  {
    myservoverti.write(servov);
  }
  
  if (avgleft > avgright)
  {
    myservohori.write(servoh +3);
    if (servoh > servohLimitHigh)
    {
    servoh = servohLimitHigh;
    }
    delay(8);
  }
  else if (avgright > avgleft)
  {
    myservohori.write(servoh -3);
    if (servoh < servohLimitLow)
     {
     servoh = servohLimitLow;
     }  
    delay(8);
  }
  else 
  {
    myservohori.write(servoh); // write means run servo
  }  delay(50);
}









































