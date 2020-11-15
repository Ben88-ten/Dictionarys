#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();
int TMP36 = A0; //Der Sensor soll am analogen Pin A0 angeschlossen werden. Wir nennen den Pin ab jetzt "TMP36"
int sensorwert; // Erstellen einer Variablen für den Sensorwert.
int temperatur = 0; //Unter der Variablen "temperatur" wird später der Temperaturwert abgespeichert.

void setup() //Hier beginnt das Setup.
{
mySwitch.enableTransmit(10);  // Der Sender wird an Pin 10 angeschlossen
}

void loop()
{ 
mySwitch.send( -234, 24);// Wohnzimmer
delay (1000);
sensorwert=analogRead(TMP36); //Auslesen des Sensorwertes.
temperatur= map(sensorwert, 0, 410, -50, 150); //Umwandeln des Sensorwertes mit Hilfe des "map" Befehls.
mySwitch.send(temperatur, 24); // Der 433mhz Sender versendet die Temperatur als Dezimalzahl.
delay (30000); // Eine Sekunde Pause.
} //Mit dieser letzten Klammer wird der Loop-Teil geschlossen.


