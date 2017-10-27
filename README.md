# Welcome to the Nease Positronic Panthers FRC Team 6468 Class File
### Willpower Class

Class file for F.I.R.S.T robotics

### How do I use this class?

  Simply include the header `#include <Willpower.h>` and instantiate the class with the ports you want to use.
  Then, whenever you want to use a method of the class, simply preceed it with the object name.
  For example, if I named my object as follows: `Willpower robo {4,5,0,1,3,2};`, I could
  use member functions like this: `robo.autoRamp("up");` 
  
  That should get you started using methods from the Willpower class (and other classes) 
  Remember, you can always submit your own function ideas and we might make them methods of
  the class. Thank you!

### Why do we need or want this?
  Instead of doing stuff like this 
  `if(a != 0){
        myRobot.TankDrive(.5,.5);
     }`
   We can just do this
   `robo.buttonPress(a,tank,.5,.5);`
   
  Before, we had to instantiate the controller, the servos, the motors, and use a bunch of different includes. Now we just name the variables accordingly and we're done! also, functions of my design won't have to be replicated- They're already in the class as member functions. Also, I'm working on making a button press function, so we don't have to make a new button press if loop everytime we need a functionality added. Functions for the robot should be made abstract and stored in the class for future use. We also need method documentation, so if someone wants to make that, that'd be good ;)
  
  Also Go Check out our WIKI to get futher briefing on this project!
