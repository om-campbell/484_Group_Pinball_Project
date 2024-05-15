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
(Demo Link)[https://youtube.com/shorts/967ty7Ltx_s?feature=share]
## Display
## Plunger
### Introduction 
The primary goal for the plunger was to electrify it, transforming it from a mechanical design that used a rubber band to launch the ball into play. By incorporating a solenoid and a push button, the user would be able to launch the ball into the field of play with a simple press. One of the challenges faced during electriying the plunger was ensuring the solenoid had enough power to effectively launch the ball.

Solenoid
After ordering and testing a 5V solenoid I decided that it would not have enough power to effectivily launch the ball into the playing field. So I decided to order a 12V solenoid and a 12V/2A power supply that could be plugged into an outlet. I found a helpful [tutorial](https://www.youtube.com/watch?v=nwVRMU9grSI&t=569s) on YouTube that showed how to control a 12V solenoid with an Arduino. After watching the tutorial, I found that it would be better to not use an Arduino for this and just use a push button, which would trigger the solenoid. A diode was used in the circuit to protect the other components from voltage spikes caused by the solenoid. When the current flowing through the solenoid, which is an inductive load, is suddenly interrupted, the collapsing magnetic field generates a high-voltage spike in the opposite direction of the original current flow. This phenomenon is known as back electromotive force (back EMF). The didode in the circuit was placed in reverse, so if there is normal current flowing through the circuit, it does nothing, but if current starts flowing backwards, then the diode stops that current by essentially short-circuiting the solenoid.
<div align="center">
  <img src="https://github.com/Gwill10/ECE484_Final_Individual_Project/assets/94477072/a8b15c34-2185-4da7-bf13-62a1379dbeaa" alt="12V Solenoid wiring diagram">
  <p>12V Solenoid wiring diagram</p>
</div>




## Flippers
