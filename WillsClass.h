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

class WillsClass{
	bool A = xbox.GetAButton();//check if A button is pressed
	bool B = xbox.GetBButton();//check if B button is pressed
	bool X = xbox.GetXButton();//check if X button is pressed
	bool Y = xbox.GetYButton();//check if Y button is pressed
	bool LStickY =  xbox.GetY((frc::GenericHID::JoystickHand)1);//check y value of left stick
	bool RStickY =  xbox.GetY((frc::GenericHID::JoystickHand)0);//check y value of right stick
	bool RBump=xbox.GetBumper((frc::GenericHID::JoystickHand)0);
	bool LBump=xbox.GetBumper((frc::GenericHID::JoystickHand)1);
	bool LTrigP = xbox.GetTriggerAxis((frc::GenericHID::JoystickHand)1);
	bool RTrigP = xbox.GetTriggerAxis((frc::GenericHID::JoystickHand)0);
	bool start = xbox.GetStartButton();
	bool back = xbox.GetBackButton();
	int
	WillsClass(int LServoPort, int RServoPort, int FRP, int BRP, int FLP, int BLP);
	WillsClass
		(int FRP, int BRP, int FLP, int BLP);
	frc::Servo LServo {LServoPort}; //constructor for left servo
	frc::Servo RServo {RServoPort}; // constructor for right servo
	frc::RobotDrive myRobot { FLP, BLP, FRP, BRP};//constructor for myRobot, paramaters are ports
	frc::XboxController xbox {0}; //constructor for xbox controller
	frc::Timer timer;
	frc::Timer autoTimer;
	frc::Timer teleTime;

	void drive(double Lval, double Rval){
		myRobot.TankDrive(Lval, Rval);	
	}
	void AutoDrive(double Lval, double Rval, double start, double fin){
		if(start < autoTimer.Get() && autoTimer.Get() < fin){
			myRobot.TankDrive(-Lval, -Rval);
		}
		else{
			myRobot.TankDrive(0.0,0.0);
		}
	}
	void AutoDrive(std::string dir, double start, double fin){
		if((start < autoTimer.Get() ) && (autoTimer.Get() < fin)){
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
		else{
			myRobot.TankDrive(0.0,0.0);
		}
	}
	void ramp(int Langle, int Rangle){
			RServo.SetAngle(Rangle);
			LServo.SetAngle(Langle);
	}

	void ramp(std::string pos){
		if(pos == "up"){
			RServo.SetAngle(130);
			LServo.SetAngle(170);
		}
		if(pos == "down"){
			RServo.SetAngle(250);
			LServo.SetAngle(60);
		}
	}
	void AutoRamp(std::string pos, double start, double fin){
		if((start < autoTimer.Get() ) && (autoTimer.Get() < fin)){
			if(pos == "up"){
				RServo.SetAngle(130);
				LServo.SetAngle(170);
				}
			if(pos == "down"){
				RServo.SetAngle(250);
				LServo.SetAngle(60);
				}
		}
	}

};
