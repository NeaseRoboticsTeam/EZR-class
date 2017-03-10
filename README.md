#Welcome to the Nease Positronic Panthers FRC Team 6468 C++ Class File

Class file for F.I.R.S.T robotics pre-loaded with custom functions

##How do I use this class?

  Simply include the header `#include <WLPWR.h>` and intitialize it with the ports you want to use.
  Then, whenever you want to use a method of the class, simply preceed it with the name of the instance
  you've constructed. For example, if I constructed my function with `Willpower robo {4,5,0,1,3,2};`, I could
  use member functions like this: `robo.AutoRamp("up");` 
  
  That should get you started using methods from the Willpower class (and other classes) 
  Remember, you can always submit your own function ideas and we might make them methods of
  the class. Thank you!

##Why do we need or want this?
  Before, we had to instantiate the controller, the servos, the motors, and such in a bunch of different includes. Now we just name the     variables accordingly and we're done! also, functions of my design won't have to be replicated- They're already in the class as member     functions. Also, I'm working on making a button press function, so we don't have to make a new button press if loop everytime we need a   functionality added
