#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include "SoftwareSerial.h"

#define STASSID "AntelGCxGx"
#define STAPSK  "7kkhs6mn"

#define STASSID2 "RDAMIANI"
#define STAPSK2  "45490400"

#define STASSID3 "Marco";
#define STAPSK3  "123456789";

SoftwareSerial NodeMCU(0,1);
const char* ssid = STASSID3;
const char* password = STAPSK3;

char apiResponse[1000] = "No Response"; //String data

void setup () {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting..");

  } 
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
    WiFiClient client;
    HTTPClient http;  //Declare an object of class HTTPClient
    http.begin(client,"http://todo-backend-express.herokuapp.com/");  //Specify request destination
    
    int httpCode = http.GET();                                                                  //Send the request
    if (httpCode > 0) { //Check the returning code
      String payload = http.getString();   //Get the request response payload
      StaticJsonBuffer<1000> jsonBuffer;
      //Serial.println("Testeando el json array");
      // parse a JSON array
      JsonArray& array2 = jsonBuffer.parseArray(payload);
      char *titleOfNearest;
      char * hour = "24";
      for(int i = 0;i < sizeof(array2);i++){
        const char* world = array2[i]["title"];
        const char* isCompleted = array2[i]["completed"];
        const char* url = array2[i]["url"];
        
        char* worldAux = const_cast<char*>(world);
        char delim[] = "|";
        char *token = strtok(worldAux,delim);
        int index = 0;
        char *importantInfo[2];
        while (token)
        {
          importantInfo[index++] = token;
          token = strtok(NULL,delim);
        }

        if(strcmp(importantInfo[1],hour) <= 0){
          titleOfNearest = importantInfo[0];
          hour = importantInfo[1];
        }
      }
      int lenOfNearest = strlen(titleOfNearest);
      Serial.write(titleOfNearest,lenOfNearest); //Write the serial data
    }
    http.end();   //Close connection
  }
  delay(5000);    //Send a request every 30 seconds
}
