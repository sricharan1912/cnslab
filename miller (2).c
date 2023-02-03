#include<stdio.h>

int modulo(int base,int pow,int mod){
	long long int b=1,i;
	for(i=0;i<pow;i++)
		b=b*base;
	return b%mod;	
}

int miller(int n){
	int m,k=0,i,b,a=2;
	if(n<2)
		return 0;
	if(n==2)
		return 1;
	if(n%2==0&&n!=2)
		return 0;
	m=n-1;
	while(m%2==0){
		m/=2;
		k++;
	}
	b=modulo(a,m,n);
	if(b==1)
		return 1;
	while(b!=1&&b!=n-1&&k!=0){
		b=modulo(b,2,n);
		if(b==0)
			return 0;
		k--;
	}
	if(b==n-1)
		return 1;
	else
		return 0;	
	
}

void main(){
	int n;
	printf("enter the number\n");
	scanf("%d",&n);
	if((miller(n)))
		printf("%d is prime\n",n);
	else
		printf("%d is not prime\n",n);	
}
