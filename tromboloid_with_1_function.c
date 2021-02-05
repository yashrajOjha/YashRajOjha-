//Write a program to find the volume of a tromboloid using one function

#include<stdio.h>
int main()
{ float h,b,d=0.0;
  printf("Ënter the dimensions\n");
  scanf("%f", &h);
  scanf("%f", &b);
  scanf("%f", &d);
 double vol = 0.0;
 vol = (0.33 *((h*d)+d))/b;
 printf("The Volume of Tromboloid %lf ", vol);
 return 0;
} 
