#include <stdio.h>
int main()
{
    int a;
    printf("Enter a number:");
    scanf("%d",&a);
    int n=100;
    if(a%2==0)
    {
        for(int i=1;i<n;i++)
        {
            if(a==2^i)
            {
                printf("POWER OF TWO");
                break;
            }
            else
                printf("NOT POWER OF TWO");
        }
    }
    else
        printf("NOT POWER OF TWO");
    return 0;
}