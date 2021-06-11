// Autor: Fabrício Onofre - RA:20130 - PD20
// Projeto NeoPixel 24 - Automação e Controle de Dispositivos
// Professor: Sergio Luiz Moral Marques

//Biblioteca do NeoPixel
#include <Adafruit_NeoPixel.h>

// Definição dos pinos correspondentes e qtd de leds
#define LED_COUNT 24
#define LED_PIN    6

// Objeto da Classe Adafruit para usar o NeoPixel
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  //Inicia os leds do NeoPixel
  strip.begin();
  strip.show(); 
}

// Variaveis usadas para sortear uma cor
byte R, G, B;
byte segundo = 1;
void loop()
{  

  for(byte tempo=0; tempo < 24; tempo++)
  {  
    // Nos segundos 15,30 e 45 a cor do led muda
    if(segundo % 15 == 0)
    {        
      // R,G e B vão formar uma cor de led aleatoria
      R=random(256);
      G=random(256);
      B=random(256);     
      strip.setPixelColor(tempo, R, G, B);
    }
    else
    {     
      strip.setPixelColor(tempo, 255,0,0); 
    }
    
    // Reinicia os segundos ao formar 1 min
    if(segundo >= 59) 
      segundo = 1;
    else
       segundo++;

    // Apresenta o NeoPixel com as alterações feitas
    strip.show();
    
    delay(1000);
  }   
  
  // Apaga todos os leds
  for(byte tempo=0; tempo < 24; tempo++)
  {  
    strip.setPixelColor(tempo, 0,0,0);   
  }   
  
  strip.show();
}
