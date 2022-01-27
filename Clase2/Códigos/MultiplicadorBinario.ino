/******************************************************************************* 
  *  Áster Electrónica
  *  Sumador Binario de 4bits
  *  Abstract: En este ejemplo, se tendran dos números de 4 bits como entrada
  *  a la salida se tendrá un número de 5 bits representado por leds, el 
  *  resultado también se puede visualizar desde el monitor serial del IDE.
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
  //Declaramos dos variables para los factores
  byte factor1 = 0;
  byte factor2 = 0;
  //Declaramos una variable que almacenará el resultado de la multiplicación
  byte resultado = 0;
  //En esta variable se alojará el resultado de la suma anterior
  byte comparador= 0;
  //Declaramos dos variables porque la salida se dividirá en dos partes
  byte salida1= 0;
  byte salida2= 0;
  //En esta variable se almacenará el resultado total
  byte total= 0;
  
//void setup es un ciclo que sólo se ejecuta una vez, sirve para ejecutar las configuraciones del microcontrolador al encenderlo 
void setup() {
  //Declaramos todo el puerto B y C como entrada
  //Declaramos como entrada PB2,PB3,PB4 y PB5. En este caso PB0 y PB1 serán salidas.
  DDRB = B00000011; 
  //Declaramos todo el puerto C como entrada.  
  DDRC = B00000000;
  //Declaramos PD2,PD3,PD4,PD5,PD6 y PD7 como entradas SIN modificar el estado de PD0 y PD1.
  DDRD &= B00000011;

  //Iniciamos la comunicación serial
  Serial.begin(9600);


}

//void loop es un ciclo que se va a ejecutar de manera infinita, es un bucle infinito
void loop() {
  //Le asigno a la variable 'sumando1' el valor del puertoB recorrido 2 lugares hacia la derecha e "ignoro" los 4 bits más significativos.
  factor1 = (PINB>>2) & B00001111;
  //Le asigno a la variable 'sumando2' el valor del puerto C e 'ignoro' los 4 bits más significativos.
  factor2 = PINC & B00001111;
  //Le asigno a la variable 'resultado' el valor de la multiplicación de ambos números
  resultado = factor1*factor2;
  //Le asigno a la variable salida1 el valor del resultado, pero recorrido dos lugares hacia la izquierda.
  salida1 = resultado << 2;
  //Le asigno a la variable salida2 el valor del resultado, pero recorrido seis lugares hacia la derecha.
  salida2 = resultado >> 6;
  //Si el valor del resultado cambia, quiere decir que hubo un cambio en las entradas
  //entonces la salida cambiará, de no ser así, el resultado se estará imprimiendo para siempre.
  if(resultado != comparador){
    //Asigno al puertoD el valor de salida1 que contiene los 6 bits menos significativos del resultado
    PORTD = salida1;
    //Asigno al puertoD el valor de salida1 que contiene los 2 bits más significativos del resultado
    PORTB = salida2;
    //Esta función imprime la operación en la terminal serial
    imprimeResultado();  
    //Almaceno en la variable 'comparador' el último resultado para futuras comparaciones.
    comparador=resultado;
  }

}
//Yo hice esta función(:
void imprimeResultado(){
  Serial.print("Factor 1");
  Serial.print("\tx\t");
  Serial.print("Factor 2");
  Serial.print("\t=\t");
  Serial.println("Resultado");

  Serial.print(factor1);
  Serial.print("\t\tx\t");
  Serial.print(factor2);
  Serial.print("\t\t=\t");
  Serial.print(resultado);
  Serial.println("\tDecimal");

  Serial.print(factor1,BIN);
  Serial.print("\t\tx\t");
  Serial.print(factor2,BIN);
  Serial.print("\t\t=\t");
  Serial.print(resultado,BIN);
  Serial.println("\tBinario");

  Serial.print(factor1,OCT);
  Serial.print("\t\tx\t");
  Serial.print(factor2,OCT);
  Serial.print("\t\t=\t");
  Serial.print(resultado,OCT);
  Serial.println("\tOctal");

  Serial.print(factor1,HEX);
  Serial.print("\t\tx\t");
  Serial.print(factor2,HEX);
  Serial.print("\t\t=\t");
  Serial.print(resultado,HEX);
  Serial.println("\tHexadecimal");
  }
