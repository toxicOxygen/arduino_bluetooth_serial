String data;
int brightness = 0;
bool canClear = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    delay(10);
    char c = Serial.read();

    if(c == 10)
      canClear = true; 
    data += c;
  }

  if(canClear){
    canClear = false;
    data.trim();
    brightness = data.toInt();
    Serial.println(brightness);
    data = "";  
  }
  analogWrite(9,brightness);
}
