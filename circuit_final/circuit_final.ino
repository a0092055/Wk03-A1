/*
Blink + Button + Fade
Press Button to Fade Up the LED, Release Button to Fade Out
*/
int ledPin = 9; // LED connected to digital pin 13
int buttonPin = 2; // Button connected to digital pin 2
int buttonRead = LOW; // Button state
int fadeValue = 0; // LED fading brightness
void setup() {
// initialize the digital pin as an output:
pinMode(ledPin, OUTPUT);
pinMode(buttonPin, INPUT);
// initialize Serial commnication port at 9600 bps:
Serial.begin(9600);
Serial.println("type 1:LED On 2: LED Off");
}
void loop()
{
buttonRead = digitalRead(buttonPin);
if(buttonRead == HIGH){ // check if button pressed
if(fadeValue <245) fadeValue=fadeValue+20; //increment fadeValue
}else if(buttonRead == LOW){ //if button is not pressed
if(fadeValue > 0) fadeValue--;
}
Serial.println(fadeValue);
analogWrite(ledPin, fadeValue);
// wait for 30 milliseconds to see the dimming effect
delay(5);
}
