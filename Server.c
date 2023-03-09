#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/sockets.h>
#include<string.h>

int main(int argc, char *argv[])
{
    char option[100],msg[100];
    int k;
    socklen_t len, sockListen;
    int sd = socket(AF_INET, SOCK_STREAM, 0)
    if (sd > 0 )
    {
        struct sockaddr_in server,client;
	    servAddr.sockaddr_in.sin_family = AF_INET; 
	    servAddr.sockaddr_in.sin_addr.s_addr = INADDR_ANY; 
	    servAddr.sockaddr_in.sin_port = htons(80);
        k = bind(sd,(struct sockaddr*)&servAddr, sizeof(servAddr));
        if (k == -1)
	    {
		    printf("Unable to Bind the Socket");  
		    exit(1);
	    }
        k = listen(sd,5);
        if(k == -1) //Checking if unable to listen
	    {
	    	printf("Unable to listen to Client");
	    	exit(1);
	    }
        while(1)
        {
            printf("waiting for the client");
            csd=accept(sd,(struct sockaddr*)NULL,NULL);
            printf("Got a client\n");
            if(fork()==0)
            child(sd);
            close(sd);
        }
    }
    else if (sd == -1)
    {
        printf("Socket Creation failed");
        exit(1);
    }
}

void child(int sd)
{
    char message[255];
    while(1)
    {
        fprintf(stderr, "Enter the message to the client\n");
        fgets(message, 254, stdin);
        //printf("\nThe length of the message is %d\n",strlen(message));
        write(sd, message, strlen(message)+1);
        if(!read(sd, message, 255))
            {
                close(sd);
                fprintf(stderr,"Client is dead, wait for a new client\n");
                exit(0);
            }
        fprintf(stderr, "Client sent back this message: %s\n", message);
    }
}