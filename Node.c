#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#include "header.h"

int Server(char *my_ip_addr, char *other_ip_addr, int my_port);
int Client(int port_no, char *other_ip_addr);

int main(int argc, char **argv)
{
    

    //Setup Packet Struct
    struct Packet
    {
        char syn_syn[2];
        char dle_stx[2];
        char destination;
        char source;
        char text[80];
        char dle_etx[2];
    };
    
    struct Packet packet;
    
    char node_num;//This node number
    char *clientaddress = "";
    char buffer[88];
    int clientport;
    int serverport;
    char *clientport = "";
    char *serverport = "";
    char yesno;
    
    
  //Setup Node Number
    printf("Please enter this machine's node number: ");
    fgets(node_num, sizeof(node_num), stdin);
    printf("Node number set as %c", node_num);
    

 
    
      //TODO Initialize Client and Server (Check stdin for node numbers)
    printf("Please enter IP address to connect to: ");
    fgets(clientaddress, sizeof(clientaddress), stdin);

    printf("Please enter port number to connect to: ");
    scanf("%10d" ,&clientport);
    
    printf("Please enter server port number: ");
    scanf("%10d" ,&serverport);
    
    printf("Is this the first machine to be setup? (y/n)");
    fgets(yesno, sizeof(yesno), stdin);
    
    if(yesno == 'y')
    {
        //Server
        printf("Listening for connection from another machine...");
        //TODO Server connection
        printf("Connected! (Server Connection)");
        
        //Client
        printf("Connecting to IP address %s ...", clientaddress);
        //TODO Client connection
        printf("Connected!(Client connection)");
    }
    
    else
    {
        //Client
        printf("Connecting to IP address %s ...", clientaddress);
        //TODO Client connection
        printf("Connected!(Client connection)");
        
        //Server
        printf("Listening for connection from another machine...");
        //TODO Server connection
        printf("Connected! (Server Connection)");
    }
    
    
   
    
    //Select.c
    
    int n;
    fd_set rset;		/* declare an fd_set for read descriptors */
    
    for (;;) {	/* endless loop, if you want continuous operation */
        FD_ZERO(&rset);		/* clear all bits in rset */
		FD_SET(STDIN_FILENO, &rset);	/* set the standard input bit */
		FD_SET(sd, &rset);	/* set the socket descriptor bit */
 		n = select((sd>STDIN_FILENO? sd:STDIN_FILENO)+1, &rset, NULL, NULL, NULL);
		/* select blocks, and n is the number of ready descriptors */
		if ( (n == -1 ) && (errno == EINTR) ) /* interruption */
		    continue;
	  	if ((n== -1) {	/* error: you may handle it, if you want */
		 	/* code to handle errors */
	  	}
        //TODO Generate token if CNTRL-P (Hex 10) is typed on machine
   
        /* after this point, handle the ready descriptor(s) */
	  
	  	/* check for ready data from the keyboard */

	  	if (FD_ISSET(STDIN_FILENO, &rset)) {
	  	    /* read data from the standard input*/

		//TODO If stdin is ready, setup packets to send

                //TODO Check if machine has token, and token is empty
                //Read stdin, designate destination machine and add to packet
                printf("Please enter destination: ");
                fgets(packet.destination, sizeof(packet.destination), stdin);
                
                //Add source address to packet
                packet.source = node_num;
                //TODO Read stdin, add input text (up to 80 chars) and add to packet
                
                //Serialize packet for sending
                buffer[0] = packet.syn_syn[0];
                buffer[1] = packet.syn_syn[1];
                buffer[2] = packet.dle_stx[0];
                buffer[3] = packet.dle_stx[1];
                buffer[4] = packet.destination;
                buffer[5] = packet.source;
                for(i = 0; i < 80; i++)
                {
                    buffer[i + 6] = packet.text[i];
                }
                buffer[86] = packet.token[0];
                buffer[87] = packet.token[1];
                //TODO Send packet
			n--;
	  	}
	  	

            
        //TODO If server is ready, read packets
	  	if ((n > 0 ) && (FD_ISSET(sd, &rset)) ) 
	  	    /* socket is ready for reading */
	  	    
			/* read data from socket */
			if(rec = recv(sd, buffer, 88, 0) == -1) { 
                printf("ERROR on recv\n");
            }
            
            //TODO Store received message into packet struct
            //Unserialize packet
            packet.syn_syn[0] = buffer[0];
            packet.syn_syn[1] = buffer[1];
            packet.dle_stx[0] = buffer[2];
            packet.dle_stx[1] = buffer[3];
            packet.destination = buffer[4];
            packet.source = buffer[5];
            for(i = 0; i < 80; i++)
            {
                packet.text[0] = buffer[i + 6];
            }
            packet.token[0] = buffer[86];
            packet.token[1] = buffer[87];
             
			//TODO If packet is for this machine, display it
                //TODO Diplay message to terminal, preceded by sender's node address
                //TODO Remove message up to, but not including, DLE-ETX
                //TODO Change packet's DLE-ETX
                
            //TODO If packet is not for this machine, send it to next machine
	    }
        
                

}

int Server(char *my_ip_addr, char *other_ip_addr, int my_port)
{
	

	int s, fd, otherlength;
	FILE *fdopen(), *fp;
	char ch;
	struct sockaddr_in myaddr;
	struct sockaddr_in otheraddr;
	otheraddr.sin_addr.s_addr=inet_addr(other_ip_addr);


	if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) ReportError ("socket");
	myaddr.sin_addr.s_addr=inet_addr(my_ip_addr);
	myaddr.sin_family  = AF_INET;
	myaddr.sin_port = htons(my_port);
	bind(s, &myaddr, sizeof(myaddr));

	listen(s, 1);
	
	fd = accept(s, &otheraddr, sizeof(otherlength));

	fprintf(stdout, "Connected");

	return(fd);
}

int Client(int port_no, char *other_ip_addr)
{
	int s;
	int n;
	int code;
	FILE *fp;
	char ch;
	struct sockaddr_in otheraddr;
	
	otheraddr.sin_addr.s_addr=inet_addr(other_ip_addr);
	otheraddr.sin_family = AF_INET;
	otheraddr.sin_port = htons(port_no);
	
	s = socket(AF_INET, SOCK_STREAM, 0);

	n = connect(s, &otheraddr, sizeof(otheraddr));

	if ( n < 0)
		return(n);
	else
		return(s);
}


