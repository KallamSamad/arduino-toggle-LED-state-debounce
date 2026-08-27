#define LED_PIN_1 11
#define LED_PIN_2 10
#define LED_PIN_3 9
#define BUTTON_1 2

unsigned long startTime=millis();
unsigned long startLEDTime=millis();
unsigned long timeDelay=1000;

byte LED_state_2 = LOW;
byte buttonState=LOW;
int toggleState=1;
int debounceDelay=50;


void toggleLED(){
      if(toggleState==1){
      toggleState=2;
      digitalWrite(LED_PIN_1,HIGH);
      digitalWrite(LED_PIN_3,LOW);

    }
    else{
      toggleState=1;
      digitalWrite(LED_PIN_1,LOW);
      digitalWrite(LED_PIN_3,HIGH);
    }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_PIN_1,OUTPUT);
  pinMode(LED_PIN_2,OUTPUT);
  pinMode(LED_PIN_3,OUTPUT);
  pinMode(BUTTON_1, INPUT);




}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long endTime=millis();
   
  if(endTime-startTime>timeDelay){
 

    if(LED_state_2==LOW){
      LED_state_2=HIGH;
    }
    else{
      LED_state_2=LOW;
    }
    digitalWrite(LED_PIN_2,LED_state_2);
    startTime+=timeDelay;

  }
  if(endTime-startLEDTime>debounceDelay){
    byte newButtonState=digitalRead(BUTTON_1);
    if(buttonState!=newButtonState){
      startLEDTime=endTime;
      buttonState=newButtonState;
      if (buttonState==HIGH){
      toggleLED();
      }
  }
  }
}
