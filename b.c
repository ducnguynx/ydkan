#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


char buffer[4096];

int main () {
    struct sockaddr_in local;
    local.sin_family = AF_INET;
    inet_pton(AF_INET, "0.0.0.0",&local.sin_addr);
    local.sin_port = htons(6969);

    int sock = socket(AF_INET,SOCK_STREAM,0);
    bind(sock,(void*)&local,sizeof(local));
    listen(sock,128);

    int client = accept(sock,NULL,NULL);
    write(client,"220 Welcome \r\n",13);

    int bytesRead=0, res;
    for(;;) {
        res = read(client, buffer, 4096);
        if(res < 0)  {
            perror("read");
            // exit(1);
            break;
        }
        if(!res)
            break;
        bytesRead += res;
    }
    printf("%d\n", bytesRead);

}
