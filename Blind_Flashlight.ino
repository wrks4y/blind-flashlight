//definitions to clarify code
#define trigPin 3
#define echoPin 2
#define vibePin 6
#define potPin A1


void setup() {
  //set up inputs and outputs
  pinMode(vibePin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(potPin, INPUT);
 
}

void loop() {
  // define variables for main loop
  float duration, distance, power, potVal;

//make sure the trigger is off
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);

//pulse trigger pin 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

//read the echo of the pulse and calulate distance using the pulse and the speed of sound  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;

//check potentiometer
  potVal = (analogRead(potPin)/200) +1;
  
  if(distance <= 300){
    //if it is in range then set the motor to a power that moves inverely with distance and scales according to the position of the potentiometer
    power = (1023 - (distance*potVal));
    if (power >= 800){
      analogWrite(vibePin,power); 
    }
    else{
      analogWrite(vibePin,0); 
    }
  }
  if(distance > 300){
   // if it is out of range then turn off the motor
   analogWrite(vibePin,0); 
  }

  //short delay to keep the code running smoothly
  delay(50);
}

