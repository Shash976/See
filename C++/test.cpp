// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int motorPin = 3;
#define MOTOR_1 6
#define MOTOR_A 5
#define MOTOR_B 8

#define slow 64  
#define normal 128  
#define fast 255  
   
int Speed; // initialization of speed variable  

// defines variables
long duration;
int distance;
void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(MOTOR_1, OUTPUT);  
  pinMode(MOTOR_A, OUTPUT);  
  pinMode(MOTOR_B, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}

void ultraSound(){
    // Clears the trigPin
  	digitalWrite(trigPin, LOW);
  	delayMicroseconds(2);
  	// Sets the trigPin on HIGH state for 10 micro seconds
  	digitalWrite(trigPin, HIGH);
  	delayMicroseconds(10);
  	digitalWrite(trigPin, LOW);
  	// Reads the echoPin, returns the sound wave travel time in microseconds
 	duration = pulseIn(echoPin, HIGH);
  	// Calculating the distance
  	distance = duration * 0.034 / 2;
  	// Prints the distance on the Serial Monitor
  	Serial.print("Distance: ");
  	Serial.println(distance);
  }

void motorNormal(){
    digitalWrite(motorPin, HIGH);
  }

void Forward_Rev(void)  
{  
  analogWrite(MOTOR_1, Speed);  
  digitalWrite(MOTOR_A, HIGH);  
  digitalWrite(MOTOR_B, LOW);  
}  
void Backward_Rev(void)  
{  
  analogWrite(MOTOR_1, Speed);  
  digitalWrite(MOTOR_A, LOW);  
  digitalWrite(MOTOR_B, HIGH);  
}  
   
void Forward_ramp_up(void)  
{  
  digitalWrite(MOTOR_A, HIGH);  
  digitalWrite(MOTOR_B, LOW);  
  for (int i=0; i<255; i++) // loop started  
    //value set from 0 to 255  
  {   
    analogWrite(MOTOR_A, i);   
    delay(15); // delay time in milliseconds  
  }   
}   
void Forward_ramp_down(void)  
{   
  digitalWrite(MOTOR_A, HIGH);  
  digitalWrite(MOTOR_B, LOW);   
    
  for (int i=255; i>=0; i--) // loop set in reverse direction  
   // value set from 255 to 0 (reverse)  
  {  
    analogWrite(MOTOR_A, i);  
    delay(15);  
  }  
}  
 // same statement but within different function  
void Backward_ramp_up(void)  
{  
  digitalWrite(MOTOR_A, LOW);  
  digitalWrite(MOTOR_B, HIGH);  
  for (int i=0; i<255; i++)   
  { analogWrite(MOTOR_A, i);   
   delay(15);   
   // we can modify the delay time as per the requirements  
  }   
}   
void Backward_ramp_down(void)  
{   
  digitalWrite(MOTOR_A, LOW);  
  digitalWrite(MOTOR_B, HIGH);   
    
  for (int i=255; i>=0; i--)   
  {  
    analogWrite(MOTOR_A, i);  
    delay(15);  
  }  
}  
   
void Brake(void)  
{  
  digitalWrite(MOTOR_A, HIGH);  
  digitalWrite(MOTOR_B, HIGH);  
}

void mainMotor() {
  Speed=slow; // Slow Speed  
  // we can modify the value as fast, slow, and normal depending on the required speed  
  //the motor will revolve according to the specified speed  
  // for example, fast will cause it to move at fast speed  
  // we can also add more parameters using #define  
   
  Forward_Rev();   
  delay(1000);  
  Brake();  
  delay(500);  
  Backward_Rev();   
  delay(1000);  
  Brake();  
  delay(500);  
  Forward_ramp_up();  
  Forward_ramp_down();  
  Backward_ramp_up();  
  Backward_ramp_down();  
}

void loop() {
  mainMotor() ;
  
}