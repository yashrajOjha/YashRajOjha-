//WAP to find the sum of two fractions.
#include<stdio.h>
struct fraction
{ int a;
  int b;
};
struct fraction input();
struct fraction calcsum(struct fraction f1, struct fraction f2); // for computing sum
void display(struct fraction frac);
int gcd(int num, int den)
{
    int div;
    if(num>den)
    {
        div=den;
    }
    else
    {
        div=num;
    }
    int g;
    for(int i=div;i>0;i--)
    {
        if(num%i==0 && den%i==0)
        {    
          g=i;
          break;
        }
    }
    return g;
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
    int g;
    g= gcd(fsum.a,fsum.b);
    fsum.a= fsum.a/g;
    fsum.b= fsum.b/g;
    return fsum;
}
void display(struct fraction frac)
{ printf("The sum of the fraction is %d/%d", frac.a, frac.b);
}
int main()
{
    struct fraction frac1, frac2, frac3;
    frac1 = input();
    frac2 = input();
    frac3 = calcsum(frac1, frac2);
    display(frac3);
    return 0; }
