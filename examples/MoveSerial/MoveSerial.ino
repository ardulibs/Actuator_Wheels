#include <Servo.h>

int stop_position = 95;
int rotate_velocity = 20;

int distance = 0;
int right_velocity = 0;
int left_velocity = 0;

int right_servo_pin = 9;
int left_servo_pin = 6;
int distance_pin = A0;

Servo right_servo;
Servo left_servo;

void setup() {
  Serial.begin(9600);
  right_servo.attach(right_servo_pin);
  left_servo.attach(left_servo_pin);
  
  Serial.println("1. Move fordward");
  Serial.println("2. Move backward");
  Serial.println("3. Rotate clockwise");
  Serial.println("4. Rotate counterclockwise");
  Serial.println("5. Stop");
  Serial.println("6. Get distance");
  Serial.println("Select option: ");
}

void loop() {
    int order = getOrder();
    executeOrder(order);    
}

int getOrder() {   
  int order = 0;
  //Recibimos la orden.
  if (Serial.available() > 0) {
    order = Serial.parseInt();
  }
  
  return order;
}

void executeOrder(int order) {
    //Ejecutamos la orden.
    switch(order){
      case 0:
        //No se ha recibido nada.
        break;
      case 1:
        Serial.println("Move fordward");
        moveFordward(20);
        break;
      case 2:
        Serial.println("Move backward");
        moveBackward(20);
        break;
      case 3:
        Serial.println("Rotate clockwise");
        rotateClockwise();
        break;
      case 4:
        Serial.println("Rotate counterclockwise");
        rotateCounterclockwise();
        break;
      case 5:
        Serial.println("Stop");
        stopAdvance();
        break;
      case 6:
        getDistance();
        break;
      default:
        Serial.println("Unknown order");
     }
}

void moveFordward(int velocity) {
  right_servo.write(stop_position+velocity);
  left_servo.write(stop_position+velocity);
}

void moveBackward(int velocity) {
  right_servo.write(stop_position-velocity);
  left_servo.write(stop_position-velocity);
}

void rotateClockwise() {
  right_servo.write(stop_position);
  left_servo.write(stop_position+rotate_velocity);
}

void rotateCounterclockwise() {
  right_servo.write(stop_position+rotate_velocity);
  left_servo.write(stop_position);  
}

void stopAdvance() {
  right_servo.write(stop_position);
  left_servo.write(stop_position);
}

void getDistance() {
  distance = random(1, 255);
  Serial.println(distance);
}
