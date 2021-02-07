//WAP to find the distance between two points using structures and 4 functions.
#include<stdio.h>
#include<math.h>
struct twopoints 
{ float x;
  float y;
};
struct twopoints getInput(); //to get input
float calcDis( struct twopoints p1, struct twopoints p2); //to calculate distance
void display(float distance); //to display

struct twopoints getInput() 
{
  struct twopoints a; // for anyset of points

  printf("Enter points ");
  scanf ("%f", &a.x);
  scanf("%f", &a.y);
  
  return a;
}	
float calcDis( struct twopoints p1, struct twopoints p2)
{ 
float dis; 
dis = sqrt(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2));
return dis;
}

void display(float distance)
{ printf("The distance between two points is %f", distance);
}

int main()
{ float dist;
  struct twopoints s1,s2;
  s1 = getInput();
 s2 = getInput();
dist = calcDis(s1,s2);
display(dist);
return 0;
}
