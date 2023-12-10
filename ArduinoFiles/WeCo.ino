
#include <WiFi.h>
#include <WiFiClient.h>
#include <FirebaseESP32.h>

//change to weco one
#define FIREBASE_HOST "weco-e6334-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "HGLIuJii7aMkmFePnAINC9SqthF6GI3Ahd1Wy1Oy"

// WiFi Credentials
#define WIFI_SSID "kanaka@unifi"
#define WIFI_PASSWORD "Roscoe19"

FirebaseData firebaseData;
FirebaseJson json;

// Motor A connections
int enA = 14;
int in1 = 27;
int in2 = 26;
// Motor B connections
int enB = 32;
int in3 = 25;
int in4 = 33;
String speedata;
int speed = 150;
int control;

void setup() {
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
  //stop();
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

// void firebase_data(){
// if (Firebase.getString(firebaseData, "/WeCo/control"))
//     {
//       if (firebaseData.stringData() == "65")
//       {
//         accelerate();
//       }
//       else if (firebaseData.stringData() == "66")
//       {
//         back();
//       }
//       else if (firebaseData.stringData() == "82")
//       {
//         right();
//       }
//       else if (firebaseData.stringData() == "76")
//       {
//         left();
//       }
//       else if (firebaseData.stringData() == "83")
//       {
//         stop();
//       }
//       else{
//       // speedata = firebaseData.stringData();
//       // speed = speedata.toInt();
//       // analogWrite(enA, speed);
//       // analogWrite(enB, speed);
//       }
//     }  
//   if (Firebase.getString(firebaseData, "/WeCo/speed"))
//     {
//       speedata = firebaseData.stringData();
//       speed = speedata.toInt();
//       analogWrite(enA, speed);
//       analogWrite(enB, speed);
//     } 
// }
void loop() {
if (Firebase.getString(firebaseData, "/WeCo/control"))
    {
      if (firebaseData.stringData() == "65")
      {
        //accelerate();
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);        
      }
      else if (firebaseData.stringData() == "66")
      {
        //back();
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
      }
      else if (firebaseData.stringData() == "82")
      {
        //right();
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
      }
      else if (firebaseData.stringData() == "76")
      {
        // left();
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
      }
      else if (firebaseData.stringData() == "83")
      {
        //stop();
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
      }
      else{
      // speedata = firebaseData.stringData();
      // speed = speedata.toInt();
      // analogWrite(enA, speed);
      // analogWrite(enB, speed);
      }
    }  
  if (Firebase.getString(firebaseData, "/WeCo/speed"))
    {
      speedata = firebaseData.stringData();
      speed = speedata.toInt();
      analogWrite(enA, speed);
      analogWrite(enB, speed);
    }
}

// This function lets you control spinning direction of motors
// void accelerate() {
// 	digitalWrite(in1, HIGH);
// 	digitalWrite(in2, LOW);
// 	digitalWrite(in3, HIGH);
//   digitalWrite(in4, LOW);
// }

// This function lets you control speed of the motors
// void back() {

// 	// Turn on motors
//   digitalWrite(in1, LOW);
//   digitalWrite(in2, HIGH);
//   digitalWrite(in3, LOW);
//   digitalWrite(in4, HIGH);
// }

// void left() {
// 	// Turn on motors
//   digitalWrite(in1, HIGH);
//   digitalWrite(in2, LOW);
//   digitalWrite(in3, LOW);
//   digitalWrite(in4, HIGH);
// }

// void right() {
// 	// Turn on motors
//   digitalWrite(in1, LOW);
//   digitalWrite(in2, HIGH);
//   digitalWrite(in3, HIGH);
//   digitalWrite(in4, LOW);
// }

// void stop(){
//   digitalWrite(in1, LOW);
// 	digitalWrite(in2, LOW);
// 	digitalWrite(in3, LOW);
// 	digitalWrite(in4, LOW);
// }






