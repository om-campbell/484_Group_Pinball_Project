# Welcome to the 484 Pinball Project Wiki
## Introduction
![image](https://github.com/om-campbell/484_Group_Pinball_Project/assets/95391563/20d9a2f8-a770-4ea8-940a-2e6816f70a2d)

The goal of this project was to electrify a mechanical cardboard pinball machine. Four aspects of the machine were changed: The playfield, the score keeping display, the plunger, and the flippers. The playfield, which origionally consisted of two holes for the player to target, was updated to two goal posts that reward the player with points that scale based on the number of balls in play. The display was updated to a color LCD and activley displays game time, balls in play, and score. The plunger **TO DO**. The flippers **TO DO**.
## Play Field
### Introduction
Obstacles are the cornerstone of any pinball machine. They are the sensors that govern score and by extensions the actions of the player. The goal of this prototype was to create a pinball machine that challanges the player and rewards skilled play. One was to make pinball more challanging is to have multiple balls in play. My pinball machine applies a score multiplier based on the number of balls in play. This is the central mechanic of the game.
### Sensors
The arduino Laser Sensor Kit was used to detect balls entering and exiting play and the when the player scores. The Laser Sensor Kit consists of two parts: the Laser Module and Receiver Module.
#### Laser Module
![image](https://github.com/IanPascoe/Pinball-Obstacles/assets/95391563/8b130b93-c085-426a-8113-2b9d1a2ffc12)

Image Source: [yvind Nydal Dahl](https://www.build-electronic-circuits.com/arduino-laser-module-ky-008/#:~:text=It's%20very%20straightforward%20to%20connect,the%20laser%20on%20and%20off.)

The Laser Module needs to be wired to a 5V power source and grounded. The signal pin has no connection.
#### Receiver Module
![image](https://github.com/IanPascoe/Pinball-Obstacles/assets/95391563/280aae61-0a56-46e5-a17a-b45dfb884981)

Image Source: [SuriTu Hobbey](https://srituhobby.com/laser-transmitter-and-receiver-module-with-arduino/)

The Receiver Module has three pins, one for 5V power, one for GND, and a digial output. For this project, the digital output data was read by an Ardunio Uno.
### Pinball Field Design
#### Sensor Location
![image](https://github.com/IanPascoe/Pinball-Obstacles/assets/95391563/3400b6c8-195b-4763-9974-96d22d5a7a30)

As mentioned above, the lasers were positioned to detect two things: One, a ball entering/exiting play, and two, when the player scores. The above image shows where each reveiver (R) and laser (T) are located on the machine.
#### Wiring Diagram
![image](https://github.com/IanPascoe/Pinball-Obstacles/assets/95391563/c11205a5-762d-42be-8df9-a1df70b77f35)
The sensors were wired as shown in the wiring diagram above.
#### Playing Field
![image](https://github.com/IanPascoe/Pinball-Obstacles/assets/95391563/951f8da3-765e-4950-9736-5b2fcc9af604)
### Demo Video
https://youtube.com/shorts/967ty7Ltx_s?feature=share
## Display
The display is positioned at the head of the pinball machine and provides information to the player via an LCD. The display is controlled by an arduino which receives information from the various sensors to determine the state of the game including; how many balls are in the field, when a point has been scored, if there is an active multiplier, etc. From the display the player will be able to see what multiplier if any is active, the score, and graphics may possibly be added later on to match our theme. 

![Back Of Pinball Display](https://github.com/om-campbell/484_Individual_Pinball_Project/assets/95777461/1805d10f-cbc5-4238-ac23-7842e7e45cd4)
![Under the board](https://github.com/om-campbell/484_Individual_Pinball_Project/assets/95777461/fceb112d-1c67-4ce6-9710-4e60679b43c0)


LCD INFO
Interface: SPI
LCD type: IPS
Driver: ST7789V
Resolution: 240(V) x 320 (H) RGB
Display size: 30.60（H）x 40.80（V）mm
Pixel size: 0.0975（H）x 0.0975（V）mm
Dimension: 58 x 35 (mm)

We used an arduino uno microcontroller clone to process the information from the game and display it to the screen. 6 Digital pins are used for the LCD and 4 are used for the various tripwire sensors receivers. 

### Schematic
The following image shows how the LCD is wired to the arduino
![image](https://github.com/om-campbell/484_Individual_Pinball_Project/assets/95777461/cbff060f-14b7-400d-baf6-167614743469)

### Demo
https://youtube.com/shorts/967ty7Ltx_s?feature=share

### References
https://www.waveshare.com/wiki/2inch_LCD_Module?Amazon


## Plunger
### Introduction 
The primary goal for the plunger was to electrify it, transforming it from a mechanical design that used a rubber band to launch the ball into play. By incorporating a solenoid and a push button, the user would be able to launch the ball into the field of play with a simple press. One of the challenges faced during electriying the plunger was ensuring the solenoid had enough power to effectively launch the ball.

### Solenoid
After ordering and testing a 5V solenoid I decided that it would not have enough power to effectivily launch the ball into the playing field. So I decided to order a 12V solenoid and a 12V/2A power supply that could be plugged into an outlet. I found a helpful [tutorial](https://www.youtube.com/watch?v=nwVRMU9grSI&t=569s) on YouTube that showed how to control a 12V solenoid with an Arduino. After watching the tutorial, I found that it would be better to not use an Arduino for this and just use a push button, which would trigger the solenoid. A diode was used in the circuit to protect the other components from voltage spikes caused by the solenoid. When the current flowing through the solenoid, which is an inductive load, is suddenly interrupted, the collapsing magnetic field generates a high-voltage spike in the opposite direction of the original current flow. This phenomenon is known as back electromotive force (back EMF). The didode in the circuit was placed in reverse, so if there is normal current flowing through the circuit, it does nothing, but if current starts flowing backwards, then the diode stops that current by essentially short-circuiting the solenoid.
<div align="center">
  <img src="https://github.com/Gwill10/ECE484_Final_Individual_Project/assets/94477072/a8b15c34-2185-4da7-bf13-62a1379dbeaa" alt="12V Solenoid wiring diagram">
  <p>12V Solenoid wiring diagram</p>
</div>

### Circuit Problem with New Solution
The problem that I encountered with this circuit is that the push button has 2A flowing through it when the soleiod is activated, and it is not rated for that amount of current. This caused the push button to burn out after a couple presses. This problem could be solved by purchasing a button that is rated for 2A, but there is also another solution, which I have shown in the wiring diagram below. The solution was to add a MOSFET, which is a type of transistor used for amplifying or switching electronic signals. It has three terminals: the gate, drain, and source. By applying a voltage to the gate, you can control the current flow between the drain and source. So the MOSFET allows us to send a small amount of current to one pin, which then controls a large amount of current through another pin. This allows the push button to control the soleniod without the full 2A flowing through it.

<div align="center">
  <img src="https://github.com/Gwill10/ECE484_Final_Individual_Project/assets/94477072/5de723a9-5cf1-42d5-93f5-2944f56965ec" alt="12V Solenoid wiring diagram">
  <p>12V Solenoid wiring diagram with MOSFET</p>
</div>

### Components
Here are the components needed to control the 12V solenoid.
* [Breadboard](https://core-electronics.com.au/solderless-breadboard-830-tie-point-zy-102.html)
* [Jumper Wires](https://core-electronics.com.au/solderless-breadboard-jumper-cable-wires-75-pieces.html)
* [Logic Level MOSFET](https://www.amazon.com/dp/B07WQWLL34?psc=1&ref=ppx_yo2ov_dt_b_product_details)
* [Push Button](https://www.amazon.com/Gikfun-6x6x5mm-Switch-Button-Arduino/dp/B00R17XUFC/ref=sr_1_3?crid=26S0GONOCOPCE&dib=eyJ2IjoiMSJ9.UnZlPAYRTmzRv8kXcUMgHIG8r1Rrm3GDYmrQnEs_uY8tCXqcbe7AL7ZT0l2t-8bD4XJi3bpUlm_64Dau7qE3XW_UaKYYrhFwLV6v_cASqXQXb70uFnKgSt7NnfscL9i4luAAzDlfKMVAC9oIzDpakvyy_MGP3vnrz0ZPtfs1QdskIVRnLKSwd--37P6kn15BpQXVbfUjUxiNpVwm8v5Q566Vl1p-wzZGv-7DWu5L4popkSyT6DHyJR3EdJ__n24qLWIGaC01ZHAeRqeV8O4UDNlh7HOiJcvPDNV3NEOqunM.jRuVocGrbWl3wyenRTjnNhs5fYBNMgEBC9oN1v_G8CI&dib_tag=se&keywords=arduino+push+button&qid=1715741766&s=industrial&sprefix=arduino+push+button%2Cindustrial%2C94&sr=1-3)
* [Flyback Diode](https://www.amazon.com/MIC-Silastic-Junction-Standard-Rectifier/dp/B07GQCSC7G)
* [10 kΩ Resistors](https://www.amazon.com/EDGELEC-Resistor-Tolerance-Multiple-Resistance/dp/B07QJB31M7/ref=sr_1_1_sspa?crid=2LKYFIA8Z9OZA&dib=eyJ2IjoiMSJ9.6LwS_eL7GUDzrQTHCbHoUhtgD75BE--f41K6RaSHsn44TNW0hac5sCANpl2l7pFhM3tHH9NEEG20bus5FYftDi74R2L55jBfD6DnxeibygG9h_AwMcJwHt9BIwnaomKBmKYNAqQWey28pwYSdTeNlIEp9ymbDTa9NWUjEW7FfiAhno4g777yDOdAlEzv5s0_akLPp74JqmrovrMvJhKHQl3WWwxIc2w2xV8ml90EP0Tmo7Xw9zngygc-jlRrYlB5eRj0666VNuu17r9VEwRuEJBeqN3CAnPtYmvmM2mdHns.n7b2tXwFjN0HdRhNzIhGft_9U5ChZ1KsUk26n_zEE84&dib_tag=se&keywords=10k+ohm+resistor&qid=1715741832&s=industrial&sprefix=10+kohm+resistot%2Cindustrial%2C97&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)
* [12V/2A Power Supply](https://www.amazon.com/dp/B077PW5JC3?psc=1&ref=ppx_yo2ov_dt_b_product_details)
* [12V Solenoid](https://www.amazon.com/FainWan-Electromagnet-JF-0530B-keepping-Solenoid/dp/B09L6ZXY61/ref=sr_1_2_sspa?dib=eyJ2IjoiMSJ9.BIP5V2fUDPePrM6d4OLKlvUrOb-dE5Xj3JJXpxAnVo88ip-A6KeZVd_-Tg8aPkEpHX3tDru0UmpwJ_qDoEnenQSHzM8N6LdNBzwRCJTM2vBoWXe3UGGzFB32Egq-Coa3AgzjI_vc-O1CSuElJZ9ifjgZwd1rOjBuc4l-blPTwgYUyuBTm9ileuQQoXkEqQ7ZQmsjpUlu_B_s7DkaUvN8hGJ-moSzfQ2L62vdfI_DmHU.qnmfzhChmKAKCqPfaQZHk8glwgoGcffK31mKzuO224s&dib_tag=se&keywords=12v+solenoid&qid=1715741701&sr=8-2-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)

### Final Circuit
Shown below is the final design of the circuit with the solenoid. In the image, there is a 3A fuse connected to the right side of the MOSFET that was taken out since it wasn't needed. 
<div align="center">
  <img src="https://github.com/Gwill10/ECE484_Final_Individual_Project/assets/94477072/121e277a-a606-409c-b2a9-f72b06effd2a" alt="Circuit with 12V solenoid" width="600">
  <p>Circuit with 12V solenoid</p>
</div>

Once the final design of the circuit was complete, I took out the push button that was originally in the circuit and soldered a larger button that could be connected to the side of the pinball machine, which is shown below. When the button is pressed, the solenoid is activated, and a ball is launched into play.
<div align="center">
  <img src="https://github.com/Gwill10/ECE484_Final_Individual_Project/assets/94477072/1d656cb4-5e8e-4776-bf7b-efbfa3c9f01c" alt="ECE484_Pinball_Button" width="600">
  <p>Push button to activate plunger</p>
</div>

### Plunger Demo Video
<div align="center">
  <a href="https://youtube.com/shorts/v7n4OeOehnQ?feature=share">
    <img src="https://img.youtube.com/vi/v7n4OeOehnQ/0.jpg" alt="Plunger Demo Video" width="400">
  </a>
</div>

## Flippers
The flippers were made up of a button, 12V solenoid and a 3D flipper. The solenoid is taped down to the board and screwed into to the flipper> This worked by have the button complete the circuit which then activated the solenoid. The solenoid would then pull the flipper down allowing it to turn on it's pivot point.     
    <img src="https://private-user-images.githubusercontent.com/94477032/331374670-c824c67c-2401-4a2d-8be2-2af26f023583.jpeg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTU4OTE3MTIsIm5iZiI6MTcxNTg5MTQxMiwicGF0aCI6Ii85NDQ3NzAzMi8zMzEzNzQ2NzAtYzgyNGM2N2MtMjQwMS00YTJkLThiZTItMmFmMjZmMDIzNTgzLmpwZWc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNTE2JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDUxNlQyMDMwMTJaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1iMjY0OTAyNDgyMjI2ZGUzOGMzYjNkYzgyYTVkYTI2ZDlkMzg1ZjU0OWRiNzA3YjgyYjUyMWVjM2E3OWUwMzBkJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.8_yXVdhXTI3dJMLeKBBlKCievaelrHiB8_-FWpmgsNk" alt="Parts Picture" width="400">

<img src="https://private-user-images.githubusercontent.com/94477032/331377753-99cd3acf-b423-4c6c-8008-2bd937f04d20.jpeg?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTU4OTIzNTcsIm5iZiI6MTcxNTg5MjA1NywicGF0aCI6Ii85NDQ3NzAzMi8zMzEzNzc3NTMtOTljZDNhY2YtYjQyMy00YzZjLTgwMDgtMmJkOTM3ZjA0ZDIwLmpwZWc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNTE2JTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDUxNlQyMDQwNTdaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1mNzJjYjk5ODNmZTUxZDE0ZGQ5OTdiNmE3NWVjYWVlMjlmM2Q0OTVhNzRiNDAyM2FlMzI5Njk1MWI5YTExZjFmJlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.lvFSXxhKz8rsTDuTFuQHLIfgeEyYFaT91JVVpBzpF1M" alt="flipper connection Picture" width="400">

Originally the flippers shared the circuit as the plunger. With this design we had power issues with getting the plunger to pull on the flipper. We first tried lighter 3D printed versions but that didn't work. We then changed to circuit to the one pictured below and had better results. 

![pinballc](https://github.com/om-campbell/484_Group_Pinball_Project/assets/94477032/107720ed-ad84-4223-b026-0078c7fc659f)


## Flipper Demo Video

https://youtube.com/shorts/DPpAwfs7jjY?feature=share
