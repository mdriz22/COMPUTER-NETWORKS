include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#define SERV_PORT 3322
int main(int argc,char **argv)
{
int i,j;
ssize_t n;
char filename[80],recvline[80];
struct sockaddr_in servaddr;
int sockfd;
sockfd=socket(AF_INET,SOCK_STREAM,0);
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(SERV_PORT);
inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
printf("Enter the file name");
scanf("%s",filename);
write(sockfd,filename,sizeof(filename));
printf("\n Data of the file from server:\n");
while(read(sockfd,recvline,80)!=0)
{
puts(recvline);
}
}

/*#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define SERV_PORT 3322

int main(int argc, char **argv) {
    char filename[80], recvline[80];
    struct sockaddr_in servaddr;
    int sockfd;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server_ip>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return 1;
    }

    printf("Enter the file name: ");
    fgets(filename, sizeof(filename), stdin);

    // Remove the trailing newline character from the input
    filename[strcspn(filename, "\n")] = '\0';

    write(sockfd, filename, sizeof(filename));
    printf("\nData of the file from server:\n");
    ssize_t n;
    while ((n = read(sockfd, recvline, sizeof(recvline))) > 0) {
        recvline[n] = '\0';  // Null-terminate the received data
        fputs(recvline, stdout);
    }
    if (n == -1) {
        perror("read");
    }

    close(sockfd);
    return 0;
}*/

