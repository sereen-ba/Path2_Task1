int switchPinFwd = 2;  
int potentiometerIn;
//Motor1
const int MotorPin1 = 5;
const int MotorPin2 = 6;


//Motor2
const int MotorPin3 = 10;
const int MotorPin4 = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(switchPinFwd, INPUT_PULLUP);
  pinMode(MotorPin1, OUTPUT);
  pinMode(MotorPin2, OUTPUT);
  pinMode(MotorPin3, OUTPUT);
  pinMode(MotorPin4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potentiometerIn = analogRead(A0);
  int output = potentiometerIn / 4; //divide the potentiometer input by 4 so it can be used in the AnalogWrite function
 
  if(digitalRead(switchPinFwd) == HIGH) //Check to see if the pin is high or low
  {
    //If the pin is HIGH, it must be set to forward
      analogWrite(MotorPin1, output);
      analogWrite(MotorPin4, output);
    //Output our potentiometer value on the forward pin.
  }
  else
  {
    //Otherwise the switch must be set to Reverse
    analogWrite(MotorPin2, output);
    analogWrite(MotorPin3, output);//Output our potentiometer value on the forward pin.
  }
  delay(25);
}
