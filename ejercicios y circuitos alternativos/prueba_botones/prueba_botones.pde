const int botonPU= 8;
const int botonPD1=12;
const int botonPD2=13;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

void setup() {

  pinMode(botonPU, INPUT);     
  pinMode(botonPD1, INPUT);     
  pinMode(botonPD2, INPUT);     

  Serial.begin(9600); 
}

void loop(){

  buttonState1 = digitalRead(botonPU);
  buttonState2 = digitalRead(botonPD1);
  buttonState3 = digitalRead(botonPD2);

  Serial.println("Botones:");
  
  Serial.print("pin 8: ");
  if(buttonState1 == HIGH) 
  {
    Serial.println("HIGH");  
  }
  else
  {
    Serial.println("LOW");  
  }


  Serial.print("pin 12: ");
  if(buttonState2 == HIGH) 
  {
    Serial.println("HIGH");  
  }
  else
  {
    Serial.println("LOW");  
  }


  Serial.print("pin 13: ");
  if(buttonState3 == HIGH) 
  {
    Serial.println("HIGH");  
  }
  else
  {
    Serial.println("LOW");  
  }
  delay(2000);


}

