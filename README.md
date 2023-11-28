# Ethernet-Cable-Tester-for-Pic-18f4550

___
## How it work

Using LCD screen to show the connection pin status. In first row show the pin status, No:12345678. In the second row is the status symbol P present Pass, F present Fail and X for open connection. To pass the cable test, the connection of cable is in sequence "No:12345678" and in the second row of LCD there is  no X, open connection detect. At the end of the row there will be sign Pass.  Open connection mean particular wire may is not connected properly due to poor crimping or so. Additional feature is it able to detect swap wire connection. Example: the cable sequence not in order like No:12345687, where pin 7 and pin 8  are not it the correct slot position.

___
## Main item require:

1) Pic 18F4550  You may use other micro-controller, just ensure it require 16 pin mirco-controller + 8 pin for LCD = 24 pin
2) Pickit 2 or 3   if you using PIC chip, can use raspberry pi.
3) 2 x16 LCD
4) ethernet cable any length
5) RJ45 jack
6) Single core cables for connection
___

## Reference

1) Datasheet 18f4550
2) LCD connection   http://www.hacktronics.com/Tutorials/arduino-character-lcd-tutorial.html
3) How to setup 18f4550  http://www.pic18f.com/tutorial/2007/12/04/tutorial-1-hardware-setup/
4) How to use pickit 2  https://www.youtube.com/watch?v=HVQ4tj-D8jM
___
