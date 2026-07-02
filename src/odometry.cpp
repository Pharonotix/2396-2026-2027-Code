#include "main.h"
#include "pros/motors.h"

/*
                                                            
  .--~*teu.      .x~~"*Weu.                      .ue~~%u.   
 dF     988Nx   d8Nu.  9888c    .xn!~%x.       .d88   z88i  
d888b   `8888>  88888  98888   x888   888.    x888E  *8888  
m8888>  98888F  "***"  9888%  X8888   8888:  :8888E   ^""   
 "**"  x88888~       ..@8*"   88888   X8888  98888E.=tWc.   
      d8888*`     ````"8Weu   88888   88888> 98888N  '888N  
    z8**"`   :   ..    ?8888L `8888  :88888X 98888E   8888E 
  :?.....  ..F :@88N   '8888N   `"**~ 88888> '8888E   8888E 
 <""888888888~ *8888~  '8888F  .xx.   88888   ?888E   8888" 
 8:  "888888*  '*8"`   9888%  '8888>  8888~    "88&   888"  
 ""    "**"`     `~===*%"`     888"  :88%        ""==*""    
                                ^"===""                     
                                                            
                                                            
*/

// drive motors

    // Define motors (use default constructors for portability; gearing set on groups below)
    pros::Motor lf(0);     // Left Front
    pros::Motor lb(1);     // Left Back
    pros::Motor lh(2);     // Left 5.5W
    pros::Motor rf(3);     // Right Front
    pros::Motor rb(4);     // Right Back
    pros::Motor rh(5);     // Right 5.5W
        
    // Create the motor groups

    pros::MotorGroup leftMotors({lf.get_port(), lb.get_port(), lh.get_port()});     // Left side motors
    pros::MotorGroup rightMotors({rf.get_port(), rb.get_port(), rh.get_port()});    // Right side motors

//? Lemlib Odometry
Imu imu(15);
Rotation horizontalEnc(-11);
Rotation verticalEnc(16);

lemlib::TrackingWheel LeftDrivetrain(
    &horizontalEnc,
    lemlib::Omniwheel::NEW_325,
    -6.125,
    4.0/3.0
    );

lemlib::TrackingWheel RightDrivetrain(
    &verticalEnc,
    lemlib::Omniwheel::NEW_325,
    6.125,
    4.0/3.0
    );  

lemlib::Drivetrain drivetrain(
	&leftMotors,
	&rightMotors,
	12.25,
	lemlib::Omniwheel::NEW_325,
	450,
	2
);

lemlib::OdomSensors sensors(
	&LeftDrivetrain,
    &RightDrivetrain,
	nullptr,
    nullptr,
    &imu
);

lemlib::ControllerSettings lateralController(
4.25,                     // proportional gain (kP)
    0.1,                      // integral gain (kI)
    2.5,                      // derivative gain (kD)
    2,             // anti windup
    .05, // small error range, in inches
    300, // small error range timeout, in milliseconds
    .2, // large error range, in inches
    700, // large error range timeout, in milliseconds
    1.25// maximum acceleration (slew)
);
lemlib::ControllerSettings angularController(
    2,                      // proportional gain (kP)
    0.25,                      // integral gain (kI)
    5,                     // derivative gain (kD)
    3,           // anti windup
    1, // small error range, in inches
    400, // small error range timeout, in milliseconds
    2, // large error range, in inches
    700, // large error range timeout, in milliseconds
    5                   // maximum acceleration (slew)
);



lemlib::ExpoDriveCurve throttleCurve(
    3,
    10,
    1.019
);

lemlib::ExpoDriveCurve steerCurve(
    3,
    10,
    1.019
);

lemlib::Chassis chassis(drivetrain, lateralController,angularController,sensors,&throttleCurve,&steerCurve);
