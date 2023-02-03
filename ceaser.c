#include<stdio.h>
#include<string.h>

 void main(){
 	char str[70];
 	int i;
  	printf("enter your string\n");
 	scanf("%[^\n]s",str);
 	for(i=0;i<strlen(str);i++)
 	{
 		if((str[i]>='a'&&str[i]<='w')||(str[i]>='A'&&str[i]<='W'))
 			str[i]=str[i]+3;
 		else if((str[i]>='w'&&str[i]<='z')||(str[i]>='X'&&str[i]<='Z'))
 			str[i]=str[i]-23;
 	}
 	printf("%s\n",str);
 	for(i=0;i<strlen(str);i++)
 	{
 		if((str[i]>='d'&&str[i]<='z')||(str[i]>='D'&&str[i]<='Z'))
 			str[i]=str[i]-3;
 		else if((str[i]>='a'&&str[i]<='c')||(str[i]>='A'&&str[i]<='C'))
 			str[i]=str[i]+23;
 	}
 	printf("%s\n",str);
 }
