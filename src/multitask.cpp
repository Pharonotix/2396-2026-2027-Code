#include "main.h"


void errorcheck(){
  while(true){
      errors();
  }
}


void locationupdate(){    
  while (true) {
        // Get the current pose from the chassis
        auto pose = chassis.getPose();
        
        // Update the location display with the current pose
        update_display();
        
        // Delay for a short period to avoid overwhelming the display
        pros::delay(100); // Update every 100 ms
    }
  }