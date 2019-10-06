int val = 0;
#define pin 2
#define button 0
unsigned long interval = 1000;
unsigned long interval2 = 100;
unsigned long _next =  millis() + interval;
unsigned long _next2 =  millis() + interval2;
int i = 0;
bool blink = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin,OUTPUT);
  pinMode(button,INPUT);
  Serial.begin(9600);
  digitalWrite(pin, HIGH);
  blink = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  led();
  buttonHandle();
}

int led(){
    
    if(blink){
      unsigned long  t = millis();
      if(t >= _next){
        digitalWrite(pin, !digitalRead(pin));
        _next = t + interval;
        
        }
           
  }
  return i;
}
int buttonHandle(){
  if(blink){
    unsigned long  t = millis();
    if(t >= _next2){

        if(digitalRead(button)==LOW){

        digitalWrite(pin,LOW);
        _next2 = t + interval2;
        
        Serial.println(button);
        digitalWrite(pin,HIGH);
        _next2 = t + interval2;
        
        }
  }
  
}
}
