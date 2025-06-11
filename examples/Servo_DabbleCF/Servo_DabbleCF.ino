/*
  ============================================================
   PROYECTO BALAM 2025 – Reto STEM - GenericController
   Universidad Galileo | Grupo Intelecto
  ============================================================

   Descripción:
     Fase: COMPITE.
     Control de movimiento de robot con cuatro motores DC
     mediante diferentes controles genéricos. Controles probados:
      - Control Marvo para PS4
      - Control GameSir Nova Lite Control Inalámbrico

   Objetivo:
     Controlar el robot en direcciones básicas (adelante, atrás,
     izquierda, derecha y detener) utilizando el joystick derecho.
     Igualmente la activación del mecanismo por medio del joystick
     izquierdo.

   Librerías:
    - ESP32Servo
    - Bluepad32
      https://github.com/ricardoquesada/bluepad32/

   Autor(es):
     Gabriela Subuyú – Tesla Lab
     Mateo Garcia - Grupo Intelecto
     Nesthor Guillermo - Grupo Intelecto
     Equipo BALAM / Grupo Intelecto

   Fecha: Mayo 2025
   Versión: 2.0
   Estado: Funcional(FASE COMPITE)

   Organización: https://github.com/proyectobalam
   Repositorio: https://github.com/proyectobalam/balam-2025-completo
   Tutorial/Referencia: https://racheldebarros.com/esp32-projects/connect-your-game-controller-to-an-esp32/
  ============================================================
*/

// ==============================================================
// Importación de librerías
#include <ESP32Servo.h>
Servo myservo;

//Incluir libreria del Dabble
#include <DabbleESP32.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE



void setup() {
  Serial.begin(115200);   // Iniciar el monitor serial  
  Dabble.begin("Balam2");       //Nombre del BT
  myservo.attach(4);
}

void loop() {

  Dabble.processInput(); // Esperando conexión por BT            
  Serial.println("KeyPressed: ");


  if (GamePad.isTrianglePressed())
  {
    Serial.print("Triangle");  
      myservo.write(90); 
  }
  if (GamePad.isSquarePressed())
  {
    Serial.print("Square");
    myservo.write(0);
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("Circle");
    myservo.write(180);
  }
  

  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
  }
}
 
