//WAP to find the sum of n fractions.
#include<stdio.h>

struct fraction
{
	int num;
    int den;
};

void input(int n, struct fraction frac[])
{ 
    printf("Enter the fraction \n");
	for(int i=0;i<n;i++)
 {
     
    printf("Enter the numerator: ");
    scanf("%d",&frac[i].num);
    printf("Enter the denominator: ");
    scanf("%d",&frac[i].den);
 }
}

int gcd(int a, int b)
{
if(b==0)
{
return a;
}
return gcd(b,a%b);
}

int lcm(int n, struct fraction frac[])
{
    int ele = frac[0].den;
    for(int i=0;i<n;i++)
    {
        ele = ((frac[i].den*ele)/(gcd(frac[i].den,ele)));
    }
    return ele;
}

int fnum(int n, int deno, struct fraction frac[])  // to calculate finalnumerator
{
int nsum = 0;
for(int i=0;i<n;i++)
{
		frac[i].num = frac[i].num * (deno/frac[i].den);
}
for(int i=0;i<n;i++)
{
	nsum =nsum+ frac[i].num;
}
return nsum;
}

void output(int numerator, int denominator)
{
	printf("Sum of given fractions is: %d/%d",numerator,denominator);
}

int main(void)
{
	int n;
	printf("Enter the number of fractions to be summed");
	scanf("%d", &n);
	struct fraction f[n];
	input(n,f);
	int dn = lcm(n,f); //stores the final Denominator
	int nm = fnum(n,dn,f); //stores the final Numerator
	output(nm,dn);
return 0;
}
