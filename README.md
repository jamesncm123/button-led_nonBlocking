# button-led_nonBlocking
ฟังชั่น แต่ล่ะ ฟังชั่น ทำงาน โดย ไม่ยุ่งเกี่ยวกัน

int val = 0;
#define pin 2 // pin LED
#define button 0 // pin BUTTON
unsigned long interval = 1000; //delay LED
unsigned long interval2 = 100; //delay BUTTON
unsigned long _next =  millis() + interval; // กำหนดรอบถัดไปของเวลาที่จะ delay
unsigned long _next2 =  millis() + interval2; // กำหนดรอบถัดไปของเวลาที่จะ delay
int i = 0;
bool blink = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin,OUTPUT);
  pinMode(button,INPUT);
  Serial.begin(9600);
  digitalWrite(pin, HIGH);
  blink = true;  // setup blink
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
        digitalWrite(pin, !digitalRead(pin)); //เปิดปิดไฟ
        _next = t + interval; // delay
        
        }
           
  }
  return i;
}
int buttonHandle(){
  if(blink){
    unsigned long  t = millis();
    if(t >= _next2){ // check time

        if(digitalRead(button)==LOW){ //check button

        digitalWrite(pin,LOW);
        _next2 = t + interval2; // delay
        
        Serial.println(button);
        digitalWrite(pin,HIGH);
        _next2 = t + interval2; // delay
        
        }
  }
  
}
}

