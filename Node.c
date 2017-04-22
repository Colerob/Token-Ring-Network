#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#include "header.h"

int Server(char *my_ip_addr, char *other_ip_addr, int my_port);
int Client(int port_no, char *other_ip_addr);

int main(int argc, char **argv)
{
    

    //Setup Packet Struct
    struct packet
    {
        unsigned short syn_syn;
        unsigned short dle_stx;
        unsigned char destination;
        unsigned char source;
        char text[80];
        unsigned short dle_etx;
    }
    
    char node_num;//This node number
    char *clientaddress = "";
<<<<<<< HEAD
    char *clientport = "";
    char *serverport = "";
=======
    int clientport;
    int serverport;
>>>>>>> a729b8155604a8e1e94e9b9a6497a812cc0360f3
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
    
<<<<<<< HEAD
    
            
    printf("Connecting to IP address %s ...", clientaddress);
    //TODO Client connection
    printf("Connected!(Client connection)");
    
    

 
    
     printf("Listening for connection from another machine...");
    //TODO Server connection
    printf("Connected! (Server Connection)");
=======
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
    

    

>>>>>>> a729b8155604a8e1e94e9b9a6497a812cc0360f3
    
   
    
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
                //TODO Read stdin, designate destination machine and add to packet
                //TODO Add source address to packet
                //TODO Read stdin, add input text (up to 80 chars) and add to packet
			n--;
	  	}
	  	

            
        //TODO If server is ready, read packets
	  	if ((n > 0 ) && (FD_ISSET(sd, &rset)) ) 
	  	    /* socket is ready for reading */
	  	    
			/* read data from socket */
			
			//TODO If packet is for this machine, display it
                //TODO Diplay message to terminal, preceded by sender's node address
                //TODO Remove message up to, but not including, DLE-ETX
                //TODO Change packet's DLE-ETX
                
            //TODO If packet is not for this machine, send it to next machine
	    }
        
<<<<<<< HEAD
                

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
=======
>>>>>>> a729b8155604a8e1e94e9b9a6497a812cc0360f3
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


