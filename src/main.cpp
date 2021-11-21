#define BLINKER_MIOT_LIGHT
#define BLINKER_WIFI

#include <Blinker.h>

char auth[] = "点灯科技key";
char ssid[] = "Wi-Fi名称";
char pswd[] = "Wi-Fi密码";

int GPIO = 0;

#define BUTTON_1 "ButtonKey"

BlinkerButton Button1("key");

void button1_callback(const String &state)
{
  BLINKER_LOG("get button state: ", state);
  digitalWrite(GPIO, !digitalRead(GPIO));
  Blinker.vibrate();
}

void miotPowerState(const String &state)
{
  BLINKER_LOG("need set power state: ", state);

  if (state == BLINKER_CMD_OFF)
  {
    digitalWrite(GPIO, HIGH);

    BlinkerMIOT.powerState("off");
    BlinkerMIOT.print();
  }
  else if (state == BLINKER_CMD_ON)
  {
    digitalWrite(GPIO, LOW);
    BlinkerMIOT.powerState("on");
    BlinkerMIOT.print();
  }
}

void setup()
{
  Serial.begin(115200);
  pinMode(GPIO, OUTPUT);
  digitalWrite(GPIO, HIGH);
  Blinker.begin(auth, ssid, pswd);
  Button1.attach(button1_callback);
  BlinkerMIOT.attachPowerState(miotPowerState);
}

void loop()
{
  Blinker.run();
}
