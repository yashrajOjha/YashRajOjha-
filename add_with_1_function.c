//Write a program to add two user input numbers using one function.
#include<stdio.h>
int main()
{ int a,b=0;
  int s=0; //for the sum
  printf("Enter the number1\n");
  scanf("%d", &a);
  printf("Enter the number2\n");
  scanf("%d", &b);
  s=a+b;
  printf("Sum is %d", s);
  return 0;
}

