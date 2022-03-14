#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

 
const char* ssid = "CGA2121_LSqeC2T";
const char* password = "hiddenpassword";

//const char *host = "http://httpbin.org/post";
const char *host = "https://access-control-umg.herokuapp.com/api/test";
 
void setup() {
  Serial.begin(115200);
  Serial.println("\nWiFi station setting");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting ");
  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
    delay(500);
    Serial.println(".");
  }
  Serial.println("\nWiFi ready");
  Serial.println("My ip adress: ");
  Serial.println(WiFi.localIP());
}
 
void loop() {
  HTTPClient http;
    WiFiClient client;   
     
    http.begin(client, host); 
    http.addHeader("Content-Type", "application/json");         
     
    StaticJsonDocument<200> doc;
    // Add values in the document
    //
    doc["userID"] = "mario";
    doc["time"] = 1351824120;
   
    // Add an array.
    //
    JsonArray data = doc.createNestedArray("data");
    data.add(48.756080);
    data.add(2.302038);
     
    String requestBody;
    serializeJson(doc, requestBody);
     
    int httpCode = http.POST(requestBody);

    String payload = http.getString();
 
    Serial.print("Response Code:");
    Serial.println(httpCode);
    Serial.print("Returned data from Server: ");
    Serial.println(payload);

    http.end();
    delay(5000);
}
 
void postDataToServer() {
 
  Serial.println("Posting JSON data to server...");
  // Block until we are able to connect to the WiFi access point
  if (WiFi.status() == WL_CONNECTED) {
     
    
     
  }
}
