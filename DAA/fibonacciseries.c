#include<stdio.h>
int fib(int n)
{
    if(n==0)
{
    return 0;
}
if (n==1)
{
    return 1;
}
return fib(n-1)+fib(n-2);
}
int main()
{
    int n,result;
    printf("Enter the integer number n:");
    scanf("%d",&n);
    if (n<0)
{
    printf("Invalid number");
    return 0;
}
result=fib(n);
printf("fibonacci term is %d",result);
}
