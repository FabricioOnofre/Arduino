// Autor: Fabrício Onofre - RA:20130 - PD20
// Projeto final - Prototipagem 
// Professor: Sergio Luiz Moral Marques


class Projeto
{  
  
  public:
    Projeto(byte led1, byte led2, byte led3, byte led4,
            byte led5, byte led6, byte led7, byte led8,
            byte btn1, byte btn2, byte btn3);

  // Métodos da classe Projeto  
  void ledsPares();
  void ledsImpares();
    void todosLeds();
  
  private:
  byte leds[8]; // Vetor com posição de oito byteeiros
};

//Construtor da classe Projeto
Projeto::Projeto(byte led1, byte led2, byte led3, byte led4,
                 byte led5, byte led6, byte led7, byte led8,
                 byte btn1, byte btn2, byte btn3)
{
   // Cada posição do vetor recebe um led
    leds[0] = led1;
  leds[1] = led2;
  leds[2] = led3;
    leds[3] = led4;
  leds[4] = led5;
  leds[5] = led6; 
    leds[6] = led7;
  leds[7] = led8;
   
    //Define a entrada de cada led
  for (byte i= 0 ; i< 8 ; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  
    pinMode(btn1, INPUT_PULLUP); // Define o botão 1
  pinMode(btn2, INPUT_PULLUP); // Define o botão 2
    pinMode(btn3, INPUT_PULLUP); // Define o botao 3
}

// Método que usa só os leds pares
void Projeto::ledsPares()
{
  for(byte i=0; i < 8; i+=2)
  {
    byte velocidade = analogRead(A0);
    digitalWrite(leds[i], HIGH);  // Liga leds pares. 
  delay(velocidade);            // Velocidade de transição.
  digitalWrite(leds[i], LOW);   // Desligando o vermelho. 
  }
}

// Método que usa só os leds impares
void Projeto::ledsImpares()
{
  for(byte i=1; i < 8; i+=2)
  {
    byte velocidade = analogRead(A0);
    digitalWrite(leds[i], HIGH);  // Liga leds impares. 
  delay(velocidade);            // Velocidade de transição 
  digitalWrite(leds[i], LOW);   // Desliga leds impares.
  }
}

// Método que usa todos os leds
void Projeto::todosLeds()
{
  for(byte i=0; i < 8; i++)
  {
    byte velocidade = analogRead(A0);
    digitalWrite(leds[i], HIGH);  // Liga todos leds. 
  delay(velocidade);            // Velocidade de transição 
  digitalWrite(leds[i], LOW);   // Desliga todos leds. 
  }
}

// Objeto da classe Projeto
Projeto executar(6,7,8,9,10,11,12,13,2,3,4);


void setup()
{

}


void loop()
{  
    if (digitalRead(2) == LOW) // Se o botao 1 foi clicado
  {
   while (digitalRead(2) == LOW); // Enquanto o botão é segurado
        executar.ledsImpares(); // Faz o efeito dos impares
  }
  
  if (digitalRead(3) == LOW) // botao 2 
  {
     while (digitalRead(3) == LOW); // Enquanto o botão é segurado
        executar.ledsPares(); // Faz o efeito dos pares
  }
  
    if (digitalRead(4) == LOW) // botao 3
  {
     while (digitalRead(4) == LOW); // Enquanto o botão é segurado
    executar.todosLeds(); // Faz o efeito de todos leds
    }
}
