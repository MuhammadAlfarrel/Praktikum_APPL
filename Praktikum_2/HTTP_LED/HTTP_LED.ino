#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

// Ganti dengan password Jaringan WiFi yang user miliki
const char* ssid = "Galaxy";
const char* password = "Alfarrel";
WebServer server(80); //Inisialisasi server pada port 80
String page = "";
int LEDPin = 4; //Pin yang digunakan untuk mengendalikan LED
void setup(void){
//the HTML of the web page
  page = "<h1>Simple ESP32 Web Server</h1><p><a href=\"LEDOn\"><button>ON</button></a>&nbsp;<a href=\"LEDOff\"><button>OFF</button></a></p>";

  //Inisialisasi pin D4 padam ketika NodeMCU pertama kali menyala
  pinMode(LEDPin, OUTPUT);
  digitalWrite(LEDPin, LOW);
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password); //begin WiFi connection
  Serial.println("");
  // Wait for connection
  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", [](){
    server.send(200, "text/html", page);
  });

  server.on("/LEDOn", [](){
    server.send(200, "text/html", page);
    digitalWrite(LEDPin, HIGH);
  delay(1000);
  });

  server.on("/LEDOff", [](){
    server.send(200, "text/html", page);
    digitalWrite(LEDPin, LOW);
    delay(1000);
  });

  server.begin();
  Serial.println("Web server started!");
}

void loop(void){
  server.handleClient();
}
