// Autor: Fabrício Onofre - RA:20130 - PD20
// Projeto Controle Remoto - Automação e Controle de Dispositivos
// Professor: Sergio Luiz Moral Marques


//Biblioteca do controle remoto IR
#include <IRremote.h>

//Biblioteca do servo motor
#include <Servo.h>


IRrecv irrecv(2);// instancia a classe do IR
Servo servo;     // instancia a classe do Servo    


//variÃ¡vel com o resultado da leitura do IR
decode_results results; 

//variavel responsavel pelos graus de giro do servo
int pos = 0;

void setup()
{
  //Inicia o servo e o controle
  servo.attach(5);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Inicializa o receptor IR
  servo.write(360);
  delay(3000);
  servo.write(0);
}
    
void loop()
{ 
  if (irrecv.decode(&results)) // verfica se alguma tecla foi clicada
  {     
    if(results.value == 0xFD50AF)//verifica se a tecla SOBE foi acionada
    {
      Serial.println("Aumentou"); 
      
      // O servo gira mais 5 graus adicionados
      pos = pos + 5;
      servo.write(pos);
    }
        
    if(results.value == 0xFD10EF)//verifica se a tecla DESCE foi acionada
    {
      // O servo gira menos 5 graus adicionados
      Serial.println("Diminuiu");    
      pos = pos - 5;
      servo.write(pos);
    }
    
    irrecv.resume();
    delay(50);
  }           
} 
