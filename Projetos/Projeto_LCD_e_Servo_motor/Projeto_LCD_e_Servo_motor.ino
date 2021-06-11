// Autor: Fabrício Onofre - RA:20130 - PD20
// Projeto LCD e Servo motor - Automação e Controle de Dispositivos
// Professor: Sergio Luiz Moral Marques


#include <Servo.h>
#include <LiquidCrystal.h>

#define rs  2
#define en  3
#define d4  4
#define d5  5
#define d6  6
#define d7  7
#define ldr A0

// Objeto da Classe Liquid para usar o Display
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

// Objeto da Classe Servo para usar o Servo Motor
Servo servo;

int valorLdr; 
int pos = 0;


//Inicia o Servo Motor e o Display
void setup()
{
  servo.attach(10);
  valorLdr  = 0;
  
  lcd.begin(16,2);
  lcd.setCursor(1,0);
  lcd.print("Leitura do LDR");  
}

void loop()
{
  // A intensidade da luz é passada através do LDR
  valorLdr  = analogRead(ldr) / 4; 
  
  /* Verifica-se a intensidade da luz...
  Muita luz = 180° de giro no Servo Motor
  Pouca Luz = 0° de giro no Servo Motor*/
  if(valorLdr > 0 && valorLdr < 131) 
  {     
    servo.write(0);    
    lcd.setCursor(1,1);       
    lcd.print("Pouca Luz:");      
    lcd.setCursor(11,1);      
    lcd.print(valorLdr);
  }
  else  
  {
    servo.write(180);
    lcd.setCursor(1,1);
    lcd.print("Muita Luz:");
    lcd.setCursor(11,1);
    lcd.print(valorLdr);
  }
  
  // Limpa o valor da intensidade atual no DIsplay
  lcd.print("          ");    
  delay(15);
}
