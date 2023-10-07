#include<stdio.h>
int * mod2div(int n[], int div[], int clength, int divlength);
int f[20];
void main()
{
int j,i,a,temp2,clength,dlength,divlength,c[20],n[20],div[50];
 a=temp2=0;
int *f;
printf("\n 1.CRC ENCODER 2.CRC DECODER \n EXIT\n Enter your choice:");
scanf("%d",&a);
switch(a)
{
case 1:
printf("enter the length of dataword\n");
scanf("%d",&dlength);
printf("enter the data word\n");
for(i=0;i<dlength;i++)
{
scanf("%d",&n[i]);
}
for(i=0;i<dlength;i++)
{
c[i]=n[i];
}
printf("enter the length of divisor\n");
scanf("%d",&divlength);
printf("enter the divisor\n");
for(i=0;i<divlength;i++)
{
scanf("%d",&div[i]);
}
clength=dlength+divlength-1;
for(i=dlength;i<clength;i++)
{
n[i]=0;
}
printf("\nthe data with zeros is \n");
for(i=0;i<clength;i++)
printf("%d",n[i]);
f=mod2div(n,div,clength,divlength);
for(i=dlength;i<clength;i++)
{
c[i]=n[i];
}
printf("\n The codeword is \n ");
for(i=0;i<clength;i++)
{
printf("%d",c[i]);
}
break;
case 2:
printf("enter the length of codeword\n");
scanf("%d",&clength);
printf("enter the code word\n");
for(i=0;i<clength;i++)
{
scanf("%d",&n[i]);
}
printf("enter the length of divisor\n");
scanf("%d",&divlength);
printf("enter the divisor\n");
for(i=0;i<divlength;i++)
{
scanf("%d",&div[i]);
}
f=mod2div(n,div,clength,divlength);
for(j=0;j<divlength;j++)
{
 temp2=temp2+f[j];
 }
if(temp2==0)
printf("\n No error in received code");
else
printf("\n error occurs in received code");
break;
case 3:
printf("EXIT");
}
return 0;
}
// function description mod2div
int * mod2div(int n[], int div[], int clength, int divlength)
{
int i,M,temp,dlength,j,quot[20];
dlength=clength-divlength+1;
for(i=0;i<dlength;i++)
{
temp=i;
if(n[i]==1)
{
quot[i]=1;
for (j=0;j<divlength;j++)
{
M=n[temp]^div[j];
n[temp]=f[j]=M;
temp=temp+1;
}
}
else
{
quot[i]=0;
for(j=0;j<divlength;j++)
f[j]=n[i+j];
}
}
printf("\n and the quotient is \n ");
for(j=0;j<dlength;j++)
printf("%d",quot[j]);
printf("\n and the remainder is \n ");
for(j=0;j<divlength;j++)
printf("%d",f[j]);
return f;
}
