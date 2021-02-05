//Write a program to add two user input numbers using 4 functions.
#include <stdio.h>
int enternum()
{
    int n; 
    printf("Enter a number\n");
    scanf("%d",&n);
    return n;
}

int findsum(int a, int b)
{
    int s;
    s = a+b;
    return s;
}

void output(int sum)
{
    printf("Sum of  the two numbers is %d",sum);
}

int main()
{
    int n1,n2,s1;
    n1=enternum();
    n2=enternum();
    s1=findsum(n1,n2);
    output(s1);
    return 0;
}

