#define led 13
void setup(){
pinMode(led,OUTPUT);
digitalWrite(led,HIGH);
delay(2000);
Serial.begin(9600);
Serial.println("Enter the following for controlling the LED in different ways");  
Serial.println("1 for steady on ; 2 for slow blink ; 3 for fast blink ;0 for no light ;");
digitalWrite(led,LOW);



}
 enum mode{
  steady,slow,fast,stop
  };
  
unsigned long lasttime = 0;
mode ledstate = stop;
bool state = false;
void loop(){
    unsigned long time = millis();
 
  if(Serial.available()){
  char num = Serial.read();
   if(num =='1'){
    ledstate = steady;
      Serial.println("IN ON STATE");
   }
   else if(num =='2'){
     ledstate = slow;
      Serial.println("IN SLOW BLINKING STATE");
   }
   else if(num =='3'){
     ledstate = fast;
      Serial.println("IN FAST BLINKING STATE");
   }
   else if(num =='0'){
     ledstate = stop;
      Serial.println("IN OFF STATE");
   }
  }
  switch (ledstate){
  case stop : 
    digitalWrite(led,LOW);
   
    break ;
  case steady :
    digitalWrite(led,HIGH);
   
    break;
  case slow :
   
    if(time - lasttime >= 1000){
     state = !state;
      digitalWrite(led,state);
      lasttime = time;
    }
    break;
  case fast :
    
    if(time - lasttime >= 300){
     state = !state;
      digitalWrite(led,state);
      lasttime = time;
    }
    break;
  }
  
}
//URAT controlled led FSM Machine
