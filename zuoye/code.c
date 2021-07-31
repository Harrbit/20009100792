#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

#define LE1 12
#define LE2 13

int pinInterrupt=2;
int tick = -1; //计数值
byte income=0;
//中断服务程序
void myfunc()
{
  tick=-1;
  Serial.println(tick);
  digitalWrite(LE1,LOW);
  digitalWrite(LE2,LOW);
  income=0-'0';
  digitalWrite(IN1,income&0x1);
  digitalWrite(IN2,(income>>1)&0x1);
  digitalWrite(IN3,(income>>2)&0x1);
  digitalWrite(IN4,(income>>3)&0x1);
  digitalWrite(LE1,HIGH);
  digitalWrite(LE2,HIGH);
}
 
void setup()
{
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(7, INPUT);
  
  pinMode(LE1, OUTPUT);
  pinMode(LE2, OUTPUT);
  
  digitalWrite(LE1,HIGH);
  digitalWrite(LE2,LOW);

  Serial.begin(9600); //初始化串口
  
  attachInterrupt( 2, myfunc, FALLING);
}
 

void loop()
{
  ++tick;
  if(tick == 100) tick=0;
  if(tick%10==0) 
  {
    digitalWrite(LE1,LOW);
    income=(tick/10)%10-'0';
  	digitalWrite(IN1,income&0x1);
  	digitalWrite(IN2,(income>>1)&0x1);
  	digitalWrite(IN3,(income>>2)&0x1);
  	digitalWrite(IN4,(income>>3)&0x1);
    digitalWrite(LE1,HIGH);
  }
  income=tick%10-'0';
  digitalWrite(IN1,income&0x1);
  digitalWrite(IN2,(income>>1)&0x1);
  digitalWrite(IN3,(income>>2)&0x1);
  digitalWrite(IN4,(income>>3)&0x1);
  
  delay(1000);
  
}