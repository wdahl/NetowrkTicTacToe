#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <netdb.h>
   
void error(char* str){
    printf("Usage: %s -s [servername] -p [portnumber]\n", str);
    printf("Play Tic-Tac-Toe Game.\n");
    printf("User is x's; Computer is o'x\n\n");
    printf("Mandatory arguments.\n");
    printf(" -s\tservername to connect to.\n");
    printf(" -p\tport number to bind to.\n\n");
    printf("Protocol for Playing:\n");
    printf(" Spaces on board are labled from left-to-right and top-to-bottom from 1 to 9.\n");
    printf(" Enter the number of the space you would like to play on.\n");
    printf("  1 | 2 | 3 \n");
    printf(" ---|---|---\n");
    printf("  4 | 5 | 6 \n");
    printf(" ---|---|---\n");
    printf("  7 | 8 | 9 \n\n");
    printf("Exit status:\n");
    printf(" 0\tSucessful exection.\n");
    printf(" 1\tError occured.\n");
}

int main(int argc, char *argv[]) 
{
    if(strcmp(argv[1], "-h") == 0){
        error(argv[0]);
        return 1;
    }

    else if(argc != 5){
        error(argv[0]);
        return 1;
    }

    else if(strcmp(argv[1], "-s") != 0){
        error(argv[0]);
        return 1;
    }

    else if(strcmp(argv[3], "-p") != 0){
        error(argv[0]);
        return 1;
    }

    char* servername = argv[2];
    int port = atoi(argv[4]);


    struct sockaddr_in address; 
    int sock;
    char buffer[1024] = {0};
    char* space;
    struct hostent* hostname = gethostbyname(servername);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    { 
        printf("Socket creation error \n"); 
        return 1; 
    } 
   
    memset(&address, '0', sizeof(address)); 
   
    address.sin_family = AF_INET; 
    address.sin_port = htons(port);
    address.sin_addr = *(struct in_addr *)(hostname->h_addr);
   
    if (connect(sock, (struct sockaddr *)&address, sizeof(address)) < 0) 
    { 
        printf("Connection Failed \n"); 
        return 1; 
    } 

    printf("    |   |   \n");
    printf(" ---|---|---\n");
    printf("    |   |   \n");
    printf(" ---|---|---\n");
    printf("    |   |   \n");

    printf("Choose space to play.\n");
    fgets(space, 1024, stdin);
    send(sock , space, strlen(space) , 0);  
    read(sock , buffer, 1024);

    while(buffer[0] == '0'){
        printf("%s\n",buffer + 1); 
        printf("Choose space to play.\n");
        fgets(space, 1024, stdin);
        send(sock , space, strlen(space) , 0);  
        read(sock , buffer, 1024); 
    } 

    printf("%s\n",buffer + 1);

    if(buffer[0] == 't'){
        printf("It's a tie!\n");
    }

    else{
        printf("%c has won!\n", buffer[0]);
    }

    close(sock);

    return 0;
} 