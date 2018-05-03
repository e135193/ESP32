
void setup() {
 
  Serial.begin(112500);
 
  xTaskCreate(taskOne,"TaskOne",10000,NULL,1,NULL); 

  xTaskCreate(taskTwo,"TaskTwo",10000,NULL,1,NULL); 
}
 
void loop() {
  
}
 
void taskOne( void * parameter )
{
    for( int i = 0;i<10;i++ ){
        Serial.println("Hello from task 1");
        delay(500);
    }
 
    Serial.println("Ending task 1");
    vTaskDelete( NULL );
}
 
void taskTwo( void * parameter)
{
    for( int i = 0;i<10;i++ ){
        Serial.println("Hello from task 2");
        delay(1000);
    }
    Serial.println("Ending task 2");
    vTaskDelete( NULL );
}
