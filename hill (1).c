#include<stdio.h>
#include<string.h>
#include<ctype.h>

char temp[3][3],key[3][3];

void multiply(){
	int i,j,k;
	int mul[3][3];
	for(j=0;j<3;j++){
		mul[0][j]=0;
		for(k=0;k<3;k++)
			mul[0][j]+=temp[0][k]*key[k][j];
		}
	for(j=0;j<3;j++)
		printf("%d-%c ",(mul[0][j]%26),(mul[0][j]%26)+65);
	printf("\n");
}

void main(){
	int i,j;
	char str[50];
	printf("enter the string\n");
	scanf("%s",str);
	for(i=0;i<strlen(str);i++)
		str[i]=toupper(str[i]);
		
	printf("enter the key\n");	
	for(i=0;i<3;i++)
		for(j=0;j<3;j++){
			scanf("%d",&key[i][j]);
			temp[i][j]=0;
		}
	i=0;
	while(str[i]!=NULL){
		for(j=0;j<3;j++)
		{
			temp[0][j]=(str[i++])-65;
			printf("%d-%c ",temp[0][j],temp[0][j]+65);
		}
		printf(":");
		multiply();
	}
}
