//Define pin numbers
const int trigPin = 11;
const int echoPin = 12;
const int bluePin = 2;
const int greenPin = 3;
const int orangePin = 4;

//Define variables
long duration;
int distance;

void setup() {
  //Initialize serial communication
  Serial.begin(9600);

  //Set pin modes
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode (bluePin, OUTPUT);
  pinMode (greenPin, OUTPUT);
  pinMode (orangePin, OUTPUT);
}

void loop() {
  //Clear the trig pin by setting it low
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //Trigger the trig pin by sending a 10 microsecond pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58;
  Serial.println(distance);

  if (distance <= 5){
    digitalWrite(bluePin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(orangePin, HIGH);
  }
  else if (distance <= 10){
    digitalWrite(bluePin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(orangePin, LOW);
  }
  else if (distance <= 20){
    digitalWrite(bluePin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(orangePin, LOW);
  }
  else {
    digitalWrite(bluePin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(orangePin, LOW);
  }
}
