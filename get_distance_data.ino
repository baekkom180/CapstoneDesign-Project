/*
 *  This sketch sends a message to a TCP server
 *
 */

#include <WiFi.h>
#include <WiFiMulti.h>



WiFiMulti WiFiMulti;
#define ONE_WIRE_BUS 23


int trigPin = 25;
int echoPin = 26;
long duration;
int distance;
void setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    
   // delay(10);

    // We start by connecting to a WiFi network
    WiFiMulti.addAP("TOMNTOMS1F", "TOMNTOMS4565");

    Serial.println();
    Serial.println();
    Serial.print("Wait for WiFi... ");

    while(WiFiMulti.run() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.begin(115200);
    //sensors.begin();
    delay(500);
}


void loop()
{
    const uint16_t port = 8085;
    const char * host = "ec2-174-129-80-114.compute-1.amazonaws.com"; // ip or dns
    String get_data;
   // sensors.requestTemperatures();
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration*0.034/2;
    Serial.print("Distance: ");
    Serial.println(distance);
    get_data += "/distance_data?device_id=1&value=";
    get_data += distance;
    Serial.print(get_data);
    
    Serial.print("Connecting to ");
    Serial.println(host);

    // Use WiFiClient class to create TCP connections
    WiFiClient client;

    if (!client.connect(host, port)) {
        Serial.println("Connection failed.");
        Serial.println("Waiting 5 seconds before retrying...");
        delay(5000);
        return;
    }
    if(distance<=50){
      client.print("GET " + get_data + " HTTP/1.1\n\n");
    }
    

    int maxloops = 0;

    //wait for the server's reply to become available
    while (!client.available() && maxloops < 1000)
    {
      maxloops++;
      delay(1); //delay 1 msec
    }
    if (client.available() > 0)
    {
      //read back one line from the server
      String line = client.readStringUntil('\r');
      Serial.println(line);
    }
    else
    {
      Serial.println("client.available() timed out ");
    }
    Serial.println("Closing connection.");
    //client.stop();
    delay(1000);
    //sleep();
}
