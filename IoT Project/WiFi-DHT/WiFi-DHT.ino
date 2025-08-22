

// Example testing sketch for various DHT humidity/temperature sensors written by ladyada
// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"
#include "WiFi.h"
#define WIFI_NETWORK "xxxxxxxx"  //YOUR WIFI NETWORK SSID HERE
#define WIFI_PASS "xxxxxxxxx"   //WIF PASSWORD
#define WIFI_TIMEOUT_MS 20000

#define DHTPIN 4     // Digital pin connected to the DHT sensor


// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  




// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);


void connectToWifi() {
  Serial.print("Connecting to Wifi");
  // In order to connect to an existing network we need to utilize station mode. 
  WiFi.mode(WIFI_STA);
  // Connect to the Network Using SSID and Pass. 
  WiFi.begin(WIFI_NETWORK, WIFI_PASS);
// Store the time it takes for Wifi to connect. 
  unsigned long startAttemptTime = millis();
// The While loop utilize the Wifi Status to check if its connect as well as makes sure that the timeout was not reached. 
  while(WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT_MS){
    
    Serial.print(".");
    // Deply so this while loop does not run so fasts. 
    delay(100);
  }
if(WiFi.status() != WL_CONNECTED){
    Serial.println("");
    Serial.println("Failed to Connect to Wifi");
    delay(5000);
   
   
    // May want to but the ESP32 into Deep Sleep for a bit. 
  } else {
    Serial.print("Connected!");
    Serial.println(WiFi.localIP()); 
  }
}
  
void setup() {
  Serial.begin(115200);
  Serial.println(F("Ian's WiFi-Enabled DHT22 Sensor Test!"));
  connectToWifi();
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}
