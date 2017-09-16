#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
const char* Gniazdko1_ON = "0110101000101100000011110";
const char* Gniazdko2_ON = "0110101000101100000010110";
const char* Gniazdko3_ON = "0110101000101100000011010";
const char* Gniazdko1_OFF = "0110101000101100000001110";
const char* Gniazdko2_OFF = "0110101000101100000000110";
const char* Gniazdko3_OFF = "0110101000101100000001010";
void SetupRadioTransmiter()
{
	mySwitch.enableReceive(4); //D2 Lolin
	mySwitch.enableTransmit(5); //D1 Lolin
	mySwitch.setPulseLength(300);
	mySwitch.setRepeatTransmit(15);
}

void TransmiterLoop(int behavior)
{
	switch (behavior)
	{
	case 0:
		Serial.println("Gniazdko1_OFF");
		mySwitch.send(Gniazdko1_OFF);
		break;
	case 1:
		Serial.println("Gniazdko1_ON");
		mySwitch.send(Gniazdko1_ON);
		break;
	default:
		return;
	}
}
