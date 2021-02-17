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



struct fraction fnum(int n, struct fraction frac[])  // to calculate finalnumerator
{
    struct fraction finalfrac;
    finalfrac.den = lcm(n, frac);
    int nsum = 0;
    for(int i=0;i<n;i++)
    {
		frac[i].num = frac[i].num * (finalfrac.den/frac[i].den);
    }
    for(int i=0;i<n;i++)
    {
	nsum =nsum+ frac[i].num;
    }
    finalfrac.num = nsum;
    return finalfrac;
}

void output(int n,struct fraction f[], struct fraction finalf)
{
	printf("Sum of given fractions");
	for(int i=0;i<n;i++)
	{
	    printf("%d/%d +", f[i].num, f[i].den);
	}
	printf(" is %d/%d", finalf.num,finalf.den);
}

int main()
{
	int n;
	printf("Enter the number of fractions to be summed");
	scanf("%d", &n);
	struct fraction f[n];
	input(n,f);
	struct fraction finalf = fnum(n,f); //stores the final fraction
	output(n,f, finalf);
        return 0;
}

