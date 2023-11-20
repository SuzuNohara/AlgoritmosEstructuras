#include<stdio.h>
#include<stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
    int udp_socket, lbind, tam;
    unsigned char msj[100] = "Hola red XD";
    struct sockaddr_in local, remota;
    udp_socket = socket(PF_INET, SOCK_DGRAM, 0);
    if(udp_socket == -1){
        perror("Error al crear el socket\n");
        exit(-1);
    }else{
        printf("Socket creado exitosamente\n");
        local.sin_family = AF_INET;
        local.sin_port = htons(0);
        local.sin_addr.s_addr = INADDR_ANY;
        lbind = bind(udp_socket, (struct sockaddr *) &local, sizeof(local));
        if(lbind == -1){
            perror("Error en el bind\n");
            exit(-2);
        }else{
            printf("Bind creado exitosamente\n");
            remota.sin_family = AF_INET;
            remota.sin_port = htons(53);
            remota.sin_addr.s_addr = inet_addr("8.8.8.8");
            tam = sendTo(udp_socket, msj, 20, 0, (struct sockaddr *) &remota, sizeof(remota));
            if(tam == -1){
                perror("Error al enviar\n");
                exit(-3);
            }else{
                printf("Mensaje enviado\n");
            }
        }
    }
    printf("Cerrando socket\n");
    close(udp_socket);
    return 0;
}
