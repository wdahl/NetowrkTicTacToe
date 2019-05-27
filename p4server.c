#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 

struct Board{
    char space_1;
    char space_2;
    char space_3;
    char space_4;
    char space_5;
    char space_6;
    char space_7;
    char space_8;
    char space_9;
} board = {' ', ' ', ' ', ' ', ' ', ' ',  ' ', ' ', ' '};

void error(char* str){
    printf("Usage: %s -p [portnumber]\n", str);
    printf("Play Tic-Tac-Toe Game.\n\n");
    printf("Mandatory arguments.\n");
    printf(" -p\t\tport number to bind to.\n\n");
    printf("Exit status:\n");
    printf(" 0\tSucessful exection.\n");
    printf(" 1\tError occured.\n");
}

int is_full(){
    if(board.space_1 != ' '){
        if(board.space_2 != ' '){
            if(board.space_3 != ' '){
                if(board.space_4 != ' '){
                    if(board.space_5 != ' '){
                        if(board.space_6 != ' '){
                            if(board.space_7 != ' '){
                                if(board.space_8 != ' '){
                                    if(board.space_9 != ' '){
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

int is_valid(char* buf){
    char space = buf[0];
    switch(space){
        case '1':
            if(board.space_1 == ' '){
                board.space_1 = 'x';
                return 1;
            }
            else{
                return 0;
            }
            break;

        case '2':
           if(board.space_2 == ' '){
               board.space_2 = 'x';
               return 1;
           }
           else{
               return 0;
           }
           break;

        case '3':
            if(board.space_3 == ' '){
                board.space_3 = 'x';
                return 1;
            }
            else{
                return 0;
            }
            break;

        case '4':
            if(board.space_4 == ' '){
                board.space_4 = 'x';
                return 1;
            }
            else{
                return 0;
            }
            break;

        case '5':
           if(board.space_5 == ' '){
               board.space_5 = 'x';
               return 1;
           }
           else{
               return 0;
           }
           break;

        case '6':
            if(board.space_6 == ' '){
                board.space_6 = 'x';
                return 1;
            }
            else{
                return 0;
            }
            break;

        case '7':
            if(board.space_7 == ' '){
                board.space_7 = 'x';
                return 1;
            }
            else{
                return 0;
            }
            break;

        case '8':
           if(board.space_8 == ' '){
               board.space_8 = 'x';
               return 1;
           }
           else{
               return 0;
           }
           break;

        case '9':
            if(board.space_9 == ' '){
                board.space_9 = 'x';
                return 1;
            }
            else{
                return 0;
            }
            break;
        
        default:
            return 0;
    }
}

char winning(){
    if(board.space_1 != ' '){
        if(board.space_1 == board.space_2 && board.space_1 == board.space_3){
            return board.space_1;
        }
        else if(board.space_1 == board.space_5 && board.space_1 == board.space_9){
            return board.space_1;
        }
        else if(board.space_1 == board.space_4 && board.space_1 == board.space_7){
            return board.space_1;
        }
    }

    if(board.space_2 != ' '){
        if(board.space_2 == board.space_5 && board.space_2 == board.space_8){
            return board.space_2;
        }  
    }

    if(board.space_3 != ' '){
        if(board.space_3 == board.space_6 && board.space_3 == board.space_9){
            return board.space_3;
        }
        else if(board.space_3 == board.space_5 && board.space_3 == board.space_7){
            return board.space_3;
        }
    }

    if(board.space_4 != ' '){
        if(board.space_4 == board.space_5 && board.space_4 == board.space_6){
            return board.space_4;
        }
    }

    if(board.space_7 != ' '){
        if(board.space_7 == board.space_8 && board.space_7 == board.space_9){
            return board.space_7;
        }
    }

    if(is_full()){
        return 't';
    }

    return '0';
}

void play_space(){
    while(1){
        int n = (rand() % 9) + 1;
        switch(n){
            case 1:
                if(board.space_1 == ' '){
                    board.space_1 = 'o';
                    return;
                }
                break;

            case 2:
                if(board.space_2 == ' '){
                    board.space_2 = 'o';
                    return;
                }
                break;

            case 3:
                if(board.space_3 == ' '){
                    board.space_3 = 'o';
                    return;
                }
                break;

            case 4:
                if(board.space_4 == ' '){
                    board.space_4 = 'o';
                    return;
                }
                break;

            case 5:
                if(board.space_5 == ' '){
                    board.space_5 = 'o';
                    return;
                }
                break;

            case 6:
                if(board.space_6 == ' '){
                    board.space_6 = 'o';
                    return;
                }
                break;

            case 7:
                if(board.space_7 == ' '){
                    board.space_7 = 'o';
                    return;
                }
                break;

            case 8:
                if(board.space_8 == ' '){
                    board.space_8 = 'o';
                    return;
                }
                break;

            case 9:
                if(board.space_9 == ' '){
                    board.space_9 = 'o';
                    return;
                }
                break;
        }
    }
}

char* board_to_string(){
    char *top = malloc(1024);
    char mid[1024];
    char bot[1024];
    char line[1024] = " ---|---|---\n";

    sprintf(top, "  %c | %c | %c \n", board.space_1, board.space_2, board.space_3);
    sprintf(mid, "  %c | %c | %c \n", board.space_4, board.space_5, board.space_6);
    sprintf(bot, "  %c | %c | %c \n", board.space_7, board.space_8, board.space_9);
    
    strcat(top, line);
    strcat(top, mid);
    strcat(top, line);
    strcat(top, bot);
    
    return top;
}

void new_board(){
    board.space_1 = ' ';
    board.space_2 = ' ';
    board.space_3 = ' ';
    board.space_4 = ' ';
    board.space_5 = ' ';
    board.space_6 = ' ';
    board.space_7 = ' ';
    board.space_8 = ' ';
    board.space_9 = ' ';
}

int main(int argc, char *argv[]) 
{ 
    if(strcmp(argv[1], "-h") == 0){
        error(argv[0]);
        return 1;
    }

    else if(argc != 3){
        error(argv[0]);
        return 1;
    }

    else if(strcmp(argv[1], "-p") != 0){
        error(argv[0]);
        return 1;
    }

    int port = atoi(argv[2]);

    int sock, new_sock;
    int opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    char* board_packet = malloc(1024);
        
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        printf("socket failed\n"); 
        return 1; 
    } 

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    { 
        printf("setting socket option failed\n"); 
        return 1;
    } 

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(port); 
       
    if (bind(sock, (struct sockaddr *)&address,  addrlen)<0) 
    { 
        printf("bind failed\n"); 
        return 1;
    } 

    
    if (listen(sock, 3) < 0) 
    { 
        printf("listen failed\n"); 
        return 1; 
    } 

    while(1){
        if ((new_sock = accept(sock, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) 
        { 
            printf("accept failed\n"); 
            return 1; 
        }

        char winner[2];

        while(read(new_sock, buffer, 1024)){
            if(is_valid(buffer)){
                if(winning() == '0'){
                    play_space();
                    winner[0] = winning();
                    winner[1] = '\0';
                    strcpy(board_packet, winner);
                }
                else{
                    winner[0] = winning();
                    winner[1] = '\0';
                    strcpy(board_packet, winner);
                }
                strcat(board_packet, board_to_string());
            }
            else{
                strcpy(board_packet, "0Invalid space inputed\n");
                strcat(board_packet, board_to_string());
            }

            send(new_sock, board_packet, strlen(board_packet), 0);  
        }

        new_board();
        close(new_sock);
    }

    close(sock);
    return 0; 
} 