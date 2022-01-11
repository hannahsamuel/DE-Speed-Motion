# DE End of Course Project: Speed Calculator
#### By: Hannah Samuel
## Introduction
 For my final project in Digital Electronics, I wanted to use my arduino skills to calculate speed of an object moving on a straight path from an inital destination to a final destination. I chose these project because it is very applicable to the movemnt of vechicles on the road today and provides good insight on how to implement more safer guidlines. So this inspired me to create a minituare model of how the the speed of moving object would be calculated. In addition to calculated, I wanted the user to see this information visibly on a platform such as the speed limit signs that conveys the speed of a incoming driver.
 

<img src="https://user-images.githubusercontent.com/90801601/148887834-06350ebc-516d-4920-b732-1b5d284f3938.png" width="750" height="400">
<img src="https://user-images.githubusercontent.com/90801601/148888078-2d3ffd5a-c400-4bcd-b3c8-95e3a0ca25cd.png" width="750" height="400">
## Part Selection
To mimic the effect of the bluetooth detectors and signal, I replicated this behavior using the HY810H photointerrupters that are easier to maniuplate between a HIGH and LOW state to produce a desired response on an led (light emitting diode).


Photointerrupters are sensors that contain two main parts to it. On one side is a light emitter and on the opposite side is the phototransistor, or light receving end. The led, which is the internal light emitter, is given a certain amount of voltage with the help of a resistor to pass a channel of light to the phototransistor

<img src="https://user-images.githubusercontent.com/90801601/148890374-4695475e-08e0-43ab-b994-ac9a54bd2c81.jpg" width="300" height="300">

When the light passes through, the phototransistor is able to receive current and the internal led lights up. This is created our first state called "low" which means there is a consistent flow of light passed and no interruptions have occured. When you place an object in between the led and phototransistor, the current is blocked creating the second state "high" which tells you that an object had stipped the flow of the led. These two state allow you to pass an object through and convert from one state to the next.

![photointerrupterdiagram](https://user-images.githubusercontent.com/90801601/148890987-7c6734ad-7024-4b9c-a3e5-d4e1b4d6cb7c.jpg)

To show the results of the speed calculation, I utilized a liquid crystal display that is wried to the breadboard and arduino board to receive power for the interface pins and know what letters and numbers to display on the screen. LCDs are made a liquid crystal but from the human eye we see pixels. The pixels are charges with electric voltage and emit light that we see. By coding the lcd, I could print the speed calculation directly to the scren of the lcd. 

<img src="https://user-images.githubusercontent.com/90801601/148893982-3c4b5d01-713c-46c4-b611-64fb446fdfeb.png" width="500" height="300">


## Board Selection

To switch bewteen the high and low state by reading the analog values on a serial monitor, I utilzed the Arduino Uno as the microcontroller because it would provide the most simple wiring from a breadboard to the arduino board and connected to my laptop with a usb cable. This allowed me to test code easily by uploading it directly and seeing the results immediately. It also doesn't not need to be attached to a breadboard on its own because it is capable of supplying voltage and a ground port that can be wired to the corresponding section on the breadboard.The arduion uno board has the capability to manipulate interface pinds at the same time to provide control over the display using code. Some of these interface pins include register select, read/write, enable, display contrast, power supple, and back lights pins. Because of these pinds, the lcd is very efficent in changing the display to meet the needs of information that needs to be displayed. 

<img src="https://user-images.githubusercontent.com/90801601/148891733-3c3b41fa-d51d-491d-a9a2-4713c9a8cb43.jpg" width="750" height="450">

## Wiring

Now that I had selected my parts, I researched what wire connections needed to be made to supply power to the photointerruper and external leds. 

## Code Implementation




## Technical Challenges







