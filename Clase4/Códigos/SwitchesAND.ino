/******************************************************************************* 
  *  Áster Electrónica
  *  Operador booleano AND
  *  Abstract: En este ejemplo, se usan operadores booleanos, evaluaremos 
  *  el estado de 4 switches para encender un LED.
  *  Creado por Miguel AngelLo.
  *  LinkedIn: @miguelangello21
  *  Conexiones físicas:
  *        Tarjeta UNO | Entradas 
  *               5V -> VCC
  *              GND -> GND
  *               10 <- B0
  *               11 <- B1
  *               12 <- B2  
  *               13 <- B3
  *        Tarjeta UNO | Salidas 
  *               5V -> VCC
  *              GND -> GND
  *                2 -> D0(LED)         
********************************************************************************/ 

//void setup es un ciclo que sólo se ejecuta una vez, sirve para ejecutar las configuraciones del microcontrolador al encenderlo  
void setup() {
  //Declaramos las entradas y salidas con la función pinMode
  //pinMode(numeroDePin,estado);
  //En este caso usaremos 4 entradas y 1 salida
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  pinMode(2,OUTPUT);
  
}

//void loop es un ciclo que se va a ejecutar de manera infinita, es un bucle infinito
void loop() {
  //Evaluamos 4 condiciones AND de manera simultanea, únicamente si todos los switches están encendidos, el led encenderá.
  if((digitalRead(10)==HIGH)&&(digitalRead(11)==HIGH)&&(digitalRead(12)==HIGH)&&(digitalRead(13)==HIGH)){
    digitalWrite(2,HIGH);
    }
  //Si la condición no se cumple, la condición if nunca encenderá el led
  digitalWrite(2,LOW);

}
