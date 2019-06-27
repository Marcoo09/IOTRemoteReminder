# IOTRemoteReminder
It's a remote reminder of things, it includes an app in which you can set things and the hour and this will show the nearest thing that you have saved through a display. It includes integration with an audio buzzer, distance sensor, lcd screen and ESP8266 WIFI V. 0.9 .

This app and the arduino project retrieves the data from the following service:

http://todo-backend-express.herokuapp.com

The mobile app have been done in React Native.

The connection ports are:

Distance sensor: Gnd to Gnd. Echo -> pin 4. Trig -> pin 5. Vcc -> pin 11.

LCD: Gnd to Gnd. Vcc -> 5v. Sda -> A4. Scl -> A5.

Wif: Gnd to Gnd. Tx -> Rx. Rx -> Tx.

Buzzer: Positive to Pin 8 Negative to Gnd of ESP8266 Wifi module.
