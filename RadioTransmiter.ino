#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
const char *Switch1_ON = "0110101000101100000011110";
const char *Switch2_ON = "0110101000101100000010110";
const char *Switch3_ON = "0110101000101100000011010";
const char *Switch1_OFF = "0110101000101100000001110";
const char *Switch2_OFF = "0110101000101100000000110";
const char *Switch3_OFF = "0110101000101100000001010";
void SetupRadioTransmiter()
{
	mySwitch.enableReceive(4);  //D2 Lolin I/O
	mySwitch.enableTransmit(5); //D1 Lolin I/O
	mySwitch.setPulseLength(300);
	mySwitch.setRepeatTransmit(15); // in case of lost signals
}

void TransmiterLoop(int behavior)
{
	switch (behavior)
	{
	case 10:
		mySwitch.send(Switch1_OFF);
		break;
	case 11:
		mySwitch.send(Switch1_ON);
		break;
	case 20:
		mySwitch.send(Switch2_OFF);
		break;
	case 21:
		mySwitch.send(Switch2_ON);
		break;
	case 30:
		mySwitch.send(Switch3_OFF);
		break;
	case 31:
		mySwitch.send(Switch3_ON);
		break;
	default:
		return;
	}
}

void ListenForRfSignals()
{
	if (mySwitch.available())
	{

		int value = mySwitch.getReceivedValue();

		if (value == 0)
		{
			Serial.print("Unknown encoding");
		}
		else
		{
			output(
				mySwitch.getReceivedValue(),
				mySwitch.getReceivedBitlength(),
				mySwitch.getReceivedDelay(),
				mySwitch.getReceivedRawdata(),
				mySwitch.getReceivedProtocol()
			);
		}

		mySwitch.resetAvailable();
	}
}