
void setup() {
  
  Serial.begin(112500);
  
}
 
void loop() {
  
  taskOne();

  taskTwo();

  while(1);
  
}
 
void taskOne( )
{
    for( int i = 0;i<10;i++ ){
        Serial.println("Hello from task 1");
        delay(500);
    }
    Serial.println("Ending task 1");
}
 
void taskTwo( )
{
    for( int i = 0;i<10;i++ ){
        Serial.println("Hello from task 2");
        delay(1000);
    }
    Serial.println("Ending task 2");
}
