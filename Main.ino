
void setup() {
	Serial.begin(115200);
	delay(10);
	SetupRadioTransmiter();
	SetupWifi();
 
	pinMode(4, OUTPUT); //built-in ESP8266 LED
}

void loop() {
	int behavior;
	behavior = WifiLoop();
	if (behavior != -99)
	{
    digitalWrite(4, HIGH); 
		TransmiterLoop(behavior);
	}
 delay(500);
 digitalWrite(4, LOW);
 delay(500);
}
