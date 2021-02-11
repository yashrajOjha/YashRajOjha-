//WAP to find the sum of two fractions.
#include<stdio.h>
struct fraction
{ int a;
  int b;
};
struct fraction input();
struct fraction calcsum(struct fraction f1, struct fraction f2); // for computing sum
void display(struct fraction finalfrac, int g1); // for displaying the final fraction

int gcd(int num, int den)
{
if(den==0)
{
return num;
}
return gcd(den,num%den);
}

struct fraction input()
{
    struct fraction frac;
    printf("Enter the numerator\n");
    scanf("%d", &frac.a);
    printf("Enter the denominator\n");
    scanf("%d", &frac.b);
    return frac;
}
struct fraction calcsum(struct fraction f1, struct fraction f2)
{
    struct fraction fsum;
    fsum.a = (f1.a*f2.b)+(f2.a*f1.b);
    fsum.b = (f1.b*f2.b);
    return fsum;
}
void display(struct fraction finalfrac, int g1)
{ printf("The sum of the fraction is %d/%d", finalfrac.a/g1, finalfrac.b/g1);
 //  printf("%d", g1);
}
int main()
{
    struct fraction frac1, frac2, frac3;
    int g;
    frac1 = input();
    frac2 = input();
    frac3 = calcsum(frac1, frac2);
    g = gcd(frac3.a, frac3.b);
    display(frac3, g);
    return 0; }

