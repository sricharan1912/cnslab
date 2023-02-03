#include<stdio.h>
#include<ctype.h>


char str[50],key[50],temp[26],mat[5][5];

void check(char a){
	int i;
	if(a=='I')
		a='J';
	for(i=0;temp[i]!=NULL;i++){
		if(a==temp[i])
			return;
	}
	temp[i]=a;
}

void makematrix(){
	int k=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			mat[i][j]=temp[k++];
			printf("%c",mat[i][j]);
			}
		printf("\n");
		}
}

void fill(){
	int i;
	printf("enter the plaintext\n");
	scanf("%s",str);
	for(i=0;str[i]!=NULL;i++){
		str[i]=toupper(str[i]);
	}
	printf("enter the key\n");
	scanf("%s",key);
	for(i=0;key[i]!=NULL;i++){
		key[i]=toupper(key[i]);
	}
	for(i=0;key[i]!=NULL;i++){
		check(key[i]);
	}
	for(i='A';i<='Z';i++){
		check(i);
	}
	makematrix();
	
}

void encrypt(char a,char b){
	int i,j,k,m;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(a==mat[i][j])
				goto out1;
	out1:
	for(k=0;k<5;k++)
		for(m=0;m<5;m++)
			if(b==mat[k][m])
				goto out2;
	out2:
	if(i==k){
		printf("%c",mat[i][(j+1)%5]);
		printf("%c",mat[k][(m+1)%5]);
	}
	else if(j==m){
		printf("%c",mat[(i+1)%5][j]);
		printf("%c",mat[(k+1)%5][m]);
	}
	else{
		printf("%c",mat[i][m]);
		printf("%c",mat[k][j]);
	}
}

void playfair(){
	for(int i=0;str[i]!=NULL;i++){
		if(str[i]=='I')
			str[i]='J';
		if(str[i+1]=='I')
			str[i+1]='J';
		if(str[i]==str[i+1]||str[i+1]==NULL)
			encrypt(str[i],'X');
		else{
			encrypt(str[i],str[i+1]);
			i++;
		}
	}
}
void main(){
	fill();
	playfair();
}
