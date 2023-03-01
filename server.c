#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<windows.h>
#include<winsock2.h>
#include<sys/types.h>
#include<wininet.h>

int sock, client;

int main(){
    char buffer[1024];
    char response[18384];
    struct sockaddr_in server_address, client_address;
    int i = 0;
    int optval = 1;
    socklen_t client_length;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(setsockopt(sock, SOL_SOCKET, SOL_REUSEADDR, &optval, sizeof(optval)) < 0){
        printf("уккщк ыуеештп еру ыщслук\n");
        return 1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("192.168.0.2");
    server_address.sin_port = htons(49343);

    bind(sock, (struct sockaddr *) &server_address, sizeof(server_address));

    listen(sock, 400);
    client_length = sizeof(client_address);
    client_socket = accept(sock, (structure sockaddr *) &client_address, &client_length);
}