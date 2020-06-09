

// *******************************************************
// ******** CONFIGURACION SENSORES DE TEMPERATURA ********
// *******************************************************
#define DEBUG 1



#define ONE_WIRE_BUS_0 14 // A0
#define ONE_WIRE_BUS_1 15 // A1
#define ONE_WIRE_BUS_2 16 // A2
#define ONE_WIRE_BUS_3 17 // A3


// Lower resolution
#define TEMPERATURE_PRECISION 9

//#define POSITION_1  {0x28,0xFF,0xFD,0x36,0x84,0x16,0x04,0x98}
//#define POSITION_1  {0x28,0xA3,0x77,0x02,0x08,0x00,0x00,0x05}

//#define POSITION_1  {0x28,0xf7,0x56,0x6a,0x09,0x00,0x00,0xe5}
#define POSITION_1  {0x28,0x5e,0x6c,0xe2,0x08,0x00,0x00,0x78}
#define NAME_SENSOR_1 "temp_out"
#define POSITION_2  {0x28,0x05,0x4a,0xe2,0x08,0x00,0x00,0xca}
#define NAME_SENSOR_2 "temp_in"
#define POSITION_3  {0x28,0x53,0x8E,0x01,0x08,0x00,0x00,0xAA}
#define NAME_SENSOR_3 "Temp_Amb"
#define POSITION_4  {0x28,0xFF,0x86,0x40,0x70,0x16,0x05,0x69}
#define NAME_SENSOR_4 "Tra Planta 3"
#define POSITION_5  {0xEE,0xEE,0xEE,0xEE,0xEE,0xEE,0xEE,0xEE}
#define NAME_SENSOR_5 " SENSOR POSITION"
#define POSITION_6  {0xEE,0xEE,0xEE,0xEE,0xEE,0xEE,0xEE,0xEE}
#define NAME_SENSOR_6 " SENSOR POSITIONL"
#define POSITION_7  {0xEE,0xEE,0xEE,0xEE,0xEE,0xEE,0xEE,0xEE}
#define NAME_SENSOR_7 " SENSOR POSITION"
#define POSITION_8  {0xEE,0xEE,0xEE,0xEE,0xEE,0xEE,0xEE,0xEE}
#define NAME_SENSOR_8 " SENSOR POSITION"
#define POSITION_9  {0xEE,0xEE,0xEE,0xEE,0xEE,0xEE,0xEE,0xEE}
#define NAME_SENSOR_9 " SENSOR POSITION"
#define POSITION_10  {0xEE,0xEE,0xEE,0xEE,0xEE,0xEE,0xEE,0xEE}
#define NAME_SENSOR_10 " SENSOR POSITION"
#define POSITION_11  {0xEE,0xEE,0xEE,0xEE,0xEE,0xEE,0xEE,0xEE}
#define NAME_SENSOR_11 " SENSOR POSITION"
#define POSITION_12  {0xEE,0xEE,0xEE,0xEE,0xEE,0xEE,0xEE,0xEE}
#define NAME_SENSOR_12 " SENSOR POSITION"



// *******************************************************

#include <OneWire.h>
#include <DallasTemperature.h>

String build_temperature_message_0();
String printName(DeviceAddress deviceAddress);
bool compareAddress(DeviceAddress deviceAddress_c_1, DeviceAddress deviceAddress_c_2);
void printResoltion(DeviceAddress deviceAddressPr);
String printAddress(DeviceAddress deviceAddressPa);
void temperatureSensorsBegin();


DeviceAddress tempDeviceAddress;
OneWire oneWire_0(ONE_WIRE_BUS_0);
OneWire oneWire_1(ONE_WIRE_BUS_1);
OneWire oneWire_2(ONE_WIRE_BUS_2);
OneWire oneWire_3(ONE_WIRE_BUS_3);
DallasTemperature sensors_m_0(&oneWire_0);
DallasTemperature sensors_m_1(&oneWire_1);
DallasTemperature sensors_m_2(&oneWire_2);
DallasTemperature sensors_m_3(&oneWire_3);
//DallasTemperature sensors[]={sensors_m_0,sensors_m_1,}

 //DeviceAddress
uint8_t deviceAddress_1[]=POSITION_1;
uint8_t deviceAddress_2[]=POSITION_2;
uint8_t deviceAddress_3[]=POSITION_3;
uint8_t deviceAddress_4[]=POSITION_4;
uint8_t deviceAddress_5[]=POSITION_5;
uint8_t deviceAddress_6[]=POSITION_6;
uint8_t deviceAddress_7[]=POSITION_7;
uint8_t deviceAddress_8[]=POSITION_8;
uint8_t deviceAddress_9[]=POSITION_9;
uint8_t deviceAddress_10[]=POSITION_10;
uint8_t deviceAddress_11[]=POSITION_11;
uint8_t deviceAddress_12[]=POSITION_12;

String temperatureString = ("");
uint8_t numberOfDevices=0;
uint32_t t_last_lcd;

String build_temperature_message_0() {

  if (DEBUG) Serial.println(F("****buildTemperatureMessage_0()"));
  numberOfDevices = sensors_m_0.getDeviceCount();
  if (DEBUG) Serial.print(F("numberOfDevices = "));
  if (DEBUG) Serial.println(numberOfDevices);
  sensors_m_0.requestTemperatures();

  String message_to_tx ="";
  for(int i=0;i<numberOfDevices; i++)
  {
     if(sensors_m_0.getAddress(tempDeviceAddress, i))
     {
       if (DEBUG) Serial.print(F("device number= "));
       if (DEBUG) Serial.println(i);
       float tempC = sensors_m_0.getTempC(tempDeviceAddress);
       String value_18 = String(tempC,1);
       String name_18 = printName(tempDeviceAddress);
       if (DEBUG) Serial.println(name_18 + ":" + value_18);
       message_to_tx = message_to_tx + name_18 + ":" + value_18 ;
       if (i != (numberOfDevices -1)) {message_to_tx +=",";}
     }

  }
  return message_to_tx;
}



String build_temperature_message_1() {

  if (DEBUG) Serial.println(F("****buildTemperatureMessage_1()"));
  numberOfDevices = sensors_m_1.getDeviceCount();
  if (DEBUG) Serial.print(F("numberOfDevices = "));
  if (DEBUG) Serial.println(numberOfDevices);
  sensors_m_1.requestTemperatures();

  String message_to_tx ="";
  for(int i=0;i<numberOfDevices; i++)
  {
     if(sensors_m_1.getAddress(tempDeviceAddress, i))
     {
       if (DEBUG) Serial.print(F("device number= "));
       if (DEBUG) Serial.println(i);
       float tempC = sensors_m_1.getTempC(tempDeviceAddress);
       String value_18 = String(tempC,1);
       String name_18 = printName(tempDeviceAddress);
       if (DEBUG) Serial.println(name_18 + ":" + value_18);
       message_to_tx = message_to_tx + name_18 + ":" + value_18 ;
       if (i != (numberOfDevices -1)) {message_to_tx +=",";}
     }

  }
  return message_to_tx;
}



String printName(DeviceAddress deviceAddress)
{

  String temp_sensor_name;

  // Incluye el nombre del sensor
  if     (compareAddress(deviceAddress,deviceAddress_1))  {temp_sensor_name = F((NAME_SENSOR_1));}
  else if(compareAddress(deviceAddress,deviceAddress_2))  {temp_sensor_name = F((NAME_SENSOR_2));}
  else if(compareAddress(deviceAddress,deviceAddress_3))  {temp_sensor_name = F((NAME_SENSOR_3));}
  else if(compareAddress(deviceAddress,deviceAddress_4))  {temp_sensor_name = F((NAME_SENSOR_4));}
  else if(compareAddress(deviceAddress,deviceAddress_5))  {temp_sensor_name = F((NAME_SENSOR_5));}
  else if(compareAddress(deviceAddress,deviceAddress_6))  {temp_sensor_name = F((NAME_SENSOR_6));}
  else if(compareAddress(deviceAddress,deviceAddress_7))  {temp_sensor_name = F((NAME_SENSOR_7));}
  else if(compareAddress(deviceAddress,deviceAddress_8))  {temp_sensor_name = F((NAME_SENSOR_8));}
  else if(compareAddress(deviceAddress,deviceAddress_9))  {temp_sensor_name = F((NAME_SENSOR_9));}
  else if(compareAddress(deviceAddress,deviceAddress_10)) {temp_sensor_name = F((NAME_SENSOR_10));}
  else if(compareAddress(deviceAddress,deviceAddress_11)) {temp_sensor_name = F((NAME_SENSOR_11));}
  else if(compareAddress(deviceAddress,deviceAddress_12)) {temp_sensor_name = F((NAME_SENSOR_12));}

  else temp_sensor_name = printAddress(deviceAddress);

 return temp_sensor_name;

}



bool compareAddress(DeviceAddress deviceAddress_c_1, DeviceAddress deviceAddress_c_2)
  {
    for(int i=0;i<7; i++)
      {
        if (deviceAddress_c_1[i] != deviceAddress_c_2[i]){return false;}
      }
    return true;
  }

void printResoltion(DeviceAddress deviceAddressPr)
{
  temperatureString += (sensors_m_0.getResolution(deviceAddressPr), DEC);
}



String printAddress(DeviceAddress deviceAddressPa)
{
  String string_temp_r="";
  for (uint8_t i = 0; i < 8; i++)
  {
    if (deviceAddressPa[i] < 16) string_temp_r += ("0");
    uint8_t temp= (deviceAddressPa[i]);
    String stringTemp =  String(temp, HEX);
    string_temp_r = string_temp_r +stringTemp;
  }
  return string_temp_r;
}

void temperatureSensorsBegin() {
  sensors_m_0.begin();
  sensors_m_1.begin();
  sensors_m_2.begin();
  sensors_m_3.begin();
  }


void setup() {
  delay(2000);

  Serial.begin(115200);

  Serial.println("Server started");

  // added for temperature sensor
  temperatureSensorsBegin();
  t_last_lcd= millis();


  delay(100);
}

void loop() {
  uint32_t current_time= millis();
  if ((current_time - t_last_lcd) > 10000){
    Serial.print(F("******Print LCD - sgs: "));
    Serial.println(millis() / 1000);
    t_last_lcd = current_time;
    String msj = build_temperature_message_0();
    Serial.print(F("** mensaje: "));
    Serial.println(msj);
    msj = build_temperature_message_1();
    Serial.print(F("** mensaje: "));
    Serial.println(msj);
    
    //if (msj != "nook") { emoncms_publish(msj);}
  }

}
