#include <string.h>
#include <stdio.h>


void main()

{
char plain[20],cipher[20];
int i, length;

printf("\nEnter the plain text\n") ;
gets(plain);
length = strlen(plain);
printf("\n Encrypted Data\n");

for (i=0;i<length;i++)
{
cipher[i] = plain[i] + 3;
if(plain[i]=='x'||plain[i]=='y'||plain[i]=='z'||plain[i]=='X'||plain[i]=='Y'||(plain[i]=='Z'))
cipher[i]= cipher[i]-26;
printf("%c" ,cipher[i]);
}
printf("\n\n");
printf (" \n Dycrypted Data\n");

for (i=0;i<length;i++)
{
plain[i] = cipher[i] -3;
if (cipher[i]=='a'||cipher[i]=='b'||cipher[i]=='c'||cipher[i]=='A'||cipher[i]=='B'||cipher[i]=='C')

plain[i] = plain[i]+26;


printf("%c", plain[i]);
}
printf("\n\n");
}
