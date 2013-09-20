yolo-octo-robot
===============

Defining the color of tri-color led from a joystick. Project is done with an arduino

The code
========
The code is in the file joystick.ino.


The circuit
===========

We use an arduino uno with a joystick and tri-color led.


The joystick
------------
Connect the joystick in the correct pin:
* GND: with the ground.
* 5v: with the 5v pin of the arduino.
* VRx: with the anolog pin 1
* VRy: with the analog pin 0
* SW: we don't use it.


The tri-color led
-----------------
We use the pwm pin 9, 10 and 11 of digital output of the arduino.
Here, we use the following mapping:
* 9: red
* 10: green
* 11: blue

In order to decrease the high intensity of the led, we added a resistance after the led.

Image of the circuit
--------------------

<img src="http://pics.urlab.be/albums/divers/1379688212_yolo_octo_robot.png"/>



Some Pictures :
======
<img src="http://pics.urlab.be/albums/divers/1379685985_IMG_1163.JPG" width="50%"/>
<img src="http://pics.urlab.be/albums/divers/1379685985_IMG_1165.JPG" width="50%"/>
<img src="http://pics.urlab.be/albums/divers/1379685985_IMG_1166.JPG" width="50%"/>
