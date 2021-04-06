#include<stdio.h>
#define max 100
struct fraction
{
	int n;
	int d[100];
	int ns;
	int ds;
};
typedef struct fraction frac;
int input(frac f[])
{
	int ni = 0;
	scanf("%d",&ni);

	for(int i = 0;i < ni; i++)
	{
		scanf("%d",&f[i].n);
		for(int j =0;j < f[i].n ;j++)
		{
			scanf("%d",&f[i].d[j]);
		}
	}
	return ni;
}
int hcf(int a, int b)
{
	int h = 1;
	int min =0;
	if(a<b)
	{
		min = a;
	}
	else
	{
		min = b;
	}
	for(int i=min;i>0;i--)
	{
		if(a%i == 0 && b%i == 0)
		{
			h = i;
		}
	}
	return h;
}
void sim(frac f[],int ni)
{
	for(int i=0;i<ni; i++)
	{
		int h = hcf(f[i].ns,f[i].ds);
		f[i].ns = f[i].ns/h;
		f[i].ds = f[i].ds/h;
	}
}
void add(frac f[],int ni)
{
	for(int i=0;i < ni;i++)
	{
		f[i].ns = 0;
		f[i].ds = 1;
		for(int j = 0;j < f[i].n;j++)
		{
			int final1 =1;
			if(f[i].n==1)
			{
				f[i].ns = 1;
				f[i].ds = f[i].d[j];
				continue;
			}
			for(int k =0;k < f[i].n; k++)
			{
				if(j != k)
				{
					final1 = final1 * f[i].d[k];
				}
			}
			f[i].ns = f[i].ns + final1;
			f[i].ds = f[i].ds * f[i].d[j];
		}
		sim(f,ni);
	}
}
void print(frac f[],int ni)
{
	for(int i =0; i<ni ;i++)
	{
		for(int j=0; j<f[i].n;j++)
		{
			if(j!=f[i].n-1)
			{
				printf("1/%d + ",f[i].d[j]);
			}
			else
			{
				printf("1/%d = ",f[i].d[j]);
			}
		}
		printf("%d/%d\n",f[i].ns,f[i].ds);
	}
}
int main()
{
	frac f[max];
	int noi = input(f);
	add(f,noi);
	print(f,noi);
	return 0;
}
