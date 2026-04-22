#include <WiFi.h>
#include <WebServer.h>

// WiFi credentials
const char* ssid     = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// GPIO assignments
#define LED_PIN 6
#define PWM_PIN 10

// PWM configuration (runtime adjustable frequency)
static int pwmFreq       = 100;   // Hz (default)
static const int pwmResolution = 10;  // 10-bit (0–1023)

// Duty values
static const int dutyOn  = 512;
static const int dutyOff = 0;

// HTTP server
WebServer server(80);

// State
static bool pwmEnabled = false;


// HTML page with frequency slider
void handleRoot()
{
    String page;
    page.reserve(512);

    page += "<!DOCTYPE html><html><head>";
    page += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
    page += "<style>body{font-family:sans-serif;text-align:center;margin-top:40px;}";
    page += "button{padding:12px 24px;font-size:16px;margin:8px;}";
    page += "input{width:300px;}</style>";
    page += "</head><body>";

    page += "<h3>PWM Output</h3>";
    page += "<p>Status: ";
    page += (pwmEnabled ? "ON" : "OFF");
    page += "</p>";

    page += "<a href='/on'><button>ON</button></a>";
    page += "<a href='/off'><button>OFF</button></a>";

    page += "<p>Frequency: <span id='fval'>";
    page += String(pwmFreq);
    page += "</span> Hz</p>";

    page += "<input type='range' min='80' max='120' value='";
    page += String(pwmFreq);
    page += "' id='freq' oninput='updateFreq(this.value)'>";

    page += "<script>";
    page += "function updateFreq(val){";
    page += "document.getElementById('fval').innerText = val;";
    page += "fetch('/setFreq?f=' + val);";
    page += "}";
    page += "</script>";

    page += "</body></html>";

    server.send(200, "text/html", page);
}


// Enable PWM
void handleOn()
{
    pwmEnabled = true;
    ledcWrite(PWM_PIN, dutyOn);
    digitalWrite(LED_PIN, HIGH);

    server.sendHeader("Location", "/");
    server.send(303);
}


// Disable PWM
void handleOff()
{
    pwmEnabled = false;
    ledcWrite(PWM_PIN, dutyOff);
    digitalWrite(LED_PIN, LOW);

    server.sendHeader("Location", "/");
    server.send(303);
}


// Update frequency
void handleSetFreq()
{
    if (server.hasArg("f")) {
        pwmFreq = server.arg("f").toInt();

        // reattach with new frequency
        ledcDetach(PWM_PIN);
        ledcAttach(PWM_PIN, pwmFreq, pwmResolution);

        // restore state
        ledcWrite(PWM_PIN, pwmEnabled ? dutyOn : dutyOff);
    }

    server.send(200, "text/plain", "OK");
}


void setup()
{
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    // initial PWM setup
    ledcAttach(PWM_PIN, pwmFreq, pwmResolution);
    ledcWrite(PWM_PIN, dutyOff);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(200);
    }

    server.on("/", handleRoot);
    server.on("/on", handleOn);
    server.on("/off", handleOff);
    server.on("/setFreq", handleSetFreq);

    server.begin();
    Serial.println(WiFi.localIP());

}


void loop()
{
    server.handleClient();
}
