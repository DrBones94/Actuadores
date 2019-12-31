/*
 * KY-25 SWITCH MAGNETICO (x2) PARA LOS LATERALES
 * MD-SWL3D FIN DE CARRERA (x1) PARA QUE EL FRENO ACTIVE LOS SPOILERS
 * EN EL FUTURO VER SI HAY MODULO WIFI O BLUETOOTH PARA QUE CONECTE CON UNA API Y PUEDA MANEJAR LOS CONTROLES DESDE EL CELULAR.
*/

int diffuserPin = 23; //Actuador de diffuser
int spoiler1Pin = 31; //Actuador de spoiler 1
int spoiler2Pin = 32; //Actuador de spoiler 2
int spoiler3Pin = 33; //Actuador de spoiler 3
int spoiler4Pin = 34; //Actuador de spoiler 4
int frontAirPin = 24; //Actuador de frontAir
int brakePin = 13; //Fin de carrera del freno
int switchPin = 12; //Switch de activacion
int rightSidePin = 11; //Activador del lateral derecho
int leftSidePin = 10; //Activador del lateral izquierdo
int rightSpoilerPin = 25; //Lateral derecho
int leftSpoilerPin = 26; //Lateral izquierdo


void setup() {
  
  pinMode(brakePin, INPUT); //Freno con el fin de carrera
  pinMode(diffuserPin, OUTPUT); //Diffuser
  pinMode(spoiler1Pin, OUTPUT); //Spoiler
  pinMode(spoiler2Pin, OUTPUT); //Spoiler
  pinMode(spoiler3Pin, OUTPUT); //Spoiler
  pinMode(spoiler4Pin, OUTPUT); //Spoiler
  pinMode(switchPin, INPUT); //Activador de spoiler.
  pinMode(rightSidePin, INPUT);
  pinMode(leftSidePin, INPUT);
  pinMode(rightSpoilerPin, OUTPUT);
  pinMode(leftSpoilerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int ky25 = analogRead(A1);
  Serial.println(ky25);
  
  delay(3);
  int brake = digitalRead(brakePin);
  int switch1 = digitalRead(switchPin); 
  int rightSide = analogRead(A1);
  int leftSide = analogRead(A2);

  if(brake == 1 /*&& switch1 == 1*/){
    digitalWrite(diffuserPin, brake);
    digitalWrite(spoiler1Pin, brake);
    digitalWrite(spoiler2Pin, brake);
    //digitalWrite(diffuserPin, brake);
    brake = digitalRead(brakePin);
  }

  int derecha = 0;
  int izquierda = 0;
  
  if(rightSide > 10){
    if(derecha == 0){
      derecha = 1;
    }else{
      derecha = 0;
    }
    digitalWrite(rightSpoilerPin, derecha);
  }else if(leftSide > 10){
    if(izquierda == 0){
      izquierda = 1;
    }else{
      izquierda = 0;
    }
    digitalWrite(leftSpoilerPin, izquierda);
  }else{
    digitalWrite(rightSpoilerPin, 0);
    digitalWrite(leftSpoilerPin, 0);
  }

	brake = 0;
  digitalWrite(diffuserPin, brake);
  digitalWrite(spoiler1Pin, brake);
  digitalWrite(spoiler2Pin, brake);
}
