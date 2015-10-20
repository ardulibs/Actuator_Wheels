#include <Servo.h>
#include <ActuatorWheels.h>

int left_servo_pin = 6;
int right_servo_pin = 9;
int velocity = 10;

ActuatorWheels wheels;

void setup() {
  Serial.begin(9600);
  wheels.attach(left_servo_pin, right_servo_pin);
  
  Serial.println("1. Move fordward");
  Serial.println("2. Move backward");
  Serial.println("3. Rotate clockwise");
  Serial.println("4. Rotate counterclockwise");
  Serial.println("5. Stop");
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
        wheels.moveFordward(velocity);
        break;
      case 2:
        Serial.println("Move backward");
        wheels.moveBackward(velocity);
        break;
      case 3:
        Serial.println("Rotate clockwise");
        wheels.rotateClockwise(velocity);
        break;
      case 4:
        Serial.println("Rotate counterclockwise");
        wheels.rotateCounterclockwise(velocity);
        break;
      case 5:
        Serial.println("Stop");
        wheels.stopAdvance();
        break;
      default:
        Serial.println("Unknown order");
     }
}