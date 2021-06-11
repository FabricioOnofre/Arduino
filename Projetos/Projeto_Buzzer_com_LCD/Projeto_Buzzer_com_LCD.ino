// Fabricio Onofre - Ra: 20130 - PD20
// Prof° Sérgio -  Automação e Controle de Dispositivos
// Projeto Buzzer com LCD

#include <LiquidCrystal.h>

// Definião das entradas/pinos
#define RS 12
#define EN 11
#define buzzer 6
#define D4 5
#define D5 4
#define D6 3
#define D7 2
#define caracteres     16
#define linhas        2
#define btnSobe       7
#define btnSeleciona  8
#define btnDesce    9

// Notas para a Marcha Imperial - Star Wars
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a  440
#define aS 455
#define b  466
#define cH 523
#define cSH  554
#define dH 587
#define dSH 622
#define eH  659
#define fH  698
#define fSH  740
#define gH  784
#define gSH  830
#define aH  880

// Nome das musicas no LCD
String musica1 = "Star Wars";
String musica2 = "Mario Bros";

LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);

void setup()
{
  pinMode(btnSobe, INPUT_PULLUP);
  pinMode(btnSeleciona, INPUT_PULLUP);
  pinMode(btnDesce, INPUT_PULLUP);

  lcd.begin(caracteres, linhas);
  delay(50); // para garantir a inicialização do modulo
  lcd.clear();  // limpa o display
}
// Inicia os dados do LCD
bool primeiraVez = true;

// Define qual música vai tocar
byte selecionaMusica = 0;
 
//melodia do MARIO THEME
short melodiaMario[] = {660,660,660,510,660,770,380,510,380,320,
440,480,450,430,380,660,760,860,700,760,660,520,580,480,510,
380,320,440,480,450,430,380,660,760,860,700,760,660,520,580,
480,500,760,720,680,620,650,380,430,500,430,500,570,500,760,
720,680,620,650,1020,1020,1020,380,500,760,720,680,620,650,380,
430,500,430,500,570,585,550,500,380,500,500,500,500,760,720,680,
620,650,380,430,500,430,500,570,500,760,720,680,620,650,
1020,1020,1020,380,500,760,720,680,620,650,380,430,500,430,500,
570,585,550,500,380,500,500,500,500,500,500,500,580,660,
500,430,380,500,500,500,500,580,660,870,760,500,500,500,500,580,
660,500,430,380,660,660,660,510,660,770,380};
 
//duraçao de cada nota
short duracaodasnotasMario[] = {100,100,100,100,100,100,100,100,
100,100,100,80,100,100,100,80,50,100,80,50,80,80,80,80,100,100,
100,100,80,100,100,100,80,50,100,80,50,80,80,80,80,100,100,100,
100,150,150,100,100,100,100,100,100,100,100,100,100,150,200,80,
80,80,100,100,100,100,100,150,150,100,100,100,100,100,100,100,
100,100,100,100,100,100,100,100,100,100,150,150,100,100,100,100,
100,100,100,100,100,100,150,200,80,80,80,100,100,100,100,100,
150,150,100,100,100,100,100,100,100,100,100,100,100,100,100,60,
80,60,80,80,80,80,80,80,60,80,60,80,80,80,80,80,60,80,60,80,80,
80,80,80,80,100,100,100,100,100,100,100};                         
 
// Método para tocar a letra da musica
void beep(short note, short duration)
{
  tone(buzzer, note);             
  delay(duration);           
  noTone(buzzer);
    delay(duration);
}

// Parte 1 da Marcha Imperial
void parte1()
{
beep(a, 500);
beep(a, 500); 
beep(a, 500);
beep(f, 350);
beep(cH, 150); 
beep(a, 500);
beep(f, 350);
beep(cH, 150);
beep(a, 650);

delay(500);

beep(eH, 500);
beep(eH, 500);
beep(eH, 500); 
beep(fH, 350);
beep(cH, 150);
beep(gS, 500);
beep(f, 350);
beep(cH, 150);
beep(a, 650);

delay(500);
}


// Parte 2 da Marcha Imperial
void parte2()
{
beep(aH, 500);
beep(a, 300);
beep(a, 150);
beep(aH, 500);
beep(gSH, 325);
beep(gH, 175);
beep(fSH, 125);
beep(fH, 125); 
beep(fSH, 250);

delay(325);

beep(aS, 250);
beep(dSH, 500);
beep(dH, 325); 
beep(cSH, 175); 
beep(cH, 125); 
beep(b, 125); 
beep(cH, 250); 

delay(350);
}

// Toca a Marcha Imperial no Buzzer
void musicaStarWars()
{
parte1();

//Toca a segunda variação
parte2();

//Variação 1:
beep(f, 250); 
beep(gS, 500); 
beep(f, 350); 
beep(a, 125);
beep(cH, 500);
beep(a, 375); 
beep(cH, 125);
beep(eH, 650);

delay(500);

parte2();

//Variação 2:
beep(f, 250); 
beep(gS, 500); 
beep(f, 375); 
beep(cH, 125);
beep(a, 500); 
beep(f, 375); 
beep(cH, 125);
beep(a, 650);

delay(650);
}

void musicaMario() 
{
  //for para tocar as 156 notas começando 
  //no 0 ate 156 ++ incrementado
  for (short nota = 0; nota < 156; nota++) 
  {
    short duracaodanota = duracaodasnotasMario[nota];
  tone(6, melodiaMario[nota],duracaodanota);
    
  //pausa depois das notas
  short pausadepoisdasnotas[] ={150,300,300,100,300,550,
  575,450,400,500,300,330,150,300,200,200,150,300,150,
  350,300,150,150,500,450,400,500,300,330,150,300,200,
  200,150,300,150,350,300,150,150,500,300,100,150,150,
  300,300,150,150,300,150,100,220,300,100,150,150,300,
  300,300,150,300,300,300,100,150,150,300,300,150,150,
  300,150,100,420,450,420,360,300,300,150,300,300,100,
  150,150,300,300,150,150,300,150,100,220,300,100,150,
  150,300,300,300,150,300,300,300,100,150,150,300,300,
  150,150,300,150,100,420,450,420,360,300,300,150,300,
  150,300,350,150,350,150,300,150,600,150,300,350,150,
  150,550,325,600,150,300,350,150,350,150,300,150,600,
  150,300,300,100,300,550,575};
    delay(pausadepoisdasnotas[nota]);
   }
  noTone(6);
}


void loop()
{  
  // Inicia o nome das musicas no LCD
  if(primeiraVez == true)
  {
    lcd.setCursor(3,0);
    lcd.print(musica1); 
    lcd.setCursor(3,1);
    lcd.print(musica2);
    primeiraVez = false;
  }

  // Seleciona a musica Marcha Imperial
  if (digitalRead(btnSobe)==LOW)
  {
    while (digitalRead(btnSobe) == LOW);
    lcd.clear();  // limpa o display
    lcd.setCursor(3,0);
    lcd.print(musica1 + "   #"); // deixa em destaque
    lcd.setCursor(3,1);
    lcd.print(musica2); 
    selecionaMusica = 2; // define que o Star Wars vai tocar
    delay(100);
  }
    
  // Seleciona a musica do Mario Bros
  if (digitalRead(btnDesce)==LOW)
  {
    while (digitalRead(btnDesce) == LOW);      
    lcd.clear();  // limpa o display
    lcd.setCursor(3,0);
    lcd.print(musica1); 
    lcd.setCursor(3,1);
    lcd.print(musica2 + "  #"); // deixa em destaque
    selecionaMusica = 1; // define que o Mario vai tocar
    delay(100);
  } 
  
  // Comeca a tocar a canção selecionada
  if(digitalRead(btnSeleciona)==LOW)
  {
    while (digitalRead(btnDesce) == LOW); 
    
    // qual musica vai tocar??
    switch(selecionaMusica)
    {
      case 1:
        {
          musicaMario(); // toca no buzzer
          break;
        }
        
        case 2: 
        {
          musicaStarWars(); // toca no buzzer
          break;
        }
      
        default:
        {
          // Informa o usuario da situação
          lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("Escolha uma"); 
          lcd.setCursor(3,1);
          lcd.print("  musica!!!"); 
          delay(1000);
          lcd.clear();  // limpa o display
          primeiraVez = true;
          break;
        }    
    }
  }
}
