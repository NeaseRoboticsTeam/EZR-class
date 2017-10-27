import java.util.*;
import java.lang.*;
import java.io.*;
import edu.wpi.first.wpilibj.IterativeRobot;
import edu.wpi.first.wpilibj.Joystick;
import edu.wpi.first.wpilibj.RobotDrive;
import edu.wpi.first.wpilibj.livewindow.LiveWindow;
import edu.wpi.first.wpilibj.Spark;
import edu.wpi.first.wpilibj.Servo;
import edu.wpi.first.wpilibj.IterativeRobot;
import edu.wpi.first.wpilibj.Timer;
import edu.wpi.first.wpilibj.CameraServer;
import edu.wpi.first.wpilibj.smartdashboard.SmartDashboard;

public class Willpower{
  private boolean A = xbox.GetAButton();//check if A button is pressed
	boolean B = xbox.GetBButton();//check if B button is pressed
	boolean X = xbox.GetXButton();//check if X button is pressed
	boolean Y = xbox.GetYButton();//check if Y button is pressed
	boolean Start = xbox.GetStartButton();//check if start button is pressed
	boolean Back = xbox.GetBackButton();//check if back button is pressed
	boolean RBump = xbox.GetBumper((frc::GenericHID::JoystickHand)0);//check if right bumper is pressed
	boolean LBump = xbox.GetBumper((frc::GenericHID::JoystickHand)1);//check if left bumper is pressed
	double LStickY =  xbox.GetY((frc::GenericHID::JoystickHand)1);//check y value of left stick
	double RStickY =  xbox.GetY((frc::GenericHID::JoystickHand)0);//check y value of right stick
	double LTrigP = xbox.GetTriggerAxis((frc::GenericHID::JoystickHand)1);//Get the trigger axis value of the controller left hand
	double RTrigP = xbox.GetTriggerAxis((frc::GenericHID::JoystickHand)0);//Get the trigger axis value of the controller right hand
	String rbump = "rbump";
	String lbump = "lbump";
	String start = "start";
	String back = "back";
	String a = "a";
	String c = "b";
	String x = "x";
	String y = "y";
  
   	 Willpower(int LServoPort, int RServoPort, int FRP, int BRP, int FLP, int BLP);//constructor for willpower
	 Willpower(int LServoPort, int RServoPort, int LMotor, int RMotor);
	 Willpower(int FRP, int BRP, int FLP, int BLP);//constructor for willpower **example of constructor overloading**
	 Willpower(int LMotor, int RMotor);
   	 Servo LServo = new Servo(LServoPort); //constructor for left servo
	 Servo RServo = new Servo(RServoPort); // constructor for right servo
	 RobotDrive myRobot = new RobotDrive( FLP, BLP, FRP, BRP);
	 RobotDrive myRobot = new RobotDrive( LMotor, RMotor); //constructor for myRobot, paramaters are ports
	 XboxController xbox = new XboxController(0); //constructor for xbox controller
	 Timer timer = new Timer;
	 Timer autoTimer = new Timer;
	 Timer teleTime = new Timer;
  
}
