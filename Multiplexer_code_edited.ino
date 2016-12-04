
int r0 = 0;      //value of select pin at the 4051 (s0)
int r1 = 1;      //value of select pin at the 4051 (s1)
int r2 = 2;      //value of select pin at the 4051 (s2)
int count = 0;   //which y pin we are selecting
int count2 = 0;

int sensor = 0;
int num = 0;
int pressureArray[16];

void setup() {
  Serial.begin(9600);
  pinMode(0, OUTPUT);    // s0
  pinMode(1, OUTPUT);    // s1
  pinMode(2, OUTPUT);    // s2
}

void loop () {
  for (count=0; count<=7; count++) 
  {
    // select the bit  
    r0 = bitRead(count,0);    //Forms the selecting algorithms     
    r1 = bitRead(count,1);    //     
    r2 = bitRead(count,2);    //   
      
    sensor = count+1;
    count2 = count+8;
    

    digitalWrite(0, r0);
    digitalWrite(1, r1);
    digitalWrite(2, r2);

    pressureArray[count] = analogRead(0);
    pressureArray[count2] = analogRead(1);
/*
    if( count == 6){
      Serial.print("Error: ");
      Serial.println( fsrReading - num );
      num = fsrReading;
    }*/
    
   /* Serial.print("Output ");
    Serial.println(sensor);
    Serial.print("Analog1: ");
    Serial.println(fsrReading);
    Serial.print("Analog2: ");
    Serial.println(fsrReading2);
    */

    //delay(500);
  }  

  for (count=0; count<=15; count++)
  {
    Serial.print("Output ");
    Serial.println(count);
    Serial.println(pressureArray[count]);
    
  }
  delay(1000);
  
}
