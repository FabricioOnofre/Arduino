// Autor: Fabrício Onofre - RA:20130 - PD20
// Projeto Sensor de Distância - Automação e Controle de Dispositivos
// Professor: Sergio Luiz Moral Marques

#include <LiquidCrystal.h>

#define buzzer          0
#define trPin           4
#define ecPin           5
#define RS             12
#define EN             11
#define D4              6
#define D5              3
#define D6              2
#define D7              1
#define caracteres      16
#define linhas        2
#define btnPol        8
#define btnCm       9
#define ledR           10
#define ledB            7
#define ledG           13

// Objeto da Classe Liquid 
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);

// Inicia o LCD
void setup()
{
  lcd.begin(caracteres, linhas);
  delay(50);    // para garantir a inicialização do modulo
  lcd.clear();    // limpa o display
}


bool inicio = true;   // variavel usada para iniciar o LDC
int medida = 1;       // unidades de comprimento
int velocidade = 0;   // velocidade do delay do loop


class Projeto
{
  // Construtor da classe Projeto
  public:
  Projeto(int led_R, int led_G, int led_B, int pino_buzzer,
            int btn_Pol, int btn_Cm, int tr_Pin, int ec_Pin);
  
  // Método que toca o buzzer de acordo com a distância
  void tocaBuzzer(int pino_buzzer, int note, int duration);
  
  // Método que deixa a cor do led de acordo com a distãncia
  void ledDistancia(int value_R, int value_G, int value_B,
                      int led_R, int led_G, int led_B);
  
  // Método que exibi a distância atual do sensor
    void lcdMedida(String sigla_Medida, String nome_medida,
                   long variavel_medida);
  
  // Método que inicia o sensor de distância ultrassônico
   void iniciaSensor(int tr_Pin);
};

//Método Construtor da classe Projeto
Projeto::Projeto(int led_R, int led_G, int led_B, int pino_buzzer,
            int btn_Pol, int btn_Cm, int tr_Pin, int ec_Pin)
{
  pinMode(tr_Pin, OUTPUT);
  pinMode(ec_Pin,  INPUT);
  
  pinMode(btn_Pol, INPUT_PULLUP);
  pinMode(btn_Cm, INPUT_PULLUP);
  
  //pinos do led RGB
  pinMode(led_R, OUTPUT);
  pinMode(led_G, OUTPUT);
  pinMode(led_B, OUTPUT);
  
}

// Método que passa a cor desejada para o led RGB
void Projeto::ledDistancia(int value_R, int value_G, int value_B,
                           int led_R, int led_G, int led_B)
{
  // recebe os pinos do led RGB e o valor de cada cor
    analogWrite(led_R, value_R);
    analogWrite(led_G, value_G);
    analogWrite(led_B, value_B);
}

// Método que faz o beep de alarme de acordo com a distância
void Projeto::tocaBuzzer(int pino_buzzer, int note, int duration)
{
  // recebe o pino do buzzer, a duração e a frequência da nota
    tone(pino_buzzer, note);            
  delay(duration);           
  noTone(pino_buzzer);
    delay(duration);
}

// Método que exibi a unidade de medida e seu valor no LCD
void Projeto::lcdMedida(String sigla_Medida, String nome_Medida,
                   long variavel_medida)
{
  // Limpa o display e acresenta os valores atualizados
    lcd.clear();  
    lcd.setCursor(3,0);
    lcd.print(nome_Medida);  
    lcd.setCursor(5,1);
    lcd.print(variavel_medida); 
    lcd.print(sigla_Medida);   
}
     
void Projeto::iniciaSensor(int tr_Pin)
{
  digitalWrite(tr_Pin, LOW); //  ??___
  delayMicroseconds(5);
  digitalWrite(tr_Pin, HIGH); //  ??___-----
  delayMicroseconds(10);
  digitalWrite(tr_Pin, LOW); //  ??___-----____
}

// Objeto da classe Projeto
Projeto executar(ledR, ledG, ledB, buzzer, btnPol, btnCm, trPin, ecPin);

void loop()
{
  long duracao;
  long polegadas;
  long cm;

  executar.iniciaSensor(trPin); 
  
  // espera a resposta , sendo esta uma entrada
  duracao = pulseIn(ecPin, HIGH);
  
  // faz conversao de tempo para distancia
  cm = duracao /29 /2;
  
  // fórmula de conversão de cm para polegadas
  polegadas = cm * 0.39370;
  
  /* verifica se algum botão foi clicado e a
  unidade de medida foi trocada*/
  if (digitalRead(btnCm)==LOW)
  {
    while (digitalRead(btnCm) == LOW);      
    medida = 2;
  } 
  
  if (digitalRead(btnPol)==LOW)
  {
    while (digitalRead(btnPol) == LOW);      
    medida = 1;
  }  
  
  /* Verifica a distância atual do sensor
  e executa o led e o buzzer*/
  
  // 3 a 50cm      -- Led Vermelho -- Beep rapido 
  // 50 a 100cm    -- Led Amarelo -- Beep medio
  // 100 a 150cm   -- Led Verde -- Beep Lento
  // mis que 150cm -- Led Transparente -- Sem Beep
  
  if(cm >= 3 && cm <=50 )
  {
    executar.ledDistancia(255, 0, 0, ledR, ledG, ledB);
  executar.tocaBuzzer(buzzer, 880, 100);
    velocidade = 100;
  }
  else if(cm <= 100 )
  {
    executar.ledDistancia(255, 255, 0, ledR, ledG, ledB);
    executar.tocaBuzzer(buzzer, 880, 250);
    velocidade = 250;               
  }
  else if(cm <=150)
  {           
    executar.ledDistancia(0, 255, 0, ledR, ledG, ledB);
    executar.tocaBuzzer(buzzer, 880, 400);
    velocidade = 400;     
  }
  else
  {   
    executar.ledDistancia(0, 0, 0, ledR, ledG, ledB);
    velocidade = 300;
  }
  

  /* Verifica se o lcd não está inicializando
  e apresenta a unidade de medida atual selecionada */
  if(inicio == true)
  {
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("Sensor de"); 
    lcd.setCursor(3,1);
    lcd.print("Distancia"); 
    inicio = false;
    delay(700);
  }
  else
  {
    switch(medida)
    {
      case 1:
      {
        executar.lcdMedida("cm", "Centimetros", cm);
        break;
      }
      
      case 2:
      {
        executar.lcdMedida("in", "Polegadas", polegadas);
        break;
      }
    }
  }
  delay(velocidade);
}
