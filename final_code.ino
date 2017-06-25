#define D0 8
#define D1 9
#define D2 10
#define D3 11
#define yellow_led 2
#define red_led 3
#define green_led 4
#define ac_relay 5
#define dc_relay 6
#define dc_relay2 7

void device_1()
{
   digitalWrite(green_led,HIGH);
}
void device_2()
{
   digitalWrite(red_led,HIGH);
}
void device_3()
{
   digitalWrite(yellow_led,HIGH);
}
void device_4()
{
   digitalWrite(ac_relay,HIGH);
}
void device_5()
{
   digitalWrite(dc_relay,HIGH);
   digitalWrite(dc_relay2,HIGH);
}
void Stop()
{
   digitalWrite(green_led,LOW);
   digitalWrite(red_led,LOW);
   digitalWrite(yellow_led,LOW);
   digitalWrite(ac_relay,LOW);
   digitalWrite(dc_relay,LOW);
   digitalWrite(dc_relay2,LOW);
}
void setup() 
{
  pinMode(D0, INPUT);
  pinMode(D1, INPUT);
  pinMode(D2, INPUT);
  pinMode(D3, INPUT);
  pinMode(ac_relay, OUTPUT);
  pinMode(dc_relay, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(dc_relay2, OUTPUT);
  
}

void loop() 
{
 
  int temp1=digitalRead(D0);
  int temp2=digitalRead(D1);
  int temp3=digitalRead(D2);
  int temp4=digitalRead(D3);
 
  
  if(temp1==1 && temp2==0 && temp3==1 && temp4==1) //2
  device_1();
  else if(temp1==1 && temp2==1 && temp3==0 && temp4==1) //4
  device_2();
  else if(temp1==1 && temp2==0 && temp3==0 && temp4==1) //6
  device_3();
  else if(temp1==1 && temp2==1 && temp3==1 && temp4==0) //8
  device_4();
  else if(temp1==1 && temp2==0 && temp3==1 && temp4==0) //0
  device_5();
  else if(temp1==0 && temp2==1 && temp3==0 && temp4==1) //5
  Stop();


}
