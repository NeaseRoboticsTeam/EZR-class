#include <TotalTankIncludes.h> //one big include file
bool A; //declare A for a button
bool B; //declare B for B button
bool X; //declare X for X button
bool Y; //declare Y for Y button
bool start; //xbox start button
bool back; //xbox Back button
bool RBump;
bool LBump;
double LTrigP;
double RTrigP;
double RTread; //declare RTread as a double
static double LTread; //declare LTread as a double
double RStickY; // declare RStickY as a double
double LStickY; // declare LStickY as a double
int FRP = 0; //initialize and declare FRP as an integer with a value 0
int FLP = 2; //initialize and declare FLP as an integer with a value 2
int BRP = 1; //initialize and declare BRP as an integer with a value 1
int BLP = 3; //initialize and declare BLP as an integer with a value 3
int LServoPort = 4; //left servo port
int RServoPort = 5; //right servo port
const std::string autoNameMid = "Middle Auto";
const std::string autoNameLeft= "Left Auto";
const std::string autoNameRight = "Right Auto";
frc::SendableChooser<std::string> chooser;
std::string autoSelected;
class Robot: public frc::IterativeRobot{
public:
	void RobotInit() {
		CameraServer::GetInstance()->StartAutomaticCapture();
	    chooser.AddDefault(autoNameMid, autoNameMid);
		chooser.AddObject(autoNameLeft, autoNameLeft);
		chooser.AddObject(autoNameRight, autoNameRight);
		frc::SmartDashboard::PutData("Auto Modes", &chooser);
		timer.Start();
		myRobot.SetExpiration(10000);
	}
public:
	frc::LiveWindow* lw = LiveWindow::GetInstance();
	frc::RobotDrive myRobot { FLP, BLP, FRP, BRP};//constructor for myRobot, paramaters are ports
	frc::Servo LServo {LServoPort}; //constructor for left servo
	frc::Servo RServo {RServoPort}; // constructor for right servo
	frc::XboxController WExbox{0}; //constructor for xbox controller
	frc::Spark winch {6};
	frc::Timer timer;
	frc::Timer autoTimer;
	frc::Timer teleTime;

	void AutonomousInit() override {
		autoSelected = chooser.GetSelected();
		std::cout << "Auto selected: " << autoSelected << std::endl;
		timer.Reset(); //Set timer to 0
		timer.Start(); //Start timer
		autoTimer.Reset();
		ramp("back");
	}
	void AutoDrive(double Lval, double Rval, double start, double fin){
		//double end = autoTimer.Get() + fin;
		if(start < autoTimer.Get() && autoTimer.Get() < fin){
			myRobot.TankDrive(-Lval, -Rval);
		}
		else{
			myRobot.TankDrive(0.0,0.0);
		}
	}
	void AutoDrive(std::string dir, double start, double fin){
		//double end = autoTimer.Get() + fin;
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

	void ramp(std::string pos){
		if(pos == "up"){
			RServo.SetAngle(130); //125
			LServo.SetAngle(170); //175
		}
		if(pos == "down"){
			RServo.SetAngle(250);
			LServo.SetAngle(60);
		}
	}
	void AutoRamp(std::string pos, double start, double fin){
		//double end = autoTimer.Get() + fin;
		if((start < autoTimer.Get() ) && (autoTimer.Get() < fin)){
			if(pos == "up"){
				RServo.SetAngle(130); //125
				LServo.SetAngle(170); //175
				}
			if(pos == "down"){
				RServo.SetAngle(250);
				LServo.SetAngle(60);
				}
		}
	}
	void AutonomousPeriodic() {
		if (autoSelected == autoNameMid) {
			autoTimer.Start();
			AutoDrive(-.5,-.545,.1,4.4); //mid 4.4, l/r 10
			AutoRamp("up", 4.4, 6);
			//AutoRamp("down",6,7);

		}

	}
	void TeleopInit() {
			ramp("down");
	}
	void TeleopPeriodic()
	{
		RBump=WExbox.GetBumper((frc::GenericHID::JoystickHand)0);
		LBump=WExbox.GetBumper((frc::GenericHID::JoystickHand)1);
		LTrigP = WExbox.GetTriggerAxis((frc::GenericHID::JoystickHand)1);
		RTrigP = WExbox.GetTriggerAxis((frc::GenericHID::JoystickHand)0);
		A = WExbox.GetAButton();//check if A button is pressed
		B = WExbox.GetBButton();//check if B button is pressed
		X = WExbox.GetXButton();//check if X button is pressed
		Y = WExbox.GetYButton();//check if Y button is pressed
		LStickY =  WExbox.GetY((frc::GenericHID::JoystickHand)1);//check y value of left stick
		RStickY =  WExbox.GetY((frc::GenericHID::JoystickHand)0);//check y value of right stick
	//	RTread = (pow(LStickY, 3)+(0.3*LStickY))*.7; //multiply by 3, cube, assign to LTread
		LTread = (pow(RStickY, 3)+(0.3*RStickY))*.7; //multiply by 3, cube, assign to RTread
		myRobot.TankDrive(-LTread, -LTread); //use TankDrive function
		start = WExbox.GetStartButton();
		back = WExbox.GetBackButton();
		if(LTrigP > 0 && RTrigP > 0){
			myRobot.TankDrive(1,1);
		}
		if(LTread>0){
			LTread+=.07;
		}
		if(LTread<0){
			LTread-=.07;
		}
		if(start != 0){
			winch.Set(-.8);
		}
		if(back != 0){
			winch.Set(0);
		}
		if(A != 0){
			ramp("up");
		}
		if(A == 0){
			ramp("down");
		}
		if(B != 0){
		LTread = LTread*.5;
		}
		if(X != 0){
			myRobot.TankDrive(-.65, -.61);
		}
		if(Y != 0){
			myRobot.TankDrive(.6, .68);
		}
		if(LBump != 0){
			myRobot.TankDrive(.6,-.6);
		}
		if(RBump != 0){
			myRobot.TankDrive(-.6,.6);
		}
	}
	void TestPeriodic() {
		lw->Run();
	}
};
START_ROBOT_CLASS(Robot)
