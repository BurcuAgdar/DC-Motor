int potentiometer = A0;//analog pin to which potentiometer is connected
int potentiometerValue;//value read from potentiometer
int counter=0; //variable for loop in wait function
int butonPort=2;//pin to which the button is attached
int motorPort1= 3; //the port the motor is connected to
int motorPort2= 5; //the port the motor is connected to
boolean first, second;//variables that hold the value of the button
boolean butonFlag = false;//'buttonFlag' is false unless the button is pressed

void setup()//setup function
{
  pinMode(motorPort1, OUTPUT);
  pinMode(motorPort2, OUTPUT);
  pinMode(butonPort, INPUT);
}

void btn(){ //function that checks whether the button is pressed or not
  first = digitalRead(butonPort);//the value of the button is read
  butonFlag=false;//'buttonFlag' is false unless the button is pressed
  if (second != first)//The equality of the value read from the button with the previous value is checked.
  {
      if (first == HIGH)//If the value read from the button is high, the 'butonFlag' variable will be 'true'
      {
          butonFlag = true; 
      }
  }
  second = first;//In order to compare it with the previous value, the value of the button is saved in the second variable.
}

void wait(int direction1 ,int direction2 ){//rotation time in one direction (3 sec)
  counter=0;
  while(counter<=100){ //The while cycles 100 times every 30 milliseconds to check if the button is pressed.
               //If the button is not pressed, there is a 3 second delay time
    delay(30);
    counter++;    
    potentiometerValue = analogRead(potentiometer);//value read from potentiometer
    potentiometerValue = map(potentiometerValue, 0, 1023, 0, 255); //conversion of the value read from the potentiometer to the range 0 and 255
    analogWrite(direction2, 0);
    analogWrite(direction1, potentiometerValue);//motor turns forward or backward
    btn();//button is controlled    
    if(first==HIGH && butonFlag){//If the button is pressed, the cycle is terminated.
      break;
    }
  }
}

void loop()
{ 
  wait(motorPort1,motorPort2);//Rotates forward for 3 milliseconds
  wait(motorPort2,motorPort1);//Rotates backward for 3 milliseconds
}
