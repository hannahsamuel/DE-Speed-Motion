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

Now that I had selected my parts, I researched what wire connections needed to be made to supply power to the photointerruper and external leds. I researched the part number which brought me to the a wiring diagram from the company that manufacture the photointerrupters. I also cross-checked several diagrams to clear any conflicting connections particulary with the "collecter" and "emitter" parts. 

<img width="384" alt="wiring digram" src="https://user-images.githubusercontent.com/90801601/149016879-56ab7543-5ba9-4d0c-8872-df56882e1fb7.PNG">
<img width="578" alt="wd2" src="https://user-images.githubusercontent.com/90801601/149017030-6ea602cf-44a7-40a2-bb58-d24a55567aaa.PNG">

I started to follow both of these diagrams to wire the photointerrupters and led. I made several revisions to my wiring to add more necessary components for the functionality for the circuit as a whole. Below is some photo documentation of my wiring process. 

![lcd](https://user-images.githubusercontent.com/90801601/149179963-f804832e-b016-447a-ab33-15387262159e.PNG)

![cp1](https://user-images.githubusercontent.com/90801601/149180161-38e60926-1c18-430d-b738-fc0906e0e659.PNG)

![cp2](https://user-images.githubusercontent.com/90801601/149180354-f8c66000-79ff-4548-9e1f-e0ce8a471ec6.PNG)



## Code Implementation
For the coding aspect of the projects, I coded the photo interrupters with analog pins to print analog values on the serial monitor. Then I observed the behavior of the values and determined a borderline value that would determine whethere leds would turn on and off. 
```
if (val>10)
{
digitalWrite(led, LOW);
}
else{
digitalWrite(led, HIGH);

}
//if object passed second photointerrupter, visual indication
if (val2>10)
{
digitalWrite(led2, LOW);
}
else{
digitalWrite(led2, HIGH);
}
```

Then I used if statement to change the state of the photointerrupter based on whether the analog values were reading above or below the borderline value. Then I used more if statments to calculate the time -using the millis function- between when the program started and when there was a state change.
```
 //object detected through first interrupter  -> check and declare timing -> constant changes state
if(digitalRead(led) == HIGH){
  timer = millis();
  constant = 1;
}
   //object detected through second interrupter  -> check and declare timing -> constant2 changes state
if(digitalRead(led2)== HIGH){
  timer2 = millis();
  constant2 = 1;
}
```
Once both sensors were calculated I substracted the times and began coding the speed calulations with math operations. Separate from this, I coded the interface pins of the lcd and then coded the arduino to print the final speed calculation on the lcd by setting the cursor which is the location at which the informatino will be printed on the screen. 

```
// Speed Calculation
 TIME = TIME/1000;
 speedX=(distance/TIME); //speed = distance/time
 speedX = speedX*3600;
 speedX=speedX/1000;
  //position speed on lcd
 lcd.setCursor(0, 0);
 lcd.print("Speed:");
 lcd.setCursor(0, 1);
 lcd.print(speedX, 1);
 lcd.print(" Km/Hr "); //displaying units
```
## Technical Challenges

A challenge I had was using the proper resistor values to pass the correct amount of voltage across the photointerruptors. At first I was using resistor that I had on hand or approximated, but the photointerrupters I was using were sensitive to the voltage being passed so I had to read resistor charts and obtain the correct ohms resistance. On the light emitting end was a 560 ohms resistance and on the light receiving end was a 56k ohms resistor. 

Another challenge I had was reading the analog input from the sensor. The photointerrupters were really sensitive so once you wire them into the board a simple push can mess up the reading values. To get a more accurate reading I would wait about 30 seconds to let the photointerrupter adjust to a consistent pattern of analog values before passing an object between the sensors.


## Final Thoughts
This project helped learn how to wire elctrical components and gather data from them by reading the analog values printed on the serial monitor. Using this information I would manpulate between 2 states to determine the passing of an object. I practiced and further develpoed my skills to code in the Arduino C++ environment as well as understading voltage, current, and resistant laws to produce a desired output. I also learned how to read schematic diagram and reseach sensor part to get the datasheets. 


https://user-images.githubusercontent.com/90801601/149181646-03727f83-2461-4229-a8d4-c1169f8a64c7.mp4








