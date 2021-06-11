// Autor: Fabrício Onofre - RA:20130 - PD20
// Projeto Photodiodo e LCD - Automação e Controle de Dispositivos
// Professor: Sergio Luiz Moral Marques

#include <LiquidCrystal.h>

#define ledAzul     1
#define ledAmarelo  2
#define ledVerde    3
#define pir        12
#define buzzer     11
#define tilt       10
#define caracteres 16
#define linhas      2
#define RS          9
#define EN          8
#define D4          7
#define D5          6
#define D6          5
#define D7          4

// Objeto da Classe Liquid para usar o Display
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);



void setup()
{
  // configura os pinos de acordo com o que irão fazer
  pinMode(ledAzul, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(tilt, INPUT_PULLUP);
  lcd.begin(caracteres, linhas);
  delay(50);   
  lcd.clear();  
  lcd.setCursor(3,0);
  lcd.print("PhotoDiodo:");
}

bool ativo = false;

void loop()
{
  /* Verifica o sensor pir 
  Se algum objeto se mover, o buzzer toca e o led verde liga */
  if (digitalRead(pir) == HIGH)
  {
  digitalWrite(ledVerde, HIGH);
    if (!ativo)
    {
      digitalWrite(buzzer,HIGH);
      delay(100);
      digitalWrite(buzzer,LOW);
      ativo = true;
    }
  }
  else 
  {
  digitalWrite(ledVerde, LOW);
    ativo = false;
  }
  
  int valorPhoto = analogRead(A0);
  
  /* Verificação do fotodiodo 
  Se o fotodiodo estiver recebendo luz o led azul liga */
  if(valorPhoto<82)
  {                                  
    digitalWrite(ledAzul,LOW);
  }
  else
  {                                              
    digitalWrite(ledAzul,HIGH);
  }

  /* Verificação do sensor de inclnação
  Se o sensor estiver não estiver inclinado o led amarelo liga */
  if (digitalRead(tilt) == HIGH)
  {
    digitalWrite(ledAmarelo, LOW);
  }
  else 
  {
    digitalWrite(ledAmarelo, HIGH);
  }
  
  /* Exibi o valor do photodiodo no Display */
  lcd.setCursor(5,1);
  lcd.print("     ");
  lcd.setCursor(5,1);
  lcd.print(valorPhoto);
  delay(100);
}
