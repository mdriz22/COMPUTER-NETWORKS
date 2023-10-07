#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<fcntl.h>
int main()
{
int std,i,len,port;
char content[100];
struct sockaddr_in ser,cli;
printf("\n Enter your port number");
scanf("%d",&port);
if((std=socket(AF_INET,SOCK_DGRAM,0))<0)
{
printf("\n socket not created");
exit(0);
}
bzero((char*)&ser,sizeof(ser));
bzero((char*)&cli,sizeof(cli));
ser.sin_family=cli.sin_family=AF_INET;
ser.sin_port=cli.sin_port=htons(port);
ser.sin_addr.s_addr=cli.sin_addr.s_addr=htons(INADDR_ANY);
len=sizeof(ser);
for(;;)
{
printf("\n Enter ip address\n");
scanf("\n %s",content);
sendto(std,content,100,0,(struct sockaddr*)&ser,len);
printf("\n sent to server\n");
printf("%s\n",content);
if(strcmp(content,"bye")==0)
break;
recvfrom(std,content,100,0,(struct sockaddr*)&ser,&len);
printf("\nReceive from server\n");
printf("\n%s",content);
}
close(std);
return(0);
}
