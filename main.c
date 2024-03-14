#include <kipr/wombat.h>

int main()
{
    printf("Hello World\n");
    //wait_for_light(0);
    shut_down_in(119);
     create3_connect();
    
    create3_drive_straight(-.87,-0.36);
     create3_rotate_degrees (90,35);
   
    create3_drive_straight(-.32,-0.21);
         create3_rotate_degrees (-110,24);

create3_drive_straight(-.6,-0.39);
    create3_rotate_degrees (80,28);
    
    create3_drive_straight(-.5,-0.39);
    create3_wait();

  create3_drive_straight(.37,0.39);
     create3_rotate_degrees (50,-35);
    return 0;
}
