/******************************************************************************* 
  *  Áster Electrónica
  *  Contador binario
  *  Abstract: En este ejemplo, se controlarán 4 animaciones diferentes mostradas
  *  por los leds mediante la posición de los DIP Switch.
  *  Creado por Miguel AngelLo.
  *  LinkedIn: @miguelangello21
  *  Conexiones físicas:
  *        Tarjeta UNO | Entradas 
  *               5V -> VCC
  *              GND -> GND
  *               A0 <- C0
  *               A1 <- C1
  *               A2 <- C2  
  *               A3 <- C3
  *               10 <- B0
  *               11 <- B1
  *               12 <- B2  
  *               13 <- B3
  *        Tarjeta UNO | Salidas 
  *               5V -> VCC
  *              GND -> GND
  *                2 -> D0
  *                3 -> D1
  *                4 -> D2  
  *                5 -> D3
  *                6 -> D4
  *                7 -> D5
  *                8 -> D6  
  *                9 -> D7          
********************************************************************************/
void setup() {
  //Declaramos las entradas y salidas con la función pinMode
  //pinMode(numeroDePin,estado);
  //En este caso usaremos 4 entradas y 8 salidas
  //Declaramos el pin 10, 11 ,12 y 13 como entradas
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  //Declaramos los pines 2, 3, 4, 5, 6, 7, 8 y 9 como salidas
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  //Si el pin 10 está en alto Y los demás se encuentran en estado bajo o apagados, entrara este ciclo while con la animacion1
  while((digitalRead(10)==HIGH)&&(digitalRead(11)==LOW)&&(digitalRead(12)==LOW)&&(digitalRead(13)==LOW)){
    animacion1();
    }
  //Si el pin 11 está en alto Y los demás se encuentran en estado bajo o apagados, entrara este ciclo while con la animacion2
  while((digitalRead(10)==LOW)&&(digitalRead(11)==HIGH)&&(digitalRead(12)==LOW)&&(digitalRead(13)==LOW)){
    animacion2();
    }
  //Si el pin 12 está en alto Y los demás se encuentran en estado bajo o apagados, entrara este ciclo while con la animacion3
  while((digitalRead(10)==LOW)&&(digitalRead(11)==LOW)&&(digitalRead(12)==HIGH)&&(digitalRead(13)==LOW)){
    animacion3();
    }
  //Si el pin 13 está en alto Y los demás se encuentran en estado bajo o apagados, entrara este ciclo while con la animacion4
  while((digitalRead(10)==LOW)&&(digitalRead(11)==LOW)&&(digitalRead(12)==LOW)&&(digitalRead(13)==HIGH)){
    animacion4();
    }
  //Está función está fuera de todos los ciclos while
  apagaLeds();

}
//Función para la animación uno, no regresa nada 'void' y no recibe nada ( ), pero ejecuta las instrucciones para encender y apagar los leds.
void animacion1(){
  for(int i=2;i<10;i++){
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
    }
}
//Función para la animación dos, no regresa nada 'void' y no recibe nada ( ), pero ejecuta las instrucciones para encender y apagar los leds.
void animacion2(){
  for(int i=10;i>1;i--){
    digitalWrite(i,HIGH);
    delay(100);
    digitalWrite(i,LOW);
    }
}
//Función para la animación tres, no regresa nada 'void' y no recibe nada ( ), pero ejecuta las instrucciones para encender y apagar los leds.
void animacion3(){
  for(int i=2;i<10;i++){
  digitalWrite(i,HIGH);
  delay(150);
  }
  for(int i=2;i<10;i++){
  digitalWrite(i,LOW);
  delay(150);
  }  
}
//Función para la animación cuatro, no regresa nada 'void' y no recibe nada ( ), pero ejecuta las instrucciones para encender y apagar los leds.
void animacion4(){
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  delay(500);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  delay(500);  
}
//Esta función pone todas las salidas de los leds en LOW, es decir, apaga todos los leds.
void apagaLeds(){
  for(int i=2;i<10;i++){
  digitalWrite(i,LOW);
  }  
}
