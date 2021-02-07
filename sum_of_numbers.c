//Write a program to find the sum of n different numbers using 4 functions
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    printf("Sum of the entered numbers is %d", sum);
    return 0;
}
