Owen Campbell
Grant Willoughby
Ian Pascoe
Shaun Valentine

Proposal

Plunger:
For the plunger, I will attempt to use a servo motor, which will either block the ball or release the ball into the plunger when needed. Then, for the plunger, I will use a solenoid similar to the one linked below with a push button that will 
launch the ball into the playing field. If the 5V solenoid does not have enough power to get the ball into the playing field, we could use a 12V solenoid. Then we would also have to find a way to get a 12V power supply to the solenoid. 

Obstacles:
Rubber Bouncer: Link
	
Two rubber bouncers located close to the paddles. They will be made using 3-D printing for the base, and nuts and bolts for the pegs. The bouncers will have no electrical components, they exist purely for fun. See the image below for reference.


Wall Mounted Button: Link
Protruding from the upper walls and top of the game board will be several push buttons. This will be constructed using a 3-D printed square with a simple push button mounted behind it. Durability could be a concern here, so this will be tested early 
on in the design.

Scoring:
To make the game more interesting and encourage the player to have multiple balls in play at once, each target's score will be multiplied by the number of balls in play. This will be tracked with a laser sensor mounted in front of the plunger and 
behind the paddles.

Resources:
5V Small Solenoid | Core Electronics Australia
12V Solenoid | Adafruit
Push Button
Rubber Rings
Laser Sensor



Display: 
	The display will be positioned at the head of the pinball machine and pass information to the player via a TFT or Oled LCD. The display will be controlled by an arduino which will receive information from the various sensors to determine the state 
 of the game including; how many balls are in the field, when a point has been scored, if there is an active multiplier, etc. From the display the player will be able to see what multiplier if any is active, the score, and graphics may possibly be 
 added later on to match our theme. 

We will use the arduino uno microcontroller to process the information from the game and display it to the screen. Depending on the pins required to integrate the display and various sensors, we may add another arduino to our design, using one to pass 
information to the display and another to gather and calculate data from the sensors. As of now I plan to use wires to connect the devices however, depending on the size of the board we may consider using bluetooth to transfer data between the 
microcontrollers. 


Pinball Flippers
	For the flippers, I will be using an electromagnet paired with the flipper and attach them using metal rods and levers. The whole system will just take electrical energy from the button press and convert it into mechanical energy. When the users press 
 the button to move a flipper, it completes the circuit. The press will ground the system allowing electricity through the electromagnet. The magnet will pull in the metal rod and make the flipper go up. The exact voltages for the system haven’t been 
 worked out yet. Depending on the weight of the metal will determine the strength needed to move the flipper.
