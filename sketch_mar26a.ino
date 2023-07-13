// These lines declare the pin numbers for the ultrasonic sensor's trigger pin, echo pin, and the buzzer pin.

int trigPin = 9;
int echoPin = 10;
int buzzer = 7;

//In the `setup()` function, we initialize the serial communication with a baud rate of 9600, set the pinMode for the trigger pin and buzzer pin as
//OUTPUT, and set the pinMode for the echo pin as INPUT.

void setup() {
  Serial.begin(9600); 
   pinMode(buzzer, OUTPUT);
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

//In the loop() function, we declare two variables duration and distance as long. We set the trigger pin HIGH for 10 microseconds and then LOW to 
//send an ultrasonic pulse. We measure the duration it takes for the pulse to return to the sensor using the pulseIn() function, and then we convert
//this duration into distance in centimeters using the formula distance = (duration/2)/29.1. We then print the distance on the serial monitor along
//with the unit "CM" and add a delay of 10 milliseconds.

void loop() {
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);
 
 if((distance<=60)) 
  {
    
    tone(buzzer,200);   //200 milliseconds delay
    delay(200);
    noTone(buzzer);    //then we turn off the buzzer using the noTone() function for another 200 milliseconds
    delay(200);
}
   else if(distance>60)
 {
     
    
   }
}