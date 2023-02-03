#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void sboxAccess(int[8][4][16],int[48],int*);
void decimalToBinary(int,int*);
int main()
{
	int sboxes[8][4][16],i,j,k;
	for(i=0;i<8;i++)
		for(j=0;j<4;j++)
			for(k=0;k<16;k++)
				sboxes[i][j][k]=rand()%16;
	for(k=0;k<8;k++)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<16;j++)
			{
				printf("%d",sboxes[k][i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	int input[48];
	for(k=0;k<48;k++)
		input[k]=rand()%2;
	int output[32];
	sboxAccess(sboxes,input,output);
	printf("\nS-box output");
	for(i=0;i<32;i++)
	{
		if(i%4==0)
			printf("\n");
		printf("%d",output[i]);
	}
	printf("\nPermuted output");
	int permutationTable[32]={16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25};
	int permutedoutput[32];
	for(i=0;i<32;i++)
	{
		permutedoutput[i]=output[permutationTable[i]-1];
		if(i%4==0)
			printf("\n");
		printf("%d",permutedoutput[i]);
	}
	return 0;
}
void sboxAccess(int sboxes[8][4][16],int input[48],int output[32])
{
	int i,j,k;
	int numberInput[6],row,column,binaryVersion[4];
	for(i=0;i<8;i++)
	{
		printf("%d",i);
		j=i*6;
		for(k=0;k<6;k++)
		{
			numberInput[k]=input[j+k];
		}
		row=(numberInput[0]*pow(2,1))+(numberInput[5]*pow(2,0));
		column=(numberInput[1]*pow(2,3))+(numberInput[2]*pow(2,2))+(numberInput[3]*pow(2,1))+(numberInput[4]*pow(2,0));
		printf("\nNumber in sbox %d,%d,%d=%d\n",i,row,column,sboxes[i][row][column]);
		decimalToBinary(sboxes[i][row][column],binaryVersion);
		for(k=0;k<4;k++)
		{
			output[(i*4)+k]=binaryVersion[k];
		}
	}
}
void decimalToBinary(int number,int* binary)
{
	int bin[4]={0,0,0,0};
	int i=3;
	if(number!=0)
	{
		while(number!=1)
		{
			bin[i--]=number%2;
			number/=2;
		}
		bin[i]=number;
	}
	for(i=0;i<4;i++)
	{
		binary[i]=bin[i];
	}
}
