#include <stdio.h>
int main()
{
    int a,b,c=0;
    printf("Enter a number:");
    scanf("%d",&a);
    while(a!=0)
    {
        b=a%10;
        b<<1;
        if(b==1)
            c++;
        a/=10;
    }
    printf("%d",c);
    return 0;
}