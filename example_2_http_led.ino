//#include <ESP8266WiFi.h>
//#include <string.h>
#include <WiFi.h>
#include <WiFiMulti.h>
const char *ssid = "CROWD_2G";
const char *password = "crowdcoffee1";

const char* host = "ec2-174-129-80-114.compute-1.amazonaws.com";
int led = 4;

void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network
  pinMode(led, OUTPUT);
 // digitalWrite(led, 1);
  
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
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

int value = 0;

void loop() {
//  delay(5000);
  ++value;

  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 8085;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
  String url = "/";
//  url += streamId;
//  url += "?private_key=";
//  url += privateKey;
//  url += "&value=";
//  url += value;
  url += "warning_value";
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  int timeout = millis() + 5000;
  while (client.available() == 0) {
    if (timeout - millis() < 0) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  String warning = "warning1";
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\n');
    Serial.print(line);
    Serial.print(warning);
    Serial.print("--------\n");
    if(line.equals(warning))
    {
      Serial.print("income!!\n");
      //digitalWrite(led, 0);
      //delay(1000);
      digitalWrite(led, 1);
      //delay(1000);
    }
    else
    {
      digitalWrite(led,0);
    }
  }
  
  Serial.println();
  Serial.println("closing connection");
}
