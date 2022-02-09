/******************************************************************************* 
  *  Áster Electrónica
  *  Contador binario
  *  Abstract: En este ejemplo, se realizará un contador binario de 0 a 255 con
  *  un ciclo for, el valor del contador se desplegará en los leds de salida
  *  del puerto D y en la terminal serial.
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

int contador=0;
byte salida1;
byte salida2;

void setup() {
  //Declaramos todo el puerto B y C como entrada
  //Declaramos como entrada PB2,PB3,PB4 y PB5. En este caso PB0 y PB1 serán salidas.
  DDRB = B00000011; 
  //Declaramos todo el puerto C como entrada.  
  DDRC = B00000000;
  //Declaramos PD2,PD3,PD4,PD5,PD6 y PD7 como entradas SIN modificar el estado de PD0 y PD1.
  DDRD |= B11111100;

  //Iniciamos la comunicación serial
  Serial.begin(9600);
}

void loop() {
  for(int i=0; i<256; i++){
    contador= byte(i);
    //Le asigno a la variable salida1 el valor del resultado, pero recorrido dos lugares hacia la izquierda.
    salida1 = contador << 2;
    //Le asigno a la variable salida2 el valor del resultado, pero recorrido seis lugares hacia la derecha.
    salida2 = contador >> 6;
    //Asigno al puertoD el valor de salida1 que contiene los 6 bits menos significativos del resultado
    PORTD = salida1;
    //Asigno al puertoB el valor de salida1 que contiene los 2 bits más significativos del resultado
    PORTB = salida2;
    //Esta función imprime el valor del contador en la terminal serial
    Serial.println(contador);
    //Esta función espera 1000 milisegundos y después continúa el programa
    delay(1000);        
    }

}
