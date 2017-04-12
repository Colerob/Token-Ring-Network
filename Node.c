#include <stdlib.h>
#include <stdio.h>

#include "header.h"

int main(int argc, char **argv)
{
    //TODO Setup Packet Struct
    
    //TODO Setup Node Number
    
    //TODO Initialize Client and Server (Check stdin for node numbers)

    //TODO Select.c
    
        //TODO Generate token if CNTRL-P (Hex 10) is typed on machine
        
        //TODO If stdin is ready, setup packets to send
            //TODO Read stdin, designate destination machine and add to packet
            //TODO Add source address to packet
            //TODO Read stdin, add input text (up to 80 chars) and add to packet
            //TODO Change DLE-ETX
            
        //TODO If server is ready, read packets
        
            //TODO If packet is for this machine, read it
                //TODO Diplay message to terminal, preceded by sender's node address
                //TODO Remove message up to, but not including, DLE-ETX
                //TODO Change packet's DLE-ETX
                
            //TODO If packet is not for this machine, send it to next machine
            

}
