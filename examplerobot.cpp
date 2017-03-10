#include <Riff.h>
int FRP = 0; //initialize and declare FRP as an integer with a value 0
int FLP = 2; //initialize and declare FLP as an integer with a value 2
int BRP = 1; //initialize and declare BRP as an integer with a value 1
int BLP = 3; //initialize and declare BLP as an integer with a value 3
int LServoPort = 4; //left servo port
int RServoPort = 5; //right servo port
std::string= ;
std::string = ;
std::string = ;
std::string = ;
std::string = ;
std::string = ;
std::string = ;
std::string = ;

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
		}
    
	Riff robo{LServoPort,RServoPort,FRP,BRP,FLP,BLP};
	frc::LiveWindow* lw = LiveWindow::GetInstance();
	frc::Spark winch {6};
	frc::Timer autoTimer;
	frc::Timer teleTime;
	frc::Timer timer;
  
	void AutonomousInit() override {
		autoSelected = chooser.GetSelected();
		std::cout << "Auto selected: " << autoSelected << std::endl;
		timer.Reset(); //Set timer to 0
		timer.Start(); //Start timer
		autoTimer.Reset();
		robo.ramp("back");
	}

	void AutonomousPeriodic() {
		if (autoSelected == autoNameMid) {
			autoTimer.Start();
			robo.AutoDrive(-.5,-.545,.1,4.4); //mid 4.4, l/r 10
			robo.AutoRamp("up", 4.4, 6);
		}
	}
	void TeleopInit() {
			robo.ramp("down");
	}
	void TeleopPeriodic() {
		robo.buton(
	void TestPeriodic() {
		lw->Run();
	}
};
START_ROBOT_CLASS(Robot)
