#include<stdio.h>
#include<string.h>

int rail;
char plain[50],cipher[50],decrypted[50],mat[50][50];

void encrypt(){
	int i,j,row=0,column=0,k=-1,m=0;
	for(i=0;i<rail;i++)
		for(j=0;j<strlen(plain);j++)
			mat[i][j]='\n';
			
	for(i=0;i<strlen(plain);i++){
		mat[row][column++]=plain[i];
		if(row==0||row==rail-1)
			k=k*-1;
		row+=k;
	}
	
	for(i=0;i<rail;i++)
		for(j=0;j<strlen(plain);j++)
			if(mat[i][j]!='\n')
				cipher[m++]=mat[i][j];	
				
	printf("%s\n",cipher);
}

void decrypt(){
	int i,j,row=0,column=0,k=-1,m=0;
	for(i=0;i<rail;i++)
		for(j=0;j<strlen(plain);j++)
			mat[i][j]='\n';
			
	for(i=0;i<strlen(plain);i++){
		mat[row][column++]='*';
		if(row==0||row==rail-1)
			k=k*-1;
		row+=k;
	}
	
	for(i=0;i<rail;i++)
		for(j=0;j<strlen(plain);j++)
			if(mat[i][j]=='*')
				mat[i][j]=cipher[m++];
	row=0;
	column=0;
	k=-1;
				
	for(i=0;i<strlen(plain);i++){
		decrypted[i]=mat[row][column++];
		if(row==0||row==rail-1)
			k=k*-1;
		row+=k;
	}
	
	printf("%s\n",decrypted);		
}

void main(){
	printf("enter the string\n");
	scanf("%s",plain);
	printf("enter the number of rails\n");
	scanf("%d",&rail);
	encrypt();
	decrypt();
}
