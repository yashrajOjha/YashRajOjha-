//WAP to find the sum of two fractions.
#include<stdio.h>
struct fraction
{ int a;
  int b;
};
struct fraction input();
void calcsum(struct fraction f1, struct fraction f2);
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
void calcsumdis(struct fraction f1, struct fraction f2)
{
    int nsum, dsum;
    nsum = (f1.a*f2.b)+(f2.a*f1.b);
    dsum = (f1.b*f2.b);
    printf("The Sum of fractions is %d/%d", nsum,dsum);
}
int main()
{
    struct fraction frac1, frac2;
    frac1 = input();
    frac2 = input();
    calcsumdis(frac1, frac2);
    return 0; }
