#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void encryption(int msg[100][100],int key[3][3],int cipher_mat[100][100],int len1,int order);
void decryption(int cipher_mat[100][100],int key[3][3],int len1,int order);
int main()
{
char message[100];
int order,i,j,key[3][3],count,msg[100][100],l,len,len1, cipher_mat[100][100];
printf("enter the message:\n");
gets(message);
printf("Enter the order of key:\t");
scanf("%d",&order);
printf("Enter the key:\n");
for(i=0;i<order;i++)
for(j=0;j<order;j++)
scanf("%d",&key[i][j]);
len=strlen(message);
l=len%order;
if(l==0)
 len1=len/order;
else
 len1=(len/order)+1;
 count=0;
for(i=0;i<len1;i++)
{
 for(j=0;j<order;j++)
{
 if(count<len)
 msg[i][j]=message[count++]-97;
else
 msg[i][j]='x'-97;
}
}
printf("Encryption is :\n");
encryption(msg,key,cipher_mat,len1,order);
return 0;
}
void encryption(int msg[100][100],int key[3][3],int cipher_mat[100][100],int len1,int order)
{
int i,j,k,u=0;
char encrypt[100];
for(i=0;i<len1;i++)
{
for(j=0;j<order;j++)
{
for(k=0;k<order;k++)
cipher_mat[i][j]+=msg[i][k]*key[k][j];
}
}
for(i=0;i<len1;i++)
{
for(j=0;j<order;j++)
{
cipher_mat[i][j]=cipher_mat[i][j]%26;
printf("%c",cipher_mat[i][j]+97);
encrypt[u++]=cipher_mat[i][j]+97;
}
printf("\n");
encrypt[u]='\0';
}
}
