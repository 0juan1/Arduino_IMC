#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

// Inicializa o LCD no endereço (0x20), com 16 colunas e 2 linhas
Adafruit_LiquidCrystal lcd(0);

void setup() {
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.setBacklight(HIGH);
    lcd.setCursor(0, 0);
    lcd.print("IMC CALCULATOR");
  	lcd.setCursor(0, 1);
    lcd.print("Loading");
  	delay(299);
  	lcd.setCursor(7, 1);
    lcd.print(".");
  	delay(299);
  	lcd.setCursor(8, 1);
    lcd.print(".");
    delay(299);
  	lcd.setCursor(9, 1);
    lcd.print(".");
  	delay(299);
  	lcd.setCursor(9, 1);
    lcd.print(" ");
  	delay(299);
   	lcd.setCursor(9, 1);
    lcd.print(".");
  	delay(299);
   	lcd.setCursor(9, 1);
    lcd.print(" ");
  	delay(299);
    lcd.setCursor(9, 1);
    lcd.print(".");
  	delay(299);
    lcd.setCursor(9, 1);
    lcd.print(" ");
  	delay(299);
    lcd.setCursor(9, 1);
    lcd.print(".");
  	delay(299);
  	lcd.clear();
}

void loop() {
  
  float peso, altura, imc;

  	while (true){
      lcd.setCursor(0, 0);
      lcd.print("Peso(kg):");
      Serial.println("Digite seu peso(kg): ");
      
        while (Serial.available() == 0); // Aguarda entrada
          peso = Serial.parseFloat();
          Serial.read(); // Limpa buffer
          delay(299);
      
            if (peso <= 0){
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("PESO INVALIDO!");
              Serial.println("Digite um valor valido!");
              delay(1327);
              lcd.clear();
            }
      		else {
              lcd.clear();
              	break;
            }
    }
  
    
  	while (true){
      lcd.setCursor(0, 0);
      lcd.print("Altura(m):");
      Serial.println("Digite sua altura(kg): ");
      
        while (Serial.available() == 0); // Aguarda entrada
          altura = Serial.parseFloat();
          Serial.read(); // Limpa buffer
          delay(299);
      
            if (altura <= 0){
              lcd.clear();
              lcd.setCursor(0, 0);
              lcd.print("ALTURA INVALIDA!");
              Serial.println("Digite um valor valido!");
              delay(1327);
              lcd.clear();
            } 
      		else {
				break;
            }
    }  
  
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Peso: " + String(peso) + "kg");
    lcd.setCursor(0, 1);
    lcd.print("Altura: " + String(altura) + "m");
    delay(2000);

    // Cálculo do IMC
    imc = peso / (altura * altura);

    // Determinar classificação do IMC
    String resultado;
    if (imc < 18.5){
        resultado = "ABAIXO DO PESO!";
    }
    else if (imc >= 18.5 && imc <= 24.9){
        resultado = "PESO NORMAL!";
    }
    else if (imc >= 25 && imc <= 29.9){
        resultado = "SOBREPESO!";
    }
    else {
        resultado = "OBESIDADE!";
    }

    // Exibir resultado no LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SEU IMC: " + String(imc, 1));  // Exibe o IMC
    lcd.setCursor(0, 1);
    lcd.print(resultado);
    
    // Exibir resultado no monitor serial
    Serial.println("Seu IMC: " + String(imc));
    Serial.println("Resultado: " + resultado);
    
    delay(9999);
    lcd.clear();
}