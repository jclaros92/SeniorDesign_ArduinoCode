void setup() {
  pinMode( 6 , OUTPUT);  // Must be a PWM pin
}

void loop() {
  int x;
  int y = 0;

 analogWrite( 6 , 153 );  // 60% duty cycle
  delay(10000);              // on time

  analogWrite( 6 , 0 );    // 0% duty cycle (off)
  delay(1000);             // off time



 
  
  for( x = 0 ; x < 154 ; x++ ) 
  {
    analogWrite( 6 , x );
    delay(100);
  }
  
  analogWrite( 6 , 0 ); //off

  

}
