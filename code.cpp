int num1Pin = A0;
int operPin = A1;
int num2Pin = A2;
int num1, num2, oper;
int output, outputTens;
int delayTime = 50; //milliseconds

void setup() {
  // put your setup code here, to run once:
  for (int i=0; i<=13; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
}

void loop() {

  //reading inputs from analog pins
  num1 = analogRead(num1Pin);
  oper = analogRead(operPin);
  num2 = analogRead(num2Pin);

  //converting input values
  num1 = map(num1, 0, 1023, 0, 10);
  oper = map(oper, 0, 1023, 0, 4);
  num2 = map(num2, 0, 1023, 0, 10);

  //deciding which operator to use for output
  if (oper < 1) {
  output = num1 + num2;
  }
  else if (oper < 2) {
  output = num1 - num2;
  }
  else if (oper < 3) {
  output = num1 * num2;
  }
  else {
  output = num1 / num2; // integer division
  }

  //sending 1s column output to 7 segment display
  if (output%10 == 0) {
        digitalWrite(11, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(12, HIGH);
  }
  else if (output%10 == 1) {
        digitalWrite(10, HIGH);
        digitalWrite(8, HIGH); 
  }
  else if (output%10 == 2) {
        digitalWrite(11, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(7, HIGH);
  }
  else if (output%10 == 3) {
        digitalWrite(11, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH); 
  }
  else if (output%10 == 4) {
        digitalWrite(10, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(7, HIGH); 
  }
  else if (output%10 == 5) {
        digitalWrite(11, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(7, HIGH); 
  }
  else if (output%10 == 6) {
        digitalWrite(11, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(7, HIGH); 
  }
  else if (output%10 == 7) {
        digitalWrite(11, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(8, HIGH); 
  }
  else if (output%10 == 8) {
	digitalWrite(11, HIGH);
	digitalWrite(10, HIGH);
	digitalWrite(8, HIGH);
	digitalWrite(6, HIGH);
	digitalWrite(5, HIGH);
	digitalWrite(12, HIGH);
        digitalWrite(7, HIGH);
  }
  else if (output%10 == 9) {
	digitalWrite(11, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(7, HIGH);
  }

  //sending 10s column output to 7 segment display
  outputTens = output / 10;
  if (outputTens%10 == 0) {
	digitalWrite(A5, HIGH);
        digitalWrite(13, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(1, HIGH);
        digitalWrite(A3, HIGH);
  }
  else if (outputTens%10 == 1){
        digitalWrite(13, HIGH);
        digitalWrite(3, HIGH);
  }
  else if (outputTens%10 == 2) {
	digitalWrite(A5, HIGH);
        digitalWrite(13, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(1, HIGH);
        digitalWrite(A4, HIGH);
  }
  else if (outputTens%10 == 3) {
	digitalWrite(A5, HIGH);
        digitalWrite(13, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(A4, HIGH);
  }
  else if (outputTens%10 == 4) {
        digitalWrite(13, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(A3, HIGH);
        digitalWrite(A4, HIGH); 
  }
  else if (outputTens%10 == 5) {
    	digitalWrite(A5, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(A3, HIGH);
        digitalWrite(A4, HIGH); 
  }
  else if (outputTens%10 == 6) {
    	digitalWrite(A5, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(1, HIGH);
        digitalWrite(A3, HIGH);
        digitalWrite(A4, HIGH); 
  }
  else if (outputTens%10 == 7) {
    	digitalWrite(A5, HIGH);
        digitalWrite(13, HIGH);
        digitalWrite(3, HIGH); 
  }
  else if (outputTens%10 == 8) {
	digitalWrite(A5, HIGH);
        digitalWrite(13, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(1, HIGH);
        digitalWrite(A3, HIGH);
        digitalWrite(A4, HIGH);
  }
  else if (outputTens%10 == 9) {
	digitalWrite(A5, HIGH);
        digitalWrite(13, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(A3, HIGH);
        digitalWrite(A4, HIGH);
  }

  delay(delayTime);
}
