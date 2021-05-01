#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(11,10); 

int LED = 9;

#define R2 8
#define R1 7
#define L1 2
#define L2 3

void setup() 
{   
 Serial.begin(9600); 
 MyBlue.begin(9600); 
 pinMode(9, OUTPUT); 
 pinMode (R1, OUTPUT);
 pinMode (R2, OUTPUT);
 pinMode (L1, OUTPUT);
 pinMode (L2, OUTPUT);
 pinMode (13,OUTPUT);
 pinMode (12,OUTPUT);

} 

char flag = 0;

void loop() 
{ 
while (MyBlue.available())

{
  delay (1);
   flag = MyBlue.read(); 


 if (flag == 'F') 
 { 
  forward();
 } 
 else if (flag == 'B') 
 { 
  back();
 }
 
 else if (flag == 'R')
 {
  right();
 }

else if (flag == 'L')
{
  left();
}

else 
stop();

 Serial.println (flag);
}
}

void back()
{
digitalWrite (L1, LOW);
digitalWrite (L2, HIGH);
digitalWrite (R2, HIGH);
digitalWrite (R1, LOW);
}

void forward()
{digitalWrite (L1, HIGH);
digitalWrite (L2, LOW);
digitalWrite (R2, LOW);
digitalWrite (R1, HIGH);
  }

void right()
{digitalWrite (L1, HIGH);
digitalWrite (L2, LOW);
digitalWrite (R2, HIGH);
digitalWrite (R1, LOW);
  }

void left()
{
digitalWrite (L1, LOW);
digitalWrite (L2, HIGH);
digitalWrite (R2, LOW);
digitalWrite (R1, HIGH);
}

void stop()
{
digitalWrite (L1, LOW);
digitalWrite (L2, LOW);
digitalWrite (R2, LOW);
digitalWrite (R1, LOW);
}
