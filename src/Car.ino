#include <SoftwareSerial.h>

SoftwareSerial miBT(0, 1);
char DATO;
int move;
// Definimos los pines de entrada del L298N
const int IN1_MOTOR_A_RETRO = 9;
const int IN2_MOTOR_A_AVA = 10;
const int IN3_MOTOR_B_AVA = 11;
const int IN4_MOTOR_B_RETRO = 12;

//defini pin de sensor y de servo
const int SENSOR = 6;
const int SERVO = 7;

void setup() {
  // Inicializamos los pines de salida del Arduino
  pinMode(IN1_MOTOR_A_RETRO, OUTPUT);
  pinMode(IN2_MOTOR_A_AVA, OUTPUT);
  pinMode(IN3_MOTOR_B_AVA, OUTPUT);
  pinMode(IN4_MOTOR_B_RETRO, OUTPUT);
  pinMode(SENSOR, INPUT);

  // Inicializamos el puerto serie y el módulo Bluetooth
  Serial.begin(9600); // Inicializamos el puerto serie a 9600 baudios
  miBT.begin(38400);
}

void loop() {
  // Hacemos que los motores giren hacia la derecha durante 5 segundos
  int sensorValue = digitalRead(SENSOR);
  int AUTO = HIGH;

      if(AUTO == HIGH){

        if(miBT.available())
        Serial.write(miBT.read());

        if(Serial.available())
        miBT.write(Serial.read());

        if(miBT.available()){
        DATO = miBT.read();


        Serial.println(DATO);

        switch (DATO)
        {
        case 'w':
          
          digitalWrite(IN2_MOTOR_A_AVA, HIGH);
          digitalWrite(IN3_MOTOR_B_AVA, HIGH);
          digitalWrite(IN1_MOTOR_A_RETRO, LOW);
          digitalWrite(IN4_MOTOR_B_RETRO, LOW);
          //delay(100);
          break;
        case 's':
          
          digitalWrite(IN2_MOTOR_A_AVA, LOW);
          digitalWrite(IN3_MOTOR_B_AVA, LOW);
          digitalWrite(IN1_MOTOR_A_RETRO, HIGH);
          digitalWrite(IN4_MOTOR_B_RETRO, HIGH);
          //delay(100);
          break;
        case 'a':
          
          digitalWrite(IN2_MOTOR_A_AVA, LOW);
          digitalWrite(IN3_MOTOR_B_AVA, HIGH);
          digitalWrite(IN1_MOTOR_A_RETRO, HIGH);
          digitalWrite(IN4_MOTOR_B_RETRO, LOW);
          delay(1000);

          digitalWrite(IN2_MOTOR_A_AVA, LOW);
          digitalWrite(IN3_MOTOR_B_AVA, LOW);
          digitalWrite(IN1_MOTOR_A_RETRO, LOW);
          digitalWrite(IN4_MOTOR_B_RETRO, LOW);
          break;
        case 'd':
          
          digitalWrite(IN2_MOTOR_A_AVA, HIGH);
          digitalWrite(IN3_MOTOR_B_AVA, LOW);
          digitalWrite(IN1_MOTOR_A_RETRO, LOW);
          digitalWrite(IN4_MOTOR_B_RETRO, HIGH);
          delay(1000);

          digitalWrite(IN2_MOTOR_A_AVA, LOW);
          digitalWrite(IN3_MOTOR_B_AVA, LOW);
          digitalWrite(IN1_MOTOR_A_RETRO, LOW);
          digitalWrite(IN4_MOTOR_B_RETRO, LOW);
          break;
        case 'q':
          
          digitalWrite(IN2_MOTOR_A_AVA, LOW);
          digitalWrite(IN3_MOTOR_B_AVA, LOW);
          digitalWrite(IN1_MOTOR_A_RETRO, LOW);
          digitalWrite(IN4_MOTOR_B_RETRO, LOW);
          //delay(100);
          break;
        default:
          
          digitalWrite(IN2_MOTOR_A_AVA, LOW);
          digitalWrite(IN3_MOTOR_B_AVA, LOW);
          digitalWrite(IN1_MOTOR_A_RETRO, LOW);
          digitalWrite(IN4_MOTOR_B_RETRO, LOW);
          //delay(100);
          break;
        }
      }

      }else if(AUTO == LOW){

        if(sensorValue == LOW){

      delay(300);
      digitalWrite(IN2_MOTOR_A_AVA, LOW);
      digitalWrite(IN1_MOTOR_A_RETRO, LOW);
      digitalWrite(IN3_MOTOR_B_AVA, LOW);
      digitalWrite(IN4_MOTOR_B_RETRO, LOW);
      delay(1000);

      digitalWrite(IN2_MOTOR_A_AVA, LOW);
      digitalWrite(IN1_MOTOR_A_RETRO, HIGH);
      digitalWrite(IN3_MOTOR_B_AVA, LOW);
      digitalWrite(IN4_MOTOR_B_RETRO, HIGH);
      delay(500);

      digitalWrite(IN2_MOTOR_A_AVA, LOW);
      digitalWrite(IN1_MOTOR_A_RETRO, LOW);
      digitalWrite(IN3_MOTOR_B_AVA, LOW);
      digitalWrite(IN4_MOTOR_B_RETRO, LOW);
      delay(1000);

      digitalWrite(IN2_MOTOR_A_AVA, LOW);
      digitalWrite(IN1_MOTOR_A_RETRO, HIGH);
      digitalWrite(IN3_MOTOR_B_AVA, HIGH);
      digitalWrite(IN4_MOTOR_B_RETRO, LOW);
      delay(500);

      digitalWrite(IN2_MOTOR_A_AVA, LOW);
      digitalWrite(IN1_MOTOR_A_RETRO, LOW);
      digitalWrite(IN3_MOTOR_B_AVA, LOW);
      digitalWrite(IN4_MOTOR_B_RETRO, LOW);
      delay(1000);
    }else if(sensorValue == HIGH){

      digitalWrite(IN2_MOTOR_A_AVA, HIGH);
      digitalWrite(IN1_MOTOR_A_RETRO, LOW);
      digitalWrite(IN3_MOTOR_B_AVA, HIGH);
      digitalWrite(IN4_MOTOR_B_RETRO, LOW);
    }
  }     
}
