/*********************************************************************
Insulin Minder
* OLED 128x32 I2C SSD1306 Display
* DS18B20 Temperature Sensor
* 5-Way Navigation Stick
* Adafruit 3.3V 12MHz Trinket Pro
* Battery monitoring via internal voltage reference
* Battery management via Trinket Pro LiPo backpack
*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <OneWire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/sleep.h>

// Display
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

// Temperature Sensor
#define TEMP_SENSOR_PIN 3

// Navigation Stick
#define NAV_N_PIN 8
#define NAV_S_PIN 10
#define NAV_E_PIN 11
#define NAV_W_PIN 12
#define NAV_C_PIN 9

unsigned long masterTime;

extern prog_uchar Bit_Daylong11[] PROGMEM;
extern prog_uchar Bit_Daylong11_width[] PROGMEM;
extern prog_uint16_t Bit_Daylong11_offset[] PROGMEM;

void setup()   {                
  // Setup the pins for the navigation stick
  pinMode(NAV_N_PIN, INPUT_PULLUP);
  pinMode(NAV_S_PIN, INPUT_PULLUP);
  pinMode(NAV_E_PIN, INPUT_PULLUP);
  pinMode(NAV_W_PIN, INPUT_PULLUP);
  pinMode(NAV_C_PIN, INPUT_PULLUP);
  
  pinMode(13, OUTPUT);
  masterTime = 0;

  // Initialise the temperature sensor
  getTemperature2(TEMP_SENSOR_PIN, 1);

  // Initialise the OLED display
  // generate the high voltage from the 3.3v line internally
  // initialize with the I2C addr 0x3C (for the 128x32)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);  
  
  // Setup interrupts for navigation stick
  pciSetup(NAV_N_PIN);
  pciSetup(NAV_S_PIN);
  pciSetup(NAV_E_PIN);
  pciSetup(NAV_W_PIN);
  pciSetup(NAV_C_PIN);
  
  // Setup the watch dog timer
  wdtSetup();
}


void loop() {
  int temperature = getTemperature2(TEMP_SENSOR_PIN, 0);

  displayOn();
  display.clearDisplay();
  //drawTemperatureHistory();
  display.setCursor(0, 0);
//  display.print("temp:    ");
//  display.print(temperature);
//  display.println();
  
//  display.print("vcc:     ");
//  display.print(getVcc());
//  display.println();
//  
//  display.print("nav:     ");
//  if (digitalRead(NAV_N_PIN) == LOW) display.print("N");
//  if (digitalRead(NAV_S_PIN) == LOW) display.print("S");
//  if (digitalRead(NAV_E_PIN) == LOW) display.print("E");
//  if (digitalRead(NAV_W_PIN) == LOW) display.print("W");
//  if (digitalRead(NAV_C_PIN) == LOW) display.print("C");
//  display.println();
//  
//  display.print("seconds: ");
//  display.print(masterTime);
  
  flexFontSetPos(0, 0);
  flexFontColour(WHITE);
  flexFontDrawString(&display, "A TEST OF HOW MUCH TEXT CAN BE FIT.", Bit_Daylong11, Bit_Daylong11_width, Bit_Daylong11_offset, 8, '.');  
  
  display.display();
  
  delay(2000);
  
  displayOff();
  
  //sleep();
}

void displayOn() {
  display.ssd1306_command(SSD1306_DISPLAYON);
}

void displayOff() {
  display.ssd1306_command(SSD1306_DISPLAYOFF);
}

void drawTemperatureHistory() {
  display.setCursor(0, 0);
  display.println("-1d");

  display.setCursor(79, 0);
  display.println("Now");
  
  display.drawRect(0, 8, 96, 24, WHITE);
}

// Sets up the pin change interrupt on the given pin
void pciSetup(byte pin)
{
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

void wdtSetup() {
  // Clear the reset flag
  MCUSR &= ~(1<<WDRF);
  
  // In order to change WDE or the prescaler, we need to set WDCE (This will allow updates for 4 clock cycles)
  WDTCSR |= (1<<WDCE) | (1<<WDE);

  // Set new watchdog timeout prescaler value
  WDTCSR = 1<<WDP0 | 1<<WDP3; /* 8.0 seconds */
  
  // Enable the WD interrupt (note no reset)
  WDTCSR |= _BV(WDIE);
}

// Enters sleep mode to be woken on a pin change or the watchdog timer after 8 seconds
// Various sources went into this, such as:
// * http://donalmorrissey.blogspot.com.au/2010/04/putting-arduino-diecimila-to-sleep-part.html
void sleep() {
    // Attach to interrupt 0 (pin change on port B and external interrupt 0)
    
    // Choose our preferred sleep mode
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
 
    // Set sleep enable (SE) bit
    sleep_enable();
 
    // Put the device to sleep
    sleep_mode();
 
    // Upon waking up, sketch continues from this point
    sleep_disable();
    
    // Re-endable all this peripherals
    power_all_enable();
}

// Interupt handler for pin change interrupts on port B
ISR(PCINT0_vect) {
   // This is called when the interrupt occurs, but it doesn't need to do anything as the
   // interrupt is just used to wake the microcontroller from sleep
   
  //  if (digitalRead (13) == HIGH)
  //    digitalWrite (13, LOW);
  //  else
  //    digitalWrite (13, HIGH);
}

// Interupt handler for watchdog timer
ISR(WDT_vect) {
   // This is called when the interrupt occurs.
   // We use this to:
   // i)  Update the master time (as the WDT is now the only means we have of keeping time as the normal timers won't run when asleap).
   // ii) Kick off the main "awake" loop - normally this will go to sleep immediatly unless we need to record the temperature or are 
   //     already awake doing UI stuff.
   masterTime += 8;
}

// Code taken from http://www.scargill.net/reading-dallas-ds18b20-chips-quickly/
// Thanks to Peter Scargill
int16_t getTemperature2(int x, byte start)
{
  OneWire ds(x);
  byte i;
  byte data[2];
  int16_t result;
  
  do
  {
    ds.reset();
    ds.write(0xCC);  // skip command
    ds.write(0xBE);  // read 1st 2 bytes of scratchpad
    for (i = 0; i < 2; i ++) data[i] = ds.read();
    result = (data[1] << 8) | data[0];
    result >>= 4;
    if (data[1] & 128) result |= 61440;
    if (data[0] & 8) ++result;
    ds.reset();
    ds.write(0xCC); // skip command
    ds.write(0x44, 1);  // start conversion, assuming 5V connected
    if (start) delay(1000);
  }
  while (start --);
  return result;
}

// Code taken from https://code.google.com/p/tinkerit/wiki/SecretVoltmeter
// Thanks to cathed...@gmail.com (full email not disclosed) / TinkerLondon / Tinker.it
long getVcc() {
  long result;
  // Read 1.1V reference against AVcc
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA,ADSC));
  result = ADCL;
  result |= ADCH<<8;
  result = 1126400L / result; // Back-calculate AVcc in mV
  return result;
}

