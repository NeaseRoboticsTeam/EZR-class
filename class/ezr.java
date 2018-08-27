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
	private boolean B = xbox.GetBButton();//check if B button is pressed
	private boolean X = xbox.GetXButton();//check if X button is pressed
	private boolean Y = xbox.GetYButton();//check if Y button is pressed
	private boolean Start = xbox.GetStartButton();//check if start button is pressed
	private boolean Back = xbox.GetBackButton();//check if back button is pressed
	private boolean RBump = xbox.GetBumper((frc::GenericHID::JoystickHand)0);//check if right bumper is pressed
	private boolean LBump = xbox.GetBumper((frc::GenericHID::JoystickHand)1);//check if left bumper is pressed
	private double LStickY =  xbox.GetY((frc::GenericHID::JoystickHand)1);//check y value of left stick
	private double RStickY =  xbox.GetY((frc::GenericHID::JoystickHand)0);//check y value of right stick
	private double LTrigP = xbox.GetTriggerAxis((frc::GenericHID::JoystickHand)1);//Get the trigger axis value of the controller left hand
	private double RTrigP = xbox.GetTriggerAxis((frc::GenericHID::JoystickHand)0);//Get the trigger axis value of the controller right hand
	private String rbump = "rbump";
	private String lbump = "lbump";
	private String start = "start";
	private String back = "back";
	private String a = "a";
	private String c = "b";
	private String x = "x";
	private String y = "y";
  
   	 public Willpower(int LServoPort, int RServoPort, int FRP, int BRP, int FLP, int BLP);//constructor for willpower
	 public Willpower(int LServoPort, int RServoPort, int LMotor, int RMotor);
	 public Willpower(int FRP, int BRP, int FLP, int BLP);//constructor for willpower **example of constructor overloading**
	 public Willpower(int LMotor, int RMotor);
   	 Servo LServo = new Servo(LServoPort); //constructor for left servo
	 Servo RServo = new Servo(RServoPort); // constructor for right servo
	 RobotDrive myRobot = new RobotDrive( FLP, BLP, FRP, BRP);
	 RobotDrive myRobot = new RobotDrive( LMotor, RMotor); //constructor for myRobot, paramaters are ports
	 XboxController xbox = new XboxController(0); //constructor for xbox controller
	 Timer timer = new Timer;
	 Timer autoTimer = new Timer;
	 Timer teleTime = new Timer;
  
}
