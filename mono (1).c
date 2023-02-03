#include<stdio.h>
#include<string.h>

int shouldSwap(char str[],int start,int curr){
	for(int i=start;i<curr;i++)
		if(str[i]==str[curr])
			return 0;
	return 1;
}

void mono(char str[],int index,int n){
	int temp,check;
	if(index>=n){
		printf("%s\n",str);
		return;
		}
	
	for(int i=index;i<n;i++)
	{
		check=shouldSwap(str,index,i);
		if(check){
			temp=str[i];
			str[i]=str[index];
			str[index]=temp;
			
			mono(str,index+1,n);
			
			temp=str[i];
			str[i]=str[index];
			str[index]=temp;
		}
	}
}

void main(){
	char str[50];
	int n;
	printf("enter your string:");
	scanf("%s",str);
	n=strlen(str);
	mono(str,0,n);
}
