#include<stdio.h>

 int power(int base, int pw, int mod) {
 int i,b=1;
    for(i=0;i<pw;i++)
    	b=b*base;
    return b%mod;
}

int main() {
    int a, q, x1, y1, x2, y2;
    printf("Enter the value of q and a: ");
    scanf("%d%d", &q, &a);
    printf("Enter the value of x1 for the first person : ");
    scanf("%d", &x1);
    y1 = power(a,x1,q);
    printf("Enter the value of x2 for the second person : ");
    scanf("%d", &x2);
    y2 = power(a,x2,q);
    printf("key for the first person is : %d\n", power(y1,x2,q));
    printf("key for the second person is : %d\n", power(y2,x1,q));
    return 0;
}
