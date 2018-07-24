#include <kipr/botball.h>

int getStopCounter (int pom_position)
{
    switch ( pom_position) 
    {
        case 0: return 7500;
        default:
            return 0;
    }
}

void move_wallaby( int pom_position, int start_counter)
{
    int stopCounter = getStopCounter(pom_position);
    int curCounter =0;

    printf("i am at while loop start for pom position %d \n", pom_position);
    printf("Current start counter in move wallaby %d \n", start_counter);    
    printf("Current stop counter in move wallaby %d \n", stopCounter);

    while (digital (0) == 0 )
    {
        // printf("i am inside while loop start \n");
        if (analog (0) > 1600)
        {
            motor(0,-10);
            motor(2, 90);
        }
        else
        {
            motor(0, 90);
            motor(2,-10);
        }
        curCounter = get_motor_position_counter(0);
        //printf("Current counter in move wallaby while loop %d \n", curCounter);
        if (curCounter > (start_counter + stopCounter) ) 
        {
            printf("End stop counter in move wallaby while loop %d \n", curCounter);
            printf("i am out of while loop  counter\n");
            break;
        }                    
    } 
}

int main()
{
    printf("Hello World\n");

    int pos = 0;
    int  curCounter=0;
    int numCollections=6;

    clear_motor_position_counter(0);
  
    while (pos < numCollections)
    {
        move_wallaby(pos, curCounter);
        pos++;
        curCounter = get_motor_position_counter(0);
        //clear_motor_position_counter(0);
        //curCounter=0;
        printf("i am in pom move pos %d and counter value is %d \n", pos,curCounter);
    }
return 0;
}
