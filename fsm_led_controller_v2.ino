// C++ code
// improved FSM implementation with proper debounce
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
unsigned long Bouncetime=0;
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
    if((digitalRead(button)==LOW)&& time - Bouncetime >=300){
      currently = SLOW;
      Bouncetime = time;
    }
     break;
    case SLOW :
   
    if(time - lasttime >= 1000){
      ledState = !ledState;
      digitalWrite(led,ledState);
      lasttime = time;
    }
     if((digitalRead(button)==LOW)&& time - Bouncetime >=300){
      currently = FAST;
       ledState = false;
       lasttime = time;
       Bouncetime = time;
     
    }
    break;
    
    case FAST :
   
    if(time - lasttime >= 300){
      ledState = !ledState;
      digitalWrite(led,ledState);
      lasttime = time; 
  }
   if((digitalRead(button)==LOW)&& time - Bouncetime >=300){
     currently = IDLE;
     lasttime = time;
     Bouncetime = time;
     
    }
     break;
}
}
