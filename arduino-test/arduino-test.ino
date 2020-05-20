// analog pin
const int lightPin = 0; // 0번과 3번 단자 번호를 저장할 변수를 선언하고 이름을 부여한다. 
const int tempPin = 1;
const int flamePin = 2;

// digital pin
const int ledPin = 9;
const int buzzerPin = 10;
const int buttonPin = 7;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop()
{ 
 int lightLevel = analogRead(lightPin);
 int tempLevel = analogRead(tempPin);
 int flameLevel = analogRead(flamePin);
 int buttonState = digitalRead(buttonPin);
  
 lightLevel = map(lightLevel, 0, 1023, 0, 255);
 tempLevel = (125*tempLevel)>>8;
 flameLevel = 1; //임시

 Serial.print("Light:");
 Serial.println(lightLevel);
 Serial.print("Temp:");
 Serial.println(tempLevel);
 Serial.print("Flame:");
 Serial.println(flameLevel);
 
 if(lightLevel > 200 && tempLevel > 20 && flameLevel > 0) {
  analogWrite(ledPin, 255-lightLevel);
  analogWrite(buzzerPin, 100);     
 }

 // 버튼 누르면 led, buzzer off
 if(buttonState == HIGH){
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, 0);
 }
                                                       
 delay(100); // 100ms간 대기한다.
}
