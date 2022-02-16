/******************************************************************************* 
  *  Áster Electrónica
  *  Contador binario
  *  Abstract: 
  *  Creado por Miguel AngelLo.
  *  LinkedIn: @miguelangello21
  *  Conexiones físicas: En este ejemplo se controla una pantalla LCD de 16x2
  *  mediante el uso de un convertidor paralelo-serieI2C, en este ejemplo de 
  *  despliega un mensaje en 2 partes, la pantalla se actualiza cada dos segundos.
  *        Tarjeta UNO | Salidas 
  *               5V -> VCC
  *              GND -> GND
  *               A4 -> SDA
  *               A5 -> SCL        
********************************************************************************/
#include <Wire.h> 
//Incluimos la librería de la presentación de la Clase7
#include <LiquidCrystal_I2C.h>

//Creamos un objeto de la clase LiquidCrystal_I2C de nombre lcd, los parametros son (dirección,columnas,renglones)
LiquidCrystal_I2C lcd(0x27,16,2);  

//Este ciclo sólo se ejecuta una sola vez
void setup()
{
  //Con esta función se inicializa la comununicación serial para la pantalla LCD
  lcd.init();                  
  lcd.init();
  //Esta función habilita la retroiluminación de la pantalla
  lcd.backlight();

}

//Este ciclo se estará repitiendo indefinidamente
void loop()
{
  //Colocamos el cursos en la posición 0,0
  lcd.setCursor(0,0);
  //Imprimimos el siguiente mensaje
  lcd.print("Hola mundo!");
  //Bajamos el cursor una fila o renglón
  lcd.setCursor(0,1);
  //Imprimimos el siguiente mensaje
  lcd.print("este es mi");
  //Esperamos 2 segundos
  delay(2000);
  //Limpiamos la pantalla
  lcd.clear();
  //Colocamos el cursos en la posición 0,0
  lcd.setCursor(0,0);
  //Imprimimos el siguiente mensaje
  lcd.print("primer programa");
  //Bajamos el cursor una fila o renglón
  lcd.setCursor(0,1);
  //Imprimimos el siguiente mensaje
  lcd.print("usando I2C!");
  //Esperamos 2 segundos
  delay(2000);
  //Limpiamos la pantalla
  lcd.clear();
}
