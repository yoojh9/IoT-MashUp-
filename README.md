# IoT-edu

int lightPin = 0; // 0번과 3번 단자 번호를 저장할 변수를 선언하고 이름을 부여한다. 
int tempPin = 1;
int flamePin = 2;
int ledPin = 9; //
int buzzerPin = 10;

void setup()
{
  pinMode(ledPin, OUTPUT); // ledPin 단자를 출력모드로 설정한다.
  pinMode(buzzerPin, OUTPUT); 
  Serial.begin(9600);
}

void loop()
{ 
 int lightLevel = analogRead(lightPin);
 int tempLevel = analogRead(tempPin);
 int flameLevel = analogRead(flamePin);
 
 lightLevel = map(lightLevel, 0, 1023, 0, 255);

 Serial.println(lightLevel);

 if(lightLevel > 200) {

  analogWrite(ledPin, 255-lightLevel);
  analogWrite(buzzerPin, 100);     
 } else {
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, 0);
 }
                                                       
 delay(100); // 100ms간 대기한다.
}
