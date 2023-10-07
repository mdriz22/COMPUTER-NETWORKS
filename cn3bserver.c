#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<strings.h>
#define SERV_TCP_PORT 3771
int main(int argc,char*argv[])
{
int sockfd,new,clen;
struct sockaddr_in serv_add,cli_add;
char buffer[4096];
sockfd=socket(AF_INET,SOCK_STREAM,0);
serv_add.sin_family=AF_INET;
serv_add.sin_addr.s_addr=inet_addr("127.0.0.1");
serv_add.sin_port=htons(SERV_TCP_PORT);
bind(sockfd,(struct sockaddr*)&serv_add,sizeof(serv_add));
listen(sockfd,5);
clen=sizeof(cli_add);
new=accept(sockfd,(struct sockaddr*)&cli_add,&clen);
do
{
bzero(buffer,4096);
read(new,buffer,4096);
printf("\n Client message:%s",buffer);
bzero(buffer,4096);
printf("server:");
fgets(buffer,4096,stdin);
write(new,buffer,4096);
}
while(strcmp(buffer,"bye\n")!=0);
close(sockfd);
return 0;
}

