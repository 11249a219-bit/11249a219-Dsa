#include<stdio.h>
void TOH (int n,char s,char d,char a)
{
    if (n==1)
{
    printf("\n move %d from %c to %c",n,s,d);
    return;
    }
    TOH(n-1,s,a,d);
    printf("\n move %d from %c to %c\n",n,s,d);
    TOH(n-1,a,d,s);
    }
    int main()
    {
        int n;
        printf("Enter the number of disks:");
        scanf("%d",&n);
        TOH(n,'s','d','a');
    }
