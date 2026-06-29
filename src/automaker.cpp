#include "main.h"

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

void DeleteAutonomous() {
    std::fstream file("/usd/auto.txt", std::ios::trunc); // Delete the file

    if (!file.is_open()) {
        printf("Failed to open file — check the SD card.\n");
        return;
    }
    file.close();
}

void SaveAutonomous() {
    std::fstream file("/usd/auto.txt", std::ios::out); // Open the file for writing

    bool end = false;


    if (!file.is_open()) {
        printf("Failed to open file — check the SD card.\n");
        return;
    }

    while (bool end = false) {
        if (MasterController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            end = true;
        }

        if (MasterController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        std::fstream file("/usd/auto.txt", std::ios::app); // Open the file for writing
        printf("chassis.moveToPose(%f, %f, %f, 5000, {.earlyExitRange = 1.5}, false);" , chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        }
        
        if (MasterController.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
        std::fstream file("/usd/auto.txt", std::ios::app); // Open the file for writing
        printf("chassis.moveToPose(%f, %f, %f, 5000);" , chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);
        }

    file.close();       // Close the file
}
}