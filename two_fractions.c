//WAP to find the sum of two fractions.
#include<stdio.h>
struct fraction
{ int a;
  int b;
};
struct fraction input();
struct fraction calcsum(struct fraction f1, struct fraction f2); // for computing sum
void display(struct fraction finalfrac); // for displaying the final fraction

struct fraction gcd(struct fraction f)
{
    int div;
    if(f.a>f.b)
    {
        div = f.b;
    }
    else
    {
        div = f.a;
    }
    for (int i = div; i > 0; i--) {
                if (f.a % i == 0 && f.b % i == 0) {
                        f.a = f.a / i;
                        f.b = f.b / i;
                }
        }
        
    return f;
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
void display(struct fraction finalfrac)
{ printf("The sum of the fraction is %d/%d", finalfrac.a, finalfrac.b);
}
int main()
{
    struct fraction frac1, frac2, frac3, frac4;
    frac1 = input();
    frac2 = input();
    frac3 = calcsum(frac1, frac2);
    frac4 = gcd (frac3);
    display(frac4);
    return 0; }
