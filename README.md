# BtechMiniProject

This is our BTech Mini project(Dec 2016) based upon Internet of things(IOT).

We have made anti-theft device using Arduino and ESP8266. Arduino is a microcontroller that can be programmed to do various task like house automation, sending notifications etc. And ESP8266 is a Wifi Module that is connected to the Arduino which makes arduino communicate over the Wifi.

The hardware is installed on the door, the arduino is programmed to sense if the door is close of open, the state of the door is sent over internet to the Android device, this is particularly useful when there are no people in the house and someone breaks into the house, this sends an notification to the user that alerts the user.
We used NotifyMyAndroid (NMA) as a server. Basically NMA is platform that pushes notification from any application to an Android device. 

Note: Unfortunately NotifyMyAndroid is officially dead (www.notifymyandroid.com). 
