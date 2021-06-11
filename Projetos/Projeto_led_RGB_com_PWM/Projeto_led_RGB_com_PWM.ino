//Fabricio Onofre - RA: 20130
// Prof° Sérgio - 1PD
// Projeto led RGB com PWM

// Definião das entradas/pinos
#include <LiquidCrystal.h>
#define RS 11
#define EN 12
#define D4 7
#define D5 6
#define D6 5
#define D7 4
#define caracteres 16
#define linhas     2
#define PWM1  3
#define led_R 10
#define led_B 9
#define led_G 8


// variável para armazenar o valor do pot
int valor_pot;

LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);


// define os pinos de saida e sua direção
void setup()
{
  // entradas analógicas para os pot do led RGB
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);

  //pinos do led RGB
  pinMode(led_R, OUTPUT);
  pinMode(led_G, OUTPUT);
  pinMode(led_B, OUTPUT);
  
  //pinos do LCD
  lcd.begin(caracteres, linhas); 
  
  //pinos para o led com pwm
  pinMode(PWM1, OUTPUT);
}

void loop()
{
  lcd.clear(); //Limpa o display

  // ajusta valor 0 -1023 -> 0 - 255
  valor_pot = analogRead(A0) / 4; 
  
  // liga e regula a led vermelha
  analogWrite(PWM1, valor_pot);
  
  // ajusta o valor de cada cor pro led RGB
  int vermelho = analogRead(A3) / 4;
  int verde    = analogRead(A2) / 4;
  int azul     = analogRead(A1) / 4;
  
  // porcentagem do pwm 
  int resultado = (valor_pot * 100)/ 255;

  // regulagem para decidir a cor do led RGB
  analogWrite(led_G, verde);
  analogWrite(led_B, azul);
  analogWrite(led_R, vermelho);
  
  // Informações que são apresentadas no display
  lcd.setCursor(1,0);      
  lcd.print("R:");
  lcd.setCursor(3,0);      
  lcd.print(vermelho ); // valor do R do led
  lcd.setCursor(8,0);   
  lcd.print("G:");
  lcd.setCursor(10,0);      
  lcd.print(verde );    // valor do G do led
  lcd.setCursor(1,1);      
  lcd.print("B:");
  lcd.setCursor(3,1);      
  lcd.print(azul);     // valor do B do led
  lcd.setCursor(8,1);   
  lcd.print("PWM%");
  lcd.setCursor(13,1);      
  lcd.print(resultado); // porcentagem atual usada do pwm
  
  delay(200); // atualiza o display
}
