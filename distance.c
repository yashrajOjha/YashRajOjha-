//WAP to find the distance between two point using 4 functions.
#include<stdio.h>
#include<math.h>
float inputpoints()
{
  float p=0.0;
  printf("Enter the points\n");
  scanf("%f", &p);
  return p;
}
float calcudis(float x1, float y1, float x2, float y2)
{
    float dis;
    dis = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    return dis;
}
void output(float distance)
{
    printf("The distance between two points %f ", distance);
}
int main()
{ 
 float x1,x2,y1,y2=0.0;
 x1 = inputpoints();
 y1 = inputpoints();
 x2 = inputpoints();
 y2 = inputpoints();
 float dis1 = calcudis(x1,y1,x2,y2);
 output(dis1);
 return 0;
} 
