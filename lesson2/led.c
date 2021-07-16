void setup(){
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}
void loop(){  
  int i = 6;  
  for(; i < 14;i++)  
  {    
    digitalWrite(i,HIGH);    
    delay(250);    
    digitalWrite(i,LOW);
  }
}