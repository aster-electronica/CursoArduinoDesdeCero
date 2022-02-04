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
  
  //Declaramos dos variables donde se almacenarán los dos números a sumar
  byte sumando1 = 0;
  byte sumando2 = 0;
  //En esta variable se alojará el resultado de la suma de ambos números
  byte resultado = 0;
  //En esta variable se alojará el resultado de la suma anterior
  byte comparador= 0;
  //En esta variable se alojará el resultado "modificado" para la salida de los leds
  byte salida= 0;
  
//void setup es un ciclo que sólo se ejecuta una vez, sirve para ejecutar las configuraciones del microcontrolador al encenderlo  
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

//void loop es un ciclo que se va a ejecutar de manera infinita, es un bucle infinito
void loop() {
  //Le asigno a la variable 'sumando1' el valor del puertoB recorrido 2 lugares hacia la derecha e "ignoro" los 4 bits más significativos.
  sumando1 = (PINB>>2) & B00001111;
  //Le asigno a la variable 'sumando2' el valor del puerto C e 'ignoro' los 4 bits más significativos.
  sumando2 = PINC & B00001111;
  //Le asigno a la variable 'resultado' el valor de la suma de ambos números
  resultado = sumando1+sumando2;
  //Le asigno a la variable salida el valor del resultado, pero recorrido dos lugares hacia la izquierda.
  salida = resultado << 2;
  //Si el valor del resultado cambia, quiere decir que hubo un cambio en las entradas
  //entonces la salida cambiará, de no ser así, el resultado se estará imprimiendo para siempre.
  if(resultado != comparador){
    //Asigno al puertoD la salida de la suma
    PORTD = salida; 
    //Esta función imprime la operación en la terminal serial
    imprimeResultado(); 
    //Almaceno en la variable 'comparador' el último resultado para futuras comparaciones.
    comparador=resultado;
  }

}
//Yo hice esta función(:
void imprimeResultado(){
  Serial.print("Sumando 1");
  Serial.print("\t+\t");
  Serial.print("Sumando 2");
  Serial.print("\t=\t");
  Serial.println("Resultado");

  Serial.print(sumando1);
  Serial.print("\t\t+\t");
  Serial.print(sumando2);
  Serial.print("\t\t=\t");
  Serial.print(resultado);
  Serial.println("\tDecimal");

  Serial.print(sumando1,BIN);
  Serial.print("\t\t+\t");
  Serial.print(sumando2,BIN);
  Serial.print("\t\t=\t");
  Serial.print(resultado,BIN);
  Serial.println("\tBinario");

  Serial.print(sumando1,OCT);
  Serial.print("\t\t+\t");
  Serial.print(sumando2,OCT);
  Serial.print("\t\t=\t");
  Serial.print(resultado,OCT);
  Serial.println("\tOctal");

  Serial.print(sumando1,HEX);
  Serial.print("\t\t+\t");
  Serial.print(sumando2,HEX);
  Serial.print("\t\t=\t");
  Serial.print(resultado,HEX);
  Serial.println("\tHexadecimal");
  }
