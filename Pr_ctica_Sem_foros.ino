//** Definiciones **//
int rojo=22;      //definimos el valor del pin para el led rojo
int amarillo=24;  //definimos el valor del pin para el led amarillo
int verde=26;     //definimos el valor del pin para el led verde
int ledIntensidadVerde = 3;
int ledIntensidadRojo = 2;
int boton=13;
int bocina=28;

int rojoPeaton=6;
int verdePeaton=7;

int pot = 0;

int valorBoton = LOW;
int valorPot = 0;

int momento;

//** Programa **//

void setup() {
  valorPot = analogRead(pot)*15/1000;  
  Serial.begin(9600);
  
  pinMode(verde,OUTPUT);   //declaramos el pin verde como salida  
  pinMode(amarillo,OUTPUT);//declaramos el pin amarillo como salida
  pinMode(rojo,OUTPUT);    //declaramos el pin rojo como salida  
  pinMode(rojoPeaton,OUTPUT);    
  pinMode(verdePeaton,OUTPUT);
  pinMode(ledIntensidadVerde, OUTPUT);
  pinMode(ledIntensidadRojo, OUTPUT);
  pinMode(bocina, OUTPUT);
}

void loop() {
  
  analogWrite(ledIntensidadRojo, analogRead(pot)/4.5);
  analogWrite(ledIntensidadVerde, 227-analogRead(pot)/4.5);
  if(valorPot > 0){
    Serial.print("Por favor espere: ");
    Serial.print(valorPot);
    Serial.println(" segundos");
    delay(1000);
    valorPot--;
  }else{
    Serial.print("Tiempo de espera: "); 
    Serial.print(analogRead(pot)*15/1000);
    Serial.print(" segundos");
    Serial.println();
    Serial.write(0x0d);
      
  }
    
  digitalWrite(rojoPeaton, HIGH);
  digitalWrite(verde, HIGH);
  if (digitalRead(boton) == LOW && valorPot == 0){
    Serial.println("Espere...");
    estado1();
  }
   delay(100); 
}

void estado1(){
  digitalWrite(rojo, LOW);

 for(int i=0; i<5; i++){
  digitalWrite(verde,HIGH); //encendemos el led rojo
  tone(bocina, 1000, 500);
  delay(500);             //esperamos 2 segundos
  digitalWrite(verde,LOW);  //apagamos el led rojoHIGH
  delay(500);              //esperamos medio segundo 
 }
 
 digitalWrite(amarillo,HIGH); //encendemos el led amarillo
 delay(2000);                 //esperamos 2 segundos
 digitalWrite(amarillo,LOW);  //apagamos el led amarillo
 
 
 digitalWrite(rojo,HIGH); //encendemos el led verde
 
 
 
 estado2();
}

void estado2(){
  digitalWrite(rojoPeaton, LOW);
  digitalWrite(verdePeaton, HIGH);
  Serial.println("Ahora puede pasar...");
  delay(5000);

  
 for(int i=0; i<5; i++){
  digitalWrite(verdePeaton,HIGH); //encendemos el led rojo
  tone(bocina, 1000, 400);
  delay(400);             //esperamos 2 segundos
  digitalWrite(verdePeaton,LOW);  //apagamos el led rojo
  delay(400);              //esperamos medio segundo 
 }

 digitalWrite(rojoPeaton, HIGH);
 digitalWrite(rojo, LOW);
 valorPot = analogRead(pot)*15/1000;
}
