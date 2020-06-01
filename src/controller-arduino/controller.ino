const int up = 4;
const int down = 2;
const int left = 5;
const int right = 3;
const int stop = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  pinMode(stop, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(up) == LOW)
    Serial.write("F");
    
  else if(digitalRead(down) == LOW)
    Serial.write("B");

  else if(digitalRead(right) == LOW)
    Serial.write("R");

  else if(digitalRead(left) == LOW)
    Serial.write("L");

  else if(digitalRead(stop) == LOW)
    Serial.write("S");
}
