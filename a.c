#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

char buffer[1000000];

int main () {
    memset(buffer,'a',sizeof(buffer));

    int sock = socket(AF_INET,SOCK_STREAM,0);
    
    struct sockaddr_in remote;
    remote.sin_family = AF_INET;
    inet_pton(AF_INET,"127.0.0.1",&remote.sin_addr);
    remote.sin_port = htons(6969);

    connect(sock,(void*)&remote,sizeof(remote));
    write(sock,buffer,sizeof(buffer));
    close(sock);

    return 0;
}
