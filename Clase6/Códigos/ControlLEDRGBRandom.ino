/******************************************************************************* 
  *  Áster Electrónica
  *  Contador binario
  *  Abstract: En este ejemplo, se conecta un LED RGB a las salidas PWM del
  *  Arduino UNO, los colores cambian aleatoriamente cada 3 segundos.
  *  Creado por Miguel AngelLo.
  *  LinkedIn: @miguelangello21
  *  Conexiones físicas:
  *        Tarjeta UNO | Entradas 
  *               5V -> VCC
  *              GND -> GND
  *               A0 <- Potenciometro1
  *               A1 <- Potenciometro2
  *               A2 <- Potenciometro3
  *        Tarjeta UNO | Salidas 
  *               5V -> VCC
  *              GND -> GND
  *                3 -> BLUE
  *                5 -> GREEN
  *                6 -> RED        
********************************************************************************/
void setup() {
//Declaramos A0,A1 y A2 como entradas.
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(A2,INPUT);
//Declaramos el pin digital 3, 5 y 6 como salidas. Nótese que están marcados en la placa por un ~
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
}

void loop() {
  //La función random nos regresa un número aleatorio de 0 a 255.
  analogWrite(3,random(0,255));
  analogWrite(5,random(0,255));
  analogWrite(6,random(0,255));
  //Colocamos un delay para que el color cambie cada 3 segundos 
  delay(3000);
}
