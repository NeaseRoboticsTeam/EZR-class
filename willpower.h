//Essentials needed to run the class
#include <iostream>
#include <memory>
#include <string>
#include <RobotDrive.h>
#include <XboxController.h>
#include <Spark.h>
#include <Servo.h>
#include <math.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Timer.h>
#include <CameraServer.h>
class Willpower{
	

	private:
	//Initialize Variables for functions using controller
	bool A = xbox.GetAButton();//check if A button is pressed
	bool B = xbox.GetBButton();//check if B button is pressed
	bool X = xbox.GetXButton();//check if X button is pressed
	bool Y = xbox.GetYButton();//check if Y button is pressed
	bool Start = xbox.GetStartButton();//check if start button is pressed
	bool Back = xbox.GetBackButton();//check if back button is pressed
	bool RBump = xbox.GetBumper((frc::GenericHID::JoystickHand)0);//check if right bumper is pressed
	bool LBump = xbox.GetBumper((frc::GenericHID::JoystickHand)1);//check if left bumper is pressed
	double LStickY =  xbox.GetY((frc::GenericHID::JoystickHand)1);//check y value of left stick
	double RStickY =  xbox.GetY((frc::GenericHID::JoystickHand)0);//check y value of right stick
	double LTrigP = xbox.GetTriggerAxis((frc::GenericHID::JoystickHand)1);//Get the trigger axis value of the controller left hand
	double RTrigP = xbox.GetTriggerAxis((frc::GenericHID::JoystickHand)0);//Get the trigger axis value of the controller right hand
	std::string rbump = "rbump";
	std::string lbump = "lbump";
	std::string start = "start";
	std::string back = "back";
	std::string a = "a";
	std::string c = "b";
	std::string x = "x";
	std::string y = "y";

	public:
	Willpower(int LServoPort, int RServoPort, int FRP, int BRP, int FLP, int BLP);//constructor for willpower
	Willpower(int LServoPort, int RServoPort, int LMotor, int RMotor);
	Willpower(int FRP, int BRP, int FLP, int BLP);//constructor for willpower **example of constructor overloading**
	Willpower(int LMotor, int RMotor);
	frc::Servo LServo {LServoPort}; //constructor for left servo
	frc::Servo RServo {RServoPort}; // constructor for right servo
	frc::RobotDrive myRobot { FLP, BLP, FRP, BRP};
	frc::RobotDrive myRobot { LMotor, RMotor}; //constructor for myRobot, paramaters are ports
	frc::XboxController xbox {0}; //constructor for xbox controller
	frc::Timer timer;
	frc::Timer autoTimer;
	frc::Timer teleTime;


	//simple drive function, basically our shell over the TankDrive function ;)
	void drive(double Lval, double Rval){
		myRobot.TankDrive(Lval, Rval);
	}

	//A more useful function, this one is used for when you need tankdrive in the auto phase. Just initialize with left and right speeds, a start time, and an end time
	void autoDrive(double Lval, double Rval, double start, double fin){
		autoTimer.Reset();
		autoTimer.Start();
		while(start < autoTimer.Get() && autoTimer.Get() < fin){
			myRobot.TankDrive(Lval, Rval);
		}
		autoTimer.Stop();

	}

	//Another version of autodrive, accepts directions instead of individual powers


	void autoDrive(std::string dir, double start, double fin){
          //      dir = tolower(dir);
		autoTimer.Reset();
		autoTimer.Start();
		while((start < autoTimer.Get() ) && (autoTimer.Get() < fin)){
		if(dir == "forward"){
				myRobot.TankDrive(.5,.545);
			}

		if(dir == "back"){
				myRobot.TankDrive(-.5,-.5);
			}

		if(dir == "right"){
				myRobot.TankDrive(.5,-.5);
			}

		if(dir == "left"){
				myRobot.TankDrive(-.5,.5);
			}
		}
		autoTimer.Stop();
	}
	//function to set ramp to a certain angle. BE CAREFUL NOT TO BREAK THE SERVOS WITH THIS ONE
	void ramp(int Langle, int Rangle){
			RServo.SetAngle(Rangle);
			LServo.SetAngle(Langle);
	}
	//another ramp function, CAUTION CAUTION CAUTION CAUTION!!!!!!! MAY BREAK SERVOS!!!
	void ramp(std::string pos){
	//	pos = tolower(pos);
		if(pos == "up"){
			RServo.SetAngle(130);
			LServo.SetAngle(170);
		}
		if(pos == "down"){
			RServo.SetAngle(250);
			LServo.SetAngle(60);
		}
	}
	//a third function for the ramp, just as dangerous as the others. this one can be used in auto mode though, so you have EVEN LESS CONTROL.
	void autoRamp(std::string pos, double start, double fin){
              //  pos = tolower(pos);
		autoTimer.Reset();
		autoTimer.Start();
		while((start < autoTimer.Get() ) && (autoTimer.Get() < fin)){
			if(pos == "up"){
				RServo.SetAngle(130);
				LServo.SetAngle(170);
				}
			if(pos == "down"){
				RServo.SetAngle(250);
				LServo.SetAngle(60);
				}
			}
		autoTimer.Stop();
		}
	//The GOOD STUFF. buttonPress function is meant to simplify our code by
	void buttonPress(char button, std::string func, double val1, double val2 ){
		button = tolower(button);
	switch (button) {
		case "a":
		{
			if(A != 0){
				if(func == "drive"){
					myRobot.TankDrive(val1,val2);
					}
				if(func == "servo"){
					RServo.SetAngle(val2);
					LServo.SetAngle(val1);
					}
				}
		break;
		}
		case "b":
		{
			if(B != 0){
				if(func == "drive"){
					myRobot.TankDrive(val1,val2);
					}
				if(func == "servo"){
					RServo.SetAngle(val2);
					LServo.SetAngle(val1);
					}
				}
		break;
		}
		case "x":
		{
			if(X != 0){
				if(func == "drive"){
					myRobot.TankDrive(val1,val2);
					}
				if(func == "servo"){
					RServo.SetAngle(val2);
					LServo.SetAngle(val1);
					}
				}
		break;
		}
		case "y":
		{
			if(Y != 0){
				if(func == "drive"){
					myRobot.TankDrive(val1,val2);
					}
				if(func == "servo"){
					RServo.SetAngle(val2);
					LServo.SetAngle(val1);
					}
				}
		break;
			}
		}
	}
	void buttonPress(std::string button, std::string func, double val1, double val2 ){
		//button = tolower(button);
	switch (button) {
		case "rbump":
		{
			if(RBump != 0){
				if(func == "drive"){
					myRobot.TankDrive(val1,val2);
					}
				if(func == "servo"){
					RServo.SetAngle(val2);
					LServo.SetAngle(val1);
					}
				}
		break;
		}
		case "lbump":
		{
			if(LBump != 0){
				if(func == "drive"){
					myRobot.TankDrive(val1,val2);
					}
				if(func == "servo"){
					RServo.SetAngle(val2);
					LServo.SetAngle(val1);
					}
				}
		break;
		}
		case "start":
		{
			if(Start != 0){
				if(func == "drive"){
					myRobot.TankDrive(val1,val2);
					}
				if(func == "servo"){
					RServo.SetAngle(val2);
					LServo.SetAngle(val1);
					}
				}
		break;
		}
		case "back":
		{
			if(Back != 0){
				if(func == "drive"){
					myRobot.TankDrive(val1,val2);
					}
				if(func == "servo"){
					RServo.SetAngle(val2);
					LServo.SetAngle(val1);
					}
				}
		break;
		}

	}
};
