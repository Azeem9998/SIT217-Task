int A=10; 
int B=11;
int speed;

char input;     // to store input character received via BT.

void setup()
{
  Serial.begin(9600);  
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(A0,INPUT);
  pinMode(A, OUTPUT); 
  pinMode(B,OUTPUT); 
}

void loop()
{
  speed = analogRead(A0);
  speed = speed * 0.249;
  analogWrite(A,speed);
  analogWrite(B,speed);

  while(Serial.available())
  {
    input =Serial.read();
    if(input == 'F')
    {
      forward();
    }

    else if (input== 'R')
    {
      right();

      
    }

    else if (input== 'L')
    {
      left();

    
    }  

     else if (input== 'G')
    {
      backward();

    
    }      else if (input== 'S')
    {
      stop();

    
    }  

  }

}  
void forward()
  {
  digitalWrite(5, LOW	);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void stop()
  {
  digitalWrite(5, LOW	);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void backward()
  {
  digitalWrite(5, HIGH	);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}

void right()
  {
  digitalWrite(5, HIGH	);
  digitalWrite(4, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void left()
  {
  digitalWrite(5, LOW	);
  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}
