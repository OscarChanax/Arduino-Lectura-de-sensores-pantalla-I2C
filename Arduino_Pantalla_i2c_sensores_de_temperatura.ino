# include <Wire.h>
# include <LiquidCrystal_I2C.h>
# include <M2M_LM75A.h>

//Defino variable global para control de Sensor

M2M_LM75A lm75a;

//LiquidCrystal_I2C lcd (0x3F, 16, 2);
LiquidCrystal_I2C lcd (0x27, 16, 2);

int sensor = A1;                //Defino Pin para lectura del sensor

void setup()
{
  pinMode (sensor, INPUT);

  Serial.begin (115200);

  // inicializar pantalla
  lcd.init();
  lcd.init();
  lcd.backlight();


}

void loop() {

  //******************LM35***********************

  int  valor = analogRead (sensor);

  float dato = (valor / 1024.0) * 5000;
  float temperaturaLM35 = dato / 10;        //Conversion a grados celsius

  Serial.println(temperaturaLM35);            //Imprimo en monitor serial

  //***************************************************************

  // ************************LM75*********************************

 // Serial.print(lm75a.getTemperature());            //Imprimo en monitor serial
  float temperaturaLM75 = lm75a.getTemperature();         //Obtengo el valor
  float datoAnterior = temperaturaLM75;

  //************************************************************

  // ************************Visualizar valores obtenidos en pantalla*********************************

  //Evita la visualizar el valor no deseado
  if (temperaturaLM75 != -1000.00)
  {
    lcd.setCursor(0, 0);
    lcd.print("LM75: ");
    lcd.setCursor(6, 0);
    lcd.print(temperaturaLM75);
  }

  lcd.setCursor(0, 1);
  lcd.print("LM35: ");
  lcd.setCursor(6, 1);
  lcd.print(temperaturaLM35);

  delay (1000);

}
