//WAP to find the volume of a tromboloid using 4 functions.
#include<stdio.h>
float input()
{
  float dim=0.0;
  printf("Ënter the dimensions\n");
  scanf("%f", &dim);
  return dim;
}
float calcu(float h, float b, float d)
{
    float vol;
    vol = (0.33 *((h*d)+d))/b;
    return vol;
}
void output(float volume)
{
    printf("The Volume of Tromboloid %f ", volume);
}
int main()
{ 
 float h1,b1,d1=0.0;
 h1 = input();
 b1 = input();
 d1 = input();
 float vol1 = calcu(h1,b1,d1);
 output(vol1);
 return 0;
} 
