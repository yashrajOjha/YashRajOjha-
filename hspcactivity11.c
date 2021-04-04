#include<stdio.h>
struct student
{
    char sname[20];
    int scores[20];
    float na; //normalised marks
    char grade;
};
typedef struct student stud;
struct gradebook{
    stud s[20];
    char subname[30];
    int m;
    int k;
    float sumw;
    float w[20];
};
typedef struct gradebook gb;

stud input_one_student(int now) //number of weights
{
    stud ones;
    scanf("%s",ones.sname);
    for(int i=0;i<now;i++)
    {
        scanf("%d",&ones.scores[i]);
    }
    return ones;
}

void input_n_student(int n, gb g[n])
{
    for (int i=0;i<n;i++)
    {
        scanf("%s", g[i].subname);
        //printf("--%s", g[i].subname);
        scanf("%d %d",&g[i].m, &g[i].k);
        //printf("--%d %d", g[i].m, g[i].k);
        g[i].sumw=0;
        for(int j=0;j<g[i].k;j++)
        {
            scanf("%f ",&g[i].w[j]);
        }
        for(int j=0;j<g[i].k;j++)
        {
            g[i].sumw+=g[i].w[j];
        }
        //printf("--%f",g[i].sumw);
        for(int j=0;j<g[i].m;j++)
        {
            g[i].s[j]=input_one_student(g[i].k);
        }
    }
}


stud compute_one_student(stud os, gb gc)
{
    float sum=0;
    for(int i=0;i<gc.k;i++)
    {
        sum+=(os.scores[i]*gc.w[i]);
    }
    os.na=sum/gc.sumw;
    if(os.na>=0 && os.na<60)
    {
        os.grade='E';
    }
    else if(os.na>=60 && os.na<70)
    {
        os.grade='D';
    }
    else if(os.na>=70 && os.na<80)
    {
        os.grade='C';
    }
    else if(os.na>=80 && os.na<90)
    {
        os.grade='B';
    }
    else if (os.na>=90 && os.na<100)
    {
        os.grade='A';
    }
    return os;
}

void compute_n_student(int n,gb g[n])
{
    for (int i=0;i<n;i++){
        for(int j=0;j<g[i].m;j++)
        {
        g[i].s[j]=compute_one_student(g[i].s[j], g[i]);
    }
}
}


void print_one_student(stud s)
{
    printf("%-9.9s %0.2f %c\n",s.sname,s.na,s.grade);

}

void print_n_student(int n,gb g[n])
{
    for(int i=0;i<n;i++)
    {
        printf("%s\n",g[i].subname);
        for(int j=0;j<g[i].m;j++)
        {
            print_one_student(g[i].s[j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    gb g[n];
    input_n_student(n,g);
    compute_n_student(n,g);
    print_n_student(n,g);
    return 0;
}

