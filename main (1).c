#include <kipr/wombat.h>

int main()
{
    wait_for_light(0);
    shut_down_in(119);
    enable_servos();
    int close = 414;
    int open = 1010;
    int lw = 1;
    int rw = 0;
    int arm = 3;
    int up = 0;
    int down = -4650;
   
    printf("YIPPEEn");
    set_servo_position(0,open);
    mav(lw, 2000); // leave start box
    mav(rw, 2000);
    msleep(3000);
    
    mav(lw, 2000); //turn so we can grab pool noodle on wall
    mav(rw, -2000);
    msleep(300);
    
    cmpc(0);
    while (gmpc(0) > -3300)// lower arm down so we can grab the noodle
    {
        mav(arm, -500);
    }
    ao();
    set_servo_position(0,close); // grab the noodle
    msleep(2000);
    
    mav(lw, 2000); // back up a bit
    mav(rw, 2000);
    msleep(50);
           
    while (gmpc(3) < up)//this brings the arm back up
    {
        mav(arm, 500);
    }
    ao();
    
    mav(lw, 2000); // turn back we we can go to place noodle
    mav(rw, -2000);
    msleep(300);
    
    mav(lw, 2000); // move into postion to place it on a mid hight pole
    mav(rw, 2000);
    msleep(3000);
    
    mav(lw, -2000); // turn to position
    mav(rw, 2000);
    msleep(500);
    
    while (gmpc(0) > -2300)// we are still working on getting this one to work but this will place the noodle
    {
        mav(arm, -500);
    }
    ao();
    
    set_servo_position(0,open);// place noodle
    
    disable_servos();
    return 0;
}
