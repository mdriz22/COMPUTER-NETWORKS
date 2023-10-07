#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<strings.h>
#define SERV_TCP_PORT 3771
int main(int argc,char*argv[])
{
int sockfd;
struct sockaddr_in serv_add;
char buffer[4096];
sockfd=socket(AF_INET,SOCK_STREAM,0);
serv_add.sin_family=AF_INET;
serv_add.sin_addr.s_addr=inet_addr("127.0.0.1");
serv_add.sin_port=htons(SERV_TCP_PORT);
connect(sockfd,(struct sockaddr*)&serv_add,sizeof(serv_add));
do{
bzero(buffer,4096);
printf("\n Client:");
fgets(buffer,4096,stdin);
write(sockfd,buffer,4096);
bzero(buffer,4096);
read(sockfd,buffer,4096);
printf("\n server Message:%s",buffer);
}
while(strcmp(buffer,"bye\n")!=0);
close(sockfd);
return 0;
}
