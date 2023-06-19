/*
 * Source code for Line follower Robot using Arduino Uno
 * Equipments: Arduino Uno
 *             L298N Motor Driver
 *             Infrared Obstacle avoidance Sensor (2)
 *             4WD Robot car
 *             3X 18650 3.7v battery (11.1v)
 *      
 * Author : Elijah Echekwu
 * Project: Implementing and designing a prototype of a line follower robot. 
 *          Line follower robots are used in industries to convey processes 
 *          from point to point in a production line. This eliminate the need 
 *          for paid labour and increase the overall production efficiency.
 *          
 * url: www.github.com/Elijah57/line-follower
 *          
*/

//L298N pins
#define IN_1   2 
#define IN_2   4
#define IN_3   8
#define IN_4   7
#define ENa    3
#define ENb    5

//infrared obstacle avoidance sensor pins
const int LeftIR = 9;
const int RightIR = 10;

// variables to hold the sensor state
int LS , RS ;

void setup() {
Serial.begin(9600);

//declare the pins as output
pinMode(IN_1 , OUTPUT);
pinMode(IN_2 , OUTPUT);
pinMode(IN_3 , OUTPUT);
pinMode(IN_4 , OUTPUT);
pinMode(ENa , OUTPUT);
pinMode(ENb , OUTPUT);
 
// declare sensor pins as input
pinMode(LeftIR , INPUT );
pinMode(RightIR , INPUT);
}

void loop() {

LS = digitalRead(LeftIR); //Read left sensor
RS = digitalRead(RightIR); //Read right sensor

 if(RS == 0 && LS == 0){ // move forward if both sensors are on white/ reflective surface
  forward();
 }
 if (RS == 1 && LS == 0){ //turn right, if right sensor is on the line
  right();
 }
 if (RS == 0 && LS == 1){ // turn left, if left sensor is on the line
  left();
 }
 if (RS == 1 && LS == 1){ // halt , if both sensors are on the line
  halt();
 }
}

void forward(){
  digitalWrite(IN_1 , HIGH);
  digitalWrite(IN_2 , LOW);
  digitalWrite(IN_3 , HIGH);
  digitalWrite(IN_4 ,LOW);

  analogWrite(ENa ,80);
  analogWrite(ENb ,80);
}

void halt(){
  digitalWrite(IN_1 , LOW);
  digitalWrite(IN_2 , LOW);
  digitalWrite(IN_3 , LOW);
  digitalWrite(IN_4 , LOW);

}

void left(){
  digitalWrite(IN_1 , HIGH);
  digitalWrite(IN_2 , LOW);
  digitalWrite(IN_3 , LOW);
  digitalWrite(IN_4 , HIGH);

  analogWrite(ENa ,80);
  analogWrite(ENb ,80);
  
}

void right(){
  digitalWrite(IN_1 , LOW);
  digitalWrite(IN_2 , HIGH);
  digitalWrite(IN_3 , HIGH);
  digitalWrite(IN_4 , LOW);

  analogWrite(ENa ,80);
  analogWrite(ENb ,80);
}
