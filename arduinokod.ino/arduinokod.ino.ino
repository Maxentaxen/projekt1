
// Include Libraries
#include <RTClib.h>
#include <Wire.h>
#include <U8glib.h>

// Init constants
const int tempPin = A0;
const int ledPin = 7;

// Init global variables


// Construct objects
RTC_DS3231 rtc;
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);


void setup() {
  // init communication
  Serial.begin(9600);
  Wire.begin();

  // Init Hardware
  rtc.begin();
  u8g.setFont(u8g_font_unifont);
  pinMode(ledPin, OUTPUT);

  // Settings
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop() {
  oledWrite(40, 10, getTime(), 40, 40, String(getTemp()));

  if (isPrime(getSeconds()) == 1) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  delay(500);
}


/*
*This function reads time from an ds3231 module and package the time as a String
*Parameters: Void
*Returns: time in hh:mm:ss as String and if minutes or seconds are below 10, hh:0m:0s
*/
String getTime() {
  DateTime now = rtc.now();
  String time = String(now.hour()) + ":";
  if (now.minute() < 10) {
    time = time + "0" + String(now.minute()) + ":";
  }
  else {
    time = time + String(now.minute()) + ":";
  }
  if (now.second() < 10) {
    time = time + "0" + String(now.second());
  }
  else {
    time = time + String(now.second());
  }

  return time;
}

/*
* This function reads an analog pin connected to an analog temprature sensor and calculates the corresponding temp
*Parameters: Void
*Returns: temprature as float
*/

float getTemp() {

  int Vo;
  float R1 = 10000;  // value of R1 on board
  float logR2, R2, T;
  float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741;


  Vo = analogRead(tempPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);  //calculate resistance on thermistor
  logR2 = log(R2);
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));  // temperature in Kelvin
  T = T - 273.15;                                              //convert Kelvin to Celcius

  return T;
}

/*
* This function takes a string and draws it to an oled display
*Parameters: - text: String to write to display
*Returns: void
*/

void oledWrite(int x1, int y1, String text1,
               int x2, int y2, String text2) {
  u8g.firstPage();
  do {
    u8g.drawStr(x1, y1, text1.c_str());
    u8g.drawStr(x2, y2, text2.c_str());
  } while (u8g.nextPage());
}

/*
* This function takes a number and returns whether or not the number is prime 
* Parameters: - number: Int to check for primality
* Returns: Bool
*/

bool isPrime (int n) {
  int primes[4] = {2, 3, 5, 7};

  for (int i = 0; i < 3; i++) {
    if (n % primes[i] == 0 && n != primes[i] || n == 1){
      return false;
    }
  }
  return true;
}


/* This function returns only the seconds of the current time
* Parameters: - none
* Returns: Int 
*/

int getSeconds() {
  DateTime now = rtc.now();
  return int(now.second());
}
