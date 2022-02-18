/******************************************************************************* 
  *  Áster Electrónica
  *  Contador binario
  *  Abstract: En este ejemplo, se realizará el control de 4
  *  servomotores mediante 4 potenciometros.
  *  Creado por Miguel AngelLo.
  *  LinkedIn: @miguelangello21
  *  Conexiones físicas:
  *        Tarjeta UNO | Entradas 
  *               5V -> VCC
  *              GND -> GND
  *               A0 <- Potenciometro 1
  *               A1 <- Potenciometro 2
  *               A2 <- Potenciometro 3
  *               A3 <- Potenciometro 4
  *        Tarjeta UNO | Salidas 
  *               3(PWM) -> Servomotor 1
  *               5(PWM) -> Servomotor 2
  *               6(PWM) -> Servomotor 3
  *               9(PWM) -> Servomotor 4          
********************************************************************************/
//Incluimos la biblioteca Servo (Hay que descargarla)
#include <Servo.h>

//Declaramos los 4 servomotores que vamos a usar
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;



//Esta variable nos ayudara a convertir los datos del potenciometro y pasarla a "grados"
int val;   

//Este ciclo sólo se ejecuta una sola vez
void setup() {
  //Declaramos nuestras 4 entradas analógicas
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  
  //A cada servo le asignamos el pin de salida que le corresponde, esta función declara estos pines como salidas
  servo1.attach(3);  // attaches the servo on pin 3 to the servo object
  servo2.attach(5);  // attaches the servo on pin 5 to the servo object
  servo3.attach(6);  // attaches the servo on pin 6 to the servo object
  servo4.attach(9);  // attaches the servo on pin 9 to the servo object

}

//Este ciclo se ejecuta infinitamente
void loop() {
  //En este parte se controla el servo1
  val = analogRead(A0);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  servo1.write(val);                  // sets the servo position according to the scaled value

  //En este parte se controla el servo2
  val = analogRead(A1);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  servo2.write(val);                  // sets the servo position according to the scaled value

  //En este parte se controla el servo3
  val = analogRead(A2);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  servo3.write(val);                  // sets the servo position according to the scaled value

  //En este parte se controla el servo4
  val = analogRead(A3);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  servo4.write(val);                  // sets the servo position according to the scaled value
  


}
