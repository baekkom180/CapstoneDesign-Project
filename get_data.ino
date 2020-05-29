#include <WiFi.h>
#include <WiFiMulti.h>



WiFiMulti WiFiMulti;
#define ONE_WIRE_BUS 23
int threshold = 200;
int led = 35;

int flag = 0;
int trigPin = 25;
int echoPin = 26;

int trigPin2 = 19;
int echoPin2 = 18;

int trigPin3 = 15;
int echoPin3 = 2;

long duration;
long duration2;
long duration3;

int distance;
int distance2;
int distance3;

int volume;
int soundGate = 34;

//String warning = "warning1";
void setup()
{
    //pinMode(led, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    
    pinMode(trigPin2, OUTPUT);
    pinMode(echoPin2, INPUT);
    
    pinMode(trigPin3, OUTPUT);
    pinMode(echoPin3, INPUT);

    
    pinMode(soundGate, INPUT);
    //pinMode(led, OUTPUT);
    // We start by connecting to a WiFi network
    WiFiMulti.addAP("sgwlan_guest", "");

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
    //String get_sound_data;
   // int sound_data;
    String url = "/";
    url += "warning_value";
    //Serial.println("before get data");
   // sensors.requestTemperatures();
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration*0.034/2;
    
    volume = analogRead(soundGate);

    delay(10);
    
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    duration2 = pulseIn(echoPin2, HIGH);
    distance2 = duration2*0.034/2;
    delay(10);
    
    digitalWrite(trigPin3, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin3, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin3, LOW);
    duration3 = pulseIn(echoPin3, HIGH);
    distance3 = duration3*0.034/2;
    
    //Serial.print("Distance: ");
   // Serial.println(distance);
    get_data += "/data?device_id1=1&value1=";
    get_data += distance;
    get_data += "&device_id2=2&value2=";
    get_data += distance2;
    get_data += "&device_id3=3&value3=";
    get_data += distance3;
    get_data += "&device_id4=4&value4=";
    get_data += volume;
   //Serial.println(get_data);
    
    //get_sound_data += "/sound_data?device_id=4&value=";
    //get_sound_data +=volume;
    //Serial.print(get_data);
    
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
    Serial.println("get_data:"+get_data);
    client.print("GET " + get_data + " HTTP/1.1\n\n");
    
    /*
    if(flag==0){
      Serial.print(get_data);
      if(distance<=500){
        client.print("GET " + get_data + " HTTP/1.1\n\n");
      }
      flag = 1;
    }
    else if(flag==1){
      Serial.print(get_sound_data);
      if(volume!=0){
         if(volume>=threshold){
          digitalWrite(led, HIGH);
         }
         else{
          digitalWrite(led, LOW);
         }
         client.print("GET " + get_sound_data + " HTTP/1.1\n\n");
      }
     
      flag = 0;
    }
    */
    
    /*
    client.print(String("GET ") +url + " HTTP/1.1\r\n"+ "Host: " +host + "\r\n" + 
    "Connection: close\r\n\r\n");
    int timeout = millis() + 5000;
    while(client.available()==0){
      if(timeout - millis()<0){
        Serial.println(">>>client timeout !");
        client.stop();
        return ;
      }
    }*/
    int maxloops = 0;

    //wait for the server's reply to become available
    while (!client.available() && maxloops < 1000)
    {
      maxloops++;
      delay(1); //delay 1 msec
    }
    //Serial.println("before client.available()>0");
    if (client.available() > 0)
    {
      //read back one line from the server
      String line = client.readStringUntil('\r');
      Serial.println(line);
      /*
      if(line.equals(warning)){
        Serial.print("--------------warning-----------------\n");
        digitalWrite(led, 0);
        delay(500);
        digitalWrite(led, 1);
        delay(500);
      }*/
    }
    else
    {
      Serial.println("client.available() timed out ");
    }
    Serial.println("Closing connection.");
    //client.stop();
    //delay();
    //sleep();
}
