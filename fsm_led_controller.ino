// C++ code
#define led 13
#define button 10
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(button,INPUT_PULLUP);
  
  digitalWrite(led,HIGH);
  delay(1000);
 digitalWrite(led,LOW);

}

unsigned long lasttime = 0;
bool ledState = false;
 enum state {
  IDLE,SLOW,FAST
  };
state currently = IDLE;
void loop()
{
  unsigned long time = millis();
  switch(currently){
  case IDLE :
    digitalWrite(led,HIGH);
    if(digitalRead(button)==LOW){
      currently = SLOW;
      delay(300);
    }
     break;
    case SLOW :
    digitalWrite(led,LOW);
    if(time - lasttime >= 1000){
      ledState = !ledState;
      digitalWrite(led,ledState);
      lasttime = time;
    }
     if(digitalRead(button)==LOW){
      currently = FAST;
       ledState = false;
       lasttime = time;
       delay(300);
    }
    break;
    
    case FAST :
    digitalWrite(led,LOW);
    if(time - lasttime >= 300){
    
      ledState = !ledState;
      digitalWrite(led,ledState);
      lasttime = time; 
  }
   if(digitalRead(button)==LOW){
     
      currently = IDLE;
     
    lasttime = time;
     delay(300);
    }
     break;
}
}
//Initial FSM implementation with millis() timing
