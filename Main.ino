const int Esp8266bulidInLed = 2;

void setup()
{
	Serial.begin(115200);
	delay(10);
	SetupRadioTransmiter();
	SetupWifi();

	pinMode(Esp8266bulidInLed, OUTPUT);
}

void loop()
{
	ListenForRfSignals();
	int behavior;
	behavior = WifiLoop();
	if (behavior != -99)
	{
		digitalWrite(Esp8266bulidInLed, HIGH);
		TransmiterLoop(behavior);
	}
	delay(500);
	digitalWrite(Esp8266bulidInLed, LOW);
	delay(500);
}
