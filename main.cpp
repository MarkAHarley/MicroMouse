#include "mbed.h"

PwmOut motor1speed(p23);
PwmOut motor2speed(p24);

DigitalOut motor1forward(p21);
DigitalOut motor1back(p22);

DigitalOut motor2forward(p18);
DigitalOut motor2back(p17);


// MOTOR 1 = LEFT
// MOTOR 2 = RIGHT

// 0 = Forward
// 1 = Backward
// 2 = Turn Left
// 3 = Turn Right
// 4 = Fast Stop

void P_Control(float dist1,float dist2,float k){
        float difference = dist1-dist2;
        if (difference < 0){
                motor1speed = motor1speed + k*(motor1speed*difference*(-1));
            }
        else{
                motor2speed = motor2speed + k*(motor2speed*difference);
            }


static void Control(int instructions[2])
{
    switch(instructions[0])
    {
        //FORWARD
        case 0:
            motor1forward = 1;
            motor2forward = 1;
            wait(instructions[1]);
            motor1forward = 0;
            motor2forward = 0;
            break;
            
        //BACK    
        case 1:
            motor1back = 1;
            motor2back = 1;
            wait(instructions[1]);
            motor1back = 0;
            motor2back = 0;
            break;
         
        //LEFT    
        case 2:
            motor1back = 1;
            motor2forward = 1;
            wait(instructions[1]);
            motor1back = 0;
            motor2forward = 0;
            break;
        
        //RIGHT    
        case 3:
            motor1forward = 1;
            motor2back = 1;
            wait(instructions[1]);
            motor1forward = 0;
            motor2back = 0;
            break;
        
        //FAST STOP
        case 4:
            motor1forward = 1;
            motor1back = 1;
            motor2forward = 1;
            motor2back =1;
            wait(instructions[1]);
            motor1forward = 0;
            motor1back = 0;
            motor2forward = 0;
            motor2back =0;    
            break;    
            
    }
}


int main()
{
    float motorfrequency = 2000;
    float dc = 0.50f;
    
    motor1speed.period(1/motorfrequency);
    motor2speed.period(1/motorfrequency);
    
    motor1speed = dc;
    motor2speed = dc;
    
    //Placeholder
    //int x = 0;
    //int y = 5;
    int x;
    int y;
    
    
    while(1)
    {
        x = rand() % 5;
        y = rand() % 10+1;
        int ins[2] = {x,y};
        Control(ins);
    }
    
}
