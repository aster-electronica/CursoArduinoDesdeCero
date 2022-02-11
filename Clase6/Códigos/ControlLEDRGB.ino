/******************************************************************************* 
  *  Áster Electrónica
  *  Contador binario
  *  Abstract: En este ejemplo, se conecta un LED RGB y se controlan los colores
  *  dependiendo de cada la posición de los potenciometros, cada potenciometro
  *  controla por PWM la intensidad de cada color.
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
//Inicializamos la comunicación serial
Serial.begin(9600);
}

void loop() {
  //Usamos la función digitalWrite para poner una señal PWM en el pin 3, con el ciclo de trabajo del valor analógico del pin A0 divido entre 4
  analogWrite(3,analogRead(A0)/4);
  //Usamos la función digitalWrite para poner una señal PWM en el pin 5, con el ciclo de trabajo del valor analógico del pin A1 divido entre 4
  analogWrite(5,analogRead(A1)/4);
  //Usamos la función digitalWrite para poner una señal PWM en el pin 6, con el ciclo de trabajo del valor analógico del pin A2 divido entre 4
  analogWrite(6,analogRead(A2)/4);
  //Esta función imprime los valores de los pines A0, A1 y A2 entre 4.
  imprimeValores();
}
void imprimeValores(){
  Serial.println("ROJO\tVERDE\tAZUL");
  Serial.print(analogRead(A2)/4);
  Serial.print("\t");
  Serial.print(analogRead(A1)/4);
  Serial.print("\t");
  Serial.print(analogRead(A0)/4);
  Serial.println("\t");
}
