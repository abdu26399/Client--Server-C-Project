#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/sockets.h>
#include<string.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    char option[100],message[100];
    int status;
    int sd = socket(AF_INET, SOCK_STREAM, 0)
    if (sd > 0 )
    {
        struct sockaddr_in servAddr;
	    servAddr.sin_family = AF_INET; 
	    servAddr.sin_addr.s_addr = INADDR_ANY; 
	    servAddr.sin_port = htons(80);
        int con = connect(sd,struct sockaddr *)&servAddr, sizeof(servAddr));
        if (con > 0)
        {
            while(1)
            {
                printf("Enter the command");
                // scanf("%s",option);
                // if (strcmp(option,"quit")==0)
                // {
                //     printf("Quitting");
                //     close(sd);
                //     exit(1);
                // }
                if(read(sd, message, 255)<0)
                {
                    fprintf(stderr, "read() error\n");
                    exit(3);
                }
                fprintf(stderr, "server's message: %s\n",message);
                fprintf(stderr, "Type quit to quit or a message for the server\n");
                fgets(message, 254, stdin);
                if(message[0] == 'quit' || 'QUIT')
                    {
                        close(sd);
                        exit(0);
                    }
                write(ssd, message, strlen(message)+1); 
            }
        }
        else if ( con == -1)
        {
            printf("Connection to socket failed");
            exit(1);
        }
    }
    else if (sd == -1)
    {
        printf("Socket Creation failed");
        exit(1);
    }
}