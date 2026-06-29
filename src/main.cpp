#include "main.h"
#include "UI/ui.h"

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

Controller MasterController(E_CONTROLLER_MASTER);


void initialize() {
  chassis.calibrate();
  
  // Initialize LVGL and connect to robot screen
  init_lvgl_display();
  ui_init();

  //Multitasks
  pros::Task updateLocationTask(locationupdate, "Location Update");
  pros::Task errorTask(errorcheck, "Error Checker");
}
void disabled() {}
void competition_initialize() {}
void autonomous() {}
void opcontrol() {}