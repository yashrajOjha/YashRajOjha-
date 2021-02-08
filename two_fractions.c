//WAP to find the sum of two fractions.
#include<stdio.h>
struct fraction
{ int a;
  int b;
};
struct fraction input();
float calcsum(struct fraction f1, struct fraction f2);
void display(float s);
struct fraction input()
{
    struct fraction frac;
    printf("Enter the numerator\n");
    scanf("%d", &frac.a);
    printf("Enter the denominator\n");
    scanf("%d", &frac.b);
    return frac;
}
float calcsum(struct fraction f1, struct fraction f2)
{
    float sum;
    sum = ((f1.a*f2.b)+(f2.a*f1.b))/ (f1.b*f2.b);
    return sum;
}
void display(float s)
{
    printf("The sum of two fractions is %f", s);
}
int main()
{
    struct fraction frac1, frac2;
    frac1 = input();
    frac2 = input();
    float sum1;
    sum1 = calcsum(frac1, frac2);
    display(sum1);
    return 0; }
