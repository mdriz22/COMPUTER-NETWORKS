#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#define SERV_PORT 3322

#define BUFFER_SIZE 512 

int main(int argc,char **argv)
{
int i,j;
ssize_t n;
FILE*fp;
char s[80],f[80];
struct sockaddr_in servaddr,cliaddr;
int listenfd,connfd,clilen;
listenfd=socket(AF_INET,SOCK_STREAM,0);
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(SERV_PORT);
bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
listen(listenfd,1);
clilen=sizeof(cliaddr);
connfd=accept(listenfd,(struct sockaddr*)&cliaddr,&clilen);
printf("\n Client Connected");
read(connfd,f,80);
fp=fopen(f,"r");
printf("\nName of the requested file:%s",f);
printf("\nContent of the requested file\n");
while(fgets(s,BUFFER_SIZE,fp)!=NULL)
{
printf("%s",s);
write(connfd,s,sizeof(s));
}
}
