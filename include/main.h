/**
                                                            
 *   .--~*teu.      .x~~"*Weu.                      .ue~~%u.   
    dF     988Nx   d8Nu.  9888c    .xn!~%x.       .d88   z88i  
    d888b   `8888>  88888  98888   x888   888.    x888E  *8888  
    m8888>  98888F  "***"  9888%  X8888   8888:  :8888E   ^""   
    "**"  x88888~       ..@8*"   88888   X8888  98888E.=tWc.   
        d8888*`     ````"8Weu   88888   88888> 98888N  '888N  
        z8**"`   :   ..    ?8888L `8888  :88888X 98888E   8888E 
    :?.....  ..F :@88N   '8888N   `"**~ 88888> '8888E   8888E 
    <""888888888~ *8888~  '8888F  .xx.   88888   ?888E   8888" 
*    8:  "888888*  '*8"`   9888%  '8888>  8888~    "88&   888"  
*    ""    "**"`     `~===*%"`     888"  :88%        ""==*""    
*                                    ^"===""                     
                                                                
                                                            
**/

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

// Define enums here

#define PROS_USE_SIMPLE_NAMES


#define PROS_USE_LITERALS

#include "api.h"            // IWYU pragma: keep
#include "lvgl_compat.h"    // IWYU pragma: keep
#include "liblvgl/lvgl.h"   // IWYU pragma: keep

#ifdef __cplusplus
#include "lemlib/api.hpp"   // IWYU pragma: keep
#include "pros/screen.hpp"  // IWYU pragma: keep

using namespace pros;
#endif

/**
 * Prototypes for the competition control tasks are redefined here to ensure
 * that they can be called from user code (i.e. calling autonomous from a
 * button press in opcontrol() for testing purposes).
 */
#ifdef __cplusplus
extern "C" {
    #endif
        void autonomous(void);
        void initialize(void);
        void disabled(void);
        void competition_initialize(void);
        void opcontrol(void);
    #ifdef __cplusplus
    }
#endif // __cplusplus

#ifdef __cplusplus
    #include <iostream> // IWYU pragma: keep
    #include <fstream>  // IWYU pragma: keep
    #include <cstdio>   // IWYU pragma: keep
#endif  // __cplusplus

// Shared globals and types used across multiple translation units
    // Custom functions, called from multiple .cpp files
        void errors();
        void deleteAutonomous();
        void saveAutonomous();
        void init_lvgl_display();
        void update_display();
        void locationupdate();
        void errorcheck();

    // Forward declarations for shared globals (defined in src/main.cpp)
    #ifdef __cplusplus
        extern lemlib::Chassis chassis;
        extern Imu imu;
        
        extern Controller MasterController;

        extern Motor lf, lb, lh, rf, rb, rh;

        extern MotorGroup leftMotors, rightMotors;
        extern Rotation horizontalEnc, verticalEnc;
    #endif
#endif  // _PROS_MAIN_H_
