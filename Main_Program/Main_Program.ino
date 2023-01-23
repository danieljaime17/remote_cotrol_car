#include "CTBot.h"
#include <PZEM004Tv30.h>
#include "token.h"
//----------------------------InitSensor--------------------------------------

#if defined(ESP32)
PZEM004Tv30 pzem(Serial2, 16, 17);
#else
PZEM004Tv30 pzem(Serial2);
#endif
//---------------------------Init_TelegramBot------------------------------------------
template<class T> inline Print &operator <<(Print &obj, T arg) {
  obj.print(arg);
  return obj;
}


CTBot miBot;




void setup() {
    Serial.begin(115200);
    Serial.println("Iniciando Bot de Telegram");
  
    miBot.wifiConnect(ssid, password);

    miBot.setTelegramToken(token);

    if (miBot.testConnection()) {
    Serial.println("\n Conectado");
  }
  else {
    Serial.println("\n Problemas Auxilio");
  }


    // to reset the internal energy counter pzem.resetEnergy()
}




void loop() {

    TBMessage msg;

    if (CTBotMessageText == miBot.getNewMessage(msg)) {
    Serial << "Mensaje: " << msg.sender.firstName << " - " <<  msg.text << "\n";
    miBot.sendMessage(msg.sender.id, msg.text);
  }

  delay(500);
    
    /*
    Serial.print("Custom Address:");
    Serial.println(pzem.readAddress(), HEX);

    
    // Read the data from the sensor
    float voltage = pzem.voltage();
    float current = pzem.current();
    float power = pzem.power();
    float energy = pzem.energy();
    float frequency = pzem.frequency();
    float pf = pzem.pf();

    // Check if the data is valid
    if(isnan(voltage)){
        Serial.println("Error reading voltage");
    } else if (isnan(current)) {
        Serial.println("Error reading current");
    } else if (isnan(power)) {
        Serial.println("Error reading power");
    } else if (isnan(energy)) {
        Serial.println("Error reading energy");
    } else if (isnan(frequency)) {
        Serial.println("Error reading frequency");
    } else if (isnan(pf)) {
        Serial.println("Error reading power factor");
    } else {

        // Print the values to the Serial console
        //Serial.print("Voltage: ");      Serial.print(voltage);      Serial.println("V");
        //Serial.print("Current: ");      Serial.print(current);      Serial.println("A");
        //Serial.print("Power: ");        Serial.print(power);        Serial.println("W");
        //Serial.print("Energy: ");       Serial.print(energy,3);     Serial.println("kWh");
        //Serial.print("Frequency: ");    Serial.print(frequency, 1); Serial.println("Hz");
        //Serial.print("PF: ");           Serial.println(pf);

    }
    */

    Serial.println();
    delay(2000);
}