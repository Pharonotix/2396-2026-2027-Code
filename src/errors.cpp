#include "main.h"

/*
*                                                             
*     .--~*teu.      .x~~"*Weu.                      .ue~~%u.   
*    dF     988Nx   d8Nu.  9888c    .xn!~%x.       .d88   z88i  
*   *d888b   `8888>  88888  98888   x888   888.    x888E  *8888  
*   m8888>  98888F  "***"  9888%  X8888   8888:  :8888E   ^""   
*   "**"  x88888~       ..@8*"   88888   X8888  98888E.=tWc.   
*        d8888*`     ````"8Weu   88888   88888> 98888N  '888N  
*      z8**"`   :   ..    ?8888L `8888  :88888X 98888E   8888E 
*   :?.....  ..F :@88N   '8888N   `"**~ 88888> '8888E   8888E 
*  <""888888888~ *8888~  '8888F  .xx.   88888   ?888E   8888" 
*  8:  "888888*  '*8"`   9888%  '8888>  8888~    "88&   888"  
*  ""    "**"`     `~===*%"`     888"  :88%        ""==*""    
*                                ^"===""                     
*/



bool runerror; // Global variable to track if an error has occurred

struct MotorCheck {
    pros::Motor& motor;
    std::string name;
    int disconnectFailCount = 0;
};

MotorCheck motors[] = {
    {lf, "Left front"}, {lb, "Left back"}, {lh, "Left 5.5w"},
    {rf, "Right front"}, {rb, "Right back"}, {rh, "Right 5.5w"}
};

const int DISCONNECT_THRESHOLD = 3; // consecutive bad reads required before flagging

void errors() {
    if (runerror == true) {

    std::string allErrors = "";

    for (MotorCheck& m : motors) {
        errno = 0;
        double temp = m.motor.get_temperature();
        std::uint32_t faults = m.motor.get_faults();

        if (temp == PROS_ERR_F && errno == ENODEV) {
            m.disconnectFailCount++;
            if (m.disconnectFailCount >= DISCONNECT_THRESHOLD) {
                allErrors += m.name + " disconnected Port: " + std::to_string(m.motor.get_port()) + "\n";
                runerror = true;
            }
        } else {
            m.disconnectFailCount = 0; // good read resets the counter
        }

        if (faults & E_MOTOR_FAULT_MOTOR_OVER_TEMP){
            allErrors += m.name + " is over temperature Port: " + std::to_string(m.motor.get_port()) + "\n";
            runerror = true;
        }
        if (faults & E_MOTOR_FAULT_OVER_CURRENT){
            allErrors += m.name + " is over current Port: " + std::to_string(m.motor.get_port()) + "\n";
            runerror = true;
        }
        if (faults & E_MOTOR_FAULT_DRIVER_FAULT){
            allErrors += m.name + " has an H-Bridge Error: " + std::to_string(m.motor.get_port()) + "\n";
            runerror = true;
        }
        if (faults & E_MOTOR_FAULT_DRV_OVER_CURRENT){
            allErrors += m.name + " has an H-Bridge Over Current Error: " + std::to_string(m.motor.get_port()) + "\n";
            runerror = true;
        }

    }

    if (!allErrors.empty()) {
        // LVGL function
    }
}
delay(250);
}