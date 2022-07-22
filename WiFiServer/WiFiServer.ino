#include <WiFi.h>

const char* ssid     = "ssid";
const char* password = "password";

WiFiServer server(80);

void setup()
{
    Serial.begin(115200);
    pinMode(23, OUTPUT);      

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();
}

int value = 0;

void loop(){
 WiFiClient client = server.available(); 

  if (client) {                           
    Serial.println("New Client.");          
    String currentLine = "";                
    while (client.connected()) {            
      if (client.available()) {             
        char c = client.read();          +  
        Serial.write(c);                   
        if (c == '\n') {                    
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.print("ESP32 Web Server Example<br>");
            client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 23 on.<br>");
            client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 23 off.<br>");
            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') { 
          currentLine += c;      
        }

        if (currentLine.endsWith("GET /H")) {
          digitalWrite(23, HIGH);               
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(23, LOW);                
        }
      }
    }
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
