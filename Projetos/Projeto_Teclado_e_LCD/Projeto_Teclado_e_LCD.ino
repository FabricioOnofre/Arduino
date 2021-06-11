// Autor: Fabrício Onofre - RA:20130 - PD20
// Projeto Teclado e LCD - Automação e Controle de Dispositivos
// Professor: Sergio Luiz Moral Marques

//Biblioteca do Display LCD
#include <LiquidCrystal.h>
 
// Definição dos pinos correspondentes
#define linha1      3
#define linha2      4
#define linha3      5
#define linha4      6
#define coluna1     8
#define coluna2     9
#define coluna3     10
#define coluna4     11
#define RS          14
#define EN          15
#define D4          16
#define D5          17
#define D6          18
#define D7          19

// Objeto da Classe Liquid para usar o Display
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);


// configura os pinos de acordo com o que irão fazer
void setup()
{
  //Pinos ligados aos pinos 1, 2, 3 e 4 do teclado - Linhas
  pinMode(linha1, OUTPUT);
  pinMode(linha2, OUTPUT);
  pinMode(linha3, OUTPUT);
  pinMode(linha4, OUTPUT);
   
  //Pinos ligados aos pinos 5, 6, 7 e 8 do teclado - Colunas
  pinMode(coluna1, INPUT);
  pinMode(coluna2, INPUT);
  pinMode(coluna3, INPUT);
  pinMode(coluna4, INPUT);
  
  //Iniciação do LCD
  lcd.begin(16, 2);
  delay(50);   
  lcd.clear();  
  lcd.setCursor(0,0);
  lcd.print("*:Sobe - #:Desce");
  lcd.setCursor(2,1);
  lcd.print("ABCD: Limpa");
  
  delay(500);
}

// declarando uma matriz com os dados do teclado
int dados[4][4] = { 
  {1, 2, 3, -2},
  {4, 5, 6, -2},
  {7, 8, 9, -2},
  {-2,0, -2, -2}
};

int linha = 0; 
int coluna = 0;
 
int lin, col, lugar;

void imprime_digito(int x, int y)
{
  lcd.clear(); 
  if(y == 3 & x !=3) 
  {
  
  
  }
  else if(x == 3)
  {
    if(y == 0)
    {              
      lcd.setCursor(1,0);
      lcd.print(dados[lin][col]);    
      lugar = 0;
    }
    else if(y == 2)
    {     
      lcd.setCursor(1,1); 
      lcd.print(dados[lin][col]); 
      lugar = 1;
    }
    else if(y == 1)
    {                            
      lcd.setCursor(1,lugar); 
      lcd.print("0");                      
    }    
  }
  else
  {
    lcd.setCursor(1,lugar); 
    lcd.print(dados[x][y]); 
    col = y;
    lin = x;
  }
}



void loop()
{ 
  for (int ti = 3; ti < 7; ti++) 
  {
    
    //Alterna o estado dos pinos das linhas 
    digitalWrite(3, LOW); 
    digitalWrite(4, LOW); 
    digitalWrite(5, LOW); 
    digitalWrite(6, LOW);
    digitalWrite(ti, HIGH);     
          
    linha = ti-3;
    
    //Verifica se alguma tecla da coluna 4 foi pressionada      
    if (digitalRead(coluna4) == HIGH)     
    {          
      // Mostra os numeros no LCD  
      imprime_digito(linha, 3);         
      while(digitalRead(coluna4) == HIGH){};      
    } 
    
    if (digitalRead(coluna3) == HIGH)     
    {          
      // Mostra os numeros no LCD    
      imprime_digito(linha, 2);         
      while(digitalRead(coluna4) == HIGH){};      
    }            
    
    if (digitalRead(coluna2) == HIGH)     
    {          
      // Mostra os numeros no LCD  
      imprime_digito(linha, 1);         
      while(digitalRead(coluna4) == HIGH){};      
    }            
    
    if (digitalRead(coluna1) == HIGH)     
    {          
      // Mostra os numeros no LCD        
      imprime_digito(linha, 0);         
      while(digitalRead(coluna4) == HIGH){};      
    }         
   }
   delay(10);
}
