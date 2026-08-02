#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

const char* ssid = "ESP32-Servo";
const char* password = "12345678";

#define SERVO_PIN 18
#define GREEN_LED 26
#define RED_LED 27

WebServer server(80);
Servo myServo;

const int OPEN_POSITION = 90;
const int CLOSE_POSITION = 0;


// الصفحة الرئيسية
void handleRoot() {

  String html =
  "<!DOCTYPE html>"
  "<html>"
  "<head>"
  "<title>ESP32 Servo Control</title>"
  "</head>"

  "<body style='text-align:center;font-family:Arial;'>"

  "<h1>ESP32 Servo Controller</h1>"

  "<button onclick=\"fetch('/open')\" "
  "style='font-size:30px;'>OPEN</button>"

  "<br><br>"

  "<button onclick=\"fetch('/close')\" "
  "style='font-size:30px;'>CLOSE</button>"

  "</body>"
  "</html>";

  server.send(200, "text/html", html);
}


// فتح السيرفو
void openServo() {

  myServo.write(OPEN_POSITION);

  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);

  server.send(200, "text/html",
  "<h1>Servo OPEN</h1><br><a href='/'>Back</a>");
}


// إغلاق السيرفو
void closeServo() {

  myServo.write(CLOSE_POSITION);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);

  server.send(200, "text/html",
  "<h1>Servo CLOSE</h1><br><a href='/'>Back</a>");
}


void setup() {

  Serial.begin(115200);


  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);


  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);


  myServo.attach(SERVO_PIN, 500, 2400);
  myServo.write(CLOSE_POSITION);



  WiFi.softAP(ssid, password);


  Serial.println();
  Serial.println("Access Point Started");

  Serial.print("SSID: ");
  Serial.println(ssid);

  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());



  server.on("/", handleRoot);

  server.on("/open", openServo);

  server.on("/close", closeServo);


  server.begin();

  Serial.println("Web Server Started");

}


void loop() {

  server.handleClient();

}