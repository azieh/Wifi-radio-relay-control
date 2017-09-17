#include <ESP8266WiFi.h>
extern "C" {
#include "user_interface.h"
}
const char *ssid = "eeeeChodzTu";
const char *password = "wasylwasyl666";
IPAddress ip(192, 168, 1, 250);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

String switch1Name = "Switch1";
String switch2Name = "Switch2";
String switch3Name = "Switch3";
bool switch1State = false;
bool switch2State = false;
bool switch3State = false;

WiFiServer server(80);

void SetupWifi()
{
	Serial.print("Set IP");
	WiFi.config(ip, gateway, subnet);
	Serial.print("Connecting to ");
	Serial.println(ssid);
	WiFi.hostname("MyLolin");
	uint8_t mac[] = {0x42, 0x3C, 0x42, 0x3C, 0x42, 0x3C};
	wifi_set_macaddr(STATION_IF, mac);
	WiFi.begin(ssid, password);

	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}
	Serial.println("");
	Serial.println("WiFi connected");

	// Start the server
	server.begin();
	Serial.println("Server started");

	// Print the IP address
	Serial.println(WiFi.localIP());
}

int WifiLoop()
{
	// Check if a client has connected
	WiFiClient client = server.available();

	if (!client)
	{
		return -99;
	}

	// Wait until the client sends some data
	Serial.println("New client is comming");
	while (!client.available())
	{
		delay(100);
	}

	// Read the first line of the request
	String req = client.readStringUntil('\r');
	client.flush();

	int val;
	if (req.indexOf("/" + switch1Name + "/0") != -1)
	{
		Serial.println("Turn off " + switch1Name);
		val = 10;
		switch1State = false;
	}
	else if (req.indexOf("/" + switch1Name + "/1") != -1)
	{
		Serial.println("Turn on " + switch1Name);
		val = 11;
		switch1State = true;
	}
	else if (req.indexOf("/" + switch2Name + "/0") != -1)
	{
		Serial.println("Turn off " + switch2Name);
		val = 20;
		switch2State = false;
	}
	else if (req.indexOf("/" + switch2Name + "/1") != -1)
	{
		Serial.println("Turn on " + switch2Name);
		val = 21;
		switch2State = true;
	}
	else if (req.indexOf("/" + switch3Name + "/0") != -1)
	{
		Serial.println("Turn off " + switch3Name);
		val = 30;
		switch3State = false;
	}
	else if (req.indexOf("/" + switch3Name + "/1") != -1)
	{
		Serial.println("Turn on " + switch3Name);
		val = 31;
		switch3State = true;
	}
	else
	{
		Serial.println("Empty request");
		val = -99;
	}
	//Build HTML
	String html = htmlOpen +
			htmlSwitchButtonGroup(switch1Name, switch1State) +
			htmlSwitchButtonGroup(switch2Name, switch2State) +
			htmlSwitchButtonGroup(switch3Name, switch3State) +
			htmlClose;
	// Send the response to the client
	client.print(html);
	delay(100);
	Serial.println("Data readed and client disonnected");
	return val;
}
